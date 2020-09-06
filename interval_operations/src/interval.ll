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

; Function Attrs: nounwind ssp uwtable
define { double, double } @mult(%struct.interval* nocapture readonly dereferenceable(16), %struct.interval* nocapture readonly dereferenceable(16)) local_unnamed_addr #2 {
  %3 = getelementptr inbounds %struct.interval, %struct.interval* %0, i64 0, i32 0
  %4 = load double, double* %3, align 8, !tbaa !4
  %5 = getelementptr inbounds %struct.interval, %struct.interval* %0, i64 0, i32 1
  %6 = load double, double* %5, align 8, !tbaa !9
  %7 = getelementptr inbounds %struct.interval, %struct.interval* %1, i64 0, i32 0
  %8 = load double, double* %7, align 8, !tbaa !4
  %9 = getelementptr inbounds %struct.interval, %struct.interval* %1, i64 0, i32 1
  %10 = load double, double* %9, align 8, !tbaa !9
  %11 = tail call zeroext i1 @is_negative(double %4) ; check if a.lower is negative
  %12 = tail call zeroext i1 @is_positive(double %6) ; check if a.upper is positive
  br i1 %11, label %13, label %44 ; if a.lower is negative, bring code block 13, otherwise 44

13:                                               ; preds = %2
  %14 = tail call zeroext i1 @is_negative(double %8) ; check if b.lower is negative
  %15 = tail call zeroext i1 @is_positive(double %10) ; check if b.upper is positive
  br i1 %12, label %16, label %32 ; if a.upper is positive, bring code block 16, otherwise 32

16:                                               ; preds = %13
  br i1 %14, label %17, label %28 ; if b.lower is negative, bring code block 17, otherwise 28

17:                                               ; preds = %16
  br i1 %15, label %18, label %25 ; if b.upper is positive, bring code block 18, otherwise 25

18:                                               ; preds = %17
  %19 = tail call double @multiply_down(double %4, double %10) ; multiply downward a.lower and b.upper
  %20 = tail call double @multiply_down(double %6, double %8) ; multiply downward a.upper, b.lower
  %21 = tail call double @min(double %19, double %20) ; get the min of %19 and %20
  %22 = tail call double @multiply_up(double %4, double %8) ; multiply upward a.lower and b.lower
  %23 = tail call double @multiply_up(double %6, double %10) ; multiply upward a.upper and b.upper
  %24 = tail call double @max(double %22, double %23) ; get the max of %23 and %24
  br label %58 ; bring code block 58

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
  %59 = phi double [ %21, %18 ], [ %26, %25 ], [ %30, %29 ], [ %35, %34 ], [ %38, %37 ], [ %42, %41 ], [ %49, %50 ], [ %49, %52 ], [ %56, %55 ], [ 0.000000e+00, %28 ], [ 0.000000e+00, %40 ], [ 0.000000e+00, %54 ], [ 0.000000e+00, %44 ] ; for each of the list, if the second element is true, the first element will be set to value of %59
  %60 = phi double [ %24, %18 ], [ %27, %25 ], [ %31, %29 ], [ %36, %34 ], [ %39, %37 ], [ %43, %41 ], [ %51, %50 ], [ %53, %52 ], [ %57, %55 ], [ 0.000000e+00, %28 ], [ 0.000000e+00, %40 ], [ 0.000000e+00, %54 ], [ 0.000000e+00, %44 ] ; for each of the list, if the second element is true, the first element will be set to value of %60
  %61 = insertvalue { double, double } undef, double %59, 0 ; insert the value of %59 into empty struct 
  %62 = insertvalue { double, double } %61, double %60, 1 ; insert value of %60 into %61, making it a contiguous 2 double struct
  ret { double, double } %62 ; return %62
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
