use seshat::unicode::props::*;

#[allow(non_camel_case_types)]
#[derive(FromPrimitive)]
#[repr(C)]
pub enum SH_Gc {
    // C - Other
    SH_Cc = Gc::Cc as isize,
    SH_Cf,
    SH_Cn,
    SH_Co,
    SH_Cs,
    // L - Letter
    // LC - Cased_Letter (Ll | Lt | Lu)
    SH_Ll,
    SH_Lm,
    SH_Lo,
    SH_Lt,
    SH_Lu,
    // M - Mark
    SH_Mc,
    SH_Me,
    SH_Mn,
    // N - Number
    SH_Nd,
    SH_Nl,
    SH_No,
    // P - Punctuation
    SH_Pc,
    SH_Pd,
    SH_Pe,
    SH_Pf,
    SH_Pi,
    SH_Po,
    SH_Ps,
    // S - Symbol
    SH_Sc,
    SH_Sk,
    SH_Sm,
    SH_So,
    // Z - Separator
    SH_Zl,
    SH_Zp,
    SH_Zs,
}