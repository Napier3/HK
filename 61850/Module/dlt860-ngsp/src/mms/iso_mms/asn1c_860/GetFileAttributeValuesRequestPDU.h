/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MMS"
 * 	found in "../mms-860.asn"
 * 	`asn1c -fcompound-names -no-gen-BER -no-gen-OER -no-gen-UPER -no-gen-example -gen-autotools`
 */

#ifndef	_GetFileAttributeValuesRequestPDU_H_
#define	_GetFileAttributeValuesRequestPDU_H_


#include <asn_application.h>

/* Including external dependencies */
#include "VisibleString255.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* GetFileAttributeValuesRequestPDU */
typedef struct GetFileAttributeValuesRequestPDU {
	VisibleString255_t	 filename;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GetFileAttributeValuesRequestPDU_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GetFileAttributeValuesRequestPDU;

#ifdef __cplusplus
}
#endif

#endif	/* _GetFileAttributeValuesRequestPDU_H_ */
#include <asn_internal.h>
