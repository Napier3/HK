/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MMS"
 * 	found in "../mms-860.asn"
 * 	`asn1c -fcompound-names -no-gen-BER -no-gen-OER -no-gen-UPER -no-gen-example -gen-autotools`
 */

#include "GetDataDefinitionRequestPDU.h"

static asn_TYPE_member_t asn_MBR_Member_3[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct GetDataDefinitionRequestPDU__data__Member, reference),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ObjectReference,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"reference"
		},
	{ ATF_POINTER, 1, offsetof(struct GetDataDefinitionRequestPDU__data__Member, fc),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_FunctionalConstraint,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"fc"
		},
};
static const int asn_MAP_Member_oms_3[] = { 1 };
static const ber_tlv_tag_t asn_DEF_Member_tags_3[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_Member_tag2el_3[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* reference */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* fc */
};
static asn_SEQUENCE_specifics_t asn_SPC_Member_specs_3 = {
	sizeof(struct GetDataDefinitionRequestPDU__data__Member),
	offsetof(struct GetDataDefinitionRequestPDU__data__Member, _asn_ctx),
	asn_MAP_Member_tag2el_3,
	2,	/* Count of tags in the map */
	asn_MAP_Member_oms_3,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_Member_3 = {
	"SEQUENCE",
	"SEQUENCE",
	&asn_OP_SEQUENCE,
	asn_DEF_Member_tags_3,
	sizeof(asn_DEF_Member_tags_3)
		/sizeof(asn_DEF_Member_tags_3[0]), /* 1 */
	asn_DEF_Member_tags_3,	/* Same as above */
	sizeof(asn_DEF_Member_tags_3)
		/sizeof(asn_DEF_Member_tags_3[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_Member_3,
	2,	/* Elements count */
	&asn_SPC_Member_specs_3	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_data_2[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_Member_3,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		""
		},
};
static const ber_tlv_tag_t asn_DEF_data_tags_2[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_data_specs_2 = {
	sizeof(struct GetDataDefinitionRequestPDU__data),
	offsetof(struct GetDataDefinitionRequestPDU__data, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_data_2 = {
	"data",
	"data",
	&asn_OP_SEQUENCE_OF,
	asn_DEF_data_tags_2,
	sizeof(asn_DEF_data_tags_2)
		/sizeof(asn_DEF_data_tags_2[0]) - 1, /* 1 */
	asn_DEF_data_tags_2,	/* Same as above */
	sizeof(asn_DEF_data_tags_2)
		/sizeof(asn_DEF_data_tags_2[0]), /* 2 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_OF_constraint
	},
	asn_MBR_data_2,
	1,	/* Single element */
	&asn_SPC_data_specs_2	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_GetDataDefinitionRequestPDU_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct GetDataDefinitionRequestPDU, data),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		0,
		&asn_DEF_data_2,
		0,
		{
#if !defined(ASN_DISABLE_OER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
			0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
			0
		},
		0, 0, /* No default value */
		"data"
		},
};
static const ber_tlv_tag_t asn_DEF_GetDataDefinitionRequestPDU_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_GetDataDefinitionRequestPDU_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* data */
};
static asn_SEQUENCE_specifics_t asn_SPC_GetDataDefinitionRequestPDU_specs_1 = {
	sizeof(struct GetDataDefinitionRequestPDU),
	offsetof(struct GetDataDefinitionRequestPDU, _asn_ctx),
	asn_MAP_GetDataDefinitionRequestPDU_tag2el_1,
	1,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_GetDataDefinitionRequestPDU = {
	"GetDataDefinitionRequestPDU",
	"GetDataDefinitionRequestPDU",
	&asn_OP_SEQUENCE,
	asn_DEF_GetDataDefinitionRequestPDU_tags_1,
	sizeof(asn_DEF_GetDataDefinitionRequestPDU_tags_1)
		/sizeof(asn_DEF_GetDataDefinitionRequestPDU_tags_1[0]), /* 1 */
	asn_DEF_GetDataDefinitionRequestPDU_tags_1,	/* Same as above */
	sizeof(asn_DEF_GetDataDefinitionRequestPDU_tags_1)
		/sizeof(asn_DEF_GetDataDefinitionRequestPDU_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_GetDataDefinitionRequestPDU_1,
	1,	/* Elements count */
	&asn_SPC_GetDataDefinitionRequestPDU_specs_1	/* Additional specs */
};

