/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MMS"
 * 	found in "../mms-860.asn"
 * 	`asn1c -fcompound-names -no-gen-BER -no-gen-OER -no-gen-UPER -no-gen-example -gen-autotools`
 */

#ifndef	_GetLogStatusValuesRequestPDU_H_
#define	_GetLogStatusValuesRequestPDU_H_


#include <asn_application.h>

/* Including external dependencies */
#include "ObjectReference.h"
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* GetLogStatusValuesRequestPDU */
typedef struct GetLogStatusValuesRequestPDU {
	struct GetLogStatusValuesRequestPDU__logReference {
		A_SEQUENCE_OF(ObjectReference_t) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} logReference;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GetLogStatusValuesRequestPDU_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GetLogStatusValuesRequestPDU;

#ifdef __cplusplus
}
#endif

#endif	/* _GetLogStatusValuesRequestPDU_H_ */
#include <asn_internal.h>
