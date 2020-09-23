#pragma once
#include "interval_c.h"

namespace igl
{
    class interval
    {
    private:
        interval_c val; // the lower c level interval that we implemented

    public:
        interval(double lower, double upper); // init with upper and lower
        interval(const interval &val);        // init with anther interval
        interval(double val);                 // init with one double
        double lower();                       // return the lower
        double upper();                       // return the upper

        // operations
        interval operator+(const interval &v) const;
        interval operator-(const interval &v) const;
        interval operator*(const interval &v) const;
        interval operator/(const interval &v) const;
        interval operator+=(const interval &v);
        interval operator-=(const interval &v);
        interval operator*=(const interval &v);
        interval operator/=(const interval &v);
    };
} // namespace igl
