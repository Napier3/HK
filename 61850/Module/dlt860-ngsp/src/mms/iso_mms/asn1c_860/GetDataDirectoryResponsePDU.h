/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MMS"
 * 	found in "../mms-860.asn"
 * 	`asn1c -fcompound-names -no-gen-BER -no-gen-OER -no-gen-UPER -no-gen-example -gen-autotools`
 */

#ifndef	_GetDataDirectoryResponsePDU_H_
#define	_GetDataDirectoryResponsePDU_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BOOLEAN.h>
#include <asn_SEQUENCE_OF.h>
#include "SubReference.h"
#include "FunctionalConstraint.h"
#include <constr_SEQUENCE.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward definitions */
typedef struct GetDataDirectoryResponsePDU__dataAttribute__Member {
	SubReference_t	 reference;
	FunctionalConstraint_t	*fc;	/* OPTIONAL */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GetDataDirectoryResponsePDU__dataAttribute__Member;

/* GetDataDirectoryResponsePDU */
typedef struct GetDataDirectoryResponsePDU {
	struct GetDataDirectoryResponsePDU__dataAttribute {
		A_SEQUENCE_OF(GetDataDirectoryResponsePDU__dataAttribute__Member) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} dataAttribute;
	BOOLEAN_t	*moreFollows;	/* DEFAULT TRUE */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GetDataDirectoryResponsePDU_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GetDataDirectoryResponsePDU;

#ifdef __cplusplus
}
#endif

#endif	/* _GetDataDirectoryResponsePDU_H_ */
#include <asn_internal.h>
