Seshat4C
========

Seshat language binding for C.

Build
-----

### Build for debug

```sh
$ cargo build
$ ./post-script.sh
```

Test
----

```sh
$ cd ctest
$ make
$ make run
```

Basic Usage
-----------

```c
#include <assert.h>

#include <seshat/seshat.h>

int main()
{
    sh_char ch = sh_char_new("o");
    sh_string *string = sh_string_new("Hell");
    sh_string_insert(string, 4, ch);
    sh_string *hello = sh_string_new("Hello");
    assert(sh_string_eq(string, hello));
    
    sh_string_free(string);
    sh_string_free(hello);

    return 0;
}
```
