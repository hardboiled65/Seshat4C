/*
//  props.h
//
//  Author:     Yujeonja
//  Created:    2021. 01. 06. 16:02
//  Copyright (c) 2021 Yujeonja. All rights reserved.
//
//  Unicode properties.
*/
#ifndef _SESHAT_PROPS_H
#define _SESHAT_PROPS_H

typedef struct sh_property_name {
    void *names;
} sh_property_name;

enum Gc {
    // C - Other
    Cc,
    Cf,
    Cn,
    Co,
    Cs,
    // L - Letter
    // LC - Cased_Letter (Ll | Lt | Lu)
    Ll,
    Lm,
    Lo,
    Lt,
    Lu,
    // M - Mark
    Mc,
    Me,
    Mn,
    // N - Number
    Nd,
    Nl,
    No,
    // P - Punctuation
    Pc,
    Pd,
    Pe,
    Pf,
    Pi,
    Po,
    Ps,
    // S - Symbol
    Sc,
    Sk,
    Sm,
    So,
    // Z - Separator
    Zl,
    Zp,
    Zs,
};

#endif /* _SESHAT_PROPS_H */
