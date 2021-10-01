#include "normalization.h"

#include <assert.h>

void test_nfd()
{
    sh_string *str = sh_string_new("Å");
    sh_string *cmp = sh_string_new("A\u030a");

    sh_string *nfd = sh_string_to_nfd(str);
    assert(sh_string_eq(nfd, cmp));

    sh_string_free(nfd);
    sh_string_free(cmp);
    sh_string_free(str);
}

void test_nfkd()
{
    sh_string *str = sh_string_new("㌀");
    sh_string *cmp = sh_string_new("アパート");

    sh_string *nfkd = sh_string_to_nfkd(str);
    assert(sh_string_eq(nfkd, cmp));

    sh_string_free(nfkd);
    sh_string_free(cmp);
    sh_string_free(str);
}

void test_normalization()
{
    test_nfd();
    test_nfkd();
}
