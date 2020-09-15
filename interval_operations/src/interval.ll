; ModuleID = 'interval.cc'
source_filename = "interval.cc"
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.15.0"

%struct.interval = type { double, double }

declare i32 @fesetround(i32) local_unnamed_addr #1

; Function Attrs: ssp uwtable
define double @add_down(double, double) local_unnamed_addr #0 {
  %3 = call i32 @fesetround(i32 1024)
  %4 = call double @llvm.experimental.constrained.fadd(double %0, double %1, metadata !"round.downward", metadata !"fpexcept.strict")
  ret double %4
}

; Function Attrs: ssp uwtable
define double @add_up(double, double) local_unnamed_addr #0 {
  %3 = call i32 @fesetround(i32 2048)
  %4 = call double @llvm.experimental.constrained.fadd(double %0, double %1, metadata !"round.upward", metadata !"fpexcept.strict")
  ret double %4
}

; Function Attrs: ssp uwtable
define double @subtract_down(double, double) local_unnamed_addr #0 {
  %3 = call i32 @fesetround(i32 1024)
  %4 = call double @llvm.experimental.constrained.fsub(double %0, double %1, metadata !"round.downward", metadata !"fpexcept.strict")
  ret double %4
}

; Function Attrs: ssp uwtable
define double @subtract_up(double, double) local_unnamed_addr #0 {
  %3 = call i32 @fesetround(i32 2048)
  %4 = call double @llvm.experimental.constrained.fsub(double %0, double %1, metadata !"round.upward", metadata !"fpexcept.strict")
  ret double %4
}

; Function Attrs: ssp uwtable
define double @multiply_down(double, double) local_unnamed_addr #0 {
  %3 = call i32 @fesetround(i32 1024)
  %4 = call double @llvm.experimental.constrained.fmul(double %0, double %1, metadata !"round.downward", metadata !"fpexcept.strict")
  ret double %4
}

; Function Attrs: ssp uwtable
define double @multiply_up(double, double) local_unnamed_addr #0 {
  %3 = call i32 @fesetround(i32 2048)
  %4 = call double @llvm.experimental.constrained.fmul(double %0, double %1, metadata !"round.upward", metadata !"fpexcept.strict")
  ret double %4
}

; Function Attrs: ssp uwtable
define double @divide_down(double, double) local_unnamed_addr #0 {
  %3 = call i32 @fesetround(i32 1024)
  %4 = call double @llvm.experimental.constrained.fdiv(double %0, double %1, metadata !"round.downward", metadata !"fpexcept.strict")
  ret double %4
}

; Function Attrs: ssp uwtable
define double @divide_up(double, double) local_unnamed_addr #0 {
  %3 = call i32 @fesetround(i32 2048)
  %4 = call double @llvm.experimental.constrained.fdiv(double %0, double %1, metadata !"round.upward", metadata !"fpexcept.strict")
  ret double %4
}

; Function Attrs: ssp uwtable
define double @cosine_down(double returned) local_unnamed_addr #0 {
  %2 = call i32 @fesetround(i32 1024)
  %3 = call double @llvm.experimental.constrained.cos(double %0, metadata !"round.downward", metadata !"fpexcept.strict")
  ret double %3
}

; Function Attrs: ssp uwtable
define double @cosine_up(double returned) local_unnamed_addr #0 {
  %2 = call i32 @fesetround(i32 2048)
  %3 = call double @llvm.experimental.constrained.cos(double %0, metadata !"round.upward", metadata !"fpexcept.strict")
  ret double %3
}

; Function Attrs: ssp uwtable
define double @mod_down(double, double) local_unnamed_addr #0 {
  %3 = call i32 @fesetround(i32 1024)
  %4 = call double @llvm.experimental.constrained.frem(double %0, double %1, metadata !"round.downward", metadata !"fpexcept.strict")
  ret double %4
}

; Function Attrs: ssp uwtable
define double @mod_up(double, double) local_unnamed_addr #0 {
  %3 = call i32 @fesetround(i32 2048)
  %4 = call double @llvm.experimental.constrained.frem(double %0, double %1, metadata !"round.upward", metadata !"fpexcept.strict")
  ret double %4
}

; Function Attrs: nounwind readnone ssp uwtable
define double @floor(double returned) local_unnamed_addr #2 {
  %2 = call i32 @fesetround(i32 1024) #5
  %3 = call double @llvm.experimental.constrained.floor(double %0, metadata !"fpexcept.strict")
  ret double %3
}

; Function Attrs: nounwind readnone ssp uwtable
define double @ceil(double returned) local_unnamed_addr #2 {
  %2 = call i32 @fesetround(i32 2048) #5
  %3 = call double @llvm.experimental.constrained.ceil(double %0, metadata !"fpexcept.strict")
  ret double %3
}


declare double @llvm.experimental.constrained.fadd(double, double, metadata, metadata) ; for the rounding addition operations
declare double @llvm.experimental.constrained.fsub(double, double, metadata, metadata) ; for the rounding subtraction operations
declare double @llvm.experimental.constrained.fmul(double, double, metadata, metadata) ; for the rounding multiplication operations
declare double @llvm.experimental.constrained.fdiv(double, double, metadata, metadata) ; for the rounding division operations
declare double @llvm.experimental.constrained.frem(double, double, metadata, metadata) ; for the modular operations
declare double @llvm.experimental.constrained.cos(double, metadata, metadata) ; for the cosine operation
declare double @llvm.experimental.constrained.floor(double, metadata) ; for the floor operation
declare double @llvm.experimental.constrained.ceil(double, metadata) ; for the ceil operation

; Function Attrs: ssp uwtable
define { double, double } @add_interval(%struct.interval* nocapture readonly dereferenceable(16), %struct.interval* nocapture readonly dereferenceable(16)) local_unnamed_addr #0 {
  %3 = getelementptr inbounds %struct.interval, %struct.interval* %0, i64 0, i32 0
  %4 = load double, double* %3, align 8, !tbaa !4
  %5 = getelementptr inbounds %struct.interval, %struct.interval* %1, i64 0, i32 0
  %6 = load double, double* %5, align 8, !tbaa !4
  %7 = call double @add_down(double %4, double %6)
  %8 = getelementptr inbounds %struct.interval, %struct.interval* %0, i64 0, i32 1
  %9 = load double, double* %8, align 8, !tbaa !9
  %10 = getelementptr inbounds %struct.interval, %struct.interval* %1, i64 0, i32 1
  %11 = load double, double* %10, align 8, !tbaa !9
  %12 = call double @add_up(double %9, double %11)
  %13 = call i32 @fesetround(i32 0)
  %14 = insertvalue { double, double } undef, double %7, 0
  %15 = insertvalue { double, double } %14, double %12, 1
  ret { double, double } %15
}

; Function Attrs: ssp uwtable
define { double, double } @subtract_interval(%struct.interval* nocapture readonly dereferenceable(16), %struct.interval* nocapture readonly dereferenceable(16)) local_unnamed_addr #0 {
  %3 = getelementptr inbounds %struct.interval, %struct.interval* %0, i64 0, i32 0
  %4 = load double, double* %3, align 8, !tbaa !4
  %5 = getelementptr inbounds %struct.interval, %struct.interval* %1, i64 0, i32 1
  %6 = load double, double* %5, align 8, !tbaa !9
  %7 = call double @subtract_down(double %4, double %6)
  %8 = getelementptr inbounds %struct.interval, %struct.interval* %0, i64 0, i32 1
  %9 = load double, double* %8, align 8, !tbaa !9
  %10 = getelementptr inbounds %struct.interval, %struct.interval* %1, i64 0, i32 0
  %11 = load double, double* %10, align 8, !tbaa !4
  %12 = call double @subtract_up(double %9, double %11)
  %13 = call i32 @fesetround(i32 0)
  %14 = insertvalue { double, double } undef, double %7, 0
  %15 = insertvalue { double, double } %14, double %12, 1
  ret { double, double } %15
}

; Function Attrs: ssp uwtable
define { double, double } @mult_interval(%struct.interval* nocapture readonly dereferenceable(16), %struct.interval* nocapture readonly dereferenceable(16)) local_unnamed_addr #0 {
  %3 = getelementptr inbounds %struct.interval, %struct.interval* %0, i64 0, i32 0
  %4 = load double, double* %3, align 8, !tbaa !4
  %5 = getelementptr inbounds %struct.interval, %struct.interval* %0, i64 0, i32 1
  %6 = load double, double* %5, align 8, !tbaa !9
  %7 = getelementptr inbounds %struct.interval, %struct.interval* %1, i64 0, i32 0
  %8 = load double, double* %7, align 8, !tbaa !4
  %9 = getelementptr inbounds %struct.interval, %struct.interval* %1, i64 0, i32 1
  %10 = load double, double* %9, align 8, !tbaa !9
  %11 = call zeroext i1 @is_negative(double %4)
  %12 = call zeroext i1 @is_positive(double %6)
  br i1 %11, label %13, label %50

13:                                               ; preds = %2
  %14 = call zeroext i1 @is_negative(double %8)
  %15 = call zeroext i1 @is_positive(double %10)
  br i1 %12, label %16, label %35

16:                                               ; preds = %13
  br i1 %14, label %17, label %30

17:                                               ; preds = %16
  br i1 %15, label %18, label %26

18:                                               ; preds = %17
  %19 = call double @multiply_down(double %4, double %10)
  %20 = call double @multiply_down(double %6, double %8)
  %21 = call double @min(double %19, double %20)
  %22 = call double @multiply_up(double %4, double %8)
  %23 = call double @multiply_up(double %6, double %10)
  %24 = call double @max(double %22, double %23)
  %25 = call i32 @fesetround(i32 0)
  br label %67

26:                                               ; preds = %17
  %27 = call double @multiply_down(double %6, double %8)
  %28 = call double @multiply_up(double %4, double %8)
  %29 = call i32 @fesetround(i32 0)
  br label %67

30:                                               ; preds = %16
  br i1 %15, label %31, label %67

31:                                               ; preds = %30
  %32 = call double @multiply_down(double %4, double %10)
  %33 = call double @multiply_up(double %6, double %10)
  %34 = call i32 @fesetround(i32 0)
  br label %67

35:                                               ; preds = %13
  br i1 %14, label %36, label %45

36:                                               ; preds = %35
  br i1 %15, label %37, label %41

37:                                               ; preds = %36
  %38 = call double @multiply_down(double %4, double %10)
  %39 = call double @multiply_up(double %4, double %8)
  %40 = call i32 @fesetround(i32 0)
  br label %67

41:                                               ; preds = %36
  %42 = call double @multiply_down(double %6, double %10)
  %43 = call double @multiply_up(double %4, double %8)
  %44 = call i32 @fesetround(i32 0)
  br label %67

45:                                               ; preds = %35
  br i1 %15, label %46, label %67

46:                                               ; preds = %45
  %47 = call double @multiply_down(double %4, double %10)
  %48 = call double @multiply_up(double %6, double %8)
  %49 = call i32 @fesetround(i32 0)
  br label %67

50:                                               ; preds = %2
  br i1 %12, label %51, label %67

51:                                               ; preds = %50
  %52 = call zeroext i1 @is_negative(double %8)
  %53 = call zeroext i1 @is_positive(double %10)
  br i1 %52, label %54, label %62

54:                                               ; preds = %51
  %55 = call double @multiply_down(double %6, double %8)
  br i1 %53, label %56, label %59

56:                                               ; preds = %54
  %57 = call double @multiply_up(double %6, double %10)
  %58 = call i32 @fesetround(i32 0)
  br label %67

59:                                               ; preds = %54
  %60 = call double @multiply_up(double %4, double %10)
  %61 = call i32 @fesetround(i32 0)
  br label %67

62:                                               ; preds = %51
  br i1 %53, label %63, label %67

63:                                               ; preds = %62
  %64 = call double @multiply_down(double %4, double %8)
  %65 = call double @multiply_up(double %6, double %10)
  %66 = call i32 @fesetround(i32 0)
  br label %67

67:                                               ; preds = %50, %62, %45, %30, %63, %59, %56, %46, %41, %37, %31, %26, %18
  %68 = phi double [ %24, %18 ], [ %28, %26 ], [ %33, %31 ], [ %39, %37 ], [ %43, %41 ], [ %48, %46 ], [ %57, %56 ], [ %60, %59 ], [ %65, %63 ], [ 0.000000e+00, %30 ], [ 0.000000e+00, %45 ], [ 0.000000e+00, %62 ], [ 0.000000e+00, %50 ]
  %69 = phi double [ %21, %18 ], [ %27, %26 ], [ %32, %31 ], [ %38, %37 ], [ %42, %41 ], [ %47, %46 ], [ %55, %56 ], [ %55, %59 ], [ %64, %63 ], [ 0.000000e+00, %30 ], [ 0.000000e+00, %45 ], [ 0.000000e+00, %62 ], [ 0.000000e+00, %50 ]
  %70 = insertvalue { double, double } undef, double %69, 0
  %71 = insertvalue { double, double } %70, double %68, 1
  ret { double, double } %71
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

; Function Attrs: ssp uwtable
define { double, double } @div_interval(%struct.interval* nocapture readonly dereferenceable(16), %struct.interval* nocapture readonly dereferenceable(16)) local_unnamed_addr #0 {
  %3 = getelementptr inbounds %struct.interval, %struct.interval* %0, i64 0, i32 0
  %4 = load double, double* %3, align 8, !tbaa !4
  %5 = getelementptr inbounds %struct.interval, %struct.interval* %0, i64 0, i32 1
  %6 = load double, double* %5, align 8, !tbaa !9
  %7 = getelementptr inbounds %struct.interval, %struct.interval* %1, i64 0, i32 0
  %8 = load double, double* %7, align 8, !tbaa !4
  %9 = getelementptr inbounds %struct.interval, %struct.interval* %1, i64 0, i32 1
  %10 = load double, double* %9, align 8, !tbaa !9
  %11 = call zeroext i1 @is_positive(double %8)
  br i1 %11, label %53, label %12

12:                                               ; preds = %2
  %13 = call zeroext i1 @is_negative(double %10)
  br i1 %13, label %53, label %14

14:                                               ; preds = %12
  %15 = call zeroext i1 @is_negative(double %8)
  %16 = call zeroext i1 @is_positive(double %10)
  br i1 %15, label %17, label %35

17:                                               ; preds = %14
  br i1 %16, label %86, label %18

18:                                               ; preds = %17
  %19 = call zeroext i1 @is_zero(double %4)
  br i1 %19, label %20, label %25

20:                                               ; preds = %18
  %21 = call zeroext i1 @is_zero(double %6)
  br i1 %21, label %22, label %25

22:                                               ; preds = %20
  %23 = load double, double* %3, align 8
  %24 = load double, double* %5, align 8
  br label %86

25:                                               ; preds = %20, %18
  %26 = call zeroext i1 @is_negative(double %6)
  br i1 %26, label %27, label %30

27:                                               ; preds = %25
  %28 = call double @divide_down(double %6, double %8)
  %29 = call i32 @fesetround(i32 0)
  br label %86

30:                                               ; preds = %25
  %31 = call zeroext i1 @is_negative(double %4)
  br i1 %31, label %86, label %32

32:                                               ; preds = %30
  %33 = call double @divide_up(double %4, double %8)
  %34 = call i32 @fesetround(i32 0)
  br label %86

35:                                               ; preds = %14
  br i1 %16, label %36, label %86

36:                                               ; preds = %35
  %37 = call zeroext i1 @is_zero(double %4)
  br i1 %37, label %38, label %43

38:                                               ; preds = %36
  %39 = call zeroext i1 @is_zero(double %6)
  br i1 %39, label %40, label %43

40:                                               ; preds = %38
  %41 = load double, double* %3, align 8
  %42 = load double, double* %5, align 8
  br label %86

43:                                               ; preds = %38, %36
  %44 = call zeroext i1 @is_negative(double %6)
  br i1 %44, label %45, label %48

45:                                               ; preds = %43
  %46 = call double @divide_up(double %6, double %10)
  %47 = call i32 @fesetround(i32 0)
  br label %86

48:                                               ; preds = %43
  %49 = call zeroext i1 @is_negative(double %4)
  br i1 %49, label %86, label %50

50:                                               ; preds = %48
  %51 = call double @divide_down(double %4, double %10)
  %52 = call i32 @fesetround(i32 0)
  br label %86

53:                                               ; preds = %12, %2
  %54 = call zeroext i1 @is_negative(double %6)
  br i1 %54, label %55, label %65

55:                                               ; preds = %53
  %56 = call zeroext i1 @is_negative(double %10)
  br i1 %56, label %57, label %61

57:                                               ; preds = %55
  %58 = call double @divide_down(double %6, double %8)
  %59 = call double @divide_up(double %4, double %10)
  %60 = call i32 @fesetround(i32 0)
  br label %86

61:                                               ; preds = %55
  %62 = call double @divide_down(double %4, double %8)
  %63 = call double @divide_up(double %6, double %10)
  %64 = call i32 @fesetround(i32 0)
  br label %86

65:                                               ; preds = %53
  %66 = call zeroext i1 @is_negative(double %4)
  %67 = call zeroext i1 @is_negative(double %10)
  br i1 %66, label %68, label %77

68:                                               ; preds = %65
  br i1 %67, label %69, label %73

69:                                               ; preds = %68
  %70 = call double @divide_down(double %6, double %10)
  %71 = call double @divide_up(double %4, double %10)
  %72 = call i32 @fesetround(i32 0)
  br label %86

73:                                               ; preds = %68
  %74 = call double @divide_down(double %4, double %8)
  %75 = call double @divide_up(double %6, double %8)
  %76 = call i32 @fesetround(i32 0)
  br label %86

77:                                               ; preds = %65
  br i1 %67, label %78, label %82

78:                                               ; preds = %77
  %79 = call double @divide_down(double %6, double %10)
  %80 = call double @divide_up(double %4, double %8)
  %81 = call i32 @fesetround(i32 0)
  br label %86

82:                                               ; preds = %77
  %83 = call double @divide_down(double %4, double %10)
  %84 = call double @divide_up(double %6, double %8)
  %85 = call i32 @fesetround(i32 0)
  br label %86

86:                                               ; preds = %35, %48, %30, %17, %82, %78, %73, %69, %61, %57, %50, %45, %40, %32, %27, %22
  %87 = phi double [ %58, %57 ], [ %62, %61 ], [ %70, %69 ], [ %74, %73 ], [ %79, %78 ], [ %83, %82 ], [ %23, %22 ], [ %28, %27 ], [ 0xFFF0000000000000, %32 ], [ %41, %40 ], [ 0xFFF0000000000000, %45 ], [ %51, %50 ], [ 0xFFF0000000000000, %17 ], [ 0xFFF0000000000000, %30 ], [ 0xFFF0000000000000, %48 ], [ 0x7FF8000000000000, %35 ]
  %88 = phi double [ %59, %57 ], [ %63, %61 ], [ %71, %69 ], [ %75, %73 ], [ %80, %78 ], [ %84, %82 ], [ %24, %22 ], [ 0x7FF0000000000000, %27 ], [ %33, %32 ], [ %42, %40 ], [ %46, %45 ], [ 0x7FF0000000000000, %50 ], [ 0x7FF0000000000000, %17 ], [ 0x7FF0000000000000, %30 ], [ 0x7FF0000000000000, %48 ], [ 0x7FF8000000000000, %35 ]
  %89 = insertvalue { double, double } undef, double %87, 0
  %90 = insertvalue { double, double } %89, double %88, 1
  ret { double, double } %90
}

; Function Attrs: inlinehint nounwind ssp uwtable
define linkonce_odr zeroext i1 @is_zero(double) local_unnamed_addr #3 {
  %2 = fcmp oeq double %0, 0.000000e+00
  ret i1 %2
}

; Function Attrs: ssp uwtable
define { double, double } @cosine_interval(%struct.interval* nocapture readonly dereferenceable(16)) local_unnamed_addr #0 {
  %2 = getelementptr inbounds %struct.interval, %struct.interval* %0, i64 0, i32 0
  %3 = load double, double* %2, align 8, !tbaa !4
  %4 = getelementptr inbounds %struct.interval, %struct.interval* %0, i64 0, i32 1
  %5 = load double, double* %4, align 8, !tbaa !9
  %6 = call double @divide_up(double %3, double 0x400921FB54442D18)
  %7 = call double @llvm.ceil.f64(double %6)
  %8 = call double @divide_down(double %5, double 0x400921FB54442D18)
  %9 = call double @mod_down(double %3, double 0x400921FB54442D18)
  %10 = call double @mod_down(double %5, double 0x400921FB54442D18)
  %11 = fadd double %7, 1.000000e+00
  %12 = fcmp ugt double %11, %8
  br i1 %12, label %13, label %60

13:                                               ; preds = %1
  %14 = fcmp ugt double %7, %8
  br i1 %14, label %45, label %15

15:                                               ; preds = %13
  %16 = call double @mod_down(double %7, double 2.000000e+00)
  %17 = fcmp oeq double %16, 1.000000e+00
  br i1 %17, label %18, label %26

18:                                               ; preds = %15
  %19 = call double @cosine_up(double %3)
  %20 = call double @cosine_down(double %3)
  %21 = call double @max(double %19, double %20)
  %22 = call double @cosine_up(double %5)
  %23 = call double @cosine_down(double %5)
  %24 = call double @max(double %22, double %23)
  %25 = call double @max(double %21, double %24)
  br label %60

26:                                               ; preds = %15
  %27 = fcmp oeq double %16, 0.000000e+00
  %28 = call double @cosine_up(double %3)
  %29 = call double @cosine_down(double %3)
  %30 = call double @min(double %28, double %29)
  %31 = call double @cosine_up(double %5)
  %32 = call double @cosine_down(double %5)
  %33 = call double @min(double %31, double %32)
  br i1 %27, label %34, label %36

34:                                               ; preds = %26
  %35 = call double @min(double %30, double %33)
  br label %60

36:                                               ; preds = %26
  %37 = call double @cosine_up(double %3)
  %38 = call double @cosine_down(double %3)
  %39 = call double @max(double %37, double %38)
  %40 = call double @cosine_up(double %5)
  %41 = call double @cosine_down(double %5)
  %42 = call double @max(double %40, double %41)
  %43 = call double @min(double %30, double %33)
  %44 = call double @max(double %39, double %42)
  br label %60

45:                                               ; preds = %13
  %46 = call double @cosine_up(double %3)
  %47 = call double @cosine_down(double %3)
  %48 = call double @min(double %46, double %47)
  %49 = call double @cosine_up(double %5)
  %50 = call double @cosine_down(double %5)
  %51 = call double @min(double %49, double %50)
  %52 = call double @cosine_up(double %3)
  %53 = call double @cosine_down(double %3)
  %54 = call double @max(double %52, double %53)
  %55 = call double @cosine_up(double %5)
  %56 = call double @cosine_down(double %5)
  %57 = call double @max(double %55, double %56)
  %58 = call double @min(double %48, double %51)
  %59 = call double @max(double %54, double %57)
  br label %60

60:                                               ; preds = %1, %18, %34, %36, %45
  %61 = phi double [ %58, %45 ], [ -1.000000e+00, %18 ], [ %35, %34 ], [ %43, %36 ], [ -1.000000e+00, %1 ]
  %62 = phi double [ %59, %45 ], [ %25, %18 ], [ 1.000000e+00, %34 ], [ %44, %36 ], [ 1.000000e+00, %1 ]
  %63 = call i32 @fesetround(i32 0)
  %64 = insertvalue { double, double } undef, double %61, 0
  %65 = insertvalue { double, double } %64, double %62, 1
  ret { double, double } %65
}

; Function Attrs: nounwind readnone speculatable
declare double @llvm.ceil.f64(double) #4

attributes #0 = { ssp uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "darwin-stkchk-strong-link" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "probe-stack"="___chkstk_darwin" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "correctly-rounded-divide-sqrt-fp-math"="false" "darwin-stkchk-strong-link" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "probe-stack"="___chkstk_darwin" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind readnone ssp uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "darwin-stkchk-strong-link" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "probe-stack"="___chkstk_darwin" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { inlinehint nounwind ssp uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "darwin-stkchk-strong-link" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "probe-stack"="___chkstk_darwin" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { nounwind readnone speculatable }
attributes #5 = { nounwind }

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
