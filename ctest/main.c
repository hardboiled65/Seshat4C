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
    Gc gc = sh_char_gc(ch);
    printf("%d\n", gc);
    assert(gc == Lu);
}

int main()
{
    test_char_as_uint32_t();

    test_string_insert();

    test_string_len();

    test_string_print();

    // Unicode tests.

    test_unicode_gc();

    return 0;
}
