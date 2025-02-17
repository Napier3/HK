/************************************************************************/
/* SISCO SOFTWARE MODULE HEADER *****************************************/
/************************************************************************/
/*   (c) Copyright Systems Integration Specialists Company, Inc.,	*/
/*      	  1996, All Rights Reserved.		        	*/
/*									*/
/*		    PROPRIETARY AND CONFIDENTIAL			*/
/*									*/
/* MODULE NAME : clnp_sne.h						*/
/* PRODUCT(S)  : Lean-T Stack						*/
/*									*/
/* MODULE DESCRIPTION : 						*/
/*		This header file defines the interface between the	*/
/*		Connectionless-mode Network Protocol (CLNP) and the	*/
/*		underlying sub-network.					*/
/*									*/
/* GLOBAL STRUCTURES DEFINED IN THIS MODULE :				*/
/*									*/
/*			SN_UNITDATA struct				*/
/*									*/
/* GLOBAL FUNCTIONS DEFINED IN THIS MODULE :				*/
/*									*/
/*			clnp_snet_init					*/
/*			clnp_snet_term					*/
/*			clnp_snet_read					*/
/*			clnp_snet_write					*/
/*			clnp_snet_free					*/
/*			clnp_snet_add_multicast_mac			*/
/*			clnp_snet_ext_write				*/
/*			clnp_snet_timer_tick 				*/
/*			clnp_snet_update_is				*/
/*			clnp_snet_update_es				*/
/*			clnp_snet_lookup_mac				*/
/*			clnp_snet_get_all_is_mac			*/
/*			clnp_snet_get_all_es_mac			*/
/*			clnp_snet_get_local_mac				*/
/*			clnp_snet_get_max_udata_len			*/
/*			clnp_snet_get_type				*/
/*			clnp_snet_create_es_table			*/
/*			clnp_snet_check_mac				*/
/*									*/
/* MODIFICATION LOG :							*/
/*  Date     Who   Rev			Comments			*/
/* --------  ---  ------   -------------------------------------------	*/
/* 11/20/02  ASK    11     Added ETYPE_UNITDATA struct, clnp_etype_write*/
/*			   proto					*/
/* 10/24/02  NAV    10     Add clnp_snet_rx_multicast_stop proto.       */
/* 11/15/01  JRB    09     Add more "multicast" functions.		*/
/*			   Add clnpl_log_snsdu proto.			*/
/* 02/21/00  JRB    08     Del "free_lpdu" flag from SN_UNITDATA, and	*/
/*			   use portable "clnp_snet_free" instead.	*/
/* 01/28/99  MDE    07     Added size to ETHE_ALL_ES, ETHE_ALL_IS	*/
/* 11/30/98  JRB    06     Added Ethernet defines.			*/
/*			   Added clnp_snet_add_multicast_mac prototype.	*/
/*			   Added clnp_snet_check_mac prototype.		*/
/* 09/23/97  EJV    05     Added clnp_snet_ext_write for UCA_SMP.	*/
/*			   Aligned fields in SN_UNITDATA struct.	*/
/* 06/19/97  EJV    04     Added clnp_snet_create_es_table prototype.	*/
/* 05/27/97  JRB   7.00    MMSEASE 7.0 release.				*/
/* 10/17/96  EJV    03     Added define SUBNET_PROFI.			*/
/* 07/22/96  EJV    02     Added func clnp_snet_get_type () and defines	*/
/*			   for implemented sub-networks SUBNET_ADLC and	*/
/*			   SUBNET_ETHE.					*/
/* 05/23/96  EJV    01     Created					*/
/************************************************************************/

#ifndef CLNP_SNE_INCLUDED
#define CLNP_SNE_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

/* implemented sub-networks types */
#define SUBNET_ADLC	1
#define SUBNET_ETHE	2
#define SUBNET_PROFI	3

/*----------------------------------------------------------------------*/
/* Structure below is used to pass SN_UNITDATA to/from read/write	*/
/* functions between the CLNP and CLNP-Subnetwork interface.		*/

typedef struct
  {
  ST_UCHAR   loc_mac [CLNP_MAX_LEN_MAC]; /* Buffer for local MAC addr	*/
  ST_UCHAR   rem_mac [CLNP_MAX_LEN_MAC]; /* Buffer for remote MAC addr	*/
  ST_UINT16  lpdu_len;		/* Length of LPDU.			*/
  ST_UCHAR  *lpdu;		/* Pointer to LPDU buffer to send.	*/
  }SN_UNITDATA;

#define SN_UNITDATA_LEN	sizeof (SN_UNITDATA)

/*----------------------------------------------------------------------*/
/* Defines for type of MAC address in received PDU.			*/
/* Returned by "clnp_snet_check_mac".					*/
/*----------------------------------------------------------------------*/
#define CLNP_MAC_INVALID	0	/* Invalid MAC address (not one	*/
					/* of addresses def below)	*/
#define CLNP_MAC_LOCAL		1	/* Our MAC address		*/
#define CLNP_MAC_ALL_ES		2	/* All-ES (End Systems)	address	*/
#define CLNP_MAC_ALL_IS		3	/* All-IS (Intermediate Systems)*/
#define CLNP_MAC_GOOSE		4	/* Possible GOOSE address	*/

/*----------------------------------------------------------------------*/
/* Defines and externs for Ethernet Subnetwork (SUBNET_ETHE) only.	*/
/*----------------------------------------------------------------------*/
#define ETHE_MAC_LEN		6

#define ETHE_LEN_HEAD		(2*ETHE_MAC_LEN + 2)
#define ETHE_MIN_LEN_LSDU	60
#define ETHE_MAX_LEN_LSDU	1514
#define ETHE_MAX_LEN_UDATA	(ETHE_MAX_LEN_LSDU - ETHE_LEN_HEAD)


/*----------------------------------------------------------------------*/
/* Structure below is used to pass ETYPE_UNITDATA (an Ethertype frame)  */
/* from read function between the CLNP and CLNP-Subnetwork interface.	*/
/*----------------------------------------------------------------------*/

typedef struct
  {
  ST_UCHAR   tci[2];			 /* VLAN priority tag		*/
  
  ST_UCHAR   etherID[2];		 /* Ethertype ID		*/
  ST_UCHAR   appID[2];			 /* Ethertype APPID		*/
  ST_UCHAR   etherLength[2];		 /* Ethertype length		*/
  ST_UCHAR   reserved1[2];		 /* Ethertype reserved byte 	*/
  ST_UCHAR   reserved2[2];		 /* Ethertype reserved byte 	*/
  
  /* APDU Buffer */
  ST_UCHAR   apdu[ETHE_MAX_LEN_UDATA - 14];
  } ETYPE_UNITDATA;

#define ETYPE_UNITDATA_LEN	sizeof (ETYPE_UNITDATA)

/* Ethernet frame structure */
typedef struct
  {
  ST_UCHAR dst_addr [ETHE_MAC_LEN];	/* destination MAC address	*/
  ST_UCHAR src_addr [ETHE_MAC_LEN];	/* source MAC address		*/
  ST_UCHAR frame_len[2];			/* total frame length		*/
  ST_UCHAR data_buf [ETHE_MAX_LEN_UDATA];	/* data buffer			*/
  } ETHE_FRAME;

#define ETHE_FRAME_LEN	sizeof (ETHE_FRAME)

/* All ES and all IS addresses */
extern ST_UCHAR ETHE_ALL_ES [ETHE_MAC_LEN];
extern ST_UCHAR ETHE_ALL_IS [ETHE_MAC_LEN];
  
/*----------------------------------------------------------------------*/
/* Interface functions to underlying sub-network			*/
/*----------------------------------------------------------------------*/

ST_RET clnp_snet_init (CLNP_PARAM *clnp_param);
ST_RET clnp_snet_term (ST_VOID);
ST_RET clnp_snet_read  (SN_UNITDATA *sn_req);
ST_RET clnp_snet_write (SN_UNITDATA *sn_req);
ST_RET clnp_etype_write (SN_UNITDATA *sn_req);
ST_VOID clnp_snet_free (SN_UNITDATA *sn_req);
ST_VOID	clnpl_log_snsdu (SN_UNITDATA *sn_req, ST_ULONG log_mask);
ST_RET clnp_snet_add_multicast_mac (ST_UCHAR *mac_buf);
ST_RET clnp_snet_set_multicast_filter (ST_UCHAR *mac_list, ST_INT num_macs);
ST_RET clnp_snet_rx_all_multicast_start (ST_VOID);
ST_RET clnp_snet_rx_all_multicast_stop (ST_VOID);
ST_RET clnp_snet_rx_multicast_stop (ST_VOID);

ST_RET clnp_snet_ext_write (SN_UNITDATA *sn_req, ST_LONG user_id);
ST_VOID    clnp_snet_timer_tick (ST_VOID);

ST_RET clnp_snet_update_is (ST_UCHAR *rem_nsap, ST_UCHAR *rem_mac, ST_UINT16 holding_time);
ST_RET clnp_snet_update_es (ST_UCHAR *rem_nsap, ST_UCHAR *rem_mac, ST_UINT16 holding_time);

ST_RET clnp_snet_lookup_is (ST_UCHAR *rem_mac);
ST_RET clnp_snet_lookup_es (ST_UCHAR *rem_nsap, ST_UCHAR *rem_mac);

ST_RET clnp_snet_get_all_is_mac (ST_UCHAR *mac_buf);
ST_RET clnp_snet_get_all_es_mac (ST_UCHAR *mac_buf);
ST_RET clnp_snet_get_local_mac  (ST_UCHAR *mac_buf);
ST_UINT16  clnp_snet_get_max_udata_len (ST_VOID);
ST_INT clnp_snet_get_type (ST_VOID);

ST_RET clnp_snet_create_es_table (ST_UINT max_count);
ST_INT clnp_snet_check_mac (ST_UCHAR *mac_addr);

#ifdef __cplusplus
}
#endif

#endif  /* end of 'already included' 	*/







