/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MMS"
 * 	found in "../mms-860.asn"
 * 	`asn1c -fcompound-names -no-gen-BER -no-gen-OER -no-gen-UPER -no-gen-example -gen-autotools`
 */

#ifndef	_GetLogicalDeviceDirectoryResponsePDU_H_
#define	_GetLogicalDeviceDirectoryResponsePDU_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BOOLEAN.h>
#include "SubReference.h"
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* GetLogicalDeviceDirectoryResponsePDU */
typedef struct GetLogicalDeviceDirectoryResponsePDU {
	struct GetLogicalDeviceDirectoryResponsePDU__lnReference {
		A_SEQUENCE_OF(SubReference_t) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} lnReference;
	BOOLEAN_t	*moreFollows;	/* DEFAULT TRUE */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} GetLogicalDeviceDirectoryResponsePDU_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_GetLogicalDeviceDirectoryResponsePDU;

#ifdef __cplusplus
}
#endif

#endif	/* _GetLogicalDeviceDirectoryResponsePDU_H_ */
#include <asn_internal.h>
