/*
//  ucd.h
//
//  Author:     Yujeonja
//  Created:    2021. 01. 11. 11:17
//  Copyright (c) 2021 Yujeonja. All rights reserved.
//
//  Unicode Character Database functions.
*/
#ifndef _SESHAT_UNICODE_UCD_H
#define _SESHAT_UNICODE_UCD_H

#include <stdbool.h>

#include "../char.h"
#include "../string.h"
#include "props.h"

sh_string* sh_property_name_full(sh_property_name property_name);

sh_string* sh_property_name_abbr(sh_property_name property_name);

sh_gc sh_char_gc(sh_char ch);

sh_hst sh_char_hst(sh_char ch);

sh_string* sh_char_na(sh_char ch);

void sh_gc_debug(sh_gc gc);

/*===================*/
/* Binary properties */
/*===================*/
bool sh_char_ahex(sh_char ch);

bool sh_char_alpha(sh_char ch);

bool sh_char_bidi_c(sh_char ch);

// bool sh_char_bidi_m(sh_char ch);

bool sh_char_cased(sh_char ch);

bool sh_char_ce(sh_char ch);

bool sh_char_ci(sh_char ch);

#endif /* _SESHAT_UNICODE_UCD_H */
