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
    return cos((cos(cos(value_array[5])+exp((value_array[3]) / (value_array[2])))) * (sin(sqrt(value_array[4])+value_array[0]+value_array[1]-sqrt(value_array[3]+value_array[2]))));
}
std::string print_extra_function1(const std::vector<gmp::Rational> &value_array)
{
    return std::string() + "cos" + "(" + "(" + "cos" + "(" + "cos" + "(" + rational_to_string(value_array[5]) + ")" + "+" + "Exp" + "(" + "(" + rational_to_string(value_array[3]) + ")" + "/" + "(" + rational_to_string(value_array[2])+ ")" + ")" + ")" + ")" + "*" + "(" + "sin" + "(" + "Sqrt" + "(" + rational_to_string(value_array[4]) + ")" + "+" + rational_to_string(value_array[0]) + "+" + rational_to_string(value_array[1]) + "-" + "Sqrt" + "(" + rational_to_string(value_array[3]) + "+" + rational_to_string(value_array[2]) + ")" + ")"+ ")" + ")";
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
    if (value_array[3]+value_array[2] < 0)
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
    return ((sqrt(sqrt(value_array[2]))-sqrt(value_array[0])-sin(sin(value_array[3]))) / (sqrt((sin(value_array[5])) * ((value_array[2]) / (value_array[0])))+value_array[5])) * (cos(value_array[4]+value_array[3]+value_array[1])-exp(cos((value_array[4]) / (value_array[3])))-value_array[1]);
}
std::string print_extra_function3(const std::vector<gmp::Rational> &value_array)
{
    return std::string() + "(" + "(" + "Sqrt" + "(" + "Sqrt" + "(" + rational_to_string(value_array[2]) + ")" + ")" + "-" + "Sqrt" + "(" + rational_to_string(value_array[0]) + ")" + "-" + "sin" + "(" + "sin" + "(" + rational_to_string(value_array[3]) + ")" + ")" + ")" + "/" + "(" + "Sqrt" + "(" + "(" + "sin" + "(" + rational_to_string(value_array[5]) + ")" + ")" + "*" + "(" + "(" + rational_to_string(value_array[2]) + ")" + "/" + "(" + rational_to_string(value_array[0])+ ")"+ ")" + ")" + "+" + rational_to_string(value_array[5])+ ")" + ")" + "*" + "(" + "cos" + "(" + rational_to_string(value_array[4]) + "+" + rational_to_string(value_array[3]) + "+" + rational_to_string(value_array[1]) + ")" + "-" + "Exp" + "(" + "cos" + "(" + "(" + rational_to_string(value_array[4]) + ")" + "/" + "(" + rational_to_string(value_array[3])+ ")" + ")" + ")" + "-" + rational_to_string(value_array[1])+ ")";
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
    if (sqrt((sin(value_array[5])) * ((value_array[2]) / (value_array[0])))+value_array[5] == 0)
        return false;
    if (value_array[3] == 0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> extra_function3_range = {std::uniform_real_distribution<double>(0, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(0, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int extra_function3_variable_count = 6;