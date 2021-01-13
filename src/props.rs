use seshat::unicode::props::*;

#[allow(non_camel_case_types)]
#[derive(Debug, Clone)]
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

pub fn convert_sh_gc_to_gc(gc: SH_Gc) -> Gc {
    match gc {
        SH_Gc::SH_Cc => Gc::Cc,
        SH_Gc::SH_Cf => Gc::Cf,
        SH_Gc::SH_Cn => Gc::Cn,
        SH_Gc::SH_Co => Gc::Co,
        SH_Gc::SH_Cs => Gc::Cs,
        SH_Gc::SH_Ll => Gc::Ll,
        SH_Gc::SH_Lm => Gc::Lm,
        SH_Gc::SH_Lo => Gc::Lo,
        SH_Gc::SH_Lt => Gc::Lt,
        SH_Gc::SH_Lu => Gc::Lu,
        SH_Gc::SH_Mc => Gc::Mc,
        SH_Gc::SH_Me => Gc::Me,
        SH_Gc::SH_Mn => Gc::Mn,
        SH_Gc::SH_Nd => Gc::Nd,
        SH_Gc::SH_Nl => Gc::Nl,
        SH_Gc::SH_No => Gc::No,
        SH_Gc::SH_Pc => Gc::Pc,
        SH_Gc::SH_Pd => Gc::Pd,
        SH_Gc::SH_Pe => Gc::Pe,
        SH_Gc::SH_Pf => Gc::Pf,
        SH_Gc::SH_Pi => Gc::Pi,
        SH_Gc::SH_Po => Gc::Po,
        SH_Gc::SH_Ps => Gc::Ps,
        SH_Gc::SH_Sc => Gc::Sc,
        SH_Gc::SH_Sk => Gc::Sk,
        SH_Gc::SH_Sm => Gc::Sm,
        SH_Gc::SH_So => Gc::So,
        SH_Gc::SH_Zl => Gc::Zl,
        SH_Gc::SH_Zp => Gc::Zp,
        SH_Gc::SH_Zs => Gc::Zs,
    }
}