/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MMS"
 * 	found in "../mms-860.asn"
 * 	`asn1c -fcompound-names -no-gen-BER -no-gen-OER -no-gen-UPER -no-gen-example -gen-autotools`
 */

#ifndef	_ConfirmEditSGValuesErrorPDU_H_
#define	_ConfirmEditSGValuesErrorPDU_H_


#include <asn_application.h>

/* Including external dependencies */
#include "ServiceError.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ConfirmEditSGValuesErrorPDU */
typedef ServiceError_t	 ConfirmEditSGValuesErrorPDU_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ConfirmEditSGValuesErrorPDU;
asn_struct_free_f ConfirmEditSGValuesErrorPDU_free;
asn_struct_print_f ConfirmEditSGValuesErrorPDU_print;
asn_constr_check_f ConfirmEditSGValuesErrorPDU_constraint;
xer_type_decoder_f ConfirmEditSGValuesErrorPDU_decode_xer;
xer_type_encoder_f ConfirmEditSGValuesErrorPDU_encode_xer;
per_type_decoder_f ConfirmEditSGValuesErrorPDU_decode_aper;
per_type_encoder_f ConfirmEditSGValuesErrorPDU_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _ConfirmEditSGValuesErrorPDU_H_ */
#include <asn_internal.h>
