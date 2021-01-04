use std::ffi::CStr;
use std::os::raw::c_char;

#[repr(C)]
pub struct sh_string {
    content: String,
}

#[no_mangle]
pub fn sh_string_new(c_str: *const c_char) -> *mut sh_string {
    let rust_cstr = unsafe { CStr::from_ptr(c_str) };
    let rust_str = rust_cstr.to_str();
    let rust_str = match rust_str {
        Ok(valid) => valid,
        Err(e) => {
            "Utf8Error"
        }
    };
    let rust_string: String = rust_str.to_owned();
    let s = Box::new(sh_string {
        content: rust_string,
    });

    Box::into_raw(s)
}

#[no_mangle]
pub fn sh_string_len(string: *mut sh_string) -> usize {
    let boxed = unsafe { Box::from_raw(string) };
    let size: usize = boxed.content.len();
    Box::into_raw(boxed);

    size
}

#[no_mangle]
pub fn sh_string_print(string: *mut sh_string) {
    let boxed = unsafe { Box::from_raw(string) };
    println!("{}", boxed.content);
    Box::into_raw(boxed);
}

#[cfg(test)]
mod tests {
    use std::ffi::CStr;

    #[test]
    fn it_works() {
        let c_str = CStr::from_bytes_with_nul(b"hello\0").expect("asdf");
        let s = super::sh_string_new(c_str);
        super::sh_string_print(s);
        super::sh_string_print(s);
    }
}
