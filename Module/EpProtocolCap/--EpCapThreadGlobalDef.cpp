#include "StdAfx.h"
#include "EpCapThreadGlobalDef.h"
#include "..\CriticalSection\SynCriticalSection.h"

LONG64 g_nCaptureID = 0;

CAutoCriticSection g_pCaptureIDCriticSection;


LONG64 Ep_Cap_GenerateCaptureID()
{
	CAutoSimpleLock oLock(g_pCaptureIDCriticSection);
	g_nCaptureID++;
	return g_nCaptureID;	
}

//////////////////////////////////////////////////////////////////////////
//filter

void ep_SetIP(ep_ip_address *pIP, ULONG dwIP)
{
	ASSERT (pIP != NULL);

	if (pIP == NULL)
	{
		return;
	}

	pIP->s_addr = dwIP;
}

void ep_SetIpV4(ep_ip_address *ip, const CString &strIP)
{
	char pszIP[40];
	CString_to_char(strIP, pszIP);
	ULONG saddr = atol(pszIP);
	ep_SetIP(ip, saddr);
}

void ep_GetIpV4(ep_ip_address *ip, CString &strIP)	
{
	ASSERT (ip != NULL);	
	strIP = CString(inet_ntoa(*ip));
}


void ep_FreeFilters(ep_cap_filters *pFilters)
{
	ASSERT (pFilters != NULL);

	if (pFilters == NULL)
	{
		return;
	}

	pFilters->count_filter = 0;
}

BOOL ep_SetFilterCount(ep_cap_filters *pFilters, u_char count)
{
	ASSERT (pFilters != NULL);

	if (pFilters == NULL)
	{
		return FALSE;
	}

	ep_FreeFilters(pFilters);
	pFilters->count_filter = count;
	memset(pFilters->filters, 0, count * sizeof(ep_cap_filter));

	return TRUE;
}

void ep_SetFilter(ep_cap_filter &filter, DWORD sip, DWORD dip, SHORT sport, SHORT dport)
{
	ep_SetIP(filter.ips.sip, sip);
	ep_SetIP(filter.ips.dip, dip);

	filter.ports.sport = sport;
	filter.ports.dport = dport;
}

void ep_SetTcpFilter(ep_cap_filters *pFilters, u_char index, DWORD sip, DWORD dip, SHORT sport, SHORT dport)
{
	ASSERT (pFilters != NULL);

	if (pFilters == NULL)
	{
		return;
	}

	ASSERT (0 <= index && index <= pFilters->count_filter);

	if ( !(0 <= index && index <= pFilters->count_filter) )
	{
		return;
	}

	ep_cap_filter &filter = pFilters->filters[index];
	filter.type = EFT_TCP;
	ep_SetFilter(filter, sip, dip, sport, dport);
}


void ep_SetUdpFilter(ep_cap_filters *pFilters, u_char index, DWORD sip, DWORD dip, SHORT sport, SHORT dport)
{
	ASSERT (pFilters != NULL);

	if (pFilters == NULL)
	{
		return;
	}

	ASSERT (0 <= index && index <= pFilters->count_filter);

	if ( !(0 <= index && index <= pFilters->count_filter) )
	{
		return;
	}

	ep_cap_filter &filter = pFilters->filters[index];
	filter.type = EFT_UDP;
	ep_SetFilter(filter, sip, dip, sport, dport);
}

BOOL ep_FindFilter(ep_cap_filter *pFilter, u_char type, DWORD sip, DWORD dip, SHORT sport, SHORT dport)
{
	return (pFilter->type == type && pFilter->ips.sip.s_addr == sip && pFilter->ips.dip.s_addr == dip
		&& pFilter->ports.sport == sport && pFilter->ports.dport == dport);
}

ep_cap_filter* ep_FindFilter(ep_cap_filters *pFilters, u_char type, DWORD sip, DWORD dip, SHORT sport, SHORT dport)
{
	ep_cap_filter *filter = NULL;
	u_char index = 0;

	for (index=0; index < pFilters->count_filter; index++)
	{
		if (ep_FindFilter(&pFilters->filters[index], type, sip, dip, sport, dport))
		{
			filter = &pFilters->filters[index];
			break;
		}
	}

	return filter;
}

ep_cap_filter* ep_AddFilter(ep_cap_filters *pFilters)
{
	if (pFilters->count_filter + 1 >= MAX_EP_CAP_FILTER_COUNT)
	{
		return NULL;
	}

	ASSERT (pFilters != NULL);
	pFilters->count_filter = pFilters->count_filter + 1;
	return &(pFilters->filters[pFilters->count_filter-1]);
}

ep_cap_filter* ep_AddTcpFilter(ep_cap_filters *pFilters, DWORD sip, DWORD dip, SHORT sport, SHORT dport)
{
	ASSERT (pFilters != NULL);

	if (pFilters == NULL)
	{
		return NULL;
	}

	ep_cap_filter* pFilter = ep_AddFilter(pFilters);

	if (pFilter == NULL)
	{
		return pFilter;
	}

	pFilter->type = EFT_TCP;
	ep_SetFilter(*pFilter, sip, dip, sport, dport);

	return pFilter;
}


ep_cap_filter* ep_AddUdpFilter(ep_cap_filters *pFilters, DWORD sip, DWORD dip, SHORT sport, SHORT dport)
{
	ASSERT (pFilters != NULL);

	if (pFilters == NULL)
	{
		return NULL;
	}

	ep_cap_filter* pFilter = ep_AddFilter(pFilters);

	if (pFilter == NULL)
	{
		return pFilter;
	}

	pFilter->type = EFT_UDP;
	ep_SetFilter(*pFilter, sip, dip, sport, dport);

	return pFilter;
}

ep_cap_filter* ep_AddFilter(ep_cap_filters *pFilters, u_char type, DWORD sip, DWORD dip, SHORT sport, SHORT dport)
{
	ASSERT (pFilters != NULL);

	if (pFilters == NULL)
	{
		return NULL;
	}

	ep_cap_filter* pFilter = ep_AddFilter(pFilters);

	if (pFilter == NULL)
	{
		return pFilter;
	}

	pFilter->type = type;
	ep_SetFilter(*pFilter, sip, dip, sport, dport);

	return pFilter;
}

void ep_DeleteFilter(ep_cap_filters *pFilters, ep_cap_filter *pFilter)
{
	u_char index = MAX_EP_CAP_FILTER_COUNT;
	u_char i = 0;

	for (i=0; i<pFilters->count_filter; i++)
	{
		if (&(pFilters->filters[i]) == pFilter)
		{
			index = i;
			break;
		}
	}

	ep_DeleteFilter(pFilters, index);
}

void ep_DeleteFilter(ep_cap_filters *pFilters, u_char index)
{
	if (index >= MAX_EP_CAP_FILTER_COUNT)
	{
		return;
	}

	u_char i = 0;
	
	for (i=index; i<pFilters->count_filter; i++)
	{
		pFilters->filters[i] = pFilters->filters[i+1];
	}

	pFilters->count_filter--;
}

void ep_GetFilterIpString(ep_cap_filter_ips &ips, CString &strIpFilter)
{
	CString strIp1, strIp2;
	ep_GetIpV4(ips.sip, strIp1);
	ep_GetIpV4(ips.dip, strIp2);

	if (ep_IsFilterUseSDIp(&ips))
	{
		//两个IP相同,表示目标地址或者源地址,即监视发给源地址以及源地址发送的报文
		if (ips.sip.s_addr == ips.dip.s_addr)
		{
			strIpFilter.Format(_T("src host %s or dst host %s"), strIp1, strIp2);
		}
		else
		{
			strIpFilter.Format(_T("src host %s and dst host %s"), strIp1, strIp2);
		}
	}
	else if (ep_IsFilterUseSIp(&ips))
	{
		strIpFilter.Format(_T("src host %s"), strIp1);
	}
	else if (ep_IsFilterUseDIp(&ips))
	{
		strIpFilter.Format(_T("dst host %s"), strIp2);
	}
	else
	{
		strIpFilter = _T("");
	}
}

void ep_GetFilterPortString(ep_cap_filter_ports &ports, CString &strPortFilter)
{
	if (ep_IsFilterUsePort(&ports))
	{
		if(ports.dport == ports.sport)
		{
			strPortFilter.Format(_T("src port %d or dst port %d"), ports.sport, ports.dport);
		}
		else
		{
			strPortFilter.Format(_T("src port %d and dst port %d"), ports.sport, ports.dport);
		}
	}
	else if (ep_IsFilterUseSPort(&ports))
	{
		strPortFilter.Format(_T("src port %d "), ports.sport);
	}
	else if (ep_IsFilterUseDPort(&ports))
	{
		strPortFilter.Format(_T("dst port %d "), ports.dport);
	}
	else
	{
		strPortFilter = _T("");
	}
}

void ep_GetFilterString(ep_cap_filter *pFilter, CString &strFilter)
{
	CString strType, strIpFilter, strPortFilter;

	switch (pFilter->type)
	{
	case EFT_TCP:
		strType = _T("(tcp and ip)");
		break;
	case EFT_UDP:
		strType = _T("(udp and ip)");
		break;
	default:
		ASSERT (FALSE);
		break;
	}

	strFilter = strType;

	if (ep_IsFilterUseIp(pFilter))
	{//如果使用IP过滤
		ep_GetFilterIpString(pFilter->ips, strIpFilter);
		strFilter.AppendFormat(_T(" and (%s)"), strIpFilter);
	}

	if (ep_IsFilterUsePort(pFilter))
	{//如果使用端口过滤
		ep_GetFilterPortString(pFilter->ports, strPortFilter);
		strFilter.AppendFormat(_T(" and (%s)"), strPortFilter);
	}

// 	struct in_addr addr;
// 	addr.s_addr = htonl((unsigned long)g_pNetMonitorData->m_dwLocal1Address);
// 	CString strAddrLocal1 = inet_ntoa(addr);
// 	addr.s_addr = htonl((unsigned long)g_pNetMonitorData->m_dwLocal2Address);
// 	CString strAddrLocal2 = inet_ntoa(addr);
// 
// 	//m_strFilter = "tcp and ip";
// 	if (m_bTCP)
// 	{
// 		m_strFilter.Format("tcp and ip and \
// 						   ((src host %s or dst host %s) or (dst host %s or src host %s))and \
// 						   (src port 2404 or dst port 2404)", 
// 			strAddrLocal1, strAddrLocal1, strAddrLocal2, strAddrLocal2);
// 	}
// 	if (m_bUDP)
// 	{
// 		m_strFilter.Format("udp and ip and \
// 						   ((src host %s or dst host %s) or (dst host %s or src host %s))and \
// 						   (src port 2404 or dst port 2404)", 
// 						   strAddrLocal1, strAddrLocal1, strAddrLocal2, strAddrLocal2);
// 	}

}

void ep_GetFiltersString(ep_cap_filters *pFilters, CString &strFilter)
{
	ASSERT (pFilters != NULL);

	if (pFilters == NULL)
	{
		return;
	}

	long nIndex = 0;
	strFilter = _T("");
	CString strTemp;

	if (pFilters->count_filter == 0)
	{
		return;
	}

	if (pFilters->count_filter == 1)
	{
		ep_GetFilterString(&(pFilters->filters[nIndex]), strFilter);
		return;
	}

	for (nIndex=0; nIndex < pFilters->count_filter; nIndex++)
	{
		ep_GetFilterString(&(pFilters->filters[nIndex]), strTemp);

		if (strFilter.GetLength() > 0)
		{
			strFilter.AppendFormat(_T(" or (%s)"), strTemp);
		}
		else
		{
			strFilter.AppendFormat(_T("(%s)"), strTemp);
		}
	}
}

void ep_GetFilterType(UINT nType, CString &strType)
{
	switch (nType)
	{
	case EFT_TCP:
		strType = _T("TCP");
		break;
	case EFT_UDP:
		strType = _T("UDP");
		break;
// 	case EFT_ICMP:
// 		strType = _T("ICMP");
// 		break;
// 	case EFT_ARP:
// 		strType = _T("ARP");
// 		break;
	default:
		strType = _T("");
	}
}

void ep_GetIpProtocol(UINT nProtocol, CString &strProtocol)
{
	switch (nProtocol)
	{
	case 6:
		strProtocol = _T("TCP");
		break;
	case 17:
		strProtocol = _T("UDP");
		break;
	case 1:
		strProtocol = _T("ICMP");
		break;
	default:
		strProtocol = _T("......");
	}
}
