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
    SH_Cc,
    SH_Cf,
    SH_Cn,
    SH_Co,
    SH_Cs,
    // L - Letter
    // LC - Cased_Letter (Ll | Lt | Lu)
    SH_Ll,
    SH_Lm,
    SH_Lo,
    SH_Lt,
    SH_Lu,
    // M - Mark
    SH_Mc,
    SH_Me,
    SH_Mn,
    // N - Number
    SH_Nd,
    SH_Nl,
    SH_No,
    // P - Punctuation
    SH_Pc,
    SH_Pd,
    SH_Pe,
    SH_Pf,
    SH_Pi,
    SH_Po,
    SH_Ps,
    // S - Symbol
    SH_Sc,
    SH_Sk,
    SH_Sm,
    SH_So,
    // Z - Separator
    SH_Zl,
    SH_Zp,
    SH_Zs,
} SH_Gc;

#endif /* _SESHAT_UNICODE_PROPS_H */
