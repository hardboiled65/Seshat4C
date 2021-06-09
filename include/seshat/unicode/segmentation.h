/*
//  segmentation.h
//
//  Author:     Yujeonja
//  Created:    2021. 06. 05. 12:39
//  Copyright (c) 2021 Yujeonja. All rights reserved.
//
//  Segmentation structs and functions.
*/
#ifndef _SESHAT_UNICODE_SEGMENTATION_H
#define _SESHAT_UNICODE_SEGMENTATION_H

typedef struct sh_break_graphemes {
    void *break_graphemes;
} sh_break_graphemes;

sh_break_graphemes sh_string_break_graphemes(sh_string *string);

sh_string* sh_break_graphemes_next(sh_break_graphemes *iter);

#endif /* _SESHAT_UNICODE_SEGMENTATION_H */
