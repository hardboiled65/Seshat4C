#include <assert.h>
#include <stddef.h>
#include <string.h>

#include <stdio.h>

#include <seshat/seshat.h>

#include "segmentation.h"

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

// Unicode tests.

void test_unicode_gc()
{
    sh_char ch = sh_char_new("A");
    sh_gc gc = sh_char_gc(ch);
    assert(gc == SH_GC_LU);
}

void test_unicode_gc_debug()
{
    printf("test_unicode_gc_debug begin\n");
    sh_char ch = sh_char_new("c");
    sh_gc gc = sh_char_gc(ch);
    sh_gc_debug(gc);
    printf("test_unicode_gc_debug end\n");
    printf("=========================\n");
}

void test_unicode_gc_name()
{
    printf("test_unicode_gc_name begin\n");
    sh_char ch = sh_char_new("b");
    sh_gc gc = sh_char_gc(ch);

    sh_property_name property_name = sh_gc_property_value_name(gc);

    sh_string *full = sh_property_name_full(property_name);
    printf("Full: "); fflush(stdout);
    sh_string_print(full);

    sh_string *abbr = sh_property_name_abbr(property_name);
    printf("Abbr: "); fflush(stdout);
    sh_string_print(abbr);

    sh_string_free(full);
    sh_string_free(abbr);

    printf("test_unicode_gc_name end\n");
    printf("========================\n");
}

void test_unicode_hst()
{
    sh_char ch = sh_char_new("ᄀ");
    sh_hst hst = sh_char_hst(ch);
    assert(hst == SH_HST_L);
}

void test_unicode_hst_name()
{
    printf("test_unicode_hst_name begin\n");
    sh_char ch = sh_char_new("ᄀ");
    sh_hst hst = sh_char_hst(ch);

    sh_property_name property_name = sh_hst_property_value_name(hst);

    sh_string *full = sh_property_name_full(property_name);
    printf("Full: "); fflush(stdout);
    sh_string_print(full);

    sh_string *abbr = sh_property_name_abbr(property_name);
    printf("Abbr: "); fflush(stdout);
    sh_string_print(abbr);

    sh_string_free(full);
    sh_string_free(abbr);

    printf("test_unicode_hst_name end\n");
    printf("=========================\n");
}

void test_unicode_na()
{
    // Hangul Syllable Ga.
    sh_char ch_ga = sh_char_new("가");
    sh_string *na_ga = sh_char_na(ch_ga);
    sh_string_print(na_ga);
    assert(strcmp(sh_string_c_str(na_ga), "HANGUL SYLLABLE GA") == 0);

    sh_string_free(na_ga);

    // None.
    sh_char ch_0x0 = sh_char_new("\0");
    sh_string *na_0x0 = sh_char_na(ch_0x0);
    printf("[%s]\n", sh_string_c_str(na_0x0));
    assert(strcmp(sh_string_c_str(na_0x0), "") == 0);

    sh_string_free(na_0x0);
}

void test_unicode_ahex()
{
    sh_char ch_f = sh_char_new("F");
    bool ahex_f = sh_char_ahex(ch_f);
    assert(ahex_f == true);
}

int main()
{
    test_char_new();

    test_char_as_uint32_t();

    test_string_insert();

    test_string_len();

    test_string_print();

    test_string_c_str();

    // Unicode tests.

    test_unicode_gc();

    test_unicode_gc_debug();

    test_unicode_gc_name();

    test_unicode_hst();

    test_unicode_hst_name();

    test_unicode_na();

    test_unicode_ahex();

    // Test segmentation.
    test_segmentation();

    return 0;
}
