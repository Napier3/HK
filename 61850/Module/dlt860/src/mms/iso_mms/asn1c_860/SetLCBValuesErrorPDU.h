/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MMS"
 * 	found in "../mms-860.asn"
 * 	`asn1c -fcompound-names -no-gen-BER -no-gen-OER -no-gen-UPER -no-gen-example -gen-autotools`
 */

#ifndef	_SetLCBValuesErrorPDU_H_
#define	_SetLCBValuesErrorPDU_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include "ServiceError.h"
#include <constr_SEQUENCE.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward definitions */
typedef struct SetLCBValuesErrorPDU__result__Member {
	ServiceError_t	*logEna;	/* OPTIONAL */
	ServiceError_t	*datSet;	/* OPTIONAL */
	ServiceError_t	*trgOps;	/* OPTIONAL */
	ServiceError_t	*intgPd;	/* OPTIONAL */
	ServiceError_t	*logRef;	/* OPTIONAL */
	ServiceError_t	*optFlds;	/* OPTIONAL */
	ServiceError_t	*bufTm;	/* OPTIONAL */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SetLCBValuesErrorPDU__result__Member;

/* SetLCBValuesErrorPDU */
typedef struct SetLCBValuesErrorPDU {
	struct SetLCBValuesErrorPDU__result {
		A_SEQUENCE_OF(SetLCBValuesErrorPDU__result__Member) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} result;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SetLCBValuesErrorPDU_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SetLCBValuesErrorPDU;

#ifdef __cplusplus
}
#endif

#endif	/* _SetLCBValuesErrorPDU_H_ */
#include <asn_internal.h>
