#include "properties.h"

#include <assert.h>
#include <string.h>
#include <stdio.h>

void test_gc()
{
    sh_char ch = sh_char_new("A");
    sh_gc gc = sh_char_gc(ch);
    assert(gc == SH_GC_LU);
}

void test_gc_debug()
{
    printf("test_gc_debug begin\n");
    sh_char ch = sh_char_new("c");
    sh_gc gc = sh_char_gc(ch);
    sh_gc_debug(gc);
    printf("test_gc_debug end\n");
    printf("=========================\n");
}

void test_gc_name()
{
    printf("test_gc_name begin\n");
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

    printf("test_gc_name end\n");
    printf("========================\n");
}

void test_hst()
{
    sh_char ch = sh_char_new("ᄀ");
    sh_hst hst = sh_char_hst(ch);
    assert(hst == SH_HST_L);
}

void test_hst_name()
{
    printf("test_hst_name begin\n");
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

    printf("test_hst_name end\n");
    printf("=========================\n");
}

void test_na()
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

void test_ahex()
{
    sh_char ch_f = sh_char_new("F");
    bool ahex_f = sh_char_ahex(ch_f);
    assert(ahex_f == true);
}

void test_alpha()
{
    sh_char ch_a = sh_char_new("a");
    bool alpha_a = sh_char_alpha(ch_a);
    assert(alpha_a == true);
}

void test_bidi_c()
{
    sh_char ch = sh_char_new("\u202D");
    bool bidi_c = sh_char_bidi_c(ch);
    assert(bidi_c == true);
}

void test_cased()
{
    sh_char ch_s = sh_char_new("S");
    bool cased_s = sh_char_cased(ch_s);
    assert(cased_s == true);
}

void test_ce()
{
    sh_char ch_qa = sh_char_new("क़");
    bool ce_qa = sh_char_ce(ch_qa);
    assert(ce_qa == true);
}

void test_ci()
{
    sh_char ch_colon = sh_char_new(":");
    bool ci_colon = sh_char_ci(ch_colon);
    assert(ci_colon == true);
}

void test_comp_ex()
{
    sh_char ch_gha = sh_char_new("གྷ");
    bool comp_ex_gha = sh_char_comp_ex(ch_gha);
    assert(comp_ex_gha == true);
}

void test_dash()
{
    sh_char ch_minus = sh_char_new("-");
    bool dash_minus = sh_char_dash(ch_minus);
    assert(dash_minus == true);
}

void test_dep()
{
    sh_char ch_n = sh_char_new("ŉ");
    bool dep_n = sh_char_dep(ch_n);
    assert(dep_n == true);
}

void test_properties()
{
    test_gc();

    test_gc_debug();

    test_gc_name();

    test_hst();

    test_hst_name();

    test_na();

    test_ahex();

    test_alpha();

    test_bidi_c();

    test_cased();

    test_ce();

    test_ci();

    test_comp_ex();

    test_dash();

    test_dep();
}