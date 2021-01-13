use std::ffi::CString;

use seshat::unicode::props::*;
use seshat::unicode::Ucd;

use super::char::*;
use super::string::sh_string;
use super::string::sh_string_new;
use crate::props::*;

#[repr(C)]
pub struct sh_property_name {
    names: *const PropertyName,
}

#[no_mangle]
pub fn sh_property_name_full(property_name: sh_property_name) -> *mut sh_string {
    let string = unsafe {
        CString::new((*property_name.names).full.as_bytes())
    };
    let string = match string {
        Ok(valid) => valid,
        Err(e) => {
            println!("{:?}", e);
            panic!();
        }
    };

    let property_name = sh_string_new(string.into_raw());

    property_name
}

#[no_mangle]
pub fn sh_property_name_abbr(property_name: sh_property_name) -> *mut sh_string {
    let string = unsafe {
        CString::new((*property_name.names).abbr.as_bytes())
    };
    let string = match string {
        Ok(valid) => valid,
        Err(e) => {
            panic!("{:?}", e);
        }
    };

    let name = sh_string_new(string.into_raw());

    name
}

#[no_mangle]
pub fn sh_char_gc(ch: sh_char) -> isize {
    let ch = sh_char_to_rust_char(&ch);

    ch.gc() as isize
}

#[no_mangle]
pub fn sh_gc_property_value_name(gc: SH_Gc) -> sh_property_name {
    let seshat_gc = convert_sh_gc_to_gc(gc);
    let name = sh_property_name {
        names: &seshat_gc.property_value_name(),
    };

    name
}

#[no_mangle]
pub fn sh_gc_debug(gc: SH_Gc) {
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
