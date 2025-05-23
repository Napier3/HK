/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "MMS"
 * 	found in "../mms-860.asn"
 * 	`asn1c -fcompound-names -no-gen-BER -no-gen-OER -no-gen-UPER -no-gen-example -gen-autotools`
 */

#include "AssociateRequestPDU.h"

static asn_TYPE_member_t asn_MBR_authenticationParameter_3[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct AssociateRequestPDU__authenticationParameter, signatureCertificate),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OCTET_STRING,
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
		"signatureCertificate"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct AssociateRequestPDU__authenticationParameter, signedTime),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_UtcTime,
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
		"signedTime"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct AssociateRequestPDU__authenticationParameter, signedValue),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_OCTET_STRING,
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
		"signedValue"
		},
};
static const ber_tlv_tag_t asn_DEF_authenticationParameter_tags_3[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_authenticationParameter_tag2el_3[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* signatureCertificate */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* signedTime */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* signedValue */
};
static asn_SEQUENCE_specifics_t asn_SPC_authenticationParameter_specs_3 = {
	sizeof(struct AssociateRequestPDU__authenticationParameter),
	offsetof(struct AssociateRequestPDU__authenticationParameter, _asn_ctx),
	asn_MAP_authenticationParameter_tag2el_3,
	3,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_authenticationParameter_3 = {
	"authenticationParameter",
	"authenticationParameter",
	&asn_OP_SEQUENCE,
	asn_DEF_authenticationParameter_tags_3,
	sizeof(asn_DEF_authenticationParameter_tags_3)
		/sizeof(asn_DEF_authenticationParameter_tags_3[0]) - 1, /* 1 */
	asn_DEF_authenticationParameter_tags_3,	/* Same as above */
	sizeof(asn_DEF_authenticationParameter_tags_3)
		/sizeof(asn_DEF_authenticationParameter_tags_3[0]), /* 2 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_authenticationParameter_3,
	3,	/* Elements count */
	&asn_SPC_authenticationParameter_specs_3	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_AssociateRequestPDU_1[] = {
	{ ATF_POINTER, 2, offsetof(struct AssociateRequestPDU, serverAccessPointReference),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_VisibleString129,
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
		"serverAccessPointReference"
		},
	{ ATF_POINTER, 1, offsetof(struct AssociateRequestPDU, authenticationParameter),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		0,
		&asn_DEF_authenticationParameter_3,
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
		"authenticationParameter"
		},
};
static const int asn_MAP_AssociateRequestPDU_oms_1[] = { 0, 1 };
static const ber_tlv_tag_t asn_DEF_AssociateRequestPDU_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_AssociateRequestPDU_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* serverAccessPointReference */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* authenticationParameter */
};
static asn_SEQUENCE_specifics_t asn_SPC_AssociateRequestPDU_specs_1 = {
	sizeof(struct AssociateRequestPDU),
	offsetof(struct AssociateRequestPDU, _asn_ctx),
	asn_MAP_AssociateRequestPDU_tag2el_1,
	2,	/* Count of tags in the map */
	asn_MAP_AssociateRequestPDU_oms_1,	/* Optional members */
	2, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_AssociateRequestPDU = {
	"AssociateRequestPDU",
	"AssociateRequestPDU",
	&asn_OP_SEQUENCE,
	asn_DEF_AssociateRequestPDU_tags_1,
	sizeof(asn_DEF_AssociateRequestPDU_tags_1)
		/sizeof(asn_DEF_AssociateRequestPDU_tags_1[0]), /* 1 */
	asn_DEF_AssociateRequestPDU_tags_1,	/* Same as above */
	sizeof(asn_DEF_AssociateRequestPDU_tags_1)
		/sizeof(asn_DEF_AssociateRequestPDU_tags_1[0]), /* 1 */
	{
#if !defined(ASN_DISABLE_OER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_OER_SUPPORT) */
#if !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT)
		0,
#endif  /* !defined(ASN_DISABLE_UPER_SUPPORT) || !defined(ASN_DISABLE_APER_SUPPORT) */
		SEQUENCE_constraint
	},
	asn_MBR_AssociateRequestPDU_1,
	2,	/* Elements count */
	&asn_SPC_AssociateRequestPDU_specs_1	/* Additional specs */
};

