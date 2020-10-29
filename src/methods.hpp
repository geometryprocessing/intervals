#pragma once
#include "helper_functions.hpp"
template <class T>
inline T addition(const std::vector<T> &value_array)
{
    return value_array[0] + value_array[1];
}
std::string print_addition(const std::vector<gmp::Rational> &value_array)
{
    return rational_to_string(value_array[0]) + "+" + rational_to_string(value_array[1]);
}

template <class T>
inline T subtraction(const std::vector<T> &value_array)
{
    return value_array[0] - value_array[1];
}
std::string print_subtraction(const std::vector<gmp::Rational> &value_array)
{
    return rational_to_string(value_array[0]) + "-" + rational_to_string(value_array[1]);
}

template <class T>
inline T multiplication(const std::vector<T> &value_array)
{
    return value_array[0] * value_array[1];
}
std::string print_multiplication(const std::vector<gmp::Rational> &value_array)
{
    return rational_to_string(value_array[0]) + "*" + rational_to_string(value_array[1]);
}

template <class T>
inline T division(const std::vector<T> &value_array)
{
    return value_array[0] / value_array[1];
}
std::string print_division(const std::vector<gmp::Rational> &value_array)
{
    return rational_to_string(value_array[0]) + "/" + rational_to_string(value_array[1]);
}

// test equation 1
// a / b * c / d * e / f * g / h * i / j
template <class T>
inline T expr1(const std::vector<T> &value_array)
{
    return value_array[0] / value_array[1] * value_array[2] / value_array[3] * value_array[4] / value_array[5] * value_array[6] / value_array[7] * value_array[8] / value_array[9];
}
std::string print_expr1(const std::vector<gmp::Rational> &value_array)
{
    return rational_to_string(value_array[0]) + "/" + rational_to_string(value_array[1]) + "*" + rational_to_string(value_array[2]) + "/" + rational_to_string(value_array[3]) + "*" + rational_to_string(value_array[4]) + "/" + rational_to_string(value_array[5]) + "*" + rational_to_string(value_array[6]) + "/" + rational_to_string(value_array[7]) + "*" + rational_to_string(value_array[8]) + "/" + rational_to_string(value_array[9]);
}

// test equation 2
// a * (a + b * c) / (b + c * d) - d * (e + f / g) / (g + h) - i / j
template <class T>
inline T expr2(const std::vector<T> &value_array)
{
    return value_array[0] * (value_array[0] + value_array[1] * value_array[2]) / (value_array[1] + value_array[2] * value_array[3]) - value_array[3] * (value_array[4] + value_array[5] / value_array[6]) / (value_array[6] + value_array[7]) - value_array[8] / value_array[9];
}
std::string print_expr2(const std::vector<gmp::Rational> &value_array)
{
    return rational_to_string(value_array[0]) + "*" + "(" + rational_to_string(value_array[0]) + "+" + rational_to_string(value_array[1]) + "*" + rational_to_string(value_array[2]) + ")" + "/" + "(" + rational_to_string(value_array[1]) + "+" + rational_to_string(value_array[2]) + "*" + rational_to_string(value_array[3]) + ")" + "-" + rational_to_string(value_array[3]) + "*" + "(" + rational_to_string(value_array[4]) + "+" + rational_to_string(value_array[5]) + "/" + rational_to_string(value_array[6]) + ")" + "/" + "(" + rational_to_string(value_array[6]) + "+" + rational_to_string(value_array[7]) + ")" + "-" + rational_to_string(value_array[8]) + "/" + rational_to_string(value_array[9]);
}

// test equation 3
// (a * (a / b ) * (a / b / c) - d * (d / e) * (d / e / f)  + g * (g / h) * (g / h / i)) * j
template <class T>
inline T expr3(const std::vector<T> &value_array)
{
    return (value_array[0] * (value_array[0] / value_array[1]) * (value_array[0] / value_array[1] / value_array[2]) - value_array[3] * (value_array[3] / value_array[4]) * (value_array[3] / value_array[4] / value_array[5]) + value_array[6] * (value_array[6] / value_array[7]) * (value_array[6] / value_array[7] / value_array[8])) * value_array[9];
}
std::string print_expr3(const std::vector<gmp::Rational> &value_array)
{
    return "(" + rational_to_string(value_array[0]) + "*" + "(" + rational_to_string(value_array[0]) + "/" + rational_to_string(value_array[1]) + ")" + "*" + "(" + rational_to_string(value_array[0]) + "/" + rational_to_string(value_array[1]) + "/" + rational_to_string(value_array[2]) + ")" + "-" + rational_to_string(value_array[3]) + "*" + "(" + rational_to_string(value_array[3]) + "/" + rational_to_string(value_array[4]) + ")" + "*" + "(" + rational_to_string(value_array[3]) + "/" + rational_to_string(value_array[4]) + "/" + rational_to_string(value_array[5]) + ")" + "+" + rational_to_string(value_array[6]) + "*" + "(" + rational_to_string(value_array[6]) + "/" + rational_to_string(value_array[7]) + ")" + "*" + "(" + rational_to_string(value_array[6]) + "/" + rational_to_string(value_array[7]) + "/" + rational_to_string(value_array[8]) + ")" + ")" + "*" + rational_to_string(value_array[9]);
}

template <class T>
inline T square_root(const std::vector<T> &value_array)
{
    return sqrt(value_array[0]);
}
std::string print_squre_root(const std::vector<gmp::Rational> &value_array)
{
    return "Sqrt" + rational_to_string(value_array[0]);
}

template <class T>
inline T exponential(const std::vector<T> &value_array)
{
    return exp(value_array[0]);
}
std::string print_exponential(const std::vector<gmp::Rational> &value_array)
{
    return "Exp" + rational_to_string(value_array[0]);
}

template <class T>
inline T sin(const std::vector<T> &value_array)
{
    return sin(value_array[0]);
}
std::string print_sin(const std::vector<gmp::Rational> &value_array)
{
    return "sin" + rational_to_string(value_array[0]);
}

template <class T>
inline T cos(const std::vector<T> &value_array)
{
    return cos(value_array[0]);
}
std::string print_cos(const std::vector<gmp::Rational> &value_array)
{
    return "cos" + rational_to_string(value_array[0]);
}
