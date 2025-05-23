/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MMS"
 * 	found in "../mms-860.asn"
 * 	`asn1c -fcompound-names -no-gen-BER -no-gen-OER -no-gen-UPER -no-gen-example -gen-autotools`
 */

#ifndef	_RpcCallResponsePDU_H_
#define	_RpcCallResponsePDU_H_


#include <asn_application.h>

/* Including external dependencies */
#include "Data.h"
#include <OCTET_STRING.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* RpcCallResponsePDU */
typedef struct RpcCallResponsePDU {
	Data_t	 rspData;
	OCTET_STRING_t	*nextCallID;	/* OPTIONAL */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RpcCallResponsePDU_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RpcCallResponsePDU;

#ifdef __cplusplus
}
#endif

#endif	/* _RpcCallResponsePDU_H_ */
#include <asn_internal.h>
