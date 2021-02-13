use seshat::unicode::props::*;

#[allow(non_camel_case_types)]
#[derive(Debug, Clone)]
#[repr(C)]
pub enum SH_Gc {
    // C - Other
    SH_Gc_Cc = Gc::Cc as isize,
    SH_Gc_Cf,
    SH_Gc_Cn,
    SH_Gc_Co,
    SH_Gc_Cs,
    // L - Letter
    // LC - Cased_Letter (Ll | Lt | Lu)
    SH_Gc_Ll,
    SH_Gc_Lm,
    SH_Gc_Lo,
    SH_Gc_Lt,
    SH_Gc_Lu,
    // M - Mark
    SH_Gc_Mc,
    SH_Gc_Me,
    SH_Gc_Mn,
    // N - Number
    SH_Gc_Nd,
    SH_Gc_Nl,
    SH_Gc_No,
    // P - Punctuation
    SH_Gc_Pc,
    SH_Gc_Pd,
    SH_Gc_Pe,
    SH_Gc_Pf,
    SH_Gc_Pi,
    SH_Gc_Po,
    SH_Gc_Ps,
    // S - Symbol
    SH_Gc_Sc,
    SH_Gc_Sk,
    SH_Gc_Sm,
    SH_Gc_So,
    // Z - Separator
    SH_Gc_Zl,
    SH_Gc_Zp,
    SH_Gc_Zs,
}

pub fn convert_sh_gc_to_gc(gc: SH_Gc) -> Gc {
    match gc {
        SH_Gc::SH_Gc_Cc => Gc::Cc,
        SH_Gc::SH_Gc_Cf => Gc::Cf,
        SH_Gc::SH_Gc_Cn => Gc::Cn,
        SH_Gc::SH_Gc_Co => Gc::Co,
        SH_Gc::SH_Gc_Cs => Gc::Cs,
        SH_Gc::SH_Gc_Ll => Gc::Ll,
        SH_Gc::SH_Gc_Lm => Gc::Lm,
        SH_Gc::SH_Gc_Lo => Gc::Lo,
        SH_Gc::SH_Gc_Lt => Gc::Lt,
        SH_Gc::SH_Gc_Lu => Gc::Lu,
        SH_Gc::SH_Gc_Mc => Gc::Mc,
        SH_Gc::SH_Gc_Me => Gc::Me,
        SH_Gc::SH_Gc_Mn => Gc::Mn,
        SH_Gc::SH_Gc_Nd => Gc::Nd,
        SH_Gc::SH_Gc_Nl => Gc::Nl,
        SH_Gc::SH_Gc_No => Gc::No,
        SH_Gc::SH_Gc_Pc => Gc::Pc,
        SH_Gc::SH_Gc_Pd => Gc::Pd,
        SH_Gc::SH_Gc_Pe => Gc::Pe,
        SH_Gc::SH_Gc_Pf => Gc::Pf,
        SH_Gc::SH_Gc_Pi => Gc::Pi,
        SH_Gc::SH_Gc_Po => Gc::Po,
        SH_Gc::SH_Gc_Ps => Gc::Ps,
        SH_Gc::SH_Gc_Sc => Gc::Sc,
        SH_Gc::SH_Gc_Sk => Gc::Sk,
        SH_Gc::SH_Gc_Sm => Gc::Sm,
        SH_Gc::SH_Gc_So => Gc::So,
        SH_Gc::SH_Gc_Zl => Gc::Zl,
        SH_Gc::SH_Gc_Zp => Gc::Zp,
        SH_Gc::SH_Gc_Zs => Gc::Zs,
    }
}

#[allow(non_camel_case_types)]
#[derive(Debug, Clone)]
#[repr(C)]
pub enum SH_Hst {
    SH_Hst_L,      //Leading_Jamo
    SH_Hst_LV,     //LV_Syllable
    SH_Hst_LVT,    //LVT_Syllable
    SH_Hst_NA,     //Not_Applicable
    SH_Hst_T,      //Trailing_Jamo
    SH_Hst_V,      //Vowel_Jamo
}

pub fn convert_sh_hst_to_hst(hst: SH_Hst) -> Hst {
    match hst {
        SH_Hst::SH_Hst_L => Hst::L,
        SH_Hst::SH_Hst_LV => Hst::LV,
        SH_Hst::SH_Hst_LVT => Hst::LVT,
        SH_Hst::SH_Hst_NA => Hst::NA,
        SH_Hst::SH_Hst_T => Hst::T,
        SH_Hst::SH_Hst_V => Hst::V,
    }
}