use seshat::unicode::props::*;
use seshat::unicode::Ucd;

// pub mod char;
use super::char::*;
use super::*;

#[repr(C)]
pub struct sh_property_name {
    property_name: PropertyName,
}

#[no_mangle]
pub fn sh_char_gc(ch: &sh_char) -> Gc {
    // let cp = std::char::from_u32(ch.cp);
    let ch = sh_char_to_rust_char(ch);

    ch.gc()
}

#[no_mangle]
pub fn sh_gc_name(gc: Gc) -> *mut sh_property_name {
    let boxed = Box::new(sh_property_name {
        property_name: gc.property_value_name(),
    });

    Box::into_raw(boxed)
}
