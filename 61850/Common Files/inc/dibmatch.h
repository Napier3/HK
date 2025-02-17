#ifndef DIBMATCH_H

#define DIBMATCH_H

/************************************************************************/
/* SISCO SOFTWARE MODULE HEADER *****************************************/
/************************************************************************/
/*   (c) Copyright Systems Integration Specialists Company, Inc.,	*/
/*			2003, All Rights Reserved			*/
/*									*/
/* MODULE NAME : dibmatch.h						*/
/* PRODUCT(S)  : 							*/
/*									*/
/* MODULE DESCRIPTION : 						*/
/*									*/
/* MODIFICATION LOG :							*/
/*  Date     Who   Rev			Comments			*/
/* --------  ---  ------   -------------------------------------------	*/
/* 06/11/03  MDE     01    New						*/
/************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif
									  
/************************************************************************/
/* General address matching defines, control, functions			*/

/* Compare Results */
#define DIB_MATCH_NOT	0
#define DIB_MATCH_CLOSE	1
#define DIB_MATCH_EXACT	2

typedef struct dib_match_ctrl_tag
  {
  ST_BOOLEAN match_allow_missing_ae_elements;
  ST_BOOLEAN match_allow_extra_ae_elements;
  
  ST_BOOLEAN match_ap_title;
  ST_BOOLEAN match_ae_qualifier;
  ST_BOOLEAN match_ap_invoke;
  ST_BOOLEAN match_ae_invoke;
  ST_BOOLEAN match_psel;
  ST_BOOLEAN match_ssel;
  ST_BOOLEAN match_tsel;
  ST_BOOLEAN match_net_addr;
  } DIB_MATCH_CTRL;


#ifdef __cplusplus
}
#endif
									  
#endif	/* DIBMATCH_H */
