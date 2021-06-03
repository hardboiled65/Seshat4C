/*
//  props.h
//
//  Author:     Yujeonja
//  Created:    2021. 01. 06. 16:02
//  Copyright (c) 2021 Yujeonja. All rights reserved.
//
//  Unicode properties.
*/
#ifndef _SESHAT_UNICODE_PROPS_H
#define _SESHAT_UNICODE_PROPS_H

typedef struct sh_property_name {
    void *names;
} sh_property_name;

typedef enum sh_gc {
    // C - Other
    SH_GC_CC,
    SH_GC_CF,
    SH_GC_CN,
    SH_GC_CO,
    SH_GC_CS,
    // L - Letter
    // LC - Cased_Letter (Ll | Lt | Lu)
    SH_GC_LL,
    SH_GC_LM,
    SH_GC_LO,
    SH_GC_LT,
    SH_GC_LU,
    // M - Mark
    SH_GC_MC,
    SH_GC_ME,
    SH_GC_MN,
    // N - Number
    SH_GC_ND,
    SH_GC_NL,
    SH_GC_NO,
    // P - Punctuation
    SH_GC_PC,
    SH_GC_PD,
    SH_GC_PE,
    SH_GC_PF,
    SH_GC_PI,
    SH_GC_PO,
    SH_GC_PS,
    // S - Symbol
    SH_GC_SC,
    SH_GC_SK,
    SH_GC_SM,
    SH_GC_SO,
    // Z - Separator
    SH_GC_ZL,
    SH_GC_ZP,
    SH_GC_ZS,
} sh_gc;

typedef enum sh_hst {
    SH_HST_L,      //Leading_Jamo
    SH_HST_LV,     //LV_Syllable
    SH_HST_LVT,    //LVT_Syllable
    SH_HST_NA,     //Not_Applicable
    SH_HST_T,      //Trailing_Jamo
    SH_HST_V,      //Vowel_Jamo
} sh_hst;

#endif /* _SESHAT_UNICODE_PROPS_H */
