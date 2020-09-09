; Function Attrs: norecurse nounwind readnone ssp uwtable
define double @add_down(double, double) local_unnamed_addr #0 {
  ; call the llvm intrinsic to perform downward addition
  %3 = call double @llvm.experimental.constrained.fadd(double %0, double %1, metadata !"round.downward", metadata !"fpexcept.strict")
  ret double %3
}

; Function Attrs: norecurse nounwind readnone ssp uwtable
define double @add_up(double, double) local_unnamed_addr #0 {
  ; call the llvm intrinsic to perform upward addition
  %3 = call double @llvm.experimental.constrained.fadd(double %0, double %1, metadata !"round.upward", metadata !"fpexcept.strict")
  ret double %3
}

; Function Attrs: norecurse nounwind readnone ssp uwtable
define double @subtract_down(double, double) local_unnamed_addr #0 {
  ; call the llvm intrinsic to perform downward subtraction
  %3 = call double @llvm.experimental.constrained.fsub(double %0, double %1, metadata !"round.downward", metadata !"fpexcept.strict")
  ret double %3
}

; Function Attrs: norecurse nounwind readnone ssp uwtable
define double @subtract_up(double, double) local_unnamed_addr #0 {
  ; call the llvm intrinsic to perform upward subtraction
  %3 = call double @llvm.experimental.constrained.fsub(double %0, double %1, metadata !"round.upward", metadata !"fpexcept.strict")
  ret double %3
}

; Function Attrs: norecurse nounwind readnone ssp uwtable
define double @multiply_down(double, double) local_unnamed_addr #0 {
  ; call the llvm intrinsic to perform downward multiplication
  %3 = call double @llvm.experimental.constrained.fmul(double %0, double %1, metadata !"round.downward", metadata !"fpexcept.strict")
  ret double %3
}

; Function Attrs: norecurse nounwind readnone ssp uwtable
define double @multiply_up(double, double) local_unnamed_addr #0 {
  ; call the llvm intrinsic to perform upward multiplication
  %3 = call double @llvm.experimental.constrained.fmul(double %0, double %1, metadata !"round.upward", metadata !"fpexcept.strict")
  ret double %3
}

; Function Attrs: norecurse nounwind readnone ssp uwtable
define double @divide_down(double, double) local_unnamed_addr #0 {
  ; call the llvm intrinsic to perform downward division
  %3 = call double @llvm.experimental.constrained.fdiv(double %0, double %1, metadata !"round.downward", metadata !"fpexcept.strict")
  ret double %3
}

; Function Attrs: norecurse nounwind readnone ssp uwtable
define double @divide_up(double, double) local_unnamed_addr #0 {
  ; call the llvm intrinsic to perform upward division
  %3 = call double @llvm.experimental.constrained.fdiv(double %0, double %1, metadata !"round.upward", metadata !"fpexcept.strict")
  ret double %3
}

; Function Attrs: norecurse nounwind readnone ssp uwtable
define double @cosine_down(double returned) local_unnamed_addr #0 {
  ; call the llvm intrinsic to perform downward cosine
  %2 = call double @llvm.experimental.constrained.cos(double %0, metadata !"round.downward", metadata !"fpexcept.strict")
  ret double %2
}

; Function Attrs: norecurse nounwind readnone ssp uwtable
define double @cosine_up(double returned) local_unnamed_addr #0 {
  ; call the llvm intrinsic to perform upward cosine
  %2 = call double @llvm.experimental.constrained.cos(double %0, metadata !"round.upward", metadata !"fpexcept.strict")
  ret double %2
}

; Function Attrs: norecurse nounwind readnone ssp uwtable
define double @mod_down(double, double) local_unnamed_addr #0 {
  ; call the llvm intrinsic to perform downward remainder
  %3 = call double @llvm.experimental.constrained.frem(double %0, double %1, metadata !"round.downward", metadata !"fpexcept.strict")
  ret double %3
}

; Function Attrs: norecurse nounwind readnone ssp uwtable
define double @mod_up(double, double) local_unnamed_addr #0 {
  ; call the llvm intrinsic to perform upward remainder
  %3 = call double @llvm.experimental.constrained.frem(double %0, double %1, metadata !"round.upward", metadata !"fpexcept.strict")
  ret double %3
}

; ; Function Attrs: norecurse nounwind readnone ssp uwtable
; define double @mod_down(double, double) local_unnamed_addr #0 {
;   ; call the llvm intrinsic to perform downward division
;   %3 = call double @llvm.experimental.constrained.fdiv(double %0, double %1, metadata !"round.downward", metadata !"fpexcept.strict")
;   %4 = call double @llvm.experimental.constrained.floor(double %3, metadata !"fpexcept.strict")
;   %5 = call double @llvm.experimental.constrained.fmul(double %1, double %4, metadata !"round.upward", metadata !"fpexcept.strict")
;   %6 = call double @llvm.experimental.constrained.fsub(double %0, double %5, metadata !"round.downward", metadata !"fpexcept.strict")
;   ret double %6
; }

; ; Function Attrs: norecurse nounwind readnone ssp uwtable
; define double @mod_up(double, double) local_unnamed_addr #0 {
;   ; call the llvm intrinsic to perform downward division
;   %3 = call double @llvm.experimental.constrained.fdiv(double %0, double %1, metadata !"round.downward", metadata !"fpexcept.strict")
;   %4 = call double @llvm.experimental.constrained.floor(double %3, metadata !"fpexcept.strict")
;   %5 = call double @llvm.experimental.constrained.fmul(double %1, double %4, metadata !"round.downward", metadata !"fpexcept.strict")
;   %6 = call double @llvm.experimental.constrained.fsub(double %0, double %5, metadata !"round.upward", metadata !"fpexcept.strict")
;   ret double %6
; }


declare double @llvm.experimental.constrained.fadd(double, double, metadata, metadata) ; for the rounding addition operations
declare double @llvm.experimental.constrained.fsub(double, double, metadata, metadata) ; for the rounding subtraction operations
declare double @llvm.experimental.constrained.fmul(double, double, metadata, metadata) ; for the rounding multiplication operations
declare double @llvm.experimental.constrained.fdiv(double, double, metadata, metadata) ; for the rounding division operations
declare double @llvm.experimental.constrained.frem(double, double, metadata, metadata) ; for the modular operations
declare double @llvm.experimental.constrained.floor(double, metadata) ; for flooring operations
declare double @llvm.experimental.constrained.cos(double, metadata, metadata) ; for the cosine operation