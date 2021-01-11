#include <assert.h>
#include <stddef.h>

#include <seshat.h>

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

int main()
{
    test_string_len();

    test_string_print();

    return 0;
}
