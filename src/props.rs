use seshat::unicode::props::*;

#[allow(non_camel_case_types)]
#[derive(Debug, Clone)]
#[repr(C)]
pub enum sh_gc {
    // C - Other
    SH_GC_CC = Gc::Cc as isize,
    SH_GC_CF,
    SH_GC_CN,
    SH_GC_CO,
    SH_GC_CS,
    // L - Letter
    // LC - Cased_Letter (Ll | Lt | Lu)
    SH_GC_LL,
    SH_GC_LM,
    SH_GC_LO,
    SH_GC_LT,
    SH_GC_LU,
    // M - Mark
    SH_GC_MC,
    SH_GC_ME,
    SH_GC_MN,
    // N - Number
    SH_GC_ND,
    SH_GC_NL,
    SH_GC_NO,
    // P - Punctuation
    SH_GC_PC,
    SH_GC_PD,
    SH_GC_PE,
    SH_GC_PF,
    SH_GC_PI,
    SH_GC_PO,
    SH_GC_PS,
    // S - Symbol
    SH_GC_SC,
    SH_GC_SK,
    SH_GC_SM,
    SH_GC_SO,
    // Z - Separator
    SH_GC_ZL,
    SH_GC_ZP,
    SH_GC_ZS,
}

pub fn convert_sh_gc_to_gc(gc: sh_gc) -> Gc {
    match gc {
        sh_gc::SH_GC_CC => Gc::Cc,
        sh_gc::SH_GC_CF => Gc::Cf,
        sh_gc::SH_GC_CN => Gc::Cn,
        sh_gc::SH_GC_CO => Gc::Co,
        sh_gc::SH_GC_CS => Gc::Cs,
        sh_gc::SH_GC_LL => Gc::Ll,
        sh_gc::SH_GC_LM => Gc::Lm,
        sh_gc::SH_GC_LO => Gc::Lo,
        sh_gc::SH_GC_LT => Gc::Lt,
        sh_gc::SH_GC_LU => Gc::Lu,
        sh_gc::SH_GC_MC => Gc::Mc,
        sh_gc::SH_GC_ME => Gc::Me,
        sh_gc::SH_GC_MN => Gc::Mn,
        sh_gc::SH_GC_ND => Gc::Nd,
        sh_gc::SH_GC_NL => Gc::Nl,
        sh_gc::SH_GC_NO => Gc::No,
        sh_gc::SH_GC_PC => Gc::Pc,
        sh_gc::SH_GC_PD => Gc::Pd,
        sh_gc::SH_GC_PE => Gc::Pe,
        sh_gc::SH_GC_PF => Gc::Pf,
        sh_gc::SH_GC_PI => Gc::Pi,
        sh_gc::SH_GC_PO => Gc::Po,
        sh_gc::SH_GC_PS => Gc::Ps,
        sh_gc::SH_GC_SC => Gc::Sc,
        sh_gc::SH_GC_SK => Gc::Sk,
        sh_gc::SH_GC_SM => Gc::Sm,
        sh_gc::SH_GC_SO => Gc::So,
        sh_gc::SH_GC_ZL => Gc::Zl,
        sh_gc::SH_GC_ZP => Gc::Zp,
        sh_gc::SH_GC_ZS => Gc::Zs,
    }
}

#[allow(non_camel_case_types)]
#[derive(Debug, Clone)]
#[repr(C)]
pub enum sh_hst {
    SH_HST_L,      //Leading_Jamo
    SH_HST_LV,     //LV_Syllable
    SH_HST_LVT,    //LVT_Syllable
    SH_HST_NA,     //Not_Applicable
    SH_HST_T,      //Trailing_Jamo
    SH_HST_V,      //Vowel_Jamo
}

pub fn convert_sh_hst_to_hst(hst: sh_hst) -> Hst {
    match hst {
        sh_hst::SH_HST_L => Hst::L,
        sh_hst::SH_HST_LV => Hst::LV,
        sh_hst::SH_HST_LVT => Hst::LVT,
        sh_hst::SH_HST_NA => Hst::NA,
        sh_hst::SH_HST_T => Hst::T,
        sh_hst::SH_HST_V => Hst::V,
    }
}