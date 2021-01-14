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

#include "../char.h"
#include "../string.h"
#include "props.h"

sh_string* sh_property_name_full(sh_property_name property_name);

sh_string* sh_property_name_abbr(sh_property_name property_name);

SH_Gc sh_char_gc(sh_char ch);

sh_property_name sh_gc_property_value_name(SH_Gc gc);

sh_string* sh_char_na(sh_char ch);


void sh_gc_debug(SH_Gc gc);

#endif /* _SESHAT_UNICODE_UCD_H */
