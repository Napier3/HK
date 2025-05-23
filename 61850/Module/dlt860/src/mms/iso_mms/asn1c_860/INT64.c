/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MMS"
 * 	found in "../mms-860.asn"
 * 	`asn1c -fcompound-names -no-gen-BER -no-gen-OER -no-gen-UPER -no-gen-example -gen-autotools`
 */

#include "INT64.h"

/*
 * This type is implemented using NativeInteger,
 * so here we adjust the DEF accordingly.
 */
static const ber_tlv_tag_t asn_DEF_INT64_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (2 << 2))
};
asn_TYPE_descriptor_t asn_DEF_INT64 = {
	"INT64",
	"INT64",
	&asn_OP_NativeInteger,
	asn_DEF_INT64_tags_1,
	sizeof(asn_DEF_INT64_tags_1)
		/sizeof(asn_DEF_INT64_tags_1[0]), /* 1 */
	asn_DEF_INT64_tags_1,	/* Same as above */
	sizeof(asn_DEF_INT64_tags_1)
		/sizeof(asn_DEF_INT64_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		NativeInteger_constraint
	},
	0, 0,	/* No members */
	0	/* No specifics */
};

