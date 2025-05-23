/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MMS"
 * 	found in "../mms-860.asn"
 * 	`asn1c -fcompound-names -no-gen-BER -no-gen-OER -no-gen-UPER -no-gen-example -gen-autotools`
 */

#ifndef	_GetGoCBValuesResponsePDU_H_
#define	_GetGoCBValuesResponsePDU_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BOOLEAN.h>
#include <asn_SEQUENCE_OF.h>
#include "ServiceError.h"
#include "GoCB.h"
#include <constr_CHOICE.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum GetGoCBValuesResponsePDU__gocb__Member_PR {
	GetGoCBValuesResponsePDU__gocb__Member_PR_NOTHING,	/* No components present */
	GetGoCBValuesResponsePDU__gocb__Member_PR_error,
	GetGoCBValuesResponsePDU__gocb__Member_PR_value
} GetGoCBValuesResponsePDU__gocb__Member_PR;

/* Forward definitions */
typedef struct GetGoCBValuesResponsePDU__gocb__Member {
	GetGoCBValuesResponsePDU__gocb__Member_PR present;
	union GetGoCBValuesResponsePDU__gocb__Member_u {
		ServiceError_t	 error;
		GoCB_t	 value;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GetGoCBValuesResponsePDU__gocb__Member;

/* GetGoCBValuesResponsePDU */
typedef struct GetGoCBValuesResponsePDU {
	struct GetGoCBValuesResponsePDU__gocb {
		A_SEQUENCE_OF(GetGoCBValuesResponsePDU__gocb__Member) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} gocb;
	BOOLEAN_t	*moreFollows;	/* DEFAULT TRUE */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GetGoCBValuesResponsePDU_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GetGoCBValuesResponsePDU;

#ifdef __cplusplus
}
#endif

#endif	/* _GetGoCBValuesResponsePDU_H_ */
#include <asn_internal.h>
