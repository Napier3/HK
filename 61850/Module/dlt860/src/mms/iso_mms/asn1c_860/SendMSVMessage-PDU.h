/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MMS"
 * 	found in "../mms-860.asn"
 * 	`asn1c -fcompound-names -no-gen-BER -no-gen-OER -no-gen-UPER -no-gen-example -gen-autotools`
 */

#ifndef	_SendMSVMessage_PDU_H_
#define	_SendMSVMessage_PDU_H_


#include <asn_application.h>

/* Including external dependencies */
#include "VisibleString129.h"
#include "ObjectReference.h"
#include "INT16U.h"
#include "INT32U.h"
#include "TimeStamp.h"
#include "INT8U.h"
#include <BOOLEAN.h>
#include "SmpMod.h"
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct Data;

/* SendMSVMessage-PDU */
typedef struct SendMSVMessage_PDU {
	VisibleString129_t	 msvID;
	ObjectReference_t	*datSet;	/* OPTIONAL */
	INT16U_t	 smpCnt;
	INT32U_t	 confRev;
	TimeStamp_t	*refrTm;	/* OPTIONAL */
	INT8U_t	 smpSynch;
	INT16U_t	*smpRate;	/* OPTIONAL */
	BOOLEAN_t	 simulation;
	struct SendMSVMessage_PDU__sample {
		A_SEQUENCE_OF(struct Data) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} sample;
	SmpMod_t	*smpMod;	/* OPTIONAL */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SendMSVMessage_PDU_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SendMSVMessage_PDU;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "Data.h"

#endif	/* _SendMSVMessage_PDU_H_ */
#include <asn_internal.h>
