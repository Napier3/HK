/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MMS"
 * 	found in "../mms-860.asn"
 * 	`asn1c -fcompound-names -no-gen-BER -no-gen-OER -no-gen-UPER -no-gen-example -gen-autotools`
 */

#include "SelectEditSGResponsePDU.h"

/*
 * This type is implemented using NULL,
 * so here we adjust the DEF accordingly.
 */
static const ber_tlv_tag_t asn_DEF_SelectEditSGResponsePDU_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (5 << 2))
};
asn_TYPE_descriptor_t asn_DEF_SelectEditSGResponsePDU = {
	"SelectEditSGResponsePDU",
	"SelectEditSGResponsePDU",
	&asn_OP_NULL,
	asn_DEF_SelectEditSGResponsePDU_tags_1,
	sizeof(asn_DEF_SelectEditSGResponsePDU_tags_1)
		/sizeof(asn_DEF_SelectEditSGResponsePDU_tags_1[0]), /* 1 */
	asn_DEF_SelectEditSGResponsePDU_tags_1,	/* Same as above */
	sizeof(asn_DEF_SelectEditSGResponsePDU_tags_1)
		/sizeof(asn_DEF_SelectEditSGResponsePDU_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		NULL_constraint
	},
	0, 0,	/* No members */
	0	/* No specifics */
};

