/*
//  char.h
//
//  Author:     Yujeonja
//  Created:    2021. 01. 06. 15:57
//  Copyright (c) 2021 Yujeonja. All rights reserved.
//
//  Seshat char struct and functions.
*/
#ifndef _SESHAT_CHAR_H
#define _SESHAT_CHAR_H

#include <stdint.h>

typedef struct sh_char {
    uint32_t ch;
} sh_char;

sh_char sh_char_new(const char*);

uint32_t sh_char_as_uint32_t(sh_char ch);

#endif /* _SESHAT_CHAR_H */
