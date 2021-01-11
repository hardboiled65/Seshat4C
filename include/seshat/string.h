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

#include <stddef.h>

typedef struct sh_string {
    void *content;
} sh_string;

sh_string* sh_string_new(const char*);

size_t sh_string_len(sh_string *string);

void sh_string_free(sh_string *string);

void sh_string_print(const sh_string *string);

#endif /* _SESHAT_STRING_H */
