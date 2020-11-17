#pragma once
#include "helper_functions.hpp"

// In this file you will need to define the expression you want to test on
// for each expression you will need to functions:
// 1. The actually expression itself, which will be a template function since it should take all kinds of numeric types
// 2. The function to return the query, which takes in a list of rationals and return the string that can be directly plugged into wolframalpha
// I wanted to have a vector of classes that makes things easier for testing
// but apparent I cannot have a vector of template classes
// so you will have to type out the methods you want to test
// but it's ok I guess as this gives you more freedom over what method to test
// alternatively I think there's this discussion of using boost::any for a vector
// but I will not do that for now for my distaste for boost

template <class T>
inline T addition(const std::vector<T> &value_array)
{
    return value_array[0] + value_array[1];
}
std::string print_addition(const std::vector<gmp::Rational> &value_array)
{
    return rational_to_string(value_array[0]) + "+" + rational_to_string(value_array[1]);
}
bool check_input_addition(const std::vector<double> &value_array)
{
    return true;
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
bool check_input_subtraction(const std::vector<double> &value_array)
{
    return true;
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
bool check_input_multiplication(const std::vector<double> &value_array)
{
    return true;
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
bool check_input_division(const std::vector<double> &value_array)
{
    if (value_array[1] == 0)
        return false;
    return true;
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
bool check_input_expr1(const std::vector<double> &value_array)
{
    if (value_array[1] == 0)
        return false;
    if (value_array[3] == 0)
        return false;
    if (value_array[5] == 0)
        return false;
    if (value_array[7] == 0)
        return false;
    if (value_array[9] == 0)
        return false;
    return true;
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
bool check_input_expr2(const std::vector<double> &value_array)
{
    if (value_array[1] + value_array[2] * value_array[3] == 0)
        return false;
    if (value_array[6] == 0)
        return false;
    if (value_array[9] == 0)
        return false;
    return true;
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
bool check_input_expr3(const std::vector<double> &value_array)
{
    if (value_array[1] == 0)
        return false;
    if (value_array[2] == 0)
        return false;
    if (value_array[4] == 0)
        return false;
    if (value_array[5] == 0)
        return false;
    if (value_array[7] == 0)
        return false;
    if (value_array[8] == 0)
        return false;
    return true;
}

// Generated function strings for expr4
template <class T>
inline T expr4(const std::vector<T> &value_array)
{
    return (((value_array[5] - value_array[2]) * (value_array[0] + value_array[0]) - value_array[5] + value_array[0]) * (((value_array[1] - (value_array[4]) * (value_array[3])) * (value_array[2] - value_array[1] - (value_array[5]) / (value_array[2]))) / (value_array[0] - value_array[1] - (value_array[3]) / (value_array[5]) - (value_array[4]) * (value_array[0]) + value_array[2]))) * (((value_array[3] + value_array[1] - ((value_array[1]) / (value_array[2])) * (value_array[3])) / (value_array[4])) * ((value_array[4] - value_array[3]) * ((value_array[5]) / (value_array[3])) - value_array[2] + value_array[5] + (value_array[1]) / (value_array[0]) + (value_array[4] + value_array[5] + (value_array[1]) * (value_array[0])) / ((value_array[4]) * ((value_array[4]) * (value_array[2])))));
}
std::string print_expr4(const std::vector<gmp::Rational> &value_array)
{
    return std::string() + "(" + "(" + "(" + rational_to_string(value_array[5]) + "-" + rational_to_string(value_array[2]) + ")" + "*" + "(" + rational_to_string(value_array[0]) + "+" + rational_to_string(value_array[0]) + ")" + "-" + rational_to_string(value_array[5]) + "+" + rational_to_string(value_array[0]) + ")" + "*" + "(" + "(" + "(" + rational_to_string(value_array[1]) + "-" + "(" + rational_to_string(value_array[4]) + ")" + "*" + "(" + rational_to_string(value_array[3]) + ")" + ")" + "*" + "(" + rational_to_string(value_array[2]) + "-" + rational_to_string(value_array[1]) + "-" + "(" + rational_to_string(value_array[5]) + ")" + "/" + "(" + rational_to_string(value_array[2]) + ")" + ")" + ")" + "/" + "(" + rational_to_string(value_array[0]) + "-" + rational_to_string(value_array[1]) + "-" + "(" + rational_to_string(value_array[3]) + ")" + "/" + "(" + rational_to_string(value_array[5]) + ")" + "-" + "(" + rational_to_string(value_array[4]) + ")" + "*" + "(" + rational_to_string(value_array[0]) + ")" + "+" + rational_to_string(value_array[2]) + ")" + ")" + ")" + "*" + "(" + "(" + "(" + rational_to_string(value_array[3]) + "+" + rational_to_string(value_array[1]) + "-" + "(" + "(" + rational_to_string(value_array[1]) + ")" + "/" + "(" + rational_to_string(value_array[2]) + ")" + ")" + "*" + "(" + rational_to_string(value_array[3]) + ")" + ")" + "/" + "(" + rational_to_string(value_array[4]) + ")" + ")" + "*" + "(" + "(" + rational_to_string(value_array[4]) + "-" + rational_to_string(value_array[3]) + ")" + "*" + "(" + "(" + rational_to_string(value_array[5]) + ")" + "/" + "(" + rational_to_string(value_array[3]) + ")" + ")" + "-" + rational_to_string(value_array[2]) + "+" + rational_to_string(value_array[5]) + "+" + "(" + rational_to_string(value_array[1]) + ")" + "/" + "(" + rational_to_string(value_array[0]) + ")" + "+" + "(" + rational_to_string(value_array[4]) + "+" + rational_to_string(value_array[5]) + "+" + "(" + rational_to_string(value_array[1]) + ")" + "*" + "(" + rational_to_string(value_array[0]) + ")" + ")" + "/" + "(" + "(" + rational_to_string(value_array[4]) + ")" + "*" + "(" + "(" + rational_to_string(value_array[4]) + ")" + "*" + "(" + rational_to_string(value_array[2]) + ")" + ")" + ")" + ")" + ")";
}
bool check_input_expr4(const std::vector<double> &value_array)
{
    if (value_array[2] == 0)
        return false;
    if (value_array[5] == 0)
        return false;
    if (value_array[0] - value_array[1] - (value_array[3]) / (value_array[5]) - (value_array[4]) * (value_array[0]) + value_array[2] == 0)
        return false;
    if (value_array[4] == 0)
        return false;
    if (value_array[3] == 0)
        return false;
    if (value_array[0] == 0)
        return false;
    if ((value_array[4]) * ((value_array[4]) * (value_array[2])) == 0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> expr4_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int expr4_variable_count = 6;

// Generated function strings for expr5
template <class T>
inline T expr5(const std::vector<T> &value_array)
{
    return value_array[1] - (value_array[0] + value_array[5]) * (((value_array[6] - value_array[2]) / ((value_array[9]) / (value_array[1])) + value_array[8]) * (((value_array[8]) / (value_array[5]) + value_array[9] + value_array[4]) * (value_array[4]))) - ((value_array[2] - value_array[0] + value_array[3] - value_array[6] + value_array[7] + value_array[9] + (value_array[4]) * (value_array[3])) * ((value_array[2] + value_array[6]) / ((value_array[0]) / (value_array[8])) + ((value_array[1]) / (value_array[5])) / (value_array[3]))) / (value_array[7]);
}
std::string print_expr5(const std::vector<gmp::Rational> &value_array)
{
    return std::string() + rational_to_string(value_array[1]) + "-" + "(" + rational_to_string(value_array[0]) + "+" + rational_to_string(value_array[5]) + ")" + "*" + "(" + "(" + "(" + rational_to_string(value_array[6]) + "-" + rational_to_string(value_array[2]) + ")" + "/" + "(" + "(" + rational_to_string(value_array[9]) + ")" + "/" + "(" + rational_to_string(value_array[1]) + ")" + ")" + "+" + rational_to_string(value_array[8]) + ")" + "*" + "(" + "(" + "(" + rational_to_string(value_array[8]) + ")" + "/" + "(" + rational_to_string(value_array[5]) + ")" + "+" + rational_to_string(value_array[9]) + "+" + rational_to_string(value_array[4]) + ")" + "*" + "(" + rational_to_string(value_array[4]) + ")" + ")" + ")" + "-" + "(" + "(" + rational_to_string(value_array[2]) + "-" + rational_to_string(value_array[0]) + "+" + rational_to_string(value_array[3]) + "-" + rational_to_string(value_array[6]) + "+" + rational_to_string(value_array[7]) + "+" + rational_to_string(value_array[9]) + "+" + "(" + rational_to_string(value_array[4]) + ")" + "*" + "(" + rational_to_string(value_array[3]) + ")" + ")" + "*" + "(" + "(" + rational_to_string(value_array[2]) + "+" + rational_to_string(value_array[6]) + ")" + "/" + "(" + "(" + rational_to_string(value_array[0]) + ")" + "/" + "(" + rational_to_string(value_array[8]) + ")" + ")" + "+" + "(" + "(" + rational_to_string(value_array[1]) + ")" + "/" + "(" + rational_to_string(value_array[5]) + ")" + ")" + "/" + "(" + rational_to_string(value_array[3]) + ")" + ")" + ")" + "/" + "(" + rational_to_string(value_array[7]) + ")";
}
bool check_input_expr5(const std::vector<double> &value_array)
{
    if (value_array[1] == 0)
        return false;
    if ((value_array[9]) / (value_array[1]) == 0)
        return false;
    if (value_array[5] == 0)
        return false;
    if (value_array[8] == 0)
        return false;
    if ((value_array[0]) / (value_array[8]) == 0)
        return false;
    if (value_array[3] == 0)
        return false;
    if (value_array[7] == 0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> expr5_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int expr5_variable_count = 10;

// Generated function strings for expr6
template <class T>
inline T expr6(const std::vector<T> &value_array)
{
    return ((value_array[5]) / (((value_array[6]) * (value_array[4]) - value_array[2] - value_array[7]) / (((value_array[4]) * (value_array[2])) * (value_array[6] + value_array[3])) + value_array[0] + value_array[0] - value_array[5] - value_array[3] + value_array[7])) * (value_array[1]);
}
std::string print_expr6(const std::vector<gmp::Rational> &value_array)
{
    return std::string() + "(" + "(" + rational_to_string(value_array[5]) + ")" + "/" + "(" + "(" + "(" + rational_to_string(value_array[6]) + ")" + "*" + "(" + rational_to_string(value_array[4]) + ")" + "-" + rational_to_string(value_array[2]) + "-" + rational_to_string(value_array[7]) + ")" + "/" + "(" + "(" + "(" + rational_to_string(value_array[4]) + ")" + "*" + "(" + rational_to_string(value_array[2]) + ")" + ")" + "*" + "(" + rational_to_string(value_array[6]) + "+" + rational_to_string(value_array[3]) + ")" + ")" + "+" + rational_to_string(value_array[0]) + "+" + rational_to_string(value_array[0]) + "-" + rational_to_string(value_array[5]) + "-" + rational_to_string(value_array[3]) + "+" + rational_to_string(value_array[7]) + ")" + ")" + "*" + "(" + rational_to_string(value_array[1]) + ")";
}
bool check_input_expr6(const std::vector<double> &value_array)
{
    if (((value_array[4]) * (value_array[2])) * (value_array[6] + value_array[3]) == 0)
        return false;
    if (((value_array[6]) * (value_array[4]) - value_array[2] - value_array[7]) / (((value_array[4]) * (value_array[2])) * (value_array[6] + value_array[3])) + value_array[0] + value_array[0] - value_array[5] - value_array[3] + value_array[7] == 0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> expr6_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int expr6_variable_count = 8;

// Generated function strings for expr7
template <class T>
inline T expr7(const std::vector<T> &value_array)
{
    return (value_array[2]) / (((value_array[1]) / (value_array[3] + value_array[4]) + value_array[0] - value_array[2] + (value_array[1]) / (value_array[3])) * (value_array[6]) + value_array[5]);
}
std::string print_expr7(const std::vector<gmp::Rational> &value_array)
{
    return std::string() + "(" + rational_to_string(value_array[2]) + ")" + "/" + "(" + "(" + "(" + rational_to_string(value_array[1]) + ")" + "/" + "(" + rational_to_string(value_array[3]) + "+" + rational_to_string(value_array[4]) + ")" + "+" + rational_to_string(value_array[0]) + "-" + rational_to_string(value_array[2]) + "+" + "(" + rational_to_string(value_array[1]) + ")" + "/" + "(" + rational_to_string(value_array[3]) + ")" + ")" + "*" + "(" + rational_to_string(value_array[6]) + ")" + "+" + rational_to_string(value_array[5]) + ")";
}
bool check_input_expr7(const std::vector<double> &value_array)
{
    if (value_array[3] + value_array[4] == 0)
        return false;
    if (value_array[3] == 0)
        return false;
    if (((value_array[1]) / (value_array[3] + value_array[4]) + value_array[0] - value_array[2] + (value_array[1]) / (value_array[3])) * (value_array[6]) + value_array[5] == 0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> expr7_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int expr7_variable_count = 7;

// Generated function strings for expr8
template <class T>
inline T expr8(const std::vector<T> &value_array)
{
    return ((value_array[5]) / ((value_array[7]) / (value_array[0] - ((value_array[2] + value_array[1]) * ((value_array[1]) * (value_array[3]))) * (value_array[3] - value_array[4])))) / (value_array[6]);
}
std::string print_expr8(const std::vector<gmp::Rational> &value_array)
{
    return std::string() + "(" + "(" + rational_to_string(value_array[5]) + ")" + "/" + "(" + "(" + rational_to_string(value_array[7]) + ")" + "/" + "(" + rational_to_string(value_array[0]) + "-" + "(" + "(" + rational_to_string(value_array[2]) + "+" + rational_to_string(value_array[1]) + ")" + "*" + "(" + "(" + rational_to_string(value_array[1]) + ")" + "*" + "(" + rational_to_string(value_array[3]) + ")" + ")" + ")" + "*" + "(" + rational_to_string(value_array[3]) + "-" + rational_to_string(value_array[4]) + ")" + ")" + ")" + ")" + "/" + "(" + rational_to_string(value_array[6]) + ")";
}
bool check_input_expr8(const std::vector<double> &value_array)
{
    if (value_array[0] - ((value_array[2] + value_array[1]) * ((value_array[1]) * (value_array[3]))) * (value_array[3] - value_array[4]) == 0)
        return false;
    if ((value_array[7]) / (value_array[0] - ((value_array[2] + value_array[1]) * ((value_array[1]) * (value_array[3]))) * (value_array[3] - value_array[4])) == 0)
        return false;
    if (value_array[6] == 0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> expr8_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int expr8_variable_count = 8;

// Generated function strings for expr9
template <class T>
inline T expr9(const std::vector<T> &value_array)
{
    return (value_array[0] - value_array[3] - (value_array[2]) * (value_array[5]) - value_array[7] + value_array[1]) * (value_array[3]) + (((((value_array[4]) * (value_array[1])) / (value_array[7] + value_array[6])) * ((value_array[6]) / (value_array[5]) - (value_array[1]) * (value_array[8]))) * (value_array[6])) * (((value_array[2] + value_array[7]) / ((value_array[4]) / (value_array[0])) + ((value_array[3]) * (value_array[8])) / (value_array[4] + value_array[7])) / (((value_array[6] - value_array[0]) / (value_array[2] + value_array[5])) / ((value_array[3]) / (value_array[1]) + (value_array[7]) * (value_array[1])))) - value_array[5] - ((value_array[0]) / (value_array[3])) * (value_array[2] + value_array[8]) + value_array[2] + ((value_array[8]) / (value_array[5] - value_array[4]) - (value_array[6]) / (value_array[2]) - value_array[0] - value_array[8]) / ((value_array[0]) / (value_array[4])) + value_array[8];
}
std::string print_expr9(const std::vector<gmp::Rational> &value_array)
{
    return std::string() + "(" + rational_to_string(value_array[0]) + "-" + rational_to_string(value_array[3]) + "-" + "(" + rational_to_string(value_array[2]) + ")" + "*" + "(" + rational_to_string(value_array[5]) + ")" + "-" + rational_to_string(value_array[7]) + "+" + rational_to_string(value_array[1]) + ")" + "*" + "(" + rational_to_string(value_array[3]) + ")" + "+" + "(" + "(" + "(" + "(" + "(" + rational_to_string(value_array[4]) + ")" + "*" + "(" + rational_to_string(value_array[1]) + ")" + ")" + "/" + "(" + rational_to_string(value_array[7]) + "+" + rational_to_string(value_array[6]) + ")" + ")" + "*" + "(" + "(" + rational_to_string(value_array[6]) + ")" + "/" + "(" + rational_to_string(value_array[5]) + ")" + "-" + "(" + rational_to_string(value_array[1]) + ")" + "*" + "(" + rational_to_string(value_array[8]) + ")" + ")" + ")" + "*" + "(" + rational_to_string(value_array[6]) + ")" + ")" + "*" + "(" + "(" + "(" + rational_to_string(value_array[2]) + "+" + rational_to_string(value_array[7]) + ")" + "/" + "(" + "(" + rational_to_string(value_array[4]) + ")" + "/" + "(" + rational_to_string(value_array[0]) + ")" + ")" + "+" + "(" + "(" + rational_to_string(value_array[3]) + ")" + "*" + "(" + rational_to_string(value_array[8]) + ")" + ")" + "/" + "(" + rational_to_string(value_array[4]) + "+" + rational_to_string(value_array[7]) + ")" + ")" + "/" + "(" + "(" + "(" + rational_to_string(value_array[6]) + "-" + rational_to_string(value_array[0]) + ")" + "/" + "(" + rational_to_string(value_array[2]) + "+" + rational_to_string(value_array[5]) + ")" + ")" + "/" + "(" + "(" + rational_to_string(value_array[3]) + ")" + "/" + "(" + rational_to_string(value_array[1]) + ")" + "+" + "(" + rational_to_string(value_array[7]) + ")" + "*" + "(" + rational_to_string(value_array[1]) + ")" + ")" + ")" + ")" + "-" + rational_to_string(value_array[5]) + "-" + "(" + "(" + rational_to_string(value_array[0]) + ")" + "/" + "(" + rational_to_string(value_array[3]) + ")" + ")" + "*" + "(" + rational_to_string(value_array[2]) + "+" + rational_to_string(value_array[8]) + ")" + "+" + rational_to_string(value_array[2]) + "+" + "(" + "(" + rational_to_string(value_array[8]) + ")" + "/" + "(" + rational_to_string(value_array[5]) + "-" + rational_to_string(value_array[4]) + ")" + "-" + "(" + rational_to_string(value_array[6]) + ")" + "/" + "(" + rational_to_string(value_array[2]) + ")" + "-" + rational_to_string(value_array[0]) + "-" + rational_to_string(value_array[8]) + ")" + "/" + "(" + "(" + rational_to_string(value_array[0]) + ")" + "/" + "(" + rational_to_string(value_array[4]) + ")" + ")" + "+" + rational_to_string(value_array[8]);
}
bool check_input_expr9(const std::vector<double> &value_array)
{
    if (value_array[7] + value_array[6] == 0)
        return false;
    if (value_array[5] == 0)
        return false;
    if (value_array[0] == 0)
        return false;
    if ((value_array[4]) / (value_array[0]) == 0)
        return false;
    if (value_array[4] + value_array[7] == 0)
        return false;
    if (value_array[2] + value_array[5] == 0)
        return false;
    if (value_array[1] == 0)
        return false;
    if ((value_array[3]) / (value_array[1]) + (value_array[7]) * (value_array[1]) == 0)
        return false;
    if (((value_array[6] - value_array[0]) / (value_array[2] + value_array[5])) / ((value_array[3]) / (value_array[1]) + (value_array[7]) * (value_array[1])) == 0)
        return false;
    if (value_array[3] == 0)
        return false;
    if (value_array[5] - value_array[4] == 0)
        return false;
    if (value_array[2] == 0)
        return false;
    if (value_array[4] == 0)
        return false;
    if ((value_array[0]) / (value_array[4]) == 0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> expr9_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int expr9_variable_count = 9;

// Generated function strings for expr10
template <class T>
inline T expr10(const std::vector<T> &value_array)
{
    return value_array[4] + (value_array[7] + value_array[2] + ((value_array[3]) * (value_array[0]) - (value_array[4]) * (value_array[7])) / (value_array[8] + value_array[8] + value_array[6])) * (((value_array[0] - value_array[3] - value_array[6] + (value_array[5]) / (value_array[1]) - (value_array[2]) / (value_array[2])) / (value_array[1])) / (value_array[5]));
}
std::string print_expr10(const std::vector<gmp::Rational> &value_array)
{
    return std::string() + rational_to_string(value_array[4]) + "+" + "(" + rational_to_string(value_array[7]) + "+" + rational_to_string(value_array[2]) + "+" + "(" + "(" + rational_to_string(value_array[3]) + ")" + "*" + "(" + rational_to_string(value_array[0]) + ")" + "-" + "(" + rational_to_string(value_array[4]) + ")" + "*" + "(" + rational_to_string(value_array[7]) + ")" + ")" + "/" + "(" + rational_to_string(value_array[8]) + "+" + rational_to_string(value_array[8]) + "+" + rational_to_string(value_array[6]) + ")" + ")" + "*" + "(" + "(" + "(" + rational_to_string(value_array[0]) + "-" + rational_to_string(value_array[3]) + "-" + rational_to_string(value_array[6]) + "+" + "(" + rational_to_string(value_array[5]) + ")" + "/" + "(" + rational_to_string(value_array[1]) + ")" + "-" + "(" + rational_to_string(value_array[2]) + ")" + "/" + "(" + rational_to_string(value_array[2]) + ")" + ")" + "/" + "(" + rational_to_string(value_array[1]) + ")" + ")" + "/" + "(" + rational_to_string(value_array[5]) + ")" + ")";
}
bool check_input_expr10(const std::vector<double> &value_array)
{
    if (value_array[8] + value_array[8] + value_array[6] == 0)
        return false;
    if (value_array[1] == 0)
        return false;
    if (value_array[2] == 0)
        return false;
    if (value_array[5] == 0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> expr10_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int expr10_variable_count = 9;

template <class T>
inline T square_root(const std::vector<T> &value_array)
{
    return sqrt(value_array[0]);
}
std::string print_square_root(const std::vector<gmp::Rational> &value_array)
{
    return "Sqrt" + rational_to_string(value_array[0]);
}
bool check_input_square_root(const std::vector<double> &value_array)
{
    if (value_array[0] < 0)
        return false;
    return true;
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
bool check_input_exponential(const std::vector<double> &value_array)
{
    if (value_array[0] > 700)
        return false;
    return true;
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
bool check_input_sin(const std::vector<double> &value_array)
{
    return true;
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
bool check_input_cos(const std::vector<double> &value_array)
{
    return true;
}

// Generated function strings for extra_function1
template <class T>
inline T extra_function1(const std::vector<T> &value_array)
{
    return cos((cos(cos(value_array[5]) + exp((value_array[3]) / (value_array[2])))) * (sin(sqrt(value_array[4]) + value_array[0] + value_array[1] - sqrt(value_array[3] + value_array[2]))));
}
std::string print_extra_function1(const std::vector<gmp::Rational> &value_array)
{
    return std::string() + "cos" + "(" + "(" + "cos" + "(" + "cos" + "(" + rational_to_string(value_array[5]) + ")" + "+" + "Exp" + "(" + "(" + rational_to_string(value_array[3]) + ")" + "/" + "(" + rational_to_string(value_array[2]) + ")" + ")" + ")" + ")" + "*" + "(" + "sin" + "(" + "Sqrt" + "(" + rational_to_string(value_array[4]) + ")" + "+" + rational_to_string(value_array[0]) + "+" + rational_to_string(value_array[1]) + "-" + "Sqrt" + "(" + rational_to_string(value_array[3]) + "+" + rational_to_string(value_array[2]) + ")" + ")" + ")" + ")";
}
bool check_input_extra_function1(const std::vector<double> &value_array)
{
    if (value_array[2] == 0)
        return false;
    if ((value_array[3]) / (value_array[2]) < -700)
        return false;
    if ((value_array[3]) / (value_array[2]) > 700)
        return false;
    if (value_array[4] < 0)
        return false;
    if (value_array[3] + value_array[2] < 0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> extra_function1_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(0, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int extra_function1_variable_count = 6;

// Generated function strings for extra_function2
template <class T>
inline T extra_function2(const std::vector<T> &value_array)
{
    return exp(sqrt(exp(sqrt(exp(sqrt(value_array[3]))))));
}
std::string print_extra_function2(const std::vector<gmp::Rational> &value_array)
{
    return std::string() + "Exp" + "(" + "Sqrt" + "(" + "Exp" + "(" + "Sqrt" + "(" + "Exp" + "(" + "Sqrt" + "(" + rational_to_string(value_array[3]) + ")" + ")" + ")" + ")" + ")" + ")";
}
bool check_input_extra_function2(const std::vector<double> &value_array)
{
    if (value_array[3] < 0)
        return false;
    if (sqrt(value_array[3]) > 700)
        return false;
    if (sqrt(exp(sqrt(value_array[3]))) > 700)
        return false;
    if (sqrt(exp(sqrt(exp(sqrt(value_array[3]))))) > 700)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> extra_function2_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(0, 49000), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int extra_function2_variable_count = 6;

// Generated function strings for extra_function3
template <class T>
inline T extra_function3(const std::vector<T> &value_array)
{
    return ((sqrt(sqrt(value_array[2])) - sqrt(value_array[0]) - sin(sin(value_array[3]))) / (sqrt((sin(value_array[5])) * ((value_array[2]) / (value_array[0]))) + value_array[5])) * (cos(value_array[4] + value_array[3] + value_array[1]) - exp(cos((value_array[4]) / (value_array[3]))) - value_array[1]);
}
std::string print_extra_function3(const std::vector<gmp::Rational> &value_array)
{
    return std::string() + "(" + "(" + "Sqrt" + "(" + "Sqrt" + "(" + rational_to_string(value_array[2]) + ")" + ")" + "-" + "Sqrt" + "(" + rational_to_string(value_array[0]) + ")" + "-" + "sin" + "(" + "sin" + "(" + rational_to_string(value_array[3]) + ")" + ")" + ")" + "/" + "(" + "Sqrt" + "(" + "(" + "sin" + "(" + rational_to_string(value_array[5]) + ")" + ")" + "*" + "(" + "(" + rational_to_string(value_array[2]) + ")" + "/" + "(" + rational_to_string(value_array[0]) + ")" + ")" + ")" + "+" + rational_to_string(value_array[5]) + ")" + ")" + "*" + "(" + "cos" + "(" + rational_to_string(value_array[4]) + "+" + rational_to_string(value_array[3]) + "+" + rational_to_string(value_array[1]) + ")" + "-" + "Exp" + "(" + "cos" + "(" + "(" + rational_to_string(value_array[4]) + ")" + "/" + "(" + rational_to_string(value_array[3]) + ")" + ")" + ")" + "-" + rational_to_string(value_array[1]) + ")";
}
bool check_input_extra_function3(const std::vector<double> &value_array)
{
    if (value_array[2] < 0)
        return false;
    if (value_array[0] < 0)
        return false;
    if (value_array[0] == 0)
        return false;
    if ((sin(value_array[5])) * ((value_array[2]) / (value_array[0])) < 0)
        return false;
    if (sqrt((sin(value_array[5])) * ((value_array[2]) / (value_array[0]))) + value_array[5] == 0)
        return false;
    if (value_array[3] == 0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> extra_function3_range = {std::uniform_real_distribution<double>(0, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(0, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int extra_function3_variable_count = 6;

// Generated function strings for extra_function4
template <class T>
inline T extra_function4(const std::vector<T> &value_array)
{
    return sin(sin(((value_array[7]) / (value_array[6]) + (value_array[3]) / (value_array[5])) * (((value_array[1]) * (value_array[4])) / (value_array[0]))) - cos(sqrt(cos(cos(value_array[2]))))) + sqrt((sqrt(sqrt(sqrt(value_array[6] + value_array[5])))) / (sqrt(value_array[2])));
}
std::string print_extra_function4(const std::vector<gmp::Rational> &value_array)
{
    return std::string() + "sin" + "(" + "sin" + "(" + "(" + "(" + rational_to_string(value_array[7]) + ")" + "/" + "(" + rational_to_string(value_array[6]) + ")" + "+" + "(" + rational_to_string(value_array[3]) + ")" + "/" + "(" + rational_to_string(value_array[5]) + ")" + ")" + "*" + "(" + "(" + "(" + rational_to_string(value_array[1]) + ")" + "*" + "(" + rational_to_string(value_array[4]) + ")" + ")" + "/" + "(" + rational_to_string(value_array[0]) + ")" + ")" + ")" + "-" + "cos" + "(" + "Sqrt" + "(" + "cos" + "(" + "cos" + "(" + rational_to_string(value_array[2]) + ")" + ")" + ")" + ")" + ")" + "+" + "Sqrt" + "(" + "(" + "Sqrt" + "(" + "Sqrt" + "(" + "Sqrt" + "(" + rational_to_string(value_array[6]) + "+" + rational_to_string(value_array[5]) + ")" + ")" + ")" + ")" + "/" + "(" + "Sqrt" + "(" + rational_to_string(value_array[2]) + ")" + ")" + ")";
}
bool check_input_extra_function4(const std::vector<double> &value_array)
{
    if (value_array[6] == 0)
        return false;
    if (value_array[5] == 0)
        return false;
    if (value_array[0] == 0)
        return false;
    if (cos(cos(value_array[2])) < 0)
        return false;
    if (value_array[6] + value_array[5] < 0)
        return false;
    if (value_array[2] < 0)
        return false;
    if (sqrt(value_array[2]) == 0)
        return false;
    if ((sqrt(sqrt(sqrt(value_array[6] + value_array[5])))) / (sqrt(value_array[2])) < 0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> extra_function4_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(0, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int extra_function4_variable_count = 8;

// Generated function strings for extra_function5
template <class T>
inline T extra_function5(const std::vector<T> &value_array)
{
    return sin(cos(sin(cos(value_array[2]))) + ((value_array[3]) / (value_array[0])) / ((value_array[3]) / (value_array[1])) - value_array[1] - sqrt(cos(cos(value_array[6]))) + value_array[0]) - (cos(sqrt((value_array[4]) / (value_array[7])) + sqrt((value_array[2]) * (value_array[5])) - value_array[7])) * (sin((cos(sin(value_array[6]))) * (value_array[5])) + sin((sin(value_array[0] - value_array[7])) / (value_array[6] - value_array[4])));
}
std::string print_extra_function5(const std::vector<gmp::Rational> &value_array)
{
    return std::string() + "sin" + "(" + "cos" + "(" + "sin" + "(" + "cos" + "(" + rational_to_string(value_array[2]) + ")" + ")" + ")" + "+" + "(" + "(" + rational_to_string(value_array[3]) + ")" + "/" + "(" + rational_to_string(value_array[0]) + ")" + ")" + "/" + "(" + "(" + rational_to_string(value_array[3]) + ")" + "/" + "(" + rational_to_string(value_array[1]) + ")" + ")" + "-" + rational_to_string(value_array[1]) + "-" + "Sqrt" + "(" + "cos" + "(" + "cos" + "(" + rational_to_string(value_array[6]) + ")" + ")" + ")" + "+" + rational_to_string(value_array[0]) + ")" + "-" + "(" + "cos" + "(" + "Sqrt" + "(" + "(" + rational_to_string(value_array[4]) + ")" + "/" + "(" + rational_to_string(value_array[7]) + ")" + ")" + "+" + "Sqrt" + "(" + "(" + rational_to_string(value_array[2]) + ")" + "*" + "(" + rational_to_string(value_array[5]) + ")" + ")" + "-" + rational_to_string(value_array[7]) + ")" + ")" + "*" + "(" + "sin" + "(" + "(" + "cos" + "(" + "sin" + "(" + rational_to_string(value_array[6]) + ")" + ")" + ")" + "*" + "(" + rational_to_string(value_array[5]) + ")" + ")" + "+" + "sin" + "(" + "(" + "sin" + "(" + rational_to_string(value_array[0]) + "-" + rational_to_string(value_array[7]) + ")" + ")" + "/" + "(" + rational_to_string(value_array[6]) + "-" + rational_to_string(value_array[4]) + ")" + ")" + ")";
}
bool check_input_extra_function5(const std::vector<double> &value_array)
{
    if (value_array[0] == 0)
        return false;
    if (value_array[1] == 0)
        return false;
    if ((value_array[3]) / (value_array[1]) == 0)
        return false;
    if (cos(cos(value_array[6])) < 0)
        return false;
    if (value_array[7] == 0)
        return false;
    if ((value_array[4]) / (value_array[7]) < 0)
        return false;
    if ((value_array[2]) * (value_array[5]) < 0)
        return false;
    if (value_array[6] - value_array[4] == 0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> extra_function5_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int extra_function5_variable_count = 8;

// Generated function strings for extra_function6
template <class T>
inline T extra_function6(const std::vector<T> &value_array)
{
    return cos((sin(value_array[6]) - (sin(value_array[8] + value_array[3]) + sin((value_array[0]) * (value_array[7]))) * ((cos(value_array[8])) * (value_array[1]))) * (value_array[5] - (value_array[4]) * ((value_array[1]) * (value_array[2])) - (value_array[7]) * (value_array[0]) - cos(value_array[3]) - (cos(sin(value_array[5]))) * (value_array[2] - value_array[1] - sin(value_array[8])) + (cos(value_array[4] - value_array[6])) * (value_array[3] + value_array[0] - value_array[5])) - ((value_array[1]) * (value_array[6]) + (value_array[4]) * (value_array[5]) - value_array[6] - sin(value_array[8])) * (value_array[0]) - (cos(cos(value_array[2]))) * (sin(value_array[7]) - value_array[4] + value_array[1]) + value_array[4] + cos(sin(sin(cos((value_array[6]) * (value_array[3])))))) - value_array[2] + (value_array[3]) * (sin(sin(cos(value_array[7]))));
}
std::string print_extra_function6(const std::vector<gmp::Rational> &value_array)
{
    return std::string() + "cos" + "(" + "(" + "sin" + "(" + rational_to_string(value_array[6]) + ")" + "-" + "(" + "sin" + "(" + rational_to_string(value_array[8]) + "+" + rational_to_string(value_array[3]) + ")" + "+" + "sin" + "(" + "(" + rational_to_string(value_array[0]) + ")" + "*" + "(" + rational_to_string(value_array[7]) + ")" + ")" + ")" + "*" + "(" + "(" + "cos" + "(" + rational_to_string(value_array[8]) + ")" + ")" + "*" + "(" + rational_to_string(value_array[1]) + ")" + ")" + ")" + "*" + "(" + rational_to_string(value_array[5]) + "-" + "(" + rational_to_string(value_array[4]) + ")" + "*" + "(" + "(" + rational_to_string(value_array[1]) + ")" + "*" + "(" + rational_to_string(value_array[2]) + ")" + ")" + "-" + "(" + rational_to_string(value_array[7]) + ")" + "*" + "(" + rational_to_string(value_array[0]) + ")" + "-" + "cos" + "(" + rational_to_string(value_array[3]) + ")" + "-" + "(" + "cos" + "(" + "sin" + "(" + rational_to_string(value_array[5]) + ")" + ")" + ")" + "*" + "(" + rational_to_string(value_array[2]) + "-" + rational_to_string(value_array[1]) + "-" + "sin" + "(" + rational_to_string(value_array[8]) + ")" + ")" + "+" + "(" + "cos" + "(" + rational_to_string(value_array[4]) + "-" + rational_to_string(value_array[6]) + ")" + ")" + "*" + "(" + rational_to_string(value_array[3]) + "+" + rational_to_string(value_array[0]) + "-" + rational_to_string(value_array[5]) + ")" + ")" + "-" + "(" + "(" + rational_to_string(value_array[1]) + ")" + "*" + "(" + rational_to_string(value_array[6]) + ")" + "+" + "(" + rational_to_string(value_array[4]) + ")" + "*" + "(" + rational_to_string(value_array[5]) + ")" + "-" + rational_to_string(value_array[6]) + "-" + "sin" + "(" + rational_to_string(value_array[8]) + ")" + ")" + "*" + "(" + rational_to_string(value_array[0]) + ")" + "-" + "(" + "cos" + "(" + "cos" + "(" + rational_to_string(value_array[2]) + ")" + ")" + ")" + "*" + "(" + "sin" + "(" + rational_to_string(value_array[7]) + ")" + "-" + rational_to_string(value_array[4]) + "+" + rational_to_string(value_array[1]) + ")" + "+" + rational_to_string(value_array[4]) + "+" + "cos" + "(" + "sin" + "(" + "sin" + "(" + "cos" + "(" + "(" + rational_to_string(value_array[6]) + ")" + "*" + "(" + rational_to_string(value_array[3]) + ")" + ")" + ")" + ")" + ")" + ")" + "-" + rational_to_string(value_array[2]) + "+" + "(" + rational_to_string(value_array[3]) + ")" + "*" + "(" + "sin" + "(" + "sin" + "(" + "cos" + "(" + rational_to_string(value_array[7]) + ")" + ")" + ")" + ")";
}
bool check_input_extra_function6(const std::vector<double> &value_array)
{
    return true;
}
const std::vector<std::uniform_real_distribution<double>> extra_function6_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int extra_function6_variable_count = 9;

// Generated function strings for extra_function7
template <class T>
inline T extra_function7(const std::vector<T> &value_array)
{
    return (exp(cos((value_array[5]) / (value_array[0]))) + ((cos(value_array[3])) * (sin(value_array[2]))) / (sqrt(exp(value_array[7]))) - exp(exp((value_array[4]) / (value_array[6]))) - sin(sin(value_array[1])) + (exp(value_array[7])) * (cos(value_array[2]))) / ((value_array[1]) * (value_array[6]));
}
std::string print_extra_function7(const std::vector<gmp::Rational> &value_array)
{
    return std::string() + "(" + "Exp" + "(" + "cos" + "(" + "(" + rational_to_string(value_array[5]) + ")" + "/" + "(" + rational_to_string(value_array[0]) + ")" + ")" + ")" + "+" + "(" + "(" + "cos" + "(" + rational_to_string(value_array[3]) + ")" + ")" + "*" + "(" + "sin" + "(" + rational_to_string(value_array[2]) + ")" + ")" + ")" + "/" + "(" + "Sqrt" + "(" + "Exp" + "(" + rational_to_string(value_array[7]) + ")" + ")" + ")" + "-" + "Exp" + "(" + "Exp" + "(" + "(" + rational_to_string(value_array[4]) + ")" + "/" + "(" + rational_to_string(value_array[6]) + ")" + ")" + ")" + "-" + "sin" + "(" + "sin" + "(" + rational_to_string(value_array[1]) + ")" + ")" + "+" + "(" + "Exp" + "(" + rational_to_string(value_array[7]) + ")" + ")" + "*" + "(" + "cos" + "(" + rational_to_string(value_array[2]) + ")" + ")" + ")" + "/" + "(" + "(" + rational_to_string(value_array[1]) + ")" + "*" + "(" + rational_to_string(value_array[6]) + ")" + ")";
}
bool check_input_extra_function7(const std::vector<double> &value_array)
{
    if (value_array[0] == 0)
        return false;
    if (value_array[7] < -700)
        return false;
    if (value_array[7] > 700)
        return false;
    if (sqrt(exp(value_array[7])) == 0)
        return false;
    if (value_array[6] == 0)
        return false;
    if ((value_array[4]) / (value_array[6]) < -700)
        return false;
    if ((value_array[4]) / (value_array[6]) > 700)
        return false;
    if (exp((value_array[4]) / (value_array[6])) > 700)
        return false;
    if ((value_array[1]) * (value_array[6]) == 0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> extra_function7_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-700, 700)};
const int extra_function7_variable_count = 8;

// Generated function strings for extra_function8
template <class T>
inline T extra_function8(const std::vector<T> &value_array)
{
    return exp((sin(value_array[5]) - cos(value_array[0] + cos(value_array[3]))) / (value_array[4]));
}
std::string print_extra_function8(const std::vector<gmp::Rational> &value_array)
{
    return std::string() + "Exp" + "(" + "(" + "sin" + "(" + rational_to_string(value_array[5]) + ")" + "-" + "cos" + "(" + rational_to_string(value_array[0]) + "+" + "cos" + "(" + rational_to_string(value_array[3]) + ")" + ")" + ")" + "/" + "(" + rational_to_string(value_array[4]) + ")" + ")";
}
bool check_input_extra_function8(const std::vector<double> &value_array)
{
    if (value_array[4] == 0)
        return false;
    if ((sin(value_array[5]) - cos(value_array[0] + cos(value_array[3]))) / (value_array[4]) < -700)
        return false;
    if ((sin(value_array[5]) - cos(value_array[0] + cos(value_array[3]))) / (value_array[4]) > 700)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> extra_function8_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int extra_function8_variable_count = 6;

// Generated function strings for extra_function9
template <class T>
inline T extra_function9(const std::vector<T> &value_array)
{
    return exp((sqrt((exp(cos((value_array[0]) / (value_array[3])))) / (exp(cos(sqrt(value_array[5])))))) / (sqrt((cos(cos(cos(value_array[2])))) / (sqrt(sin(cos(value_array[1])))))));
}
std::string print_extra_function9(const std::vector<gmp::Rational> &value_array)
{
    return std::string() + "Exp" + "(" + "(" + "Sqrt" + "(" + "(" + "Exp" + "(" + "cos" + "(" + "(" + rational_to_string(value_array[0]) + ")" + "/" + "(" + rational_to_string(value_array[3]) + ")" + ")" + ")" + ")" + "/" + "(" + "Exp" + "(" + "cos" + "(" + "Sqrt" + "(" + rational_to_string(value_array[5]) + ")" + ")" + ")" + ")" + ")" + ")" + "/" + "(" + "Sqrt" + "(" + "(" + "cos" + "(" + "cos" + "(" + "cos" + "(" + rational_to_string(value_array[2]) + ")" + ")" + ")" + ")" + "/" + "(" + "Sqrt" + "(" + "sin" + "(" + "cos" + "(" + rational_to_string(value_array[1]) + ")" + ")" + ")" + ")" + ")" + ")" + ")";
}
bool check_input_extra_function9(const std::vector<double> &value_array)
{
    if (value_array[3] == 0)
        return false;
    if (value_array[5] < 0)
        return false;
    if (exp(cos(sqrt(value_array[5]))) == 0)
        return false;
    if ((exp(cos((value_array[0]) / (value_array[3])))) / (exp(cos(sqrt(value_array[5])))) < 0)
        return false;
    if (sin(cos(value_array[1])) < 0)
        return false;
    if (sqrt(sin(cos(value_array[1]))) == 0)
        return false;
    if ((cos(cos(cos(value_array[2])))) / (sqrt(sin(cos(value_array[1])))) < 0)
        return false;
    if (sqrt((cos(cos(cos(value_array[2])))) / (sqrt(sin(cos(value_array[1]))))) == 0)
        return false;
    if ((sqrt((exp(cos((value_array[0]) / (value_array[3])))) / (exp(cos(sqrt(value_array[5])))))) / (sqrt((cos(cos(cos(value_array[2])))) / (sqrt(sin(cos(value_array[1])))))) < -700)
        return false;
    if ((sqrt((exp(cos((value_array[0]) / (value_array[3])))) / (exp(cos(sqrt(value_array[5])))))) / (sqrt((cos(cos(cos(value_array[2])))) / (sqrt(sin(cos(value_array[1])))))) > 700)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> extra_function9_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(0, RAND_MAX)};
const int extra_function9_variable_count = 6;

// Generated function strings for extra_function10
template <class T>
inline T extra_function10(const std::vector<T> &value_array)
{
    return sqrt(sin(value_array[5])-(cos((cos(value_array[6])) * (cos(value_array[3]))+sqrt(value_array[1])-cos(value_array[0]))) * (value_array[4])+(sqrt(cos(value_array[6]))+sqrt((value_array[3]) * (value_array[4]))) * ((value_array[5]-value_array[0]+cos(value_array[2])) * (sqrt(value_array[2])))-((sqrt(sqrt(value_array[1]))) * (sin(sin(value_array[1])))) * ((value_array[4]+value_array[2]+value_array[0]-value_array[5]) * (cos(value_array[6]+value_array[3]))));
}
std::string print_extra_function10(const std::vector<gmp::Rational> &value_array)
{
    return std::string() + "Sqrt" + "(" + "sin" + "(" + rational_to_string(value_array[5]) + ")" + "-" + "(" + "cos" + "(" + "(" + "cos" + "(" + rational_to_string(value_array[6]) + ")" + ")" + "*" + "(" + "cos" + "(" + rational_to_string(value_array[3]) + ")"+ ")" + "+" + "Sqrt" + "(" + rational_to_string(value_array[1]) + ")" + "-" + "cos" + "(" + rational_to_string(value_array[0]) + ")" + ")" + ")" + "*" + "(" + rational_to_string(value_array[4])+ ")" + "+" + "(" + "Sqrt" + "(" + "cos" + "(" + rational_to_string(value_array[6]) + ")" + ")" + "+" + "Sqrt" + "(" + "(" + rational_to_string(value_array[3]) + ")" + "*" + "(" + rational_to_string(value_array[4])+ ")" + ")" + ")" + "*" + "(" + "(" + rational_to_string(value_array[5]) + "-" + rational_to_string(value_array[0]) + "+" + "cos" + "(" + rational_to_string(value_array[2]) + ")" + ")" + "*" + "(" + "Sqrt" + "(" + rational_to_string(value_array[2]) + ")"+ ")"+ ")" + "-" + "(" + "(" + "Sqrt" + "(" + "Sqrt" + "(" + rational_to_string(value_array[1]) + ")" + ")" + ")" + "*" + "(" + "sin" + "(" + "sin" + "(" + rational_to_string(value_array[1]) + ")" + ")"+ ")" + ")" + "*" + "(" + "(" + rational_to_string(value_array[4]) + "+" + rational_to_string(value_array[2]) + "+" + rational_to_string(value_array[0]) + "-" + rational_to_string(value_array[5]) + ")" + "*" + "(" + "cos" + "(" + rational_to_string(value_array[6]) + "+" + rational_to_string(value_array[3]) + ")"+ ")"+ ")" + ")";
}
bool check_input_extra_function10(const std::vector<double> &value_array)
{
    if (value_array[1] < 0)
        return false;
    if (cos(value_array[6]) < 0)
        return false;
    if ((value_array[3]) * (value_array[4]) < 0)
        return false;
    if (value_array[2] < 0)
        return false;
    if (sin(value_array[5])-(cos((cos(value_array[6])) * (cos(value_array[3]))+sqrt(value_array[1])-cos(value_array[0]))) * (value_array[4])+(sqrt(cos(value_array[6]))+sqrt((value_array[3]) * (value_array[4]))) * ((value_array[5]-value_array[0]+cos(value_array[2])) * (sqrt(value_array[2])))-((sqrt(sqrt(value_array[1]))) * (sin(sin(value_array[1])))) * ((value_array[4]+value_array[2]+value_array[0]-value_array[5]) * (cos(value_array[6]+value_array[3]))) < 0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> extra_function10_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(0, RAND_MAX), std::uniform_real_distribution<double>(0, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int extra_function10_variable_count = 7;