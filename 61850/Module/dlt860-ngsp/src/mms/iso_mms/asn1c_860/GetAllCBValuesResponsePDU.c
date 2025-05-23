/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MMS"
 * 	found in "../mms-860.asn"
 * 	`asn1c -fcompound-names -no-gen-BER -no-gen-OER -no-gen-UPER -no-gen-example -gen-autotools`
 */

#include "GetAllCBValuesResponsePDU.h"

#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
static asn_per_constraints_t asn_PER_type_value_constr_5 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 3,  3,  0,  5 }	/* (0..5) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
static asn_TYPE_member_t asn_MBR_value_5[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct GetAllCBValuesResponsePDU__cbValue__Member__value, choice.brcb),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BRCB,
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
		"brcb"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct GetAllCBValuesResponsePDU__cbValue__Member__value, choice.urcb),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_URCB,
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
		"urcb"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct GetAllCBValuesResponsePDU__cbValue__Member__value, choice.lcb),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_LCB,
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
		"lcb"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct GetAllCBValuesResponsePDU__cbValue__Member__value, choice.sgcb),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SGCB,
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
		"sgcb"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct GetAllCBValuesResponsePDU__cbValue__Member__value, choice.gocb),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_GoCB,
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
		"gocb"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct GetAllCBValuesResponsePDU__cbValue__Member__value, choice.msvcb),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_MSVCB,
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
		"msvcb"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_value_tag2el_5[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* brcb */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* urcb */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* lcb */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* sgcb */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* gocb */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 } /* msvcb */
};
static asn_CHOICE_specifics_t asn_SPC_value_specs_5 = {
	sizeof(struct GetAllCBValuesResponsePDU__cbValue__Member__value),
	offsetof(struct GetAllCBValuesResponsePDU__cbValue__Member__value, _asn_ctx),
	offsetof(struct GetAllCBValuesResponsePDU__cbValue__Member__value, present),
	sizeof(((struct GetAllCBValuesResponsePDU__cbValue__Member__value *)0)->present),
	asn_MAP_value_tag2el_5,
	6,	/* Count of tags in the map */
	0, 0,
	-1	/* Extensions start */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_value_5 = {
	"value",
	"value",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		&asn_PER_type_value_constr_5,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		CHOICE_constraint
	},
	asn_MBR_value_5,
	6,	/* Elements count */
	&asn_SPC_value_specs_5	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_Member_3[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct GetAllCBValuesResponsePDU__cbValue__Member, reference),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SubReference,
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
	{ ATF_NOFLAGS, 0, offsetof(struct GetAllCBValuesResponsePDU__cbValue__Member, value),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_value_5,
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
		"value"
		},
};
static const ber_tlv_tag_t asn_DEF_Member_tags_3[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_Member_tag2el_3[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* reference */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* value */
};
static asn_SEQUENCE_specifics_t asn_SPC_Member_specs_3 = {
	sizeof(struct GetAllCBValuesResponsePDU__cbValue__Member),
	offsetof(struct GetAllCBValuesResponsePDU__cbValue__Member, _asn_ctx),
	asn_MAP_Member_tag2el_3,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
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

static asn_TYPE_member_t asn_MBR_cbValue_2[] = {
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
static const ber_tlv_tag_t asn_DEF_cbValue_tags_2[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_cbValue_specs_2 = {
	sizeof(struct GetAllCBValuesResponsePDU__cbValue),
	offsetof(struct GetAllCBValuesResponsePDU__cbValue, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_cbValue_2 = {
	"cbValue",
	"cbValue",
	&asn_OP_SEQUENCE_OF,
	asn_DEF_cbValue_tags_2,
	sizeof(asn_DEF_cbValue_tags_2)
		/sizeof(asn_DEF_cbValue_tags_2[0]) - 1, /* 1 */
	asn_DEF_cbValue_tags_2,	/* Same as above */
	sizeof(asn_DEF_cbValue_tags_2)
		/sizeof(asn_DEF_cbValue_tags_2[0]), /* 2 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_OF_constraint
	},
	asn_MBR_cbValue_2,
	1,	/* Single element */
	&asn_SPC_cbValue_specs_2	/* Additional specs */
};

static int asn_DFL_12_cmp_1(const void *sptr) {
	const BOOLEAN_t *st = sptr;
	
	if(!st) {
		return -1; /* No value is not a default value */
	}
	
	/* Test default value 1 */
	return (*st != 1);
}
static int asn_DFL_12_set_1(void **sptr) {
	BOOLEAN_t *st = *sptr;
	
	if(!st) {
		st = (*sptr = CALLOC(1, sizeof(*st)));
		if(!st) return -1;
	}
	
	/* Install default value 1 */
	*st = 1;
	return 0;
}
static asn_TYPE_member_t asn_MBR_GetAllCBValuesResponsePDU_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct GetAllCBValuesResponsePDU, cbValue),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		0,
		&asn_DEF_cbValue_2,
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
		"cbValue"
		},
	{ ATF_POINTER, 1, offsetof(struct GetAllCBValuesResponsePDU, moreFollows),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BOOLEAN,
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
		&asn_DFL_12_cmp_1,	/* Compare DEFAULT 1 */
		&asn_DFL_12_set_1,	/* Set DEFAULT 1 */
		"moreFollows"
		},
};
static const int asn_MAP_GetAllCBValuesResponsePDU_oms_1[] = { 1 };
static const ber_tlv_tag_t asn_DEF_GetAllCBValuesResponsePDU_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_GetAllCBValuesResponsePDU_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* cbValue */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* moreFollows */
};
static asn_SEQUENCE_specifics_t asn_SPC_GetAllCBValuesResponsePDU_specs_1 = {
	sizeof(struct GetAllCBValuesResponsePDU),
	offsetof(struct GetAllCBValuesResponsePDU, _asn_ctx),
	asn_MAP_GetAllCBValuesResponsePDU_tag2el_1,
	2,	/* Count of tags in the map */
	asn_MAP_GetAllCBValuesResponsePDU_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_GetAllCBValuesResponsePDU = {
	"GetAllCBValuesResponsePDU",
	"GetAllCBValuesResponsePDU",
	&asn_OP_SEQUENCE,
	asn_DEF_GetAllCBValuesResponsePDU_tags_1,
	sizeof(asn_DEF_GetAllCBValuesResponsePDU_tags_1)
		/sizeof(asn_DEF_GetAllCBValuesResponsePDU_tags_1[0]), /* 1 */
	asn_DEF_GetAllCBValuesResponsePDU_tags_1,	/* Same as above */
	sizeof(asn_DEF_GetAllCBValuesResponsePDU_tags_1)
		/sizeof(asn_DEF_GetAllCBValuesResponsePDU_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_GetAllCBValuesResponsePDU_1,
	2,	/* Elements count */
	&asn_SPC_GetAllCBValuesResponsePDU_specs_1	/* Additional specs */
};

