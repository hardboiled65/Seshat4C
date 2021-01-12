use std::ffi::CString;

use seshat::unicode::props::*;
use seshat::unicode::Ucd;

// pub mod char;
use super::char::*;
use super::string::sh_string;
use super::string::sh_string_new;
use super::*;

#[repr(C)]
pub struct sh_property_name {
    names: PropertyName,
}

#[no_mangle]
pub fn sh_property_name_full(property_name: sh_property_name) -> *mut sh_string {
    println!("sh_property_name_full temporary --- ");
    println!("{:?}", property_name.names.full.as_bytes());

    let string = CString::new(property_name.names.full.as_bytes());
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
pub fn sh_char_gc(ch: sh_char) -> Gc {
    let ch = sh_char_to_rust_char(&ch);

    ch.gc()
}

#[no_mangle]
pub fn sh_gc_name(gc: Gc) -> sh_property_name {
    let name = sh_property_name {
        names: gc.property_value_name(),
    };

    name
}

#[cfg(test)]
mod tests {
    use std::ffi::CStr;

    use super::char::*;
    use super::sh_property_name_full;
    use super::sh_char_gc;
    use super::sh_gc_name;

    #[test]
    fn test_property_name_full() {
        let c_str = CStr::from_bytes_with_nul(b"A\0").expect("error");
        let ch = sh_char_new(c_str.as_ptr());

        // Get Gc property.
        let gc = sh_char_gc(&ch);

        // Get Gc property name.
        let property_name = sh_gc_name(gc);

        sh_property_name_full(property_name);
    }
}
