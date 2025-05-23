/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MMS"
 * 	found in "../mms-860.asn"
 * 	`asn1c -fcompound-names -no-gen-BER -no-gen-OER -no-gen-UPER -no-gen-example -gen-autotools`
 */

#ifndef	_SmpMod_H_
#define	_SmpMod_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum SmpMod {
	SmpMod_samples_per_nominal_period	= 0,
	SmpMod_samples_per_second	= 1,
	SmpMod_seconds_per_sample	= 2
} e_SmpMod;

/* SmpMod */
typedef long	 SmpMod_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_SmpMod_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_SmpMod;
asn_struct_free_f SmpMod_free;
asn_struct_print_f SmpMod_print;
asn_constr_check_f SmpMod_constraint;
xer_type_decoder_f SmpMod_decode_xer;
xer_type_encoder_f SmpMod_encode_xer;
per_type_decoder_f SmpMod_decode_aper;
per_type_encoder_f SmpMod_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _SmpMod_H_ */
#include <asn_internal.h>
