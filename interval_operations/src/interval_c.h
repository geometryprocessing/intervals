#pragma once
struct interval_c
{
    double lower;
    double upper;
};
#ifdef _WIN32
#ifdef BUILD_DLL
#define EXPORT __declspec(dllexport)
#else
#define EXPORT __declspec(dllimport)
#endif
#else
#define EXPORT
#endif

// returns if a is negative
extern "C" EXPORT inline bool is_negative(double a);

// returns if a is positive
extern "C" EXPORT inline bool is_positive(double a);

// returns if a is zero
extern "C" EXPORT inline bool is_zero(double a);

// returns the larger of two doubles
extern "C" EXPORT inline double max(double a, double b);

// returns the smaller of two doubles
extern "C" EXPORT inline double min(double a, double b);

// perform addition of two double
// with rounding mode set downward
extern "C" EXPORT double add_down(double a, double b);

// perform addition of two double
// with rounding mode set upward
extern "C" EXPORT double add_up(double a, double b);

// perform subtraction of two double, a - b
// with the rounding mode set downward
extern "C" EXPORT double subtract_down(double a, double b);

// perform subtraction of two double, a - b
// with the rounding mode set upward
extern "C" EXPORT double subtract_up(double a, double b);
// perform multiplication of two double, a * b
// with the rounding mode set downward
extern "C" EXPORT double multiply_down(double a, double b);

// perform multiplication of two double, a * b
// with the rounding mode set upward
extern "C" EXPORT double multiply_up(double a, double b);

// perform division of two doubles, a/b
// with the rounding mode set downward
extern "C" EXPORT double divide_down(double a, double b);

// perform division of two doubles, a/b
// with the rounding mode set upward
extern "C" EXPORT double divide_up(double a, double b);

// compute the downward sin function within 0 to pi/4
// sin(a)
extern "C" EXPORT double kernel_sin_downward(double a);

// compute the upward sin function within 0 to pi/4
// sin(a)
extern "C" EXPORT double kernel_sin_upward(double a);

// compute the downward cos function within 0 to pi/4
// cos(a)
extern "C" EXPORT double kernel_cos_downward(double a);

// compute the upward cos function within 0 to pi/4
// cos(a)
extern "C" EXPORT double kernel_cos_upward(double a);

// compute the downward sin function within positive range
extern "C" EXPORT double p_sin_downward(double a);

// compute the upward sin function within positive range
extern "C" EXPORT double p_sin_upward(double a);

// compute the downward cos function within positive range
extern "C" EXPORT double p_cos_downward(double a);

// compute the upward cos function within positive range
extern "C" EXPORT double p_cos_upward(double a);

// compute the downward sin function for all range
extern "C" EXPORT double sin_downward(double a);

// compute the upward sin function for all range
extern "C" EXPORT double sin_upward(double a);

// compute the downward cos function for all range
extern "C" EXPORT double cos_downward(double a);

// compute the upward cos function for all range
extern "C" EXPORT double cos_upward(double a);

// compute the addition of two intervals
// a + b
extern "C" EXPORT interval_c add_interval(const interval_c &a, const interval_c &b);

// compute the subtraction of two intervals
// a - b
extern "C" EXPORT interval_c subtract_interval(const interval_c &a, const interval_c &b);

// conpute the multiplication of two intervals
// a * b
extern "C" EXPORT interval_c mult_interval(const interval_c &a, const interval_c &b);

// compute the division of two intervals
// a / b
extern "C" EXPORT interval_c div_interval(const interval_c &a, const interval_c &b);

// compute the sqrt of an interval
// sqrt(a)
extern "C" EXPORT interval_c sqrt_interval(const interval_c &a);

// // compute the cosine of the interval_c
// // cos(a)
// extern "C" EXPORT interval_c cosine_interval(const interval_c &a);

