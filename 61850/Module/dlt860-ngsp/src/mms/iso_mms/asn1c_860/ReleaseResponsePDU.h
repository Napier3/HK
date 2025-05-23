/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MMS"
 * 	found in "../mms-860.asn"
 * 	`asn1c -fcompound-names -no-gen-BER -no-gen-OER -no-gen-UPER -no-gen-example -gen-autotools`
 */

#ifndef	_ReleaseResponsePDU_H_
#define	_ReleaseResponsePDU_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>
#include "ServiceError.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ReleaseResponsePDU */
typedef struct ReleaseResponsePDU {
	OCTET_STRING_t	 associationId;
	ServiceError_t	 serviceError;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ReleaseResponsePDU_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ReleaseResponsePDU;

#ifdef __cplusplus
}
#endif

#endif	/* _ReleaseResponsePDU_H_ */
#include <asn_internal.h>
