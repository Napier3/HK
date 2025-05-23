/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MMS"
 * 	found in "../mms-860.asn"
 * 	`asn1c -fcompound-names -no-gen-BER -no-gen-OER -no-gen-UPER -no-gen-example -gen-autotools`
 */

#ifndef	_GetGoReferenceRequestPDU_H_
#define	_GetGoReferenceRequestPDU_H_


#include <asn_application.h>

/* Including external dependencies */
#include "ObjectReference.h"
#include "INT16U.h"
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* GetGoReferenceRequestPDU */
typedef struct GetGoReferenceRequestPDU {
	ObjectReference_t	 gocbReference;
	struct GetGoReferenceRequestPDU__memberOffset {
		A_SEQUENCE_OF(INT16U_t) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} memberOffset;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GetGoReferenceRequestPDU_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GetGoReferenceRequestPDU;

#ifdef __cplusplus
}
#endif

#endif	/* _GetGoReferenceRequestPDU_H_ */
#include <asn_internal.h>
