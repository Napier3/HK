/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MMS"
 * 	found in "../mms-860.asn"
 * 	`asn1c -fcompound-names -no-gen-BER -no-gen-OER -no-gen-UPER -no-gen-example -gen-autotools`
 */

#include "GetGoReferenceResponsePDU.h"

static asn_TYPE_member_t asn_MBR_Member_6[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct GetGoReferenceResponsePDU__memberData__Member, reference),
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
	{ ATF_NOFLAGS, 0, offsetof(struct GetGoReferenceResponsePDU__memberData__Member, fc),
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
static const ber_tlv_tag_t asn_DEF_Member_tags_6[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_Member_tag2el_6[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* reference */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* fc */
};
static asn_SEQUENCE_specifics_t asn_SPC_Member_specs_6 = {
	sizeof(struct GetGoReferenceResponsePDU__memberData__Member),
	offsetof(struct GetGoReferenceResponsePDU__memberData__Member, _asn_ctx),
	asn_MAP_Member_tag2el_6,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_Member_6 = {
	"SEQUENCE",
	"SEQUENCE",
	&asn_OP_SEQUENCE,
	asn_DEF_Member_tags_6,
	sizeof(asn_DEF_Member_tags_6)
		/sizeof(asn_DEF_Member_tags_6[0]), /* 1 */
	asn_DEF_Member_tags_6,	/* Same as above */
	sizeof(asn_DEF_Member_tags_6)
		/sizeof(asn_DEF_Member_tags_6[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_Member_6,
	2,	/* Elements count */
	&asn_SPC_Member_specs_6	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_memberData_5[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_Member_6,
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
static const ber_tlv_tag_t asn_DEF_memberData_tags_5[] = {
	(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_memberData_specs_5 = {
	sizeof(struct GetGoReferenceResponsePDU__memberData),
	offsetof(struct GetGoReferenceResponsePDU__memberData, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_memberData_5 = {
	"memberData",
	"memberData",
	&asn_OP_SEQUENCE_OF,
	asn_DEF_memberData_tags_5,
	sizeof(asn_DEF_memberData_tags_5)
		/sizeof(asn_DEF_memberData_tags_5[0]) - 1, /* 1 */
	asn_DEF_memberData_tags_5,	/* Same as above */
	sizeof(asn_DEF_memberData_tags_5)
		/sizeof(asn_DEF_memberData_tags_5[0]), /* 2 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_OF_constraint
	},
	asn_MBR_memberData_5,
	1,	/* Single element */
	&asn_SPC_memberData_specs_5	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_GetGoReferenceResponsePDU_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct GetGoReferenceResponsePDU, gocbReference),
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
		"gocbReference"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct GetGoReferenceResponsePDU, confRev),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_INT32U,
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
		"confRev"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct GetGoReferenceResponsePDU, datSet),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
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
		"datSet"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct GetGoReferenceResponsePDU, memberData),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		0,
		&asn_DEF_memberData_5,
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
		"memberData"
		},
};
static const ber_tlv_tag_t asn_DEF_GetGoReferenceResponsePDU_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_GetGoReferenceResponsePDU_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* gocbReference */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* confRev */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* datSet */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* memberData */
};
static asn_SEQUENCE_specifics_t asn_SPC_GetGoReferenceResponsePDU_specs_1 = {
	sizeof(struct GetGoReferenceResponsePDU),
	offsetof(struct GetGoReferenceResponsePDU, _asn_ctx),
	asn_MAP_GetGoReferenceResponsePDU_tag2el_1,
	4,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_GetGoReferenceResponsePDU = {
	"GetGoReferenceResponsePDU",
	"GetGoReferenceResponsePDU",
	&asn_OP_SEQUENCE,
	asn_DEF_GetGoReferenceResponsePDU_tags_1,
	sizeof(asn_DEF_GetGoReferenceResponsePDU_tags_1)
		/sizeof(asn_DEF_GetGoReferenceResponsePDU_tags_1[0]), /* 1 */
	asn_DEF_GetGoReferenceResponsePDU_tags_1,	/* Same as above */
	sizeof(asn_DEF_GetGoReferenceResponsePDU_tags_1)
		/sizeof(asn_DEF_GetGoReferenceResponsePDU_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_GetGoReferenceResponsePDU_1,
	4,	/* Elements count */
	&asn_SPC_GetGoReferenceResponsePDU_specs_1	/* Additional specs */
};

