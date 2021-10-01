/*
//  normalization.h
//
//  Author:     Yujeonja
//  Created:    2021. 10. 01. 19:12
//  Copyright (c) 2021 Yujeonja. All rights reserved.
//
//  Normalization functions.
*/
#ifndef _SESHAT_UNICODE_NORMALIZATION_H
#define _SESHAT_UNICODE_NORMALIZATION_H

sh_string* sh_string_to_nfd(sh_string *string);

sh_string* sh_string_to_nfkd(sh_string *string);

sh_string* sh_string_to_nfc(sh_string *string);

sh_string* sh_string_to_nfkc(sh_string *string);

#endif /* _SESHAT_UNICODE_NORMALIZATION_H */
