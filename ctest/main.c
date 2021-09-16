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

void test_unicode_alpha()
{
    sh_char ch_a = sh_char_new("a");
    bool alpha_a = sh_char_alpha(ch_a);
    assert(alpha_a == true);
}

void test_unicode_bidi_c()
{
    sh_char ch = sh_char_new("\u202D");
    bool bidi_c = sh_char_bidi_c(ch);
    assert(bidi_c == true);
}

void test_unicode_cased()
{
    sh_char ch_s = sh_char_new("S");
    bool cased_s = sh_char_cased(ch_s);
    assert(cased_s == true);
}

void test_unicode_ce()
{
    sh_char ch_qa = sh_char_new("क़");
    bool ce_qa = sh_char_ce(ch_qa);
    assert(ce_qa == true);
}

void test_unicode_ci()
{
    sh_char ch_colon = sh_char_new(":");
    bool ci_colon = sh_char_ci(ch_colon);
    assert(ci_colon == true);
}

void test_unicode_comp_ex()
{
    sh_char ch_gha = sh_char_new("གྷ");
    bool comp_ex_gha = sh_char_comp_ex(ch_gha);
    assert(comp_ex_gha == true);
}

void test_unicode_dash()
{
    sh_char ch_minus = sh_char_new("-");
    bool dash_minus = sh_char_dash(ch_minus);
    assert(dash_minus == true);
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

    // Unicode tests.

    test_unicode_gc();

    test_unicode_gc_debug();

    test_unicode_gc_name();

    test_unicode_hst();

    test_unicode_hst_name();

    test_unicode_na();

    test_unicode_ahex();

    test_unicode_alpha();

    test_unicode_bidi_c();

    test_unicode_cased();

    test_unicode_ce();

    test_unicode_ci();

    test_unicode_comp_ex();

    test_unicode_dash();

    // Test segmentation.
    test_segmentation();

    return 0;
}
