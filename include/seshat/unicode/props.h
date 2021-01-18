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

typedef enum SH_Gc {
    // C - Other
    SH_Gc_Cc,
    SH_Gc_Cf,
    SH_Gc_Cn,
    SH_Gc_Co,
    SH_Gc_Cs,
    // L - Letter
    // LC - Cased_Letter (Ll | Lt | Lu)
    SH_Gc_Ll,
    SH_Gc_Lm,
    SH_Gc_Lo,
    SH_Gc_Lt,
    SH_Gc_Lu,
    // M - Mark
    SH_Gc_Mc,
    SH_Gc_Me,
    SH_Gc_Mn,
    // N - Number
    SH_Gc_Nd,
    SH_Gc_Nl,
    SH_Gc_No,
    // P - Punctuation
    SH_Gc_Pc,
    SH_Gc_Pd,
    SH_Gc_Pe,
    SH_Gc_Pf,
    SH_Gc_Pi,
    SH_Gc_Po,
    SH_Gc_Ps,
    // S - Symbol
    SH_Gc_Sc,
    SH_Gc_Sk,
    SH_Gc_Sm,
    SH_Gc_So,
    // Z - Separator
    SH_Gc_Zl,
    SH_Gc_Zp,
    SH_Gc_Zs,
} SH_Gc;

typedef enum SH_Hst {
    SH_Hst_L,      //Leading_Jamo
    SH_Hst_LV,     //LV_Syllable
    SH_Hst_LVT,    //LVT_Syllable
    SH_Hst_NA,     //Not_Applicable
    SH_Hst_T,      //Trailing_Jamo
    SH_Hst_V,      //Vowel_Jamo
} SH_Hst;

#endif /* _SESHAT_UNICODE_PROPS_H */
