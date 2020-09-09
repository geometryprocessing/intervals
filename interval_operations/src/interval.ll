; ModuleID = 'interval.cc'
source_filename = "interval.cc"
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.15.0"

%struct.interval = type { double, double }

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

; Function Attrs: norecurse nounwind readonly ssp uwtable
define { double, double } @add_interval(%struct.interval* nocapture readonly dereferenceable(16), %struct.interval* nocapture readonly dereferenceable(16)) local_unnamed_addr #1 {
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
define { double, double } @subtract_interval(%struct.interval* nocapture readonly dereferenceable(16), %struct.interval* nocapture readonly dereferenceable(16)) local_unnamed_addr #1 {
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

; Function Attrs: nounwind ssp uwtable
define { double, double } @mult_interval(%struct.interval* nocapture readonly dereferenceable(16), %struct.interval* nocapture readonly dereferenceable(16)) local_unnamed_addr #2 {
  %3 = getelementptr inbounds %struct.interval, %struct.interval* %0, i64 0, i32 0
  %4 = load double, double* %3, align 8, !tbaa !4
  %5 = getelementptr inbounds %struct.interval, %struct.interval* %0, i64 0, i32 1
  %6 = load double, double* %5, align 8, !tbaa !9
  %7 = getelementptr inbounds %struct.interval, %struct.interval* %1, i64 0, i32 0
  %8 = load double, double* %7, align 8, !tbaa !4
  %9 = getelementptr inbounds %struct.interval, %struct.interval* %1, i64 0, i32 1
  %10 = load double, double* %9, align 8, !tbaa !9
  %11 = tail call zeroext i1 @is_negative(double %4)
  %12 = tail call zeroext i1 @is_positive(double %6)
  br i1 %11, label %13, label %44

13:                                               ; preds = %2
  %14 = tail call zeroext i1 @is_negative(double %8)
  %15 = tail call zeroext i1 @is_positive(double %10)
  br i1 %12, label %16, label %32

16:                                               ; preds = %13
  br i1 %14, label %17, label %28

17:                                               ; preds = %16
  br i1 %15, label %18, label %25

18:                                               ; preds = %17
  %19 = tail call double @multiply_down(double %4, double %10)
  %20 = tail call double @multiply_down(double %6, double %8)
  %21 = tail call double @min(double %19, double %20)
  %22 = tail call double @multiply_up(double %4, double %8)
  %23 = tail call double @multiply_up(double %6, double %10)
  %24 = tail call double @max(double %22, double %23)
  br label %58

25:                                               ; preds = %17
  %26 = tail call double @multiply_down(double %6, double %8)
  %27 = tail call double @multiply_up(double %4, double %8)
  br label %58

28:                                               ; preds = %16
  br i1 %15, label %29, label %58

29:                                               ; preds = %28
  %30 = tail call double @multiply_down(double %4, double %10)
  %31 = tail call double @multiply_up(double %6, double %10)
  br label %58

32:                                               ; preds = %13
  br i1 %14, label %33, label %40

33:                                               ; preds = %32
  br i1 %15, label %34, label %37

34:                                               ; preds = %33
  %35 = tail call double @multiply_down(double %4, double %10)
  %36 = tail call double @multiply_up(double %4, double %8)
  br label %58

37:                                               ; preds = %33
  %38 = tail call double @multiply_down(double %6, double %10)
  %39 = tail call double @multiply_up(double %4, double %8)
  br label %58

40:                                               ; preds = %32
  br i1 %15, label %41, label %58

41:                                               ; preds = %40
  %42 = tail call double @multiply_down(double %4, double %10)
  %43 = tail call double @multiply_up(double %6, double %8)
  br label %58

44:                                               ; preds = %2
  br i1 %12, label %45, label %58

45:                                               ; preds = %44
  %46 = tail call zeroext i1 @is_negative(double %8)
  %47 = tail call zeroext i1 @is_positive(double %10)
  br i1 %46, label %48, label %54

48:                                               ; preds = %45
  %49 = tail call double @multiply_down(double %6, double %8)
  br i1 %47, label %50, label %52

50:                                               ; preds = %48
  %51 = tail call double @multiply_up(double %6, double %10)
  br label %58

52:                                               ; preds = %48
  %53 = tail call double @multiply_up(double %4, double %10)
  br label %58

54:                                               ; preds = %45
  br i1 %47, label %55, label %58

55:                                               ; preds = %54
  %56 = tail call double @multiply_down(double %4, double %8)
  %57 = tail call double @multiply_up(double %6, double %10)
  br label %58

58:                                               ; preds = %44, %54, %40, %28, %55, %52, %50, %41, %37, %34, %29, %25, %18
  %59 = phi double [ %21, %18 ], [ %26, %25 ], [ %30, %29 ], [ %35, %34 ], [ %38, %37 ], [ %42, %41 ], [ %49, %50 ], [ %49, %52 ], [ %56, %55 ], [ 0.000000e+00, %28 ], [ 0.000000e+00, %40 ], [ 0.000000e+00, %54 ], [ 0.000000e+00, %44 ]
  %60 = phi double [ %24, %18 ], [ %27, %25 ], [ %31, %29 ], [ %36, %34 ], [ %39, %37 ], [ %43, %41 ], [ %51, %50 ], [ %53, %52 ], [ %57, %55 ], [ 0.000000e+00, %28 ], [ 0.000000e+00, %40 ], [ 0.000000e+00, %54 ], [ 0.000000e+00, %44 ]
  %61 = insertvalue { double, double } undef, double %59, 0
  %62 = insertvalue { double, double } %61, double %60, 1
  ret { double, double } %62
}

; Function Attrs: inlinehint nounwind ssp uwtable
define linkonce_odr zeroext i1 @is_negative(double) local_unnamed_addr #3 {
  %2 = fcmp olt double %0, 0.000000e+00
  ret i1 %2
}

; Function Attrs: inlinehint nounwind ssp uwtable
define linkonce_odr zeroext i1 @is_positive(double) local_unnamed_addr #3 {
  %2 = fcmp ogt double %0, 0.000000e+00
  ret i1 %2
}

; Function Attrs: inlinehint nounwind ssp uwtable
define linkonce_odr double @min(double, double) local_unnamed_addr #3 {
  %3 = fcmp olt double %0, %1
  %4 = select i1 %3, double %0, double %1
  ret double %4
}

; Function Attrs: inlinehint nounwind ssp uwtable
define linkonce_odr double @max(double, double) local_unnamed_addr #3 {
  %3 = fcmp ogt double %0, %1
  %4 = select i1 %3, double %0, double %1
  ret double %4
}

; Function Attrs: nounwind ssp uwtable
define { double, double } @cosine_interval(%struct.interval* nocapture readonly dereferenceable(16)) local_unnamed_addr #2 {
  %2 = getelementptr inbounds %struct.interval, %struct.interval* %0, i64 0, i32 0
  %3 = load double, double* %2, align 8, !tbaa !4
  %4 = getelementptr inbounds %struct.interval, %struct.interval* %0, i64 0, i32 1
  %5 = load double, double* %4, align 8, !tbaa !9
  %6 = tail call double @divide_up(double %3, double 0x400921FB54442D18)
  %7 = tail call double @divide_down(double %5, double 0x400921FB54442D18)
  %8 = fadd double %6, 1.000000e+00
  %9 = fcmp ugt double %8, %7
  br i1 %9, label %10, label %35

10:                                               ; preds = %1
  %11 = fcmp ugt double %6, %7
  br i1 %11, label %28, label %12

12:                                               ; preds = %10
  %13 = tail call double @mod_down(double %6, double 2.000000e+00)
  %14 = fcmp oeq double %13, 1.000000e+00
  br i1 %14, label %15, label %19

15:                                               ; preds = %12
  %16 = tail call double @cosine_up(double %3)
  %17 = tail call double @cosine_up(double %5)
  %18 = tail call double @max(double %16, double %17)
  br label %35

19:                                               ; preds = %12
  %20 = fcmp oeq double %13, 0.000000e+00
  %21 = tail call double @cosine_down(double %3)
  %22 = tail call double @cosine_down(double %5)
  %23 = tail call double @min(double %21, double %22)
  br i1 %20, label %35, label %24

24:                                               ; preds = %19
  %25 = tail call double @cosine_up(double %3)
  %26 = tail call double @cosine_up(double %5)
  %27 = tail call double @max(double %25, double %26)
  br label %35

28:                                               ; preds = %10
  %29 = tail call double @cosine_down(double %3)
  %30 = tail call double @cosine_down(double %5)
  %31 = tail call double @min(double %29, double %30)
  %32 = tail call double @cosine_up(double %3)
  %33 = tail call double @cosine_up(double %5)
  %34 = tail call double @max(double %32, double %33)
  br label %35

35:                                               ; preds = %15, %24, %19, %1, %28
  %36 = phi double [ %31, %28 ], [ -1.000000e+00, %1 ], [ -1.000000e+00, %15 ], [ %23, %24 ], [ %23, %19 ]
  %37 = phi double [ %34, %28 ], [ 1.000000e+00, %1 ], [ %18, %15 ], [ %27, %24 ], [ 1.000000e+00, %19 ]
  %38 = insertvalue { double, double } undef, double %36, 0
  %39 = insertvalue { double, double } %38, double %37, 1
  ret { double, double } %39
}

attributes #0 = { norecurse nounwind readnone ssp uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "darwin-stkchk-strong-link" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "probe-stack"="___chkstk_darwin" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { norecurse nounwind readonly ssp uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "darwin-stkchk-strong-link" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "probe-stack"="___chkstk_darwin" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind ssp uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "darwin-stkchk-strong-link" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "probe-stack"="___chkstk_darwin" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { inlinehint nounwind ssp uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "darwin-stkchk-strong-link" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "probe-stack"="___chkstk_darwin" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

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
