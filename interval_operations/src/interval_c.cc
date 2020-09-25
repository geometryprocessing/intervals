#include "interval_c.h"
#include "iostream"
#ifdef _WIN32
#define INFINITY_NUM INFINITY
#define NAN_NUM NAN
#else
#define INFINITY_NUM 1.0 / 0
#define NAN_NUM 0.0 / 0
#endif
extern "C"
{
#include <fenv.h>
#define PI 3.1415926535897932
    double taylor_sin_positive[3] = {
        4803839602527639.0 / 576460752303423488.0,
        6506787178212600.0 / 2361183241434822606848.0,
        6155219321001458.0 / 38685626227668133590597632.0};

    double taylor_sin_negative[3] = {
        -6004799503160666.0 / 36028797018963968.0,
        -7320136535288236.0 / 36893488147419103232.0,
        -7571207865408408.0 / 302231454903657293676544.0};

    EXPORT inline bool is_negative(double a)
    {
        return a < static_cast<double>(0);
    }

    EXPORT inline bool is_positive(double a)
    {
        return a > static_cast<double>(0);
    }

    EXPORT inline bool is_zero(double a)
    {
        return a == static_cast<double>(0);
    }

    EXPORT inline double max(double a, double b)
    {
        return a > b ? a : b;
    }

    EXPORT inline double min(double a, double b)
    {
        return a < b ? a : b;
    }

    EXPORT double add_down(double a, double b)
    {
        fesetround(FE_DOWNWARD);
        return a + b;
    }

    EXPORT double add_up(double a, double b)
    {
        fesetround(FE_UPWARD);
        return a + b;
    }

    EXPORT double subtract_down(double a, double b)
    {
        fesetround(FE_DOWNWARD);
        return a - b;
    }

    EXPORT double subtract_up(double a, double b)
    {
        fesetround(FE_UPWARD);
        return a - b;
    }

    EXPORT double multiply_down(double a, double b)
    {
        fesetround(FE_DOWNWARD);
        return a * b;
    }

    EXPORT double multiply_up(double a, double b)
    {
        fesetround(FE_UPWARD);
        return a * b;
    }

    EXPORT double divide_down(double a, double b)
    {
        fesetround(FE_DOWNWARD);
        return a / b;
    }

    EXPORT double divide_up(double a, double b)
    {
        fesetround(FE_UPWARD);
        return a / b;
    }

    EXPORT double kernel_sin_downward(double a)
    {
        if (a < taylor_sin_positive[2])
        {
            // a is small enough we can just return itself
            return a;
        }
        double result = a;

        // upward rounding a square
        fesetround(FE_UPWARD);
        double a_square_up = a * a;

        // downward rounding a square
        fesetround(FE_DOWNWARD);
        double a_square_down = a * a;

        // for the positive ones they should be rounded down
        result += (((taylor_sin_positive[2] * a_square_down * a_square_down) + taylor_sin_positive[1]) * a_square_down * a_square_down + taylor_sin_positive[0]) * a_square_down * a_square_down * a;
        result += (((taylor_sin_negative[2] * a_square_up * a_square_up) + taylor_sin_negative[1]) * a_square_up * a_square_up + taylor_sin_negative[0]) * a_square_up * a;
        fesetround(FE_TONEAREST);
        return result;
    }

    EXPORT double kernel_sin_upward(double a)
    {
        if (a < taylor_sin_positive[2])
        {
            // a is small enough we can just return itself
            return a;
        }
        double result = a;

        // downward rounding a square
        fesetround(FE_DOWNWARD);
        double a_square_down = a * a;

        // upward rounding a square
        fesetround(FE_UPWARD);
        double a_square_up = a * a;

        // for the positive ones they should be rounded down
        result += (((taylor_sin_positive[2] * a_square_up * a_square_up) + taylor_sin_positive[1]) * a_square_up * a_square_up + taylor_sin_positive[0]) * a_square_up * a_square_up * a;
        result += (((taylor_sin_negative[2] * a_square_down * a_square_down) + taylor_sin_negative[1]) * a_square_down * a_square_down + taylor_sin_negative[0]) * a_square_down * a;
        fesetround(FE_TONEAREST);
        return result;
    }

    // double cosine_down(double a)
    // {
    //     fesetround(FE_DOWNWARD);
    //     return a;
    // }

    // double cosine_up(double a)
    // {
    //     fesetround(FE_UPWARD);
    //     return a;
    // }

    // double mod_down(double a, double b)
    // {
    //     fesetround(FE_DOWNWARD);
    //     return a - b;
    // }

    // double mod_up(double a, double b)
    // {
    //     fesetround(FE_UPWARD);
    //     return a - b;
    // }

    // double floor(double a)
    // {
    //     fesetround(FE_UPWARD);
    //     return a;
    // }

    // double ceil(double a)
    // {
    //     fesetround(FE_UPWARD);
    //     return a;
    // }

    EXPORT interval_c add_interval(const interval_c &a, const interval_c &b)
    {
        double lower = add_down(a.lower, b.lower);
        double upper = add_up(a.upper, b.upper);
        interval_c result = {lower, upper};
        fesetround(FE_TONEAREST);
        return result;
    }

    EXPORT interval_c subtract_interval(const interval_c &a, const interval_c &b)
    {
        double lower = subtract_down(a.lower, b.upper);
        double upper = subtract_up(a.upper, b.lower);
        interval_c result = {lower, upper};
        fesetround(FE_TONEAREST);
        return result;
    }

    EXPORT interval_c mult_interval(const interval_c &a, const interval_c &b)
    {
        // get the individual elements
        const double al = a.lower;
        const double au = a.upper;
        const double bl = b.lower;
        const double bu = b.upper;
        interval_c result;
        if (is_negative(al))
        {
            if (is_positive(au))
            {
                if (is_negative(bl))
                {
                    if (is_positive(bu))
                    {
                        // situation 1
                        // both interval_c a and b ranges from negative to positive
                        double lower = min(multiply_down(al, bu), multiply_down(au, bl));
                        double upper = max(multiply_up(al, bl), multiply_up(au, bu));
                        interval_c result = {lower, upper};
                        fesetround(FE_TONEAREST);
                        return result;
                    }
                    else
                    {
                        // situation 2
                        // a ranges from negative to positive, but b is less than or equal to 0

                        double lower = multiply_down(au, bl);
                        double upper = multiply_up(al, bl);
                        interval_c result = {lower, upper};
                        fesetround(FE_TONEAREST);
                        return result;
                    }
                }
                else
                {
                    if (is_positive(bu))
                    {
                        // situation 3
                        // a ranges from negative to positive, but b is greater than or equal to 0
                        double lower = multiply_down(al, bu);
                        double upper = multiply_up(au, bu);
                        interval_c result = {lower, upper};
                        fesetround(FE_TONEAREST);
                        return result;
                    }
                    else
                    {
                        // situation 4
                        // a ranges from negative to positive, but b is strictly 0
                        interval_c result = {static_cast<double>(0), static_cast<double>(0)};
                        return result;
                    }
                }
            }
            else
            {
                if (is_negative(bl))
                {
                    if (is_positive(bu))
                    {
                        // situation 5
                        // a is less than or equal to 0, b ranges from negative to positive
                        double lower = multiply_down(al, bu);
                        double upper = multiply_up(al, bl);
                        interval_c result = {lower, upper};
                        fesetround(FE_TONEAREST);
                        return result;
                    }
                    else
                    {
                        // situation 6
                        // a is less than or equal to 0, b is less than or equal to 0
                        double lower = multiply_down(au, bu);
                        double upper = multiply_up(al, bl);
                        interval_c result = {lower, upper};
                        fesetround(FE_TONEAREST);
                        return result;
                    }
                }
                else
                {
                    if (is_positive(bu))
                    {
                        // situation 7
                        // a is less than or equal to 0, be is greater than or equal to 0
                        double lower = multiply_down(al, bu);
                        double upper = multiply_up(au, bl);
                        interval_c result = {lower, upper};
                        fesetround(FE_TONEAREST);
                        return result;
                    }
                    else
                    {
                        // situation 8
                        // a is less than or equal to 0, b is strictly 0
                        interval_c result = {static_cast<double>(0), static_cast<double>(0)};
                        return result;
                    }
                }
            }
        }
        else
        {
            if (is_positive(au))
            {
                if (is_negative(bl))
                {
                    if (is_positive(bu))
                    {
                        // situation 9
                        // a is greater than or equal to 0, b ranges from negative to positive
                        double lower = multiply_down(au, bl);
                        double upper = multiply_up(au, bu);
                        interval_c result = {lower, upper};
                        fesetround(FE_TONEAREST);
                        return result;
                    }
                    else
                    {
                        // situation 10
                        // a is greater than or equal to 0, b is less than or equal to 0
                        double lower = multiply_down(au, bl);
                        double upper = multiply_up(al, bu);
                        interval_c result = {lower, upper};
                        fesetround(FE_TONEAREST);
                        return result;
                    }
                }
                else if (is_positive(bu))
                {
                    // situation 11
                    // a is greater than or equal to 0, b is greater than or equal to 0
                    double lower = multiply_down(al, bl);
                    double upper = multiply_up(au, bu);
                    interval_c result = {lower, upper};
                    fesetround(FE_TONEAREST);
                    return result;
                }
                else
                {
                    // situation 12
                    // a is greater than or equal to 0, b is strictly 0
                    interval_c result = {static_cast<double>(0), static_cast<double>(0)};
                    return result;
                }
            }
            else
            {
                // situation 13
                // a is strictly 0, we do not need to care about b's range
                interval_c result = {static_cast<double>(0), static_cast<double>(0)};
                return result;
            }
        }
    }

    EXPORT interval_c div_interval(const interval_c &a, const interval_c &b)
    {
        double al = a.lower;
        double au = a.upper;
        double bl = b.lower;
        double bu = b.upper;
        if (!is_positive(bl) && !is_negative(bu))
        {
            // 0 is within the range
            if (is_negative(bl))
            {
                // bl is not zero
                if (is_positive(bu))
                {
                    // bu is not zero
                    // we can return -inf to inf
                    interval_c result = {static_cast<double>(-INFINITY_NUM), static_cast<double>(INFINITY_NUM)};
                    return result;
                }
                else
                {
                    // bu is zero
                    // we have division by negative
                    if (is_zero(al) && is_zero(au))
                    {
                        return a;
                    }
                    if (is_negative(au))
                    {
                        // a is negative, b is negative to 0
                        interval_c result = {divide_down(au, bl), static_cast<double>(INFINITY_NUM)};
                        fesetround(FE_TONEAREST);
                        return result;
                    }
                    else if (is_negative(al))
                    {
                        // a is from negative to positive, b is negative to 0
                        interval_c result = {static_cast<double>(-INFINITY_NUM), static_cast<double>(INFINITY_NUM)};
                        return result;
                    }
                    else
                    {
                        // a is 0 to positive, b is negative to 0
                        interval_c result = {static_cast<double>(-INFINITY_NUM), divide_up(al, bl)};
                        fesetround(FE_TONEAREST);
                        return result;
                    }
                }
            }
            else
            {
                // b is greater than or equal to 0
                if (is_positive(bu))
                {
                    if (is_zero(al) && is_zero(au))
                    {
                        return a;
                    }
                    if (is_negative(au))
                    {
                        // a is strictly less than 0
                        interval_c result = {static_cast<double>(-INFINITY_NUM), divide_up(au, bu)};
                        fesetround(FE_TONEAREST);
                        return result;
                    }
                    else if (is_negative(al))
                    {
                        interval_c result = {static_cast<double>(-INFINITY_NUM), static_cast<double>(INFINITY_NUM)};
                        return result;
                    }
                    else
                    {
                        // a is 0 to positive
                        interval_c result = {divide_down(al, bu), static_cast<double>(INFINITY_NUM)};
                        fesetround(FE_TONEAREST);
                        return result;
                    }
                }
                else
                {
                    interval_c result = {static_cast<double>(-NAN_NUM), static_cast<double>(NAN_NUM)};
                    return result;
                }
            }
        }
        else
        {
            // b does not include 0
            if (is_negative(au))
            {
                // a is negative
                if (is_negative(bu))
                {
                    // b is negative
                    double lower = divide_down(au, bl);
                    double upper = divide_up(al, bu);
                    interval_c result = {lower, upper};
                    fesetround(FE_TONEAREST);
                    return result;
                }
                else
                {
                    // b is positive
                    double lower = divide_down(al, bl);
                    double upper = divide_up(au, bu);
                    interval_c result = {lower, upper};
                    fesetround(FE_TONEAREST);
                    return result;
                }
            }
            else if (is_negative(al))
            {
                // a from negative to positive
                if (is_negative(bu))
                {
                    // b is negative
                    double lower = divide_down(au, bu);
                    double upper = divide_up(al, bu);
                    interval_c result = {lower, upper};
                    fesetround(FE_TONEAREST);
                    return result;
                }
                else
                {
                    // b is positive
                    double lower = divide_down(al, bl);
                    double upper = divide_up(au, bl);
                    interval_c result = {lower, upper};
                    fesetround(FE_TONEAREST);
                    return result;
                }
            }
            else
            {
                // a is positive
                if (is_negative(bu))
                {
                    // b is negative
                    double lower = divide_down(au, bu);
                    double upper = divide_up(al, bl);
                    interval_c result = {lower, upper};
                    fesetround(FE_TONEAREST);
                    return result;
                }
                else
                {
                    // b is positive
                    double lower = divide_down(al, bu);
                    double upper = divide_up(au, bl);
                    interval_c result = {lower, upper};
                    fesetround(FE_TONEAREST);
                    return result;
                }
            }
        }
    }

    // interval_c cosine_interval(const interval_c &a)
    // {
    //     double al = a.lower;
    //     double au = a.upper;
    //     double al_ratio = ceil(divide_up(al, static_cast<double>(PI)));
    //     double au_ratio = divide_down(au, static_cast<double>(PI));
    //     double al_rem = mod_down(al, static_cast<double>(PI));
    //     double au_rem = mod_down(au, static_cast<double>(PI));
    //     // printf("Lower: %f. Upper: %f\n", al_ratio, au_ratio);
    //     // printf("Lower: %f. Upper: %f\n", al_rem, au_rem);
    //     if (1 + al_ratio <= au_ratio)
    //     {
    //         interval_c result = {static_cast<double>(-1), static_cast<double>(1)};
    //         fesetround(FE_TONEAREST);
    //         return result;
    //     }
    //     else if (al_ratio <= au_ratio)
    //     {
    //         double remainder = mod_down(al_ratio, static_cast<double>(2));
    //         // printf("remainder: %f\n", remainder);
    //         // printf("cos lower %.20f, cos upper %.20f\n", cosine_up(al), cosine_up(au));
    //         // printf("cos lower %.20f, cos upper %.20f\n", cosine_down(al), cosine_down(au));
    //         // printf("lower %.20f, upper %.20f\n", min(cosine_down(al), cosine_down(au)), max(cosine_up(al), cosine_up(au)));
    //         if (remainder == static_cast<double>(1))
    //         {
    //             double al_up = max(cosine_up(al), cosine_down(al));
    //             double au_up = max(cosine_up(au), cosine_down(au));
    //             interval_c result = {static_cast<double>(-1), max(al_up, au_up)};
    //             fesetround(FE_TONEAREST);
    //             return result;
    //         }
    //         else if (remainder == static_cast<double>(0))
    //         {
    //             double al_down = min(cosine_up(al), cosine_down(al));
    //             double au_down = min(cosine_up(au), cosine_down(au));
    //             interval_c result = {min(al_down, au_down), static_cast<double>(1)};
    //             fesetround(FE_TONEAREST);
    //             return result;
    //         }
    //         else
    //         {
    //             double al_down = min(cosine_up(al), cosine_down(al));
    //             double au_down = min(cosine_up(au), cosine_down(au));
    //             double al_up = max(cosine_up(al), cosine_down(al));
    //             double au_up = max(cosine_up(au), cosine_down(au));
    //             double lower = min(al_down, au_down);
    //             double upper = max(al_up, au_up);
    //             interval_c result = {lower, upper};
    //             fesetround(FE_TONEAREST);
    //             return result;
    //         }
    //     }
    //     else
    //     {
    //         // printf("cos lower %.20f, cos upper %.20f\n", cosine_up(al), cosine_up(au));
    //         // printf("cos lower %.20f, cos upper %.20f\n", cosine_down(al), cosine_down(au));
    //         // printf("lower %.20f, upper %.20f\n", min(cosine_down(al), cosine_down(au)), max(cosine_up(al), cosine_up(au)));
    //         double al_down = min(cosine_up(al), cosine_down(al));
    //         double au_down = min(cosine_up(au), cosine_down(au));
    //         double al_up = max(cosine_up(al), cosine_down(al));
    //         double au_up = max(cosine_up(au), cosine_down(au));
    //         double lower = min(al_down, au_down);
    //         double upper = max(al_up, au_up);
    //         interval_c result = {lower, upper};
    //         // printf("%.20f\n", result.lower);
    //         // printf("%.20f\n", result.upper);
    //         fesetround(FE_TONEAREST);
    //         return result;
    //     }
    // }
}
