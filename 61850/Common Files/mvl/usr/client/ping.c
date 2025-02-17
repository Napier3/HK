#pragma pack(4) 
#include "winsock2.h"
//#include "stdlib.h"
//#include "stdio.h"
#include "glbtypes.h"
#include "sysincs.h"
#include "glbsem.h"
#define ICMP_ECHO 8 
#define ICMP_ECHOREPLY 0 
#define ICMP_MIN 8 // minimum 8 byte icmp packet (just header) 
/* The IP header */ 
typedef struct iphdr { 
unsigned int h_len:4; // length of the header 
unsigned int version:4; // Version of IP 
unsigned char tos; // Type of service 
unsigned short total_len; // total length of the packet 
unsigned short ident; // unique identifier 
unsigned short frag_and_flags; // flags 
unsigned char ttl; 
unsigned char proto; // protocol (TCP, UDP etc) 
unsigned short checksum; // IP checksum 
unsigned int sourceIP; 
unsigned int destIP; 
}IpHeader; 
// 
// ICMP header 
// 

typedef struct icmphdr { 
BYTE i_type; 
BYTE i_code; /* type sub code */ 
USHORT i_cksum; 
USHORT i_id; 
USHORT i_seq; 
/* This is not the std header, but we reserve space for time */ 
ULONG timestamp; 
}IcmpHeader; 

#define DEF_PACKET_SIZE 32
#define MAX_PACKET 1024 

void fill_icmp_data(char *, int); 
USHORT checksum(USHORT *, int); 

int ping(unsigned long IP);

/* 
Helper function to fill in various stuff in our ICMP request. 
*/ 
void fill_icmp_data(char * icmp_data, int datasize){ 
IcmpHeader *icmp_hdr; 
char *datapart; 
icmp_hdr = (IcmpHeader*)icmp_data; 
icmp_hdr->i_type = ICMP_ECHO; 
icmp_hdr->i_code = 0; 
icmp_hdr->i_id = (USHORT)GetCurrentProcessId(); 
icmp_hdr->i_cksum = 0; 
icmp_hdr->i_seq = 0; 
datapart = icmp_data + sizeof(IcmpHeader); 
// 
// Place some junk in the buffer. 
// 
memset(datapart,'E', datasize - sizeof(IcmpHeader)); 
} 

USHORT checksum(USHORT *buffer, int size) { 
unsigned long cksum=0; 
	while(size >1) { 
		cksum+=*buffer++; 
		size -=sizeof(USHORT); 
	} 
	if(size) { 
		cksum += *(UCHAR*)buffer; 
	}
	
	cksum = (cksum >> 16) + (cksum & 0xffff); 
	cksum += (cksum >>16); 
	return (USHORT)(~cksum); 
} 

int decode_resp(char *buf, int bytes,struct sockaddr_in *from, struct sockaddr_in *dest) {

	IpHeader *iphdr;
	IcmpHeader *icmphdr;
	unsigned short iphdrlen;

	iphdr = (IpHeader *)buf;
	iphdrlen = iphdr->h_len * 4 ; // number of 32-bit words *4 = bytes

	icmphdr = (IcmpHeader*)(buf + iphdrlen);

	if (icmphdr->i_type != ICMP_ECHOREPLY) {
		return 0;
	}

	if (icmphdr->i_id != (USHORT)GetCurrentProcessId()) {
		return 0;
	}

	if (from->sin_addr.s_addr == dest->sin_addr.s_addr){
		     return 1;
	}else    return 0;
}


int ping(unsigned long IP)
{
SOCKET sockRaw; 
struct sockaddr_in dest,from; 
int timeout = 1000;
int bread, bwrote;
char icmp_data[MAX_PACKET]={0};
char recvbuf[MAX_PACKET]={0};
int fromlen;
int datasize;
int i;

	sockRaw = WSASocket (AF_INET,
					   SOCK_RAW,
					   IPPROTO_ICMP,
					   NULL, 0, WSA_FLAG_OVERLAPPED);
	if (sockRaw == INVALID_SOCKET) { 
		closesocket(sockRaw);
		return 0;
	} 

	bread = setsockopt(sockRaw,SOL_SOCKET,SO_RCVTIMEO,(char*)&timeout, 
	sizeof(timeout)); 
	if(bread == SOCKET_ERROR) { 
		closesocket(sockRaw);
		return 0;
	} 

	timeout = 1000; 
	bread = setsockopt(sockRaw,SOL_SOCKET,SO_SNDTIMEO,(char*)&timeout, 
	sizeof(timeout)); 
	if(bread == SOCKET_ERROR) {  
		closesocket(sockRaw);
		return 0;
	}

	memset(&dest,0,sizeof(dest));
	dest.sin_addr.s_addr = IP;
	dest.sin_family = AF_INET; 

	datasize = DEF_PACKET_SIZE; 
    datasize += sizeof(IcmpHeader); 

	memset(icmp_data,0,MAX_PACKET);
	fill_icmp_data(icmp_data,  datasize); 

	((IcmpHeader*)icmp_data)->i_cksum = 0; 
	((IcmpHeader*)icmp_data)->timestamp = GetTickCount(); 
	((IcmpHeader*)icmp_data)->i_seq = 1; 
	((IcmpHeader*)icmp_data)->i_cksum = checksum((USHORT*)icmp_data, datasize);

	for(i=0; i<10; i++){
		bwrote = sendto(sockRaw,icmp_data,datasize,0,(struct sockaddr*)&dest,
						sizeof(dest));
		if (bwrote == SOCKET_ERROR){ 
			closesocket(sockRaw);
			return 0; 
		}

		fromlen = sizeof(from); 
		bread = recvfrom(sockRaw,recvbuf,MAX_PACKET,0,(struct sockaddr*)&from,
					 &fromlen); 
		if (bread == SOCKET_ERROR){ 
			closesocket(sockRaw);
			return 0;
		}
		if(1 == decode_resp(recvbuf,bread,&from, &dest)){
					closesocket(sockRaw);
						return 1;
		}

		Sleep(1000);
	}
	closesocket(sockRaw);
	return 0;
} 

 

