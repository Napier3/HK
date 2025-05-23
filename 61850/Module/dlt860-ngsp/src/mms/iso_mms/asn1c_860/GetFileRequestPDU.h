/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MMS"
 * 	found in "../mms-860.asn"
 * 	`asn1c -fcompound-names -no-gen-BER -no-gen-OER -no-gen-UPER -no-gen-example -gen-autotools`
 */

#ifndef	_GetFileRequestPDU_H_
#define	_GetFileRequestPDU_H_


#include <asn_application.h>

/* Including external dependencies */
#include "VisibleString255.h"
#include "INT32U.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* GetFileRequestPDU */
typedef struct GetFileRequestPDU {
	VisibleString255_t	 filename;
	INT32U_t	 startPostion;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GetFileRequestPDU_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GetFileRequestPDU;

#ifdef __cplusplus
}
#endif

#endif	/* _GetFileRequestPDU_H_ */
#include <asn_internal.h>
