/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MMS"
 * 	found in "../mms-860.asn"
 * 	`asn1c -fcompound-names -no-gen-BER -no-gen-OER -no-gen-UPER -no-gen-example -gen-autotools`
 */

#ifndef	_GetSGCBValuesResponsePDU_H_
#define	_GetSGCBValuesResponsePDU_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BOOLEAN.h>
#include <asn_SEQUENCE_OF.h>
#include "ServiceError.h"
#include "SGCB.h"
#include <constr_CHOICE.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum GetSGCBValuesResponsePDU__sgcb__Member_PR {
	GetSGCBValuesResponsePDU__sgcb__Member_PR_NOTHING,	/* No components present */
	GetSGCBValuesResponsePDU__sgcb__Member_PR_error,
	GetSGCBValuesResponsePDU__sgcb__Member_PR_value
} GetSGCBValuesResponsePDU__sgcb__Member_PR;

/* Forward definitions */
typedef struct GetSGCBValuesResponsePDU__sgcb__Member {
	GetSGCBValuesResponsePDU__sgcb__Member_PR present;
	union GetSGCBValuesResponsePDU__sgcb__Member_u {
		ServiceError_t	 error;
		SGCB_t	 value;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GetSGCBValuesResponsePDU__sgcb__Member;

/* GetSGCBValuesResponsePDU */
typedef struct GetSGCBValuesResponsePDU {
	struct GetSGCBValuesResponsePDU__sgcb {
		A_SEQUENCE_OF(GetSGCBValuesResponsePDU__sgcb__Member) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} sgcb;
	BOOLEAN_t	*moreFollows;	/* DEFAULT TRUE */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GetSGCBValuesResponsePDU_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GetSGCBValuesResponsePDU;

#ifdef __cplusplus
}
#endif

#endif	/* _GetSGCBValuesResponsePDU_H_ */
#include <asn_internal.h>
