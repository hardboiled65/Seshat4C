use std::ffi::CString;

use seshat::unicode::Ucd;

use super::char::*;
use super::string::sh_string;
use super::string::sh_string_new;
use crate::props::*;

#[no_mangle]
pub extern "C" fn sh_char_gc(ch: sh_char) -> isize {
    let ch = sh_char_to_rust_char(&ch);

    ch.gc() as isize
}

#[no_mangle]
pub extern "C" fn sh_char_hst(ch: sh_char) -> isize {
    let ch = sh_char_to_rust_char(&ch);

    ch.hst() as isize
}

#[no_mangle]
pub extern "C" fn sh_char_na(ch: sh_char) -> *mut sh_string {
    let ch = sh_char_to_rust_char(&ch);
    let na = ch.na();

    let cstring_na = CString::new(na.as_bytes());
    let cstring_na = match cstring_na {
        Ok(val) => val,
        Err(e) => panic!("{:?}", e),
    };

    let string = sh_string_new(cstring_na.into_raw());

    string
}

#[no_mangle]
pub extern "C" fn sh_gc_debug(gc: sh_gc) {
    println!("Gc: {:?}", gc);
}

#[no_mangle]
pub extern "C" fn sh_char_ahex(ch: sh_char) -> bool {
    let ch = sh_char_to_rust_char(&ch);
    let ahex = ch.ahex();

    ahex
}

#[no_mangle]
pub extern "C" fn sh_char_alpha(ch: sh_char) -> bool {
    let ch = sh_char_to_rust_char(&ch);
    let alpha = ch.alpha();

    alpha
}

#[cfg(test)]
mod tests {
    use std::ffi::CStr;

    use crate::char::*;
    use super::sh_property_name_full;
    use super::sh_char_gc;
    use super::sh_gc_property_value_name;

    #[test]
    fn test_property_name_full() {
        let c_str = CStr::from_bytes_with_nul(b"A\0").expect("error");
        let ch = sh_char_new(c_str.as_ptr());

        // Get Gc property.
        let gc = sh_char_gc(ch);

        // Get Gc property name.
        // let property_name = sh_gc_name(gc.into());

        // sh_property_name_full(property_name);
    }
}
