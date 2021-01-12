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

Gc sh_char_gc(sh_char ch);

sh_property_name gc_property_name(Gc gc);

#endif /* _SESHAT_UNICODE_UCD_H */
