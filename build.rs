fn main() {
    // Version info.
    // Major version.
    let major_version = env!("CARGO_PKG_VERSION").split('.').next().unwrap();
    println!("cargo:rustc-cdylib-link-arg=-Wl,-soname,libseshat.so.{}",
        major_version);
}
