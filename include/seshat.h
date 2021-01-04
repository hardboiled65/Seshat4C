/*
//  seshat.h
//
//  Author:     Yujeonja
//  Created:    2021. 01. 04. 21:07
//  Copyright (c) 2021 Yujeonja. All rights reserved.
//
//  Seshat main string and functions.
*/
#ifndef _SESHAT_H
#define _SESHAT_H

typedef struct sh_string {
    void *content;
} sh_string;

sh_string* sh_string_new(const char*);

void sh_string_print(const sh_string *string);

#endif /* _SESHAT_H */
