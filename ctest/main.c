#include <assert.h>
#include <stddef.h>
#include <string.h>

#include <stdio.h>

#include <seshat/seshat.h>

#include "properties.h"
#include "segmentation.h"
#include "normalization.h"

void test_char_new()
{
    sh_char char_0x0 = sh_char_new("\0");
}

void test_char_as_uint32_t()
{
    sh_char ch = sh_char_new("A");
    uint32_t u32 = sh_char_as_uint32_t(ch);
    assert(u32 == 0x41);

    sh_char ch_0x0 = sh_char_new("\0");
    uint32_t u32_0x0 = sh_char_as_uint32_t(ch_0x0);
    assert(u32_0x0 == 0x0);

    sh_char ch_0x1 = sh_char_new("\x01");
    uint32_t u32_0x1 = sh_char_as_uint32_t(ch_0x1);
    assert(u32_0x1 == 0x1);
}

void test_char_to_string()
{
    sh_char ch_hoshi = sh_char_new("星");
    sh_string *str_hoshi = sh_char_to_string(ch_hoshi);
    assert(strcmp(sh_string_c_str(str_hoshi), "星") == 0);
    sh_string_free(str_hoshi);
}

void test_string_insert()
{
    sh_string *string = sh_string_new("insert tes");
    sh_char ch = sh_char_new("t");
    sh_string_insert(string, 10, ch);
    sh_string_print(string);

    sh_string_free(string);
}

void test_string_len()
{
    sh_string *string = sh_string_new("Hello");
    size_t len = sh_string_len(string);
    assert(len == 5);

    sh_string_free(string);
}

void test_string_print()
{
    sh_string *string = sh_string_new("Foo bar");
    sh_string_print(string);

    sh_string_free(string);
}

void test_string_c_str()
{
    sh_string *string = sh_string_new("Compare with strcmp");
    const char *c_str = sh_string_c_str(string);
    assert(strcmp("Compare with strcmp", c_str) == 0);

    sh_string_free(string);
}

void test_binary_property()
{
    sh_char ch_f = sh_char_new("F");
    bool ahex_f = sh_char_ahex(ch_f);
    sh_binary_property binary_property = sh_binary_property_from(ahex_f);
    assert(binary_property == SH_BINARY_PROPERTY_Y);
    sh_property_name property_name = sh_binary_property_property_value_name(
        binary_property);
    sh_string *property_name_full = sh_property_name_full(property_name);
    assert(strcmp(sh_string_c_str(property_name_full), "Yes") == 0);
}


int main()
{
    test_char_new();

    test_char_as_uint32_t();

    test_char_to_string();

    test_string_insert();

    test_string_len();

    test_string_print();

    test_string_c_str();

    test_binary_property();

    // Test properties.
    test_properties();

    // Test segmentation.
    test_segmentation();

    // Test normalization.
    test_normalization();

    return 0;
}
