fn main() {
    println!("cargo:rustc-cdylib-link-arg=-Wl,-soname,libseshat4c.so.{}",
        env!("CARGO_PKG_VERSION"));
}
