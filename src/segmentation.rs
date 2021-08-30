use std::ffi::CString;

use seshat::unicode::Segmentation;
use seshat::unicode::BreakGraphemes;

use super::string::*;

#[repr(C)]
pub struct sh_break_graphemes<'a> {
    iter: Box<BreakGraphemes<'a>>,
}

#[no_mangle]
pub extern "C" fn sh_string_break_graphemes<'a>(string: *mut sh_string) -> sh_break_graphemes<'a> {
    sh_break_graphemes {
        iter: Box::new(unsafe { (*string).content.break_graphemes() }),
    }
}

#[no_mangle]
pub extern "C" fn sh_break_graphemes_next(iter: *mut sh_break_graphemes) -> *mut sh_string {
    let mut boxed = unsafe { Box::from_raw(iter) };
    let mut string: Box<sh_string> = Box::new(sh_string {
        content: String::new(),
        c_string: CString::new("").unwrap(),
    });
    let mut is_none = false;

    match boxed.iter.next() {
        Some(val) => {
            string.content = val.to_string();
            string.c_string = CString::new(val).unwrap();
        },
        None => {
            is_none = true;
        }
    }

    Box::into_raw(boxed);

    if !is_none {
        Box::into_raw(string)
    } else {
        std::ptr::null_mut()
    }
}

/*
#[cfg(test)]
mod tests {
    use std::ffi::CStr;

    use super::sh_string_new;
    use super::sh_string_free;
    use super::sh_string_break_graphemes;
    use super::sh_break_graphemes_next;

    #[test]
    fn test_break_graphemes() {
        let c_str = CStr::from_bytes_with_nul(b"Hello!\0").expect("error");
        let sh_str = sh_string_new(c_str.as_ptr());

        let break_graphemes = sh_string_break_graphemes(sh_str);
        // sh_break_graphemes_next(break_graphemes);

        sh_string_free(sh_str);
    }
}
*/