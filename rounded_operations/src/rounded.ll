; ModuleID = 'rounded.c'
source_filename = "rounded.c"
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.15.0"

; Function Attrs: norecurse nounwind readnone ssp uwtable
define double @add_down(double, double) local_unnamed_addr #0 {
  %3 = call double @llvm.experimental.constrained.fadd(double %0, double %1, metadata !"round.downward", metadata !"fpexcept.strict")
  ret double %3
}

; Function Attrs: norecurse nounwind readnone ssp uwtable
define double @add_up(double, double) local_unnamed_addr #0 {
  %3 = call double @llvm.experimental.constrained.fadd(double %0, double %1, metadata !"round.upward", metadata !"fpexcept.strict")
  ret double %3
}

; Function Attrs: norecurse nounwind readnone ssp uwtable
define double @subtract_down(double, double) local_unnamed_addr #0 {
  %3 = fsub double %0, %1
  ret double %3
}

; Function Attrs: norecurse nounwind readnone ssp uwtable
define double @subtract_up(double, double) local_unnamed_addr #0 {
  %3 = fsub double %0, %1
  ret double %3
}

; Function Attrs: norecurse nounwind readnone ssp uwtable
define double @multiply_down(double, double) local_unnamed_addr #0 {
  %3 = fmul double %0, %1
  ret double %3
}

; Function Attrs: norecurse nounwind readnone ssp uwtable
define double @multiply_up(double, double) local_unnamed_addr #0 {
  %3 = fmul double %0, %1
  ret double %3
}

declare double @llvm.experimental.constrained.fadd(double, double, metadata, metadata)

attributes #0 = { norecurse nounwind readnone ssp uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "darwin-stkchk-strong-link" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "probe-stack"="___chkstk_darwin" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0, !1, !2}
!llvm.ident = !{!3}

!0 = !{i32 2, !"SDK Version", [3 x i32] [i32 10, i32 15, i32 6]}
!1 = !{i32 1, !"wchar_size", i32 4}
!2 = !{i32 7, !"PIC Level", i32 2}
!3 = !{!"Apple clang version 11.0.3 (clang-1103.0.32.62)"}
