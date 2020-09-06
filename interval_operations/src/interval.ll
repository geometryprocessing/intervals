; ModuleID = 'interval.cc'
source_filename = "interval.cc"
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.15.0"

%struct.interval = type { double, double }

; Function Attrs: norecurse nounwind readnone ssp uwtable
define double @add_down(double, double) local_unnamed_addr #0 {
  %3 = fadd double %0, %1
  ret double %3
}

; Function Attrs: norecurse nounwind readnone ssp uwtable
define double @add_up(double, double) local_unnamed_addr #0 {
  %3 = fadd double %0, %1
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

; Function Attrs: norecurse nounwind readonly ssp uwtable
define { double, double } @add(%struct.interval* nocapture readonly dereferenceable(16), %struct.interval* nocapture readonly dereferenceable(16)) local_unnamed_addr #1 {
  %3 = getelementptr inbounds %struct.interval, %struct.interval* %0, i64 0, i32 0
  %4 = load double, double* %3, align 8, !tbaa !4
  %5 = getelementptr inbounds %struct.interval, %struct.interval* %1, i64 0, i32 0
  %6 = load double, double* %5, align 8, !tbaa !4
  %7 = tail call double @add_down(double %4, double %6)
  %8 = getelementptr inbounds %struct.interval, %struct.interval* %0, i64 0, i32 1
  %9 = load double, double* %8, align 8, !tbaa !9
  %10 = getelementptr inbounds %struct.interval, %struct.interval* %1, i64 0, i32 1
  %11 = load double, double* %10, align 8, !tbaa !9
  %12 = tail call double @add_up(double %9, double %11)
  %13 = insertvalue { double, double } undef, double %7, 0
  %14 = insertvalue { double, double } %13, double %12, 1
  ret { double, double } %14
}

; Function Attrs: norecurse nounwind readonly ssp uwtable
define { double, double } @subtract(%struct.interval* nocapture readonly dereferenceable(16), %struct.interval* nocapture readonly dereferenceable(16)) local_unnamed_addr #1 {
  %3 = getelementptr inbounds %struct.interval, %struct.interval* %0, i64 0, i32 0
  %4 = load double, double* %3, align 8, !tbaa !4
  %5 = getelementptr inbounds %struct.interval, %struct.interval* %1, i64 0, i32 1
  %6 = load double, double* %5, align 8, !tbaa !9
  %7 = tail call double @subtract_down(double %4, double %6)
  %8 = getelementptr inbounds %struct.interval, %struct.interval* %0, i64 0, i32 1
  %9 = load double, double* %8, align 8, !tbaa !9
  %10 = getelementptr inbounds %struct.interval, %struct.interval* %1, i64 0, i32 0
  %11 = load double, double* %10, align 8, !tbaa !4
  %12 = tail call double @subtract_up(double %9, double %11)
  %13 = insertvalue { double, double } undef, double %7, 0
  %14 = insertvalue { double, double } %13, double %12, 1
  ret { double, double } %14
}

; Function Attrs: norecurse nounwind readonly ssp uwtable
define { double, double } @mult(%struct.interval* nocapture readonly dereferenceable(16), %struct.interval* nocapture readnone dereferenceable(16)) local_unnamed_addr #1 {
  %3 = getelementptr inbounds %struct.interval, %struct.interval* %0, i64 0, i32 0
  %4 = load double, double* %3, align 8
  %5 = getelementptr inbounds %struct.interval, %struct.interval* %0, i64 0, i32 1
  %6 = load double, double* %5, align 8
  %7 = insertvalue { double, double } undef, double %4, 0
  %8 = insertvalue { double, double } %7, double %6, 1
  ret { double, double } %8
}

attributes #0 = { norecurse nounwind readnone ssp uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "darwin-stkchk-strong-link" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "probe-stack"="___chkstk_darwin" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { norecurse nounwind readonly ssp uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "darwin-stkchk-strong-link" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "probe-stack"="___chkstk_darwin" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0, !1, !2}
!llvm.ident = !{!3}

!0 = !{i32 2, !"SDK Version", [3 x i32] [i32 10, i32 15, i32 6]}
!1 = !{i32 1, !"wchar_size", i32 4}
!2 = !{i32 7, !"PIC Level", i32 2}
!3 = !{!"Apple clang version 11.0.3 (clang-1103.0.32.62)"}
!4 = !{!5, !6, i64 0}
!5 = !{!"_ZTS8interval", !6, i64 0, !6, i64 8}
!6 = !{!"double", !7, i64 0}
!7 = !{!"omnipotent char", !8, i64 0}
!8 = !{!"Simple C++ TBAA"}
!9 = !{!5, !6, i64 8}
