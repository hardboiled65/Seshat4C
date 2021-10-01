use std::ffi::CString;

use seshat::unicode::Normalization;

use super::string::*;

#[no_mangle]
pub extern "C" fn sh_string_to_nfd(string: *mut sh_string) -> *mut sh_string {
    let nfd = unsafe { (*string).content.to_nfd() };
    let nfd_c = CString::new(nfd.as_bytes()).unwrap();

    let s = Box::new(sh_string {
        content: nfd,
        c_string: nfd_c,
    });

    Box::into_raw(s)
}

#[no_mangle]
pub extern "C" fn sh_string_to_nfkd(string: *mut sh_string) -> *mut sh_string {
    let nfkd = unsafe { (*string).content.to_nfkd() };
    let nfkd_c = CString::new(nfkd.as_bytes()).unwrap();

    let s = Box::new(sh_string {
        content: nfkd,
        c_string: nfkd_c,
    });

    Box::into_raw(s)
}
