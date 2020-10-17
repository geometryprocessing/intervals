#pragma once
#include "interval_c.h"
#include <tuple>

class interval
{
private:
    interval_c val;                  // the lower c level interval that we implemented
    interval(const interval_c &val); // init with lower level interval

public:
    interval();                           // empty init
    interval(double lower, double upper); // init with upper and lower
    interval(const interval &val);        // init with anther interval
    interval(double val);                 // init with one double
    double lower() const;                 // return the lower
    double upper() const;                 // return the upper
    interval_c c_interval_val() const;    // return interval struct we implemented in c

    // operations
    interval operator+(const interval &v) const;
    interval operator-(const interval &v) const;
    interval operator*(const interval &v) const;
    interval operator/(const interval &v) const;
    interval operator+(double v) const;
    interval operator-(double v) const;
    interval operator*(double v) const;
    interval operator/(double v) const;

    interval operator+=(const interval &v);
    interval operator-=(const interval &v);
    interval operator*=(const interval &v);
    interval operator/=(const interval &v);
    interval operator+=(double v);
    interval operator-=(double v);
    interval operator*=(double v);
    interval operator/=(double v);

    friend interval operator+(double v, const interval &n);
    friend interval operator-(double v, const interval &n);
    friend interval operator*(double v, const interval &n);
    friend interval operator/(double v, const interval &n);

    double width();                                                 // return the width of the interval
    friend double width(const interval &n);                         // return the width of the interval
    friend bool zero_in(const interval &n);                         // return if zero is inside the interval
    friend std::pair<interval, interval> bisect(const interval &n); // bisect the interval to two parts

    friend interval sqrt(const interval &v);
    friend interval exp(const interval &v);
    friend interval sin(const interval &v);
    friend interval cos(const interval &v);
};
