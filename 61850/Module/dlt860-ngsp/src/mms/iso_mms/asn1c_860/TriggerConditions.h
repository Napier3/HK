/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MMS"
 * 	found in "../mms-860.asn"
 * 	`asn1c -fcompound-names -no-gen-BER -no-gen-OER -no-gen-UPER -no-gen-example -gen-autotools`
 */

#ifndef	_TriggerConditions_H_
#define	_TriggerConditions_H_


#include <asn_application.h>

/* Including external dependencies */
#include <BIT_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum TriggerConditions {
	TriggerConditions_reserved	= 0,
	TriggerConditions_data_change	= 1,
	TriggerConditions_quality_change	= 2,
	TriggerConditions_data_update	= 3,
	TriggerConditions_integrity	= 4,
	TriggerConditions_general_interrogation	= 5
} e_TriggerConditions;

/* TriggerConditions */
typedef BIT_STRING_t	 TriggerConditions_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_TriggerConditions_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_TriggerConditions;
asn_struct_free_f TriggerConditions_free;
asn_struct_print_f TriggerConditions_print;
asn_constr_check_f TriggerConditions_constraint;
xer_type_decoder_f TriggerConditions_decode_xer;
xer_type_encoder_f TriggerConditions_encode_xer;
per_type_decoder_f TriggerConditions_decode_aper;
per_type_encoder_f TriggerConditions_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _TriggerConditions_H_ */
#include <asn_internal.h>
