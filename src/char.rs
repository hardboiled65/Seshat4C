use std::ffi::CStr;
use std::os::raw::c_char;

#[repr(C)]
pub struct sh_char {
    cp: u32
}

#[no_mangle]
pub extern "C" fn sh_char_new(c_str: *const c_char) -> sh_char
{
    let rust_cstr = unsafe { CStr::from_ptr(c_str) };
    let rust_str = rust_cstr.to_str();
    let rust_str = match rust_str {
        Ok(valid) => valid,
        Err(_) => "Utf8Err",
    };
    // Get chars.
    let mut chars = rust_str.chars();
    // Get first char or error.
    let iter = chars.next();
    let mut ch = '\0';
    match iter {
        Some(chr) => { ch = chr; },
        None => {},
    }
    let ch = sh_char {
        cp: ch as u32,
    };

    ch
}

#[no_mangle]
pub extern "C" fn sh_char_from_u32(cp: u32) -> sh_char {
    if cp > 0x10FFFF {
        return sh_char {
            cp: 0,
        };
    }

    sh_char {
        cp: cp,
    }
}

#[no_mangle]
pub extern "C" fn sh_char_from_uint32_t(cp: u32) -> sh_char {
    if cp > 0x10FFFF {
        return sh_char {
            cp: 0,
        };
    }

    sh_char {
        cp: cp,
    }
}

#[no_mangle]
pub extern "C" fn sh_char_as_uint32_t(ch: sh_char) -> u32 {
    ch.cp as u32
}

pub fn sh_char_to_rust_char(ch: &sh_char) -> char {
    match std::char::from_u32(ch.cp) {
        Some(val) => val,
        None => '\u{0000}',
    }
}

#[cfg(test)]
mod tests {
    use std::ffi::CStr;
    use super::sh_char_new;

    #[test]
    fn test_char_new() {
        let c_str = CStr::from_bytes_with_nul(b"H\0").expect("error");
        let ch = sh_char_new(c_str.as_ptr());
        let rust_char = super::sh_char_to_rust_char(&ch);
        assert_eq!(rust_char, 'H');
    }
}
