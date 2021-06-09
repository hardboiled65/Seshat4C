#include "segmentation.h"

#include <assert.h>

void test_break_graphemes()
{
    sh_string *s = sh_string_new("👩‍❤️‍👩🏳️‍🌈👨‍❤️‍👨");
    sh_string *s1 = sh_string_new("👩‍❤️‍👩");
    sh_string *s2 = sh_string_new("🏳️‍🌈");
    sh_string *s3 = sh_string_new("👨‍❤️‍👨");
    sh_string *grapheme;

    sh_break_graphemes iter = sh_string_break_graphemes(s);
    grapheme = sh_break_graphemes_next(&iter);
    sh_string_print(grapheme);
    assert(sh_string_eq(s1, grapheme) == true);
    sh_string_free(grapheme);
    grapheme = NULL;

    grapheme = sh_break_graphemes_next(&iter);
    assert(sh_string_eq(s2, grapheme) == true);
    sh_string_free(grapheme);
    grapheme = NULL;

    grapheme = sh_break_graphemes_next(&iter);
    assert(sh_string_eq(s3, grapheme) == true);
    sh_string_free(grapheme);
    grapheme = NULL;

    grapheme = sh_break_graphemes_next(&iter);
    assert(grapheme == NULL);

    sh_string_free(s);
    sh_string_free(s1);
    sh_string_free(s2);
    sh_string_free(s3);
}

void test_segmentation()
{
    test_break_graphemes();
}
