/*
//  string.h
//
//  Author:     Yujeonja
//  Created:    2021. 01. 11. 11:31
//  Copyright (c) 2021 Yujeonja. All rights reserved.
//
//  Seshat string struct and functions.
*/
#ifndef _SESHAT_STRING_H
#define _SESHAT_STRING_H

#include <stdbool.h>
#include <stddef.h>

#include "char.h"

typedef struct sh_string {
    void *content;
} sh_string;

sh_string* sh_string_new(const char*);

void sh_string_insert(sh_string *string, size_t idx, sh_char ch);

size_t sh_string_len(sh_string *string);

void sh_string_free(sh_string *string);

bool sh_string_eq(sh_string *string, sh_string *other);

void sh_string_print(const sh_string *string);

const char* sh_string_c_str(const sh_string *string);

#endif /* _SESHAT_STRING_H */
