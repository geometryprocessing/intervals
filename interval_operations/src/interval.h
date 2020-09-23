struct interval
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
// the code will be further modified inside llvm ir
extern "C" EXPORT double add_down(double a, double b);

// perform addition of two double
// with rounding mode set upward
// the code will be further modified inside llvm ir
extern "C" EXPORT double add_up(double a, double b);

// perform subtraction of two double, a - b
// with the rounding mode set downward
// the code will be further modified inside llvm ir
extern "C" EXPORT double subtract_down(double a, double b);

// perform subtraction of two double, a - b
// with the rounding mode set upward
// the code will be further modified inside llvm ir
extern "C" EXPORT double subtract_up(double a, double b);
// perform multiplication of two double, a * b
// with the rounding mode set downward
// the code will be further modified inside llvm ir
extern "C" EXPORT double multiply_down(double a, double b);

// perform multiplication of two double, a * b
// with the rounding mode set upward
// the code will be further modified inside llvm ir
extern "C" EXPORT double multiply_up(double a, double b);

// perform division of two doubles, a/b
// with the rounding mode set downward
// the code will be further modified inside llvm ir
extern "C" EXPORT double divide_down(double a, double b);

// perform division of two doubles, a/b
// with the rounding mode set upward
// the code will be further modified inside llvm ir
extern "C" EXPORT double divide_up(double a, double b);

// // perform the cosine of a double, cos(a)
// // with the rounding mode set downward
// // the code will be further modified inside llvm ir
// extern "C" EXPORT double cosine_down(double a);

// // perform the cosine of a double, cos(a)
// // with the rounding mode set upward
// // the code will be further modified inside llvm ir
// extern "C" EXPORT double cosine_up(double a);

// // computes the modulo of two doubles, a%b
// // with the rounding mode set downward
// // the code will be further modified inside llvm ir
// extern "C" EXPORT double mod_down(double a, double b);

// // computes the modulo of two doubles, a%b
// // with the rounding mode set upward
// // the code will be further modified inside llvm ir
// extern "C" EXPORT double mod_up(double a, double b);

// // computes the floor of a double
// // the code will be further modified inside llvm ir
// extern "C" EXPORT double floor(double a);

// // computes the ceil of a double
// // the code will be further modified inside llvm ir
// extern "C" EXPORT double ceil(double a);

// compute the addition of two intervals
// a + b
extern "C" EXPORT interval add_interval(const interval &a, const interval &b);

// compute the subtraction of two intervals
// a - b
extern "C" EXPORT interval subtract_interval(const interval &a, const interval &b);

// conpute the multiplication of two intervals
// a * b
extern "C" EXPORT interval mult_interval(const interval &a, const interval &b);

// compute the division of two intervals
// a / b
extern "C" EXPORT interval div_interval(const interval &a, const interval &b);

// compute the cosine of the interval
// cos(a)
extern "C" EXPORT interval cosine_interval(const interval &a);