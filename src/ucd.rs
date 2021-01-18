use std::ffi::CString;

use seshat::unicode::props::*;
use seshat::unicode::Ucd;

use super::char::*;
use super::string::sh_string;
use super::string::sh_string_new;
use crate::props::*;

#[repr(C)]
pub struct sh_property_name {
    names: Box<PropertyName>,
}

#[no_mangle]
pub extern "C" fn sh_property_name_full(property_name: sh_property_name) -> *mut sh_string {
    let names: PropertyName = *property_name.names;
    let string = CString::new(names.full.as_bytes());
    let string = match string {
        Ok(valid) => valid,
        Err(e) => {
            panic!("{:?}", e);
        }
    };

    Box::into_raw(property_name.names);

    let property_name = sh_string_new(string.into_raw());

    property_name
}

#[no_mangle]
pub extern "C" fn sh_property_name_abbr(property_name: sh_property_name) -> *mut sh_string {
    let names: PropertyName = *property_name.names;
    let string = CString::new(names.abbr.as_bytes());
    let string = match string {
        Ok(valid) => valid,
        Err(e) => {
            panic!("{:?}", e);
        }
    };

    Box::into_raw(property_name.names);

    let name = sh_string_new(string.into_raw());

    name
}

#[no_mangle]
pub extern "C" fn sh_char_gc(ch: sh_char) -> isize {
    let ch = sh_char_to_rust_char(&ch);

    ch.gc() as isize
}

#[no_mangle]
pub extern "C" fn sh_gc_property_value_name(gc: SH_Gc) -> sh_property_name {
    let seshat_gc = convert_sh_gc_to_gc(gc);
    let name = sh_property_name {
        names: Box::new(seshat_gc.property_value_name()),
    };

    name
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
pub extern "C" fn sh_gc_debug(gc: SH_Gc) {
    println!("Gc: {:?}", gc);
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
