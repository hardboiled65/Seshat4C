#include <assert.h>
#include <stddef.h>

#include <stdio.h>

#include <seshat.h>

void test_char_as_uint32_t()
{
    sh_char ch = sh_char_new("A");
    uint32_t u32 = sh_char_as_uint32_t(ch);
    assert(u32 == 0x41);
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

// Unicode tests.

void test_unicode_gc()
{
    sh_char ch = sh_char_new("A");
    SH_Gc gc = sh_char_gc(ch);
    assert(gc == SH_Lu);
}

void test_unicode_gc_debug()
{
    printf("test_unicode_gc_debug begin\n");
    sh_char ch = sh_char_new("c");
    SH_Gc gc = sh_char_gc(ch);
    sh_gc_debug(gc);
    printf("test_unicode_gc_debug end\n");
    printf("=========================\n");
}

void test_unicode_gc_name()
{
    printf("test_unicode_gc_name begin\n");
    sh_char ch = sh_char_new("b");
    SH_Gc gc = sh_char_gc(ch);

    sh_property_name property_name = sh_gc_property_value_name(gc);

    sh_string *full = sh_property_name_full(property_name);
    printf("Full: ");
    sh_string_print(full);

    sh_string *abbr = sh_property_name_abbr(property_name);
    printf("Abbr: ");
    sh_string_print(abbr);

    sh_string_free(full);
    sh_string_free(abbr);

    printf("test_unicode_gc_name end\n");
    printf("========================\n");
}

int main()
{
    test_char_as_uint32_t();

    test_string_insert();

    test_string_len();

    test_string_print();

    // Unicode tests.

    test_unicode_gc();

    test_unicode_gc_debug();

    test_unicode_gc_name();

    return 0;
}
