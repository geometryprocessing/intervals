#include "interval.hpp"

interval::interval(const interval_c &val)
{
    this->val = val;
}

interval::interval()
{
    this->val.lower = 0.0;
    this->val.upper = 0.0;
}

interval::interval(double lower, double upper)
{
    this->val.lower = lower;
    this->val.upper = upper;
}

interval::interval(const interval &val)
{
    this->val.lower = val.lower();
    this->val.upper = val.upper();
}

interval::interval(double val)
{
    this->val.lower = val;
    this->val.upper = val;
}

double interval::lower() const
{
    return this->val.lower;
}

double interval::upper() const
{
    return this->val.upper;
}

interval_c interval::c_interval_val() const
{
    return this->val;
}

// interval with interval operation
interval interval::operator+(const interval &v) const
{
    interval_c result = add_interval(this->val, v.val);
    interval res = interval(result);
    return interval(res);
}

interval interval::operator-(const interval &v) const
{
    interval_c result = subtract_interval(this->val, v.val);
    interval res = interval(result);
    return interval(res);
}

interval interval::operator*(const interval &v) const
{
    interval_c result = mult_interval(this->val, v.val);
    interval res = interval(result);
    return interval(res);
}

interval interval::operator/(const interval &v) const
{
    interval_c result = div_interval(this->val, v.val);
    interval res = interval(result);
    return interval(res);
}

// interval with double operation
interval interval::operator+(double v) const
{
    interval_c other_val = {v, v};
    interval_c result = add_interval(this->val, other_val);
    interval res = interval(result);
    return res;
}
interval interval::operator-(double v) const
{
    interval_c other_val = {v, v};
    interval_c result = subtract_interval(this->val, other_val);
    interval res = interval(result);
    return res;
}
interval interval::operator*(double v) const
{
    interval_c other_val = {v, v};
    interval_c result = mult_interval(this->val, other_val);
    interval res = interval(result);
    return res;
}
interval interval::operator/(double v) const
{
    interval_c other_val = {v, v};
    interval_c result = div_interval(this->val, other_val);
    interval res = interval(result);
    return res;
}

// interval with interval operation, changing self value
interval interval::operator+=(const interval &v)
{
    this->val = add_interval(this->val, v.val);
    return (*this);
}

interval interval::operator-=(const interval &v)
{
    this->val = subtract_interval(this->val, v.val);
    return (*this);
}

interval interval::operator*=(const interval &v)
{
    this->val = mult_interval(this->val, v.val);
    return (*this);
}

interval interval::operator/=(const interval &v)
{
    this->val = div_interval(this->val, v.val);
    return (*this);
}

// interval with double operation, changing self value
interval interval::operator+=(double v)
{
    interval_c other_val = {v, v};
    this->val = add_interval(this->val, other_val);
    return (*this);
}
interval interval::operator-=(double v)
{
    interval_c other_val = {v, v};
    this->val = subtract_interval(this->val, other_val);
    return (*this);
}
interval interval::operator*=(double v)
{
    interval_c other_val = {v, v};
    this->val = mult_interval(this->val, other_val);
    return (*this);
}
interval interval::operator/=(double v)
{
    interval_c other_val = {v, v};
    this->val = div_interval(this->val, other_val);
    return (*this);
}

// friend double with interval operation
interval operator+(double v, const interval &n)
{
    interval_c other_val = {v, v};
    interval_c result = add_interval(other_val, n.val);
    interval res = interval(result);
    return res;
}
interval operator-(double v, const interval &n)
{
    interval_c other_val = {v, v};
    interval_c result = subtract_interval(other_val, n.val);
    interval res = interval(result);
    return res;
}
interval operator*(double v, const interval &n)
{
    interval_c other_val = {v, v};
    interval_c result = mult_interval(other_val, n.val);
    interval res = interval(result);
    return res;
}
interval operator/(double v, const interval &n)
{
    interval_c other_val = {v, v};
    interval_c result = div_interval(other_val, n.val);
    interval res = interval(result);
    return res;
}

double interval::width()
{
    return this->val.upper - this->val.lower;
}

double width(const interval &n)
{
    return n.upper() - n.lower();
}

bool zero_in(const interval &n)
{
    return n.upper() >= 0 && n.lower() <= 0;
}

std::pair<interval, interval> bisect(const interval &n)
{
    return {interval(n.lower(), (n.lower() + n.upper()) / 2), interval((n.lower() + n.upper()) / 2, n.upper())};
}

interval sqrt(const interval &v)
{
    interval_c result = sqrt_interval(v.val);
    return result;
}

interval exp(const interval &v)
{
    interval_c result = exp_interval(v.val);
    return result;
}