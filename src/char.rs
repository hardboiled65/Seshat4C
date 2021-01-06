use std::os::raw::c_char;

#[repr(C)]
pub struct sh_char {
    cp: u32
}

#[no_mangle]
pub fn sh_char_new(c_str: *const c_char) -> sh_char
{
    let mut ch = sh_char {
        cp: 0,
    };

    ch
}

#[cfg(test)]
mod tests {
    use std::ffi::CStr;
    use super::sh_char_new;

    #[test]
    fn test_char_new() {
        let c_str = CStr::from_bytes_with_nul(b"H\0").expect("error");
        let ch = sh_char_new(c_str.as_ptr());
    }
}
