#include "interval.h"

extern "C"
{
    inline bool is_negative(double a)
    {
        return a < static_cast<double>(0);
    }

    inline bool is_positive(double a)
    {
        return a > static_cast<double>(0);
    }

    inline bool is_zero(double a)
    {
        return a == static_cast<double>(0);
    }

    inline double max(double a, double b)
    {
        return a > b ? a : b;
    }

    inline double min(double a, double b)
    {
        return a < b ? a : b;
    }

    double add_down(double a, double b)
    {
        return a + b;
    }

    double add_up(double a, double b)
    {
        return a + b;
    }

    double subtract_down(double a, double b)
    {
        return a - b;
    }

    double subtract_up(double a, double b)
    {
        return a - b;
    }

    double multiply_down(double a, double b)
    {
        return a * b;
    }

    double multiply_up(double a, double b)
    {
        return a * b;
    }

    interval add(const interval &a, const interval &b)
    {
        interval result = {add_down(a.lower, b.lower), add_up(a.upper, b.upper)};
        return result;
    }

    interval subtract(const interval &a, const interval &b)
    {
        interval result = {subtract_down(a.lower, b.upper), subtract_up(a.upper, b.lower)};
        return result;
    }

    interval mult(const interval &a, const interval &b)
    {
        // get the individual elements
        const double al = a.lower;
        const double au = a.upper;
        const double bl = b.lower;
        const double bu = b.upper;
        interval result;
        if (is_negative(al))
            if (is_positive(au))
            {
                if (is_negative(bl))
                {
                    if (is_positive(bu))
                    {
                        // situation 1
                        // both interval a and b ranges from negative to positive
                        return {min(multiply_down(al, bu), multiply_down(au, bl)),
                                max(multiply_up(al, bl), multiply_up(au, bu))};
                    }
                    else
                    {
                        // situation 2
                        // a ranges from negative to positive, but b is less than or equal to 0
                        return {multiply_down(au, bl), multiply_up(al, bl)};
                    }
                }
                else
                {
                    if (is_positive(bu))
                    {
                        // situation 3
                        // a ranges from negative to positive, but b is greater than or equal to 0
                        return {multiply_down(al, bu), multiply_up(au, bu)};
                    }
                    else
                    {
                        // situation 4
                        // a ranges from negative to positive, but b is strictly 0
                        return {static_cast<double>(0), static_cast<double>(0)};
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
                        return {multiply_down(al, bu), multiply_up(al, bl)};
                    }
                    else
                    {
                        // situation 6
                        // a is less than or equal to 0, b is less than or equal to 0
                        return {multiply_down(au, bu), multiply_up(al, bl)};
                    }
                }
                else
                {
                    if (is_positive(bu))
                    {
                        // situation 7
                        // a is less than or equal to 0, be is greater than or equal to 0
                        return {multiply_down(al, bu), multiply_up(au, bl)};
                    }
                    else
                    {
                        // situation 8
                        // a is less than or equal to 0, b is strictly 0
                        return {static_cast<double>(0), static_cast<double>(0)};
                    }
                }
            }
        else
        {
            if (is_positive(au))
            {
                if (is_negative(bl))
                {
                    if (is_positive(bu)){
                        // situation 9
                        // a is greater than or equal to 0, b ranges from negative to positive
                        return {multiply_down(au, bl), multiply_up(au, bu)};
                    }
                    else{
                        // situation 10
                        // a is greater than or equal to 0, b is less than or equal to 0
                        return {multiply_down(au, bl), multiply_up(al, bu)};
                    }
                }
                else if (is_positive(bu)){
                    // situation 11
                    // a is greater than or equal to 0, b is greater than or equal to 0
                    return {multiply_down(al, bl), multiply_up(au, bu)};
                }
                else {
                    // situation 12
                    // a is greater than or equal to 0, b is strictly 0
                    return {static_cast<double>(0), static_cast<double>(0)};
                }
            }
            else
            {
                // situation 13
                // a is strictly 0, we do not need to care about b's range
                return {static_cast<double>(0), static_cast<double>(0)};
            }
        }
    }
}
