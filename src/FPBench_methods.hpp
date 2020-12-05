#pragma once
#include "helper_functions.hpp"

// FPBench rigidBody2
template <class T>
inline T rigidBody2(const std::vector<T> &value_array)
{
	return ((((((2.0 * value_array[0]) * value_array[1]) * value_array[2]) + ((3.0 * value_array[2]) * value_array[2])) - (((value_array[1] * value_array[0]) * value_array[1]) * value_array[2])) + ((3.0 * value_array[2]) * value_array[2])) - value_array[1];
}
std::string print_rigidBody2(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(((((((2) * " + "(" + rational_to_string(v[0]) + ")" + ") * " + "(" + rational_to_string(v[1]) + ")" + ") * " + "(" + rational_to_string(v[2]) + ")" + ") + (((3) * " + "(" + rational_to_string(v[2]) + ")" + ") * " + "(" + rational_to_string(v[2]) + ")" + ")) - (((" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[0]) + ")" + ") * " + "(" + rational_to_string(v[1]) + ")" + ") * " + "(" + rational_to_string(v[2]) + ")" + ")) + (((3) * " + "(" + rational_to_string(v[2]) + ")" + ") * " + "(" + rational_to_string(v[2]) + ")" + ")) - " + "(" + rational_to_string(v[1]) + ")";
}
bool check_input_rigidBody2(const std::vector<double> &v)
{
    if (-15.0 > v[0])
        return false;
    if (v[0] > 15.0)
        return false;
    if (-15.0 > v[1])
        return false;
    if (v[1] > 15.0)
        return false;
    if (-15.0 > v[2])
        return false;
    if (v[2] > 15.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> rigidBody2_range = {std::uniform_real_distribution<double>(-15.0, 15.0), std::uniform_real_distribution<double>(-15.0, 15.0), std::uniform_real_distribution<double>(-15.0, 15.0)};
const int rigidBody2_variable_count = 3;


// FPBench triangle11
template <class T>
inline T triangle11(const std::vector<T> &value_array)
{
	return sqrt((((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[0])) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[1])) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[2]));
}
std::string print_triangle11(const std::vector<gmp::Rational> &v)
{
	return std::string() + "sqrt((((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[0]) + ")" + ")) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[1]) + ")" + ")) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[2]) + ")" + "))";
}
bool check_input_triangle11(const std::vector<double> &v)
{
    if (1.0 > v[0])
        return false;
    if (v[0] > 9.0)
        return false;
    if (1.0 > v[1])
        return false;
    if (v[1] > 9.0)
        return false;
    if (1.0 > v[2])
        return false;
    if (v[2] > 9.0)
        return false;
    if ((v[0] + v[1]) <= (v[2] + 1.0/100000000000))
        return false;
    if ((v[0] + v[2]) <= (v[1] + 1.0/100000000000))
        return false;
    if ((v[1] + v[2]) <= (v[0] + 1.0/100000000000))
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> triangle11_range = {std::uniform_real_distribution<double>(1.0, 9.0), std::uniform_real_distribution<double>(1.0, 9.0), std::uniform_real_distribution<double>(1.0, 9.0)};
const int triangle11_variable_count = 3;


// FPBench sine
template <class T>
inline T sine(const std::vector<T> &value_array)
{
	return ((value_array[0] - (((value_array[0] * value_array[0]) * value_array[0]) / 6.0)) + (((((value_array[0] * value_array[0]) * value_array[0]) * value_array[0]) * value_array[0]) / 120.0)) - (((((((value_array[0] * value_array[0]) * value_array[0]) * value_array[0]) * value_array[0]) * value_array[0]) * value_array[0]) / 5040.0);
}
std::string print_sine(const std::vector<gmp::Rational> &v)
{
	return std::string() + "((" + "(" + rational_to_string(v[0]) + ")" + " - (((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[0]) + ")" + ") * " + "(" + rational_to_string(v[0]) + ")" + ") / (6))) + (((((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[0]) + ")" + ") * " + "(" + rational_to_string(v[0]) + ")" + ") * " + "(" + rational_to_string(v[0]) + ")" + ") * " + "(" + rational_to_string(v[0]) + ")" + ") / (120))) - (((((((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[0]) + ")" + ") * " + "(" + rational_to_string(v[0]) + ")" + ") * " + "(" + rational_to_string(v[0]) + ")" + ") * " + "(" + rational_to_string(v[0]) + ")" + ") * " + "(" + rational_to_string(v[0]) + ")" + ") * " + "(" + rational_to_string(v[0]) + ")" + ") / (5040))";
}
bool check_input_sine(const std::vector<double> &v)
{
    if (-1.57079632679 >= v[0])
        return false;
    if (v[0] >= 1.57079632679)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> sine_range = {std::uniform_real_distribution<double>(-1.57079632679, 1.57079632679)};
const int sine_variable_count = 1;


// FPBench sum
template <class T>
inline T sum(const std::vector<T> &value_array)
{
	return (((value_array[0] + value_array[1]) - value_array[2]) + ((value_array[1] + value_array[2]) - value_array[0])) + ((value_array[2] + value_array[0]) - value_array[1]);
}
std::string print_sum(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") - " + "(" + rational_to_string(v[2]) + ")" + ") + ((" + "(" + rational_to_string(v[1]) + ")" + " + " + "(" + rational_to_string(v[2]) + ")" + ") - " + "(" + rational_to_string(v[0]) + ")" + ")) + ((" + "(" + rational_to_string(v[2]) + ")" + " + " + "(" + rational_to_string(v[0]) + ")" + ") - " + "(" + rational_to_string(v[1]) + ")" + ")";
}
bool check_input_sum(const std::vector<double> &v)
{
    if (1.0 > v[0])
        return false;
    if (v[0] > 2.0)
        return false;
    if (1.0 > v[1])
        return false;
    if (v[1] > 2.0)
        return false;
    if (1.0 > v[2])
        return false;
    if (v[2] > 2.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> sum_range = {std::uniform_real_distribution<double>(1.0, 2.0), std::uniform_real_distribution<double>(1.0, 2.0), std::uniform_real_distribution<double>(1.0, 2.0)};
const int sum_variable_count = 3;


// FPBench test05_nonlin1, r4
template <class T>
inline T test05_nonlin1_r4(const std::vector<T> &value_array)
{
	return (value_array[0] - 1.0) / ((value_array[0] * value_array[0]) - 1.0);
}
std::string print_test05_nonlin1_r4(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(" + "(" + rational_to_string(v[0]) + ")" + " - (1)) / ((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[0]) + ")" + ") - (1))";
}
bool check_input_test05_nonlin1_r4(const std::vector<double> &v)
{
    if (1.00001 >= v[0])
        return false;
    if (v[0] >= 2.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> test05_nonlin1_r4_range = {std::uniform_real_distribution<double>(1.00001, 2.0)};
const int test05_nonlin1_r4_variable_count = 1;


// FPBench hartman3
template <class T>
inline T hartman3(const std::vector<T> &value_array)
{
	return -((((1.0 * (exp(-(((3.0 * ((value_array[0] - 0.3689) * (value_array[0] - 0.3689))) + (10.0 * ((value_array[1] - 0.117) * (value_array[1] - 0.117)))) + (30.0 * ((value_array[2] - 0.2673) * (value_array[2] - 0.2673))))))) + (1.2 * (exp(-(((0.1 * ((value_array[0] - 0.4699) * (value_array[0] - 0.4699))) + (10.0 * ((value_array[1] - 0.4387) * (value_array[1] - 0.4387)))) + (35.0 * ((value_array[2] - 0.747) * (value_array[2] - 0.747)))))))) + (3.0 * (exp(-(((3.0 * ((value_array[0] - 0.1091) * (value_array[0] - 0.1091))) + (10.0 * ((value_array[1] - 0.8732) * (value_array[1] - 0.8732)))) + (30.0 * ((value_array[2] - 0.5547) * (value_array[2] - 0.5547)))))))) + (3.2 * (exp(-(((0.1 * ((value_array[0] - 0.03815) * (value_array[0] - 0.03815))) + (10.0 * ((value_array[1] - 0.5743) * (value_array[1] - 0.5743)))) + (35.0 * ((value_array[2] - 0.8828) * (value_array[2] - 0.8828))))))));
}
std::string print_hartman3(const std::vector<gmp::Rational> &v)
{
	return std::string() + "-(((((1) * (exp(-((((3) * ((" + "(" + rational_to_string(v[0]) + ")" + " - (3689/10000)) * (" + "(" + rational_to_string(v[0]) + ")" + " - (3689/10000)))) + ((10) * ((" + "(" + rational_to_string(v[1]) + ")" + " - (117/1000)) * (" + "(" + rational_to_string(v[1]) + ")" + " - (117/1000))))) + ((30) * ((" + "(" + rational_to_string(v[2]) + ")" + " - (2673/10000)) * (" + "(" + rational_to_string(v[2]) + ")" + " - (2673/10000)))))))) + ((6/5) * (exp(-((((1/10) * ((" + "(" + rational_to_string(v[0]) + ")" + " - (4699/10000)) * (" + "(" + rational_to_string(v[0]) + ")" + " - (4699/10000)))) + ((10) * ((" + "(" + rational_to_string(v[1]) + ")" + " - (4387/10000)) * (" + "(" + rational_to_string(v[1]) + ")" + " - (4387/10000))))) + ((35) * ((" + "(" + rational_to_string(v[2]) + ")" + " - (747/1000)) * (" + "(" + rational_to_string(v[2]) + ")" + " - (747/1000))))))))) + ((3) * (exp(-((((3) * ((" + "(" + rational_to_string(v[0]) + ")" + " - (1091/10000)) * (" + "(" + rational_to_string(v[0]) + ")" + " - (1091/10000)))) + ((10) * ((" + "(" + rational_to_string(v[1]) + ")" + " - (2183/2500)) * (" + "(" + rational_to_string(v[1]) + ")" + " - (2183/2500))))) + ((30) * ((" + "(" + rational_to_string(v[2]) + ")" + " - (5547/10000)) * (" + "(" + rational_to_string(v[2]) + ")" + " - (5547/10000))))))))) + ((16/5) * (exp(-((((1/10) * ((" + "(" + rational_to_string(v[0]) + ")" + " - (763/20000)) * (" + "(" + rational_to_string(v[0]) + ")" + " - (763/20000)))) + ((10) * ((" + "(" + rational_to_string(v[1]) + ")" + " - (5743/10000)) * (" + "(" + rational_to_string(v[1]) + ")" + " - (5743/10000))))) + ((35) * ((" + "(" + rational_to_string(v[2]) + ")" + " - (2207/2500)) * (" + "(" + rational_to_string(v[2]) + ")" + " - (2207/2500)))))))))";
}
bool check_input_hartman3(const std::vector<double> &v)
{
    if (0.0 > v[0])
        return false;
    if (v[0] > 1.0)
        return false;
    if (0.0 > v[1])
        return false;
    if (v[1] > 1.0)
        return false;
    if (0.0 > v[2])
        return false;
    if (v[2] > 1.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> hartman3_range = {std::uniform_real_distribution<double>(0.0, 1.0), std::uniform_real_distribution<double>(0.0, 1.0), std::uniform_real_distribution<double>(0.0, 1.0)};
const int hartman3_variable_count = 3;


// FPBench NMSE example 3.5
template <class T>
inline T NMSE_example_3_5(const std::vector<T> &value_array)
{
	return atan(value_array[0] + 1.0) - atan(value_array[0]);
}
std::string print_NMSE_example_3_5(const std::vector<gmp::Rational> &v)
{
	return std::string() + "atan(" + "(" + rational_to_string(v[0]) + ")" + " + (1)) - atan(" + "(" + rational_to_string(v[0]) + ")" + ")";
}
bool check_input_NMSE_example_3_5(const std::vector<double> &v)
{
    return true;
}
const std::vector<std::uniform_real_distribution<double>> NMSE_example_3_5_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int NMSE_example_3_5_variable_count = 1;


// FPBench Shoelace formula
template <class T>
inline T Shoelace_formula(const std::vector<T> &value_array)
{
	return 0.5 * ((((value_array[0] * value_array[3]) - (value_array[1] * value_array[2])) + ((value_array[2] * value_array[5]) - (value_array[3] * value_array[4]))) + ((value_array[4] * value_array[1]) - (value_array[5] * value_array[0])));
}
std::string print_Shoelace_formula(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(1/2) * ((((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[3]) + ")" + ") - (" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[2]) + ")" + ")) + ((" + "(" + rational_to_string(v[2]) + ")" + " * " + "(" + rational_to_string(v[5]) + ")" + ") - (" + "(" + rational_to_string(v[3]) + ")" + " * " + "(" + rational_to_string(v[4]) + ")" + "))) + ((" + "(" + rational_to_string(v[4]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ") - (" + "(" + rational_to_string(v[5]) + ")" + " * " + "(" + rational_to_string(v[0]) + ")" + ")))";
}
bool check_input_Shoelace_formula(const std::vector<double> &v)
{
    return true;
}
const std::vector<std::uniform_real_distribution<double>> Shoelace_formula_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int Shoelace_formula_variable_count = 6;


// FPBench NMSE example 3.10
template <class T>
inline T NMSE_example_3_10(const std::vector<T> &value_array)
{
	return log(1.0 - value_array[0]) / log(1.0 + value_array[0]);
}
std::string print_NMSE_example_3_10(const std::vector<gmp::Rational> &v)
{
	return std::string() + "log((1) - " + "(" + rational_to_string(v[0]) + ")" + ") / log((1) + " + "(" + rational_to_string(v[0]) + ")" + ")";
}
bool check_input_NMSE_example_3_10(const std::vector<double> &v)
{
    if (-1.0 >= v[0])
        return false;
    if (v[0] >= 1.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> NMSE_example_3_10_range = {std::uniform_real_distribution<double>(-1.0, 1.0)};
const int NMSE_example_3_10_variable_count = 1;


// FPBench x_by_xy
template <class T>
inline T x_by_xy(const std::vector<T> &value_array)
{
	return value_array[0] / (value_array[0] + value_array[1]);
}
std::string print_x_by_xy(const std::vector<gmp::Rational> &v)
{
	return std::string() + "" + "(" + rational_to_string(v[0]) + ")" + " / (" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ")";
}
bool check_input_x_by_xy(const std::vector<double> &v)
{
    if (1.0 > v[0])
        return false;
    if (v[0] > 4.0)
        return false;
    if (1.0 > v[1])
        return false;
    if (v[1] > 4.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> x_by_xy_range = {std::uniform_real_distribution<double>(1.0, 4.0), std::uniform_real_distribution<double>(1.0, 4.0)};
const int x_by_xy_variable_count = 2;


// FPBench NMSE section 3.11
template <class T>
inline T NMSE_section_3_11(const std::vector<T> &value_array)
{
	return exp(value_array[0]) / (exp(value_array[0]) - 1.0);
}
std::string print_NMSE_section_3_11(const std::vector<gmp::Rational> &v)
{
	return std::string() + "exp(" + "(" + rational_to_string(v[0]) + ")" + ") / (exp(" + "(" + rational_to_string(v[0]) + ")" + ") - (1))";
}
bool check_input_NMSE_section_3_11(const std::vector<double> &v)
{
    return true;
}
const std::vector<std::uniform_real_distribution<double>> NMSE_section_3_11_range = {std::uniform_real_distribution<double>(-700, 700)};
const int NMSE_section_3_11_variable_count = 1;


// FPBench NMSE problem 3.3.1
template <class T>
inline T NMSE_problem_3_3_1(const std::vector<T> &value_array)
{
	return (1.0 / (value_array[0] + 1.0)) - (1.0 / value_array[0]);
}
std::string print_NMSE_problem_3_3_1(const std::vector<gmp::Rational> &v)
{
	return std::string() + "((1) / (" + "(" + rational_to_string(v[0]) + ")" + " + (1))) - ((1) / " + "(" + rational_to_string(v[0]) + ")" + ")";
}
bool check_input_NMSE_problem_3_3_1(const std::vector<double> &v)
{
    return true;
}
const std::vector<std::uniform_real_distribution<double>> NMSE_problem_3_3_1_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int NMSE_problem_3_3_1_variable_count = 1;


// FPBench floudas2
template <class T>
inline T floudas2(const std::vector<T> &value_array)
{
	return -value_array[0] - value_array[1];
}
std::string print_floudas2(const std::vector<gmp::Rational> &v)
{
	return std::string() + "-" + "(" + rational_to_string(v[0]) + ")" + " - " + "(" + rational_to_string(v[1]) + ")";
}
bool check_input_floudas2(const std::vector<double> &v)
{
    if (0.0 > v[0])
        return false;
    if (v[0] > 3.0)
        return false;
    if (0.0 > v[1])
        return false;
    if (v[1] > 4.0)
        return false;
    if (((((2 * ((v[0] * v[0]) * (v[0] * v[0]))) - ((8 * (v[0] * v[0])) * v[0])) + ((8 * v[0]) * v[0])) - v[1]) < 0)
        return false;
    if (((((((4 * ((v[0] * v[0]) * (v[0] * v[0]))) - ((32 * (v[0] * v[0])) * v[0])) + ((88 * v[0]) * v[0])) - (96 * v[0])) + 36) - v[1]) < 0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> floudas2_range = {std::uniform_real_distribution<double>(0.0, 3.0), std::uniform_real_distribution<double>(0.0, 4.0)};
const int floudas2_variable_count = 2;


// FPBench test03_nonlin2
template <class T>
inline T test03_nonlin2(const std::vector<T> &value_array)
{
	return (value_array[0] + value_array[1]) / (value_array[0] - value_array[1]);
}
std::string print_test03_nonlin2(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") / (" + "(" + rational_to_string(v[0]) + ")" + " - " + "(" + rational_to_string(v[1]) + ")" + ")";
}
bool check_input_test03_nonlin2(const std::vector<double> &v)
{
    if (0.0 >= v[0])
        return false;
    if (v[0] >= 1.0)
        return false;
    if (-1.0 >= v[1])
        return false;
    if (v[1] >= -0.1)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> test03_nonlin2_range = {std::uniform_real_distribution<double>(0.0, 1.0), std::uniform_real_distribution<double>(-1.0, -0.1)};
const int test03_nonlin2_variable_count = 2;


// FPBench nonlin2
template <class T>
inline T nonlin2(const std::vector<T> &value_array)
{
	return ((value_array[0] * value_array[1]) - 1.0) / (((value_array[0] * value_array[1]) * (value_array[0] * value_array[1])) - 1.0);
}
std::string print_nonlin2(const std::vector<gmp::Rational> &v)
{
	return std::string() + "((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ") - (1)) / (((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ") * (" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ")) - (1))";
}
bool check_input_nonlin2(const std::vector<double> &v)
{
    if (1.001 > v[0])
        return false;
    if (v[0] > 2.0)
        return false;
    if (1.001 > v[1])
        return false;
    if (v[1] > 2.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> nonlin2_range = {std::uniform_real_distribution<double>(1.001, 2.0), std::uniform_real_distribution<double>(1.001, 2.0)};
const int nonlin2_variable_count = 2;


// FPBench Complex sine and cosine
template <class T>
inline T Complex_sine_and_cosine(const std::vector<T> &value_array)
{
	return (0.5 * sin(value_array[0])) * (exp(-value_array[1]) - exp(value_array[1]));
}
std::string print_Complex_sine_and_cosine(const std::vector<gmp::Rational> &v)
{
	return std::string() + "((1/2) * sin(" + "(" + rational_to_string(v[0]) + ")" + ")) * (exp(-" + "(" + rational_to_string(v[1]) + ")" + ") - exp(" + "(" + rational_to_string(v[1]) + ")" + "))";
}
bool check_input_Complex_sine_and_cosine(const std::vector<double> &v)
{
    return true;
}
const std::vector<std::uniform_real_distribution<double>> Complex_sine_and_cosine_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-700, 700)};
const int Complex_sine_and_cosine_variable_count = 2;


// FPBench floudas
template <class T>
inline T floudas(const std::vector<T> &value_array)
{
	return value_array[0] + value_array[1];
}
std::string print_floudas(const std::vector<gmp::Rational> &v)
{
	return std::string() + "" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")";
}
bool check_input_floudas(const std::vector<double> &v)
{
    if (0.0 > v[0])
        return false;
    if (v[0] > 2.0)
        return false;
    if (0.0 > v[1])
        return false;
    if (v[1] > 3.0)
        return false;
    if ((v[0] + v[1]) > 2)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> floudas_range = {std::uniform_real_distribution<double>(0.0, 2.0), std::uniform_real_distribution<double>(0.0, 3.0)};
const int floudas_variable_count = 2;


// FPBench NMSE problem 3.4.2
template <class T>
inline T NMSE_problem_3_4_2(const std::vector<T> &value_array)
{
	return (value_array[2] * (exp((value_array[0] + value_array[1]) * value_array[2]) - 1.0)) / ((exp(value_array[0] * value_array[2]) - 1.0) * (exp(value_array[1] * value_array[2]) - 1.0));
}
std::string print_NMSE_problem_3_4_2(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(" + "(" + rational_to_string(v[2]) + ")" + " * (exp((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") * " + "(" + rational_to_string(v[2]) + ")" + ") - (1))) / ((exp(" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[2]) + ")" + ") - (1)) * (exp(" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[2]) + ")" + ") - (1)))";
}
bool check_input_NMSE_problem_3_4_2(const std::vector<double> &v)
{
    return true;
}
const std::vector<std::uniform_real_distribution<double>> NMSE_problem_3_4_2_range = {std::uniform_real_distribution<double>(-12.5, 12.5), std::uniform_real_distribution<double>(-12.5, 12.5), std::uniform_real_distribution<double>(-25, 25)};
const int NMSE_problem_3_4_2_variable_count = 3;


// FPBench NMSE example 3.8
template <class T>
inline T NMSE_example_3_8(const std::vector<T> &value_array)
{
	return (((value_array[0] + 1.0) * log(value_array[0] + 1.0)) - (value_array[0] * log(value_array[0]))) - 1.0;
}
std::string print_NMSE_example_3_8(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(((" + "(" + rational_to_string(v[0]) + ")" + " + (1)) * log(" + "(" + rational_to_string(v[0]) + ")" + " + (1))) - (" + "(" + rational_to_string(v[0]) + ")" + " * log(" + "(" + rational_to_string(v[0]) + ")" + "))) - (1)";
}
bool check_input_NMSE_example_3_8(const std::vector<double> &v)
{
    return true;
}
const std::vector<std::uniform_real_distribution<double>> NMSE_example_3_8_range = {std::uniform_real_distribution<double>(0, RAND_MAX)};
const int NMSE_example_3_8_variable_count = 1;


// FPBench polarToCarthesian, x
template <class T>
inline T polarToCarthesian_x(const std::vector<T> &value_array)
{
	return value_array[0] * cos((value_array[1] * ((3.14159265359) / 180.0)));
}
std::string print_polarToCarthesian_x(const std::vector<gmp::Rational> &v)
{
	return std::string() + "" + "(" + rational_to_string(v[0]) + ")" + " * cos((" + "(" + rational_to_string(v[1]) + ")" + " * (((314159265359/100000000000)) / (180))))";
}
bool check_input_polarToCarthesian_x(const std::vector<double> &v)
{
    if (1.0 > v[0])
        return false;
    if (v[0] > 10.0)
        return false;
    if (0.0 > v[1])
        return false;
    if (v[1] > 360.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> polarToCarthesian_x_range = {std::uniform_real_distribution<double>(1.0, 10.0), std::uniform_real_distribution<double>(0.0, 360.0)};
const int polarToCarthesian_x_variable_count = 2;


// FPBench turbine1
template <class T>
inline T turbine1(const std::vector<T> &value_array)
{
	return ((3.0 + (2.0 / (value_array[2] * value_array[2]))) - (((0.125 * (3.0 - (2.0 * value_array[0]))) * (((value_array[1] * value_array[1]) * value_array[2]) * value_array[2])) / (1.0 - value_array[0]))) - 4.5;
}
std::string print_turbine1(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(((3) + ((2) / (" + "(" + rational_to_string(v[2]) + ")" + " * " + "(" + rational_to_string(v[2]) + ")" + "))) - ((((1/8) * ((3) - ((2) * " + "(" + rational_to_string(v[0]) + ")" + "))) * (((" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ") * " + "(" + rational_to_string(v[2]) + ")" + ") * " + "(" + rational_to_string(v[2]) + ")" + ")) / ((1) - " + "(" + rational_to_string(v[0]) + ")" + "))) - (9/2)";
}
bool check_input_turbine1(const std::vector<double> &v)
{
    if (-4.5 > v[0])
        return false;
    if (v[0] > -0.3)
        return false;
    if (0.4 > v[1])
        return false;
    if (v[1] > 0.9)
        return false;
    if (3.8 > v[2])
        return false;
    if (v[2] > 7.8)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> turbine1_range = {std::uniform_real_distribution<double>(-4.5, -0.3), std::uniform_real_distribution<double>(0.4, 0.9), std::uniform_real_distribution<double>(3.8, 7.8)};
const int turbine1_variable_count = 3;


// FPBench triangle9
template <class T>
inline T triangle9(const std::vector<T> &value_array)
{
	return sqrt((((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[0])) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[1])) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[2]));
}
std::string print_triangle9(const std::vector<gmp::Rational> &v)
{
	return std::string() + "sqrt((((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[0]) + ")" + ")) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[1]) + ")" + ")) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[2]) + ")" + "))";
}
bool check_input_triangle9(const std::vector<double> &v)
{
    if (1.0 > v[0])
        return false;
    if (v[0] > 9.0)
        return false;
    if (1.0 > v[1])
        return false;
    if (v[1] > 9.0)
        return false;
    if (1.0 > v[2])
        return false;
    if (v[2] > 9.0)
        return false;
    if ((v[0] + v[1]) <= (v[2] + 1.0/1000000000))
        return false;
    if ((v[0] + v[2]) <= (v[1] + 1.0/1000000000))
        return false;
    if ((v[1] + v[2]) <= (v[0] + 1.0/1000000000))
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> triangle9_range = {std::uniform_real_distribution<double>(1.0, 9.0), std::uniform_real_distribution<double>(1.0, 9.0), std::uniform_real_distribution<double>(1.0, 9.0)};
const int triangle9_variable_count = 3;


// FPBench sineOrder3
template <class T>
inline T sineOrder3(const std::vector<T> &value_array)
{
	return (0.954929658551372 * value_array[0]) - (0.12900613773279798 * ((value_array[0] * value_array[0]) * value_array[0]));
}
std::string print_sineOrder3(const std::vector<gmp::Rational> &v)
{
	return std::string() + "((238732414637843/250000000000000) * " + "(" + rational_to_string(v[0]) + ")" + ") - ((6450306886639899/50000000000000000) * ((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[0]) + ")" + ") * " + "(" + rational_to_string(v[0]) + ")" + "))";
}
bool check_input_sineOrder3(const std::vector<double> &v)
{
    if (-2.0 >= v[0])
        return false;
    if (v[0] >= 2.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> sineOrder3_range = {std::uniform_real_distribution<double>(-2.0, 2.0)};
const int sineOrder3_variable_count = 1;


// FPBench doppler3
template <class T>
inline T doppler3(const std::vector<T> &value_array)
{
	return (-(331.4 + (0.6 * value_array[2])) * value_array[1]) / (((331.4 + (0.6 * value_array[2])) + value_array[0]) * ((331.4 + (0.6 * value_array[2])) + value_array[0]));
}
std::string print_doppler3(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(-((1657/5) + ((3/5) * " + "(" + rational_to_string(v[2]) + ")" + ")) * " + "(" + rational_to_string(v[1]) + ")" + ") / ((((1657/5) + ((3/5) * " + "(" + rational_to_string(v[2]) + ")" + ")) + " + "(" + rational_to_string(v[0]) + ")" + ") * (((1657/5) + ((3/5) * " + "(" + rational_to_string(v[2]) + ")" + ")) + " + "(" + rational_to_string(v[0]) + ")" + "))";
}
bool check_input_doppler3(const std::vector<double> &v)
{
    if (-30.0 > v[0])
        return false;
    if (v[0] > 120.0)
        return false;
    if (320.0 > v[1])
        return false;
    if (v[1] > 20300.0)
        return false;
    if (-50.0 > v[2])
        return false;
    if (v[2] > 30.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> doppler3_range = {std::uniform_real_distribution<double>(-30.0, 120.0), std::uniform_real_distribution<double>(320.0, 20300.0), std::uniform_real_distribution<double>(-50.0, 30.0)};
const int doppler3_variable_count = 3;


// FPBench triangle1
template <class T>
inline T triangle1(const std::vector<T> &value_array)
{
	return sqrt((((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[0])) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[1])) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[2]));
}
std::string print_triangle1(const std::vector<gmp::Rational> &v)
{
	return std::string() + "sqrt((((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[0]) + ")" + ")) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[1]) + ")" + ")) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[2]) + ")" + "))";
}
bool check_input_triangle1(const std::vector<double> &v)
{
    if (1.0 > v[0])
        return false;
    if (v[0] > 9.0)
        return false;
    if (1.0 > v[1])
        return false;
    if (v[1] > 9.0)
        return false;
    if (1.0 > v[2])
        return false;
    if (v[2] > 9.0)
        return false;
    if ((v[0] + v[1]) <= (v[2] + 1.0/10))
        return false;
    if ((v[0] + v[2]) <= (v[1] + 1.0/10))
        return false;
    if ((v[1] + v[2]) <= (v[0] + 1.0/10))
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> triangle1_range = {std::uniform_real_distribution<double>(1.0, 9.0), std::uniform_real_distribution<double>(1.0, 9.0), std::uniform_real_distribution<double>(1.0, 9.0)};
const int triangle1_variable_count = 3;


// FPBench NMSE p42, negative
template <class T>
inline T NMSE_p42_negative(const std::vector<T> &value_array)
{
	return (-value_array[1] - sqrt((value_array[1] * value_array[1]) - (4.0 * (value_array[0] * value_array[2])))) / (2.0 * value_array[0]);
}
std::string print_NMSE_p42_negative(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(-" + "(" + rational_to_string(v[1]) + ")" + " - sqrt((" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ") - ((4) * (" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[2]) + ")" + ")))) / ((2) * " + "(" + rational_to_string(v[0]) + ")" + ")";
}
bool check_input_NMSE_p42_negative(const std::vector<double> &v)
{
    if ((v[1] * v[1]) < (4 * (v[0] * v[2])))
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> NMSE_p42_negative_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int NMSE_p42_negative_variable_count = 3;


// FPBench matrixDeterminant2
template <class T>
inline T matrixDeterminant2(const std::vector<T> &value_array)
{
	return ((value_array[0] * (value_array[4] * value_array[8])) + ((value_array[6] * (value_array[1] * value_array[5])) + (value_array[2] * (value_array[3] * value_array[7])))) - ((value_array[4] * (value_array[2] * value_array[6])) + ((value_array[8] * (value_array[1] * value_array[3])) + (value_array[0] * (value_array[5] * value_array[7]))));
}
std::string print_matrixDeterminant2(const std::vector<gmp::Rational> &v)
{
	return std::string() + "((" + "(" + rational_to_string(v[0]) + ")" + " * (" + "(" + rational_to_string(v[4]) + ")" + " * " + "(" + rational_to_string(v[8]) + ")" + ")) + ((" + "(" + rational_to_string(v[6]) + ")" + " * (" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[5]) + ")" + ")) + (" + "(" + rational_to_string(v[2]) + ")" + " * (" + "(" + rational_to_string(v[3]) + ")" + " * " + "(" + rational_to_string(v[7]) + ")" + ")))) - ((" + "(" + rational_to_string(v[4]) + ")" + " * (" + "(" + rational_to_string(v[2]) + ")" + " * " + "(" + rational_to_string(v[6]) + ")" + ")) + ((" + "(" + rational_to_string(v[8]) + ")" + " * (" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[3]) + ")" + ")) + (" + "(" + rational_to_string(v[0]) + ")" + " * (" + "(" + rational_to_string(v[5]) + ")" + " * " + "(" + rational_to_string(v[7]) + ")" + "))))";
}
bool check_input_matrixDeterminant2(const std::vector<double> &v)
{
    if (-10.0 > v[0])
        return false;
    if (v[0] > 10.0)
        return false;
    if (-10.0 > v[1])
        return false;
    if (v[1] > 10.0)
        return false;
    if (-10.0 > v[2])
        return false;
    if (v[2] > 10.0)
        return false;
    if (-10.0 > v[3])
        return false;
    if (v[3] > 10.0)
        return false;
    if (-10.0 > v[4])
        return false;
    if (v[4] > 10.0)
        return false;
    if (-10.0 > v[5])
        return false;
    if (v[5] > 10.0)
        return false;
    if (-10.0 > v[6])
        return false;
    if (v[6] > 10.0)
        return false;
    if (-10.0 > v[7])
        return false;
    if (v[7] > 10.0)
        return false;
    if (-10.0 > v[8])
        return false;
    if (v[8] > 10.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> matrixDeterminant2_range = {std::uniform_real_distribution<double>(-10.0, 10.0), std::uniform_real_distribution<double>(-10.0, 10.0), std::uniform_real_distribution<double>(-10.0, 10.0), std::uniform_real_distribution<double>(-10.0, 10.0), std::uniform_real_distribution<double>(-10.0, 10.0), std::uniform_real_distribution<double>(-10.0, 10.0), std::uniform_real_distribution<double>(-10.0, 10.0), std::uniform_real_distribution<double>(-10.0, 10.0), std::uniform_real_distribution<double>(-10.0, 10.0)};
const int matrixDeterminant2_variable_count = 9;


// FPBench delta
template <class T>
inline T delta(const std::vector<T> &value_array)
{
	return (((((((value_array[0] * value_array[3]) * (((((-value_array[0] + value_array[1]) + value_array[2]) - value_array[3]) + value_array[4]) + value_array[5])) + ((value_array[1] * value_array[4]) * (((((value_array[0] - value_array[1]) + value_array[2]) + value_array[3]) - value_array[4]) + value_array[5]))) + ((value_array[2] * value_array[5]) * (((((value_array[0] + value_array[1]) - value_array[2]) + value_array[3]) + value_array[4]) - value_array[5]))) + ((-value_array[1] * value_array[2]) * value_array[3])) + ((-value_array[0] * value_array[2]) * value_array[4])) + ((-value_array[0] * value_array[1]) * value_array[5])) + ((-value_array[3] * value_array[4]) * value_array[5]);
}
std::string print_delta(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(((((((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[3]) + ")" + ") * (((((-" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") - " + "(" + rational_to_string(v[3]) + ")" + ") + " + "(" + rational_to_string(v[4]) + ")" + ") + " + "(" + rational_to_string(v[5]) + ")" + ")) + ((" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[4]) + ")" + ") * (((((" + "(" + rational_to_string(v[0]) + ")" + " - " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") + " + "(" + rational_to_string(v[3]) + ")" + ") - " + "(" + rational_to_string(v[4]) + ")" + ") + " + "(" + rational_to_string(v[5]) + ")" + "))) + ((" + "(" + rational_to_string(v[2]) + ")" + " * " + "(" + rational_to_string(v[5]) + ")" + ") * (((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") - " + "(" + rational_to_string(v[2]) + ")" + ") + " + "(" + rational_to_string(v[3]) + ")" + ") + " + "(" + rational_to_string(v[4]) + ")" + ") - " + "(" + rational_to_string(v[5]) + ")" + "))) + ((-" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[2]) + ")" + ") * " + "(" + rational_to_string(v[3]) + ")" + ")) + ((-" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[2]) + ")" + ") * " + "(" + rational_to_string(v[4]) + ")" + ")) + ((-" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ") * " + "(" + rational_to_string(v[5]) + ")" + ")) + ((-" + "(" + rational_to_string(v[3]) + ")" + " * " + "(" + rational_to_string(v[4]) + ")" + ") * " + "(" + rational_to_string(v[5]) + ")" + ")";
}
bool check_input_delta(const std::vector<double> &v)
{
    if (4.0 > v[0])
        return false;
    if (v[0] > 6.3504)
        return false;
    if (4.0 > v[1])
        return false;
    if (v[1] > 6.3504)
        return false;
    if (4.0 > v[2])
        return false;
    if (v[2] > 6.3504)
        return false;
    if (4.0 > v[3])
        return false;
    if (v[3] > 6.3504)
        return false;
    if (4.0 > v[4])
        return false;
    if (v[4] > 6.3504)
        return false;
    if (4.0 > v[5])
        return false;
    if (v[5] > 6.3504)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> delta_range = {std::uniform_real_distribution<double>(4.0, 6.3504), std::uniform_real_distribution<double>(4.0, 6.3504), std::uniform_real_distribution<double>(4.0, 6.3504), std::uniform_real_distribution<double>(4.0, 6.3504), std::uniform_real_distribution<double>(4.0, 6.3504), std::uniform_real_distribution<double>(4.0, 6.3504)};
const int delta_variable_count = 6;


// FPBench test06_sums4, sum1
template <class T>
inline T test06_sums4_sum1(const std::vector<T> &value_array)
{
	return ((value_array[0] + value_array[1]) + value_array[2]) + value_array[3];
}
std::string print_test06_sums4_sum1(const std::vector<gmp::Rational> &v)
{
	return std::string() + "((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") + " + "(" + rational_to_string(v[3]) + ")";
}
bool check_input_test06_sums4_sum1(const std::vector<double> &v)
{
    if (-1e-05 >= v[0])
        return false;
    if (v[0] >= 1.00001)
        return false;
    if (0.0 >= v[1])
        return false;
    if (v[1] >= 1.0)
        return false;
    if (0.0 >= v[2])
        return false;
    if (v[2] >= 1.0)
        return false;
    if (0.0 >= v[3])
        return false;
    if (v[3] >= 1.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> test06_sums4_sum1_range = {std::uniform_real_distribution<double>(-1e-05, 1.00001), std::uniform_real_distribution<double>(0.0, 1.0), std::uniform_real_distribution<double>(0.0, 1.0), std::uniform_real_distribution<double>(0.0, 1.0)};
const int test06_sums4_sum1_variable_count = 4;


// FPBench sec4-example
template <class T>
inline T sec4_example(const std::vector<T> &value_array)
{
	return ((value_array[0] * value_array[1]) - 1.0) / (((value_array[0] * value_array[1]) * (value_array[0] * value_array[1])) - 1.0);
}
std::string print_sec4_example(const std::vector<gmp::Rational> &v)
{
	return std::string() + "((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ") - (1)) / (((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ") * (" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ")) - (1))";
}
bool check_input_sec4_example(const std::vector<double> &v)
{
    if (1.001 > v[0])
        return false;
    if (v[0] > 2.0)
        return false;
    if (1.001 > v[1])
        return false;
    if (v[1] > 2.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> sec4_example_range = {std::uniform_real_distribution<double>(1.001, 2.0), std::uniform_real_distribution<double>(1.001, 2.0)};
const int sec4_example_variable_count = 2;


// FPBench logexp
template <class T>
inline T logexp(const std::vector<T> &value_array)
{
	return log(1.0 + exp(value_array[0]));
}
std::string print_logexp(const std::vector<gmp::Rational> &v)
{
	return std::string() + "log((1) + exp(" + "(" + rational_to_string(v[0]) + ")" + "))";
}
bool check_input_logexp(const std::vector<double> &v)
{
    if (-8.0 > v[0])
        return false;
    if (v[0] > 8.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> logexp_range = {std::uniform_real_distribution<double>(-8.0, 8.0)};
const int logexp_variable_count = 1;


// FPBench NMSE problem 3.3.5
template <class T>
inline T NMSE_problem_3_3_5(const std::vector<T> &value_array)
{
	return cos(value_array[0] + value_array[1]) - cos(value_array[0]);
}
std::string print_NMSE_problem_3_3_5(const std::vector<gmp::Rational> &v)
{
	return std::string() + "cos(" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") - cos(" + "(" + rational_to_string(v[0]) + ")" + ")";
}
bool check_input_NMSE_problem_3_3_5(const std::vector<double> &v)
{
    return true;
}
const std::vector<std::uniform_real_distribution<double>> NMSE_problem_3_3_5_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int NMSE_problem_3_3_5_variable_count = 2;


// FPBench NMSE example 3.3
template <class T>
inline T NMSE_example_3_3(const std::vector<T> &value_array)
{
	return sin(value_array[0] + value_array[1]) - sin(value_array[0]);
}
std::string print_NMSE_example_3_3(const std::vector<gmp::Rational> &v)
{
	return std::string() + "sin(" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") - sin(" + "(" + rational_to_string(v[0]) + ")" + ")";
}
bool check_input_NMSE_example_3_3(const std::vector<double> &v)
{
    return true;
}
const std::vector<std::uniform_real_distribution<double>> NMSE_example_3_3_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int NMSE_example_3_3_variable_count = 2;


// FPBench kepler0
template <class T>
inline T kepler0(const std::vector<T> &value_array)
{
	return ((((value_array[1] * value_array[4]) + (value_array[2] * value_array[5])) - (value_array[1] * value_array[2])) - (value_array[4] * value_array[5])) + (value_array[0] * (((((-value_array[0] + value_array[1]) + value_array[2]) - value_array[3]) + value_array[4]) + value_array[5]));
}
std::string print_kepler0(const std::vector<gmp::Rational> &v)
{
	return std::string() + "((((" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[4]) + ")" + ") + (" + "(" + rational_to_string(v[2]) + ")" + " * " + "(" + rational_to_string(v[5]) + ")" + ")) - (" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[2]) + ")" + ")) - (" + "(" + rational_to_string(v[4]) + ")" + " * " + "(" + rational_to_string(v[5]) + ")" + ")) + (" + "(" + rational_to_string(v[0]) + ")" + " * (((((-" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") - " + "(" + rational_to_string(v[3]) + ")" + ") + " + "(" + rational_to_string(v[4]) + ")" + ") + " + "(" + rational_to_string(v[5]) + ")" + "))";
}
bool check_input_kepler0(const std::vector<double> &v)
{
    if (4.0 > v[0])
        return false;
    if (v[0] > 6.36)
        return false;
    if (4.0 > v[1])
        return false;
    if (v[1] > 6.36)
        return false;
    if (4.0 > v[2])
        return false;
    if (v[2] > 6.36)
        return false;
    if (4.0 > v[3])
        return false;
    if (v[3] > 6.36)
        return false;
    if (4.0 > v[4])
        return false;
    if (v[4] > 6.36)
        return false;
    if (4.0 > v[5])
        return false;
    if (v[5] > 6.36)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> kepler0_range = {std::uniform_real_distribution<double>(4.0, 6.36), std::uniform_real_distribution<double>(4.0, 6.36), std::uniform_real_distribution<double>(4.0, 6.36), std::uniform_real_distribution<double>(4.0, 6.36), std::uniform_real_distribution<double>(4.0, 6.36), std::uniform_real_distribution<double>(4.0, 6.36)};
const int kepler0_variable_count = 6;


// FPBench triangle5
template <class T>
inline T triangle5(const std::vector<T> &value_array)
{
	return sqrt((((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[0])) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[1])) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[2]));
}
std::string print_triangle5(const std::vector<gmp::Rational> &v)
{
	return std::string() + "sqrt((((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[0]) + ")" + ")) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[1]) + ")" + ")) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[2]) + ")" + "))";
}
bool check_input_triangle5(const std::vector<double> &v)
{
    if (1.0 > v[0])
        return false;
    if (v[0] > 9.0)
        return false;
    if (1.0 > v[1])
        return false;
    if (v[1] > 9.0)
        return false;
    if (1.0 > v[2])
        return false;
    if (v[2] > 9.0)
        return false;
    if ((v[0] + v[1]) <= (v[2] + 1.0/100000))
        return false;
    if ((v[0] + v[2]) <= (v[1] + 1.0/100000))
        return false;
    if ((v[1] + v[2]) <= (v[0] + 1.0/100000))
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> triangle5_range = {std::uniform_real_distribution<double>(1.0, 9.0), std::uniform_real_distribution<double>(1.0, 9.0), std::uniform_real_distribution<double>(1.0, 9.0)};
const int triangle5_variable_count = 3;


// FPBench bspline3
template <class T>
inline T bspline3(const std::vector<T> &value_array)
{
	return -((value_array[0] * value_array[0]) * value_array[0]) / 6.0;
}
std::string print_bspline3(const std::vector<gmp::Rational> &v)
{
	return std::string() + "-((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[0]) + ")" + ") * " + "(" + rational_to_string(v[0]) + ")" + ") / (6)";
}
bool check_input_bspline3(const std::vector<double> &v)
{
    if (0.0 > v[0])
        return false;
    if (v[0] > 1.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> bspline3_range = {std::uniform_real_distribution<double>(0.0, 1.0)};
const int bspline3_variable_count = 1;


// FPBench predatorPrey
template <class T>
inline T predatorPrey(const std::vector<T> &value_array)
{
	return (((4.0) * value_array[0]) * value_array[0]) / (1.0 + ((value_array[0] / (1.11)) * (value_array[0] / (1.11))));
}
std::string print_predatorPrey(const std::vector<gmp::Rational> &v)
{
	return std::string() + "((((4)) * " + "(" + rational_to_string(v[0]) + ")" + ") * " + "(" + rational_to_string(v[0]) + ")" + ") / ((1) + ((" + "(" + rational_to_string(v[0]) + ")" + " / ((111/100))) * (" + "(" + rational_to_string(v[0]) + ")" + " / ((111/100)))))";
}
bool check_input_predatorPrey(const std::vector<double> &v)
{
    if (0.1 > v[0])
        return false;
    if (v[0] > 0.3)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> predatorPrey_range = {std::uniform_real_distribution<double>(0.1, 0.3)};
const int predatorPrey_variable_count = 1;


// FPBench turbine3
template <class T>
inline T turbine3(const std::vector<T> &value_array)
{
	return ((3.0 - (2.0 / (value_array[2] * value_array[2]))) - (((0.125 * (1.0 + (2.0 * value_array[0]))) * (((value_array[1] * value_array[1]) * value_array[2]) * value_array[2])) / (1.0 - value_array[0]))) - 0.5;
}
std::string print_turbine3(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(((3) - ((2) / (" + "(" + rational_to_string(v[2]) + ")" + " * " + "(" + rational_to_string(v[2]) + ")" + "))) - ((((1/8) * ((1) + ((2) * " + "(" + rational_to_string(v[0]) + ")" + "))) * (((" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ") * " + "(" + rational_to_string(v[2]) + ")" + ") * " + "(" + rational_to_string(v[2]) + ")" + ")) / ((1) - " + "(" + rational_to_string(v[0]) + ")" + "))) - (1/2)";
}
bool check_input_turbine3(const std::vector<double> &v)
{
    if (-4.5 > v[0])
        return false;
    if (v[0] > -0.3)
        return false;
    if (0.4 > v[1])
        return false;
    if (v[1] > 0.9)
        return false;
    if (3.8 > v[2])
        return false;
    if (v[2] > 7.8)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> turbine3_range = {std::uniform_real_distribution<double>(-4.5, -0.3), std::uniform_real_distribution<double>(0.4, 0.9), std::uniform_real_distribution<double>(3.8, 7.8)};
const int turbine3_variable_count = 3;


// FPBench triangle7
template <class T>
inline T triangle7(const std::vector<T> &value_array)
{
	return sqrt((((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[0])) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[1])) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[2]));
}
std::string print_triangle7(const std::vector<gmp::Rational> &v)
{
	return std::string() + "sqrt((((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[0]) + ")" + ")) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[1]) + ")" + ")) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[2]) + ")" + "))";
}
bool check_input_triangle7(const std::vector<double> &v)
{
    if (1.0 > v[0])
        return false;
    if (v[0] > 9.0)
        return false;
    if (1.0 > v[1])
        return false;
    if (v[1] > 9.0)
        return false;
    if (1.0 > v[2])
        return false;
    if (v[2] > 9.0)
        return false;
    if ((v[0] + v[1]) <= (v[2] + 1.0/10000000))
        return false;
    if ((v[0] + v[2]) <= (v[1] + 1.0/10000000))
        return false;
    if ((v[1] + v[2]) <= (v[0] + 1.0/10000000))
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> triangle7_range = {std::uniform_real_distribution<double>(1.0, 9.0), std::uniform_real_distribution<double>(1.0, 9.0), std::uniform_real_distribution<double>(1.0, 9.0)};
const int triangle7_variable_count = 3;


// FPBench doppler1
template <class T>
inline T doppler1(const std::vector<T> &value_array)
{
	return (-(331.4 + (0.6 * value_array[2])) * value_array[1]) / (((331.4 + (0.6 * value_array[2])) + value_array[0]) * ((331.4 + (0.6 * value_array[2])) + value_array[0]));
}
std::string print_doppler1(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(-((1657/5) + ((3/5) * " + "(" + rational_to_string(v[2]) + ")" + ")) * " + "(" + rational_to_string(v[1]) + ")" + ") / ((((1657/5) + ((3/5) * " + "(" + rational_to_string(v[2]) + ")" + ")) + " + "(" + rational_to_string(v[0]) + ")" + ") * (((1657/5) + ((3/5) * " + "(" + rational_to_string(v[2]) + ")" + ")) + " + "(" + rational_to_string(v[0]) + ")" + "))";
}
bool check_input_doppler1(const std::vector<double> &v)
{
    if (-100.0 > v[0])
        return false;
    if (v[0] > 100.0)
        return false;
    if (20.0 > v[1])
        return false;
    if (v[1] > 20000.0)
        return false;
    if (-30.0 > v[2])
        return false;
    if (v[2] > 50.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> doppler1_range = {std::uniform_real_distribution<double>(-100.0, 100.0), std::uniform_real_distribution<double>(20.0, 20000.0), std::uniform_real_distribution<double>(-30.0, 50.0)};
const int doppler1_variable_count = 3;


// FPBench triangle3
template <class T>
inline T triangle3(const std::vector<T> &value_array)
{
	return sqrt((((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[0])) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[1])) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[2]));
}
std::string print_triangle3(const std::vector<gmp::Rational> &v)
{
	return std::string() + "sqrt((((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[0]) + ")" + ")) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[1]) + ")" + ")) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[2]) + ")" + "))";
}
bool check_input_triangle3(const std::vector<double> &v)
{
    if (1.0 > v[0])
        return false;
    if (v[0] > 9.0)
        return false;
    if (1.0 > v[1])
        return false;
    if (v[1] > 9.0)
        return false;
    if (1.0 > v[2])
        return false;
    if (v[2] > 9.0)
        return false;
    if ((v[0] + v[1]) <= (v[2] + 1.0/1000))
        return false;
    if ((v[0] + v[2]) <= (v[1] + 1.0/1000))
        return false;
    if ((v[1] + v[2]) <= (v[0] + 1.0/1000))
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> triangle3_range = {std::uniform_real_distribution<double>(1.0, 9.0), std::uniform_real_distribution<double>(1.0, 9.0), std::uniform_real_distribution<double>(1.0, 9.0)};
const int triangle3_variable_count = 3;


// FPBench Rump's example, from C program
template <class T>
inline T Rump_s_example_from_C_program(const std::vector<T> &value_array)
{
	return (((333.75 * (((value_array[1] * value_array[1]) * (value_array[1] * value_array[1])) * (value_array[1] * value_array[1]))) + ((value_array[0] * value_array[0]) * (((((11.0 * (value_array[0] * value_array[0])) * (value_array[1] * value_array[1])) - (((value_array[1] * value_array[1]) * (value_array[1] * value_array[1])) * (value_array[1] * value_array[1]))) - (121.0 * ((value_array[1] * value_array[1]) * (value_array[1] * value_array[1])))) - 2.0))) + (5.5 * (((value_array[1] * value_array[1]) * (value_array[1] * value_array[1])) * ((value_array[1] * value_array[1]) * (value_array[1] * value_array[1]))))) + (value_array[0] / (2.0 * value_array[1]));
}
std::string print_Rump_s_example_from_C_program(const std::vector<gmp::Rational> &v)
{
	return std::string() + "((((1335/4) * (((" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ") * (" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ")) * (" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + "))) + ((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[0]) + ")" + ") * ((((((11) * (" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[0]) + ")" + ")) * (" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ")) - (((" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ") * (" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ")) * (" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + "))) - ((121) * ((" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ") * (" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ")))) - (2)))) + ((11/2) * (((" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ") * (" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ")) * ((" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ") * (" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + "))))) + (" + "(" + rational_to_string(v[0]) + ")" + " / ((2) * " + "(" + rational_to_string(v[1]) + ")" + "))";
}
bool check_input_Rump_s_example_from_C_program(const std::vector<double> &v)
{
    return true;
}
const std::vector<std::uniform_real_distribution<double>> Rump_s_example_from_C_program_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int Rump_s_example_from_C_program_variable_count = 2;


// FPBench exp1x
template <class T>
inline T exp1x(const std::vector<T> &value_array)
{
	return (exp(value_array[0]) - 1.0) / value_array[0];
}
std::string print_exp1x(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(exp(" + "(" + rational_to_string(v[0]) + ")" + ") - (1)) / " + "(" + rational_to_string(v[0]) + ")";
}
bool check_input_exp1x(const std::vector<double> &v)
{
    if (0.01 > v[0])
        return false;
    if (v[0] > 0.5)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> exp1x_range = {std::uniform_real_distribution<double>(0.01, 0.5)};
const int exp1x_variable_count = 1;


// FPBench NMSE problem 3.4.4
template <class T>
inline T NMSE_problem_3_4_4(const std::vector<T> &value_array)
{
	return sqrt((exp(2.0 * value_array[0]) - 1.0) / (exp(value_array[0]) - 1.0));
}
std::string print_NMSE_problem_3_4_4(const std::vector<gmp::Rational> &v)
{
	return std::string() + "sqrt((exp((2) * " + "(" + rational_to_string(v[0]) + ")" + ") - (1)) / (exp(" + "(" + rational_to_string(v[0]) + ")" + ") - (1)))";
}
bool check_input_NMSE_problem_3_4_4(const std::vector<double> &v)
{
    return true;
}
const std::vector<std::uniform_real_distribution<double>> NMSE_problem_3_4_4_range = {std::uniform_real_distribution<double>(-350, 350)};
const int NMSE_problem_3_4_4_variable_count = 1;


// FPBench delta4
template <class T>
inline T delta4(const std::vector<T> &value_array)
{
	return (((((-value_array[1] * value_array[2]) - (value_array[0] * value_array[3])) + (value_array[1] * value_array[4])) + (value_array[2] * value_array[5])) - (value_array[4] * value_array[5])) + (value_array[0] * (((((-value_array[0] + value_array[1]) + value_array[2]) - value_array[3]) + value_array[4]) + value_array[5]));
}
std::string print_delta4(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(((((-" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[2]) + ")" + ") - (" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[3]) + ")" + ")) + (" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[4]) + ")" + ")) + (" + "(" + rational_to_string(v[2]) + ")" + " * " + "(" + rational_to_string(v[5]) + ")" + ")) - (" + "(" + rational_to_string(v[4]) + ")" + " * " + "(" + rational_to_string(v[5]) + ")" + ")) + (" + "(" + rational_to_string(v[0]) + ")" + " * (((((-" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") - " + "(" + rational_to_string(v[3]) + ")" + ") + " + "(" + rational_to_string(v[4]) + ")" + ") + " + "(" + rational_to_string(v[5]) + ")" + "))";
}
bool check_input_delta4(const std::vector<double> &v)
{
    if (4.0 > v[0])
        return false;
    if (v[0] > 6.3504)
        return false;
    if (4.0 > v[1])
        return false;
    if (v[1] > 6.3504)
        return false;
    if (4.0 > v[2])
        return false;
    if (v[2] > 6.3504)
        return false;
    if (4.0 > v[3])
        return false;
    if (v[3] > 6.3504)
        return false;
    if (4.0 > v[4])
        return false;
    if (v[4] > 6.3504)
        return false;
    if (4.0 > v[5])
        return false;
    if (v[5] > 6.3504)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> delta4_range = {std::uniform_real_distribution<double>(4.0, 6.3504), std::uniform_real_distribution<double>(4.0, 6.3504), std::uniform_real_distribution<double>(4.0, 6.3504), std::uniform_real_distribution<double>(4.0, 6.3504), std::uniform_real_distribution<double>(4.0, 6.3504), std::uniform_real_distribution<double>(4.0, 6.3504)};
const int delta4_variable_count = 6;


// FPBench instantaneousCurrent
template <class T>
inline T instantaneousCurrent(const std::vector<T> &value_array)
{
	return (sqrt((((value_array[4] * (value_array[1])) / (((value_array[1]) * (value_array[1])) + ((((2.0 * (3.14159265359)) * value_array[2]) * value_array[3]) * (((2.0 * (3.14159265359)) * value_array[2]) * value_array[3])))) * ((value_array[4] * (value_array[1])) / (((value_array[1]) * (value_array[1])) + ((((2.0 * (3.14159265359)) * value_array[2]) * value_array[3]) * (((2.0 * (3.14159265359)) * value_array[2]) * value_array[3]))))) + ((-(value_array[4] * (((2.0 * (3.14159265359)) * value_array[2]) * value_array[3])) / (((value_array[1]) * (value_array[1])) + ((((2.0 * (3.14159265359)) * value_array[2]) * value_array[3]) * (((2.0 * (3.14159265359)) * value_array[2]) * value_array[3])))) * (-(value_array[4] * (((2.0 * (3.14159265359)) * value_array[2]) * value_array[3])) / (((value_array[1]) * (value_array[1])) + ((((2.0 * (3.14159265359)) * value_array[2]) * value_array[3]) * (((2.0 * (3.14159265359)) * value_array[2]) * value_array[3]))))))) * cos((((2.0 * (3.14159265359)) * value_array[2]) * value_array[0]) + (atan((-(value_array[4] * (((2.0 * (3.14159265359)) * value_array[2]) * value_array[3])) / (((value_array[1]) * (value_array[1])) + ((((2.0 * (3.14159265359)) * value_array[2]) * value_array[3]) * (((2.0 * (3.14159265359)) * value_array[2]) * value_array[3])))) / ((value_array[4] * (value_array[1])) / (((value_array[1]) * (value_array[1])) + ((((2.0 * (3.14159265359)) * value_array[2]) * value_array[3]) * (((2.0 * (3.14159265359)) * value_array[2]) * value_array[3])))))));
}
std::string print_instantaneousCurrent(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(sqrt((((" + "(" + rational_to_string(v[4]) + ")" + " * (" + "(" + rational_to_string(v[1]) + ")" + ")) / (((" + "(" + rational_to_string(v[1]) + ")" + ") * (" + "(" + rational_to_string(v[1]) + ")" + ")) + (((((2) * ((314159265359/100000000000))) * " + "(" + rational_to_string(v[2]) + ")" + ") * " + "(" + rational_to_string(v[3]) + ")" + ") * ((((2) * ((314159265359/100000000000))) * " + "(" + rational_to_string(v[2]) + ")" + ") * " + "(" + rational_to_string(v[3]) + ")" + ")))) * ((" + "(" + rational_to_string(v[4]) + ")" + " * (" + "(" + rational_to_string(v[1]) + ")" + ")) / (((" + "(" + rational_to_string(v[1]) + ")" + ") * (" + "(" + rational_to_string(v[1]) + ")" + ")) + (((((2) * ((314159265359/100000000000))) * " + "(" + rational_to_string(v[2]) + ")" + ") * " + "(" + rational_to_string(v[3]) + ")" + ") * ((((2) * ((314159265359/100000000000))) * " + "(" + rational_to_string(v[2]) + ")" + ") * " + "(" + rational_to_string(v[3]) + ")" + "))))) + ((-(" + "(" + rational_to_string(v[4]) + ")" + " * ((((2) * ((314159265359/100000000000))) * " + "(" + rational_to_string(v[2]) + ")" + ") * " + "(" + rational_to_string(v[3]) + ")" + ")) / (((" + "(" + rational_to_string(v[1]) + ")" + ") * (" + "(" + rational_to_string(v[1]) + ")" + ")) + (((((2) * ((314159265359/100000000000))) * " + "(" + rational_to_string(v[2]) + ")" + ") * " + "(" + rational_to_string(v[3]) + ")" + ") * ((((2) * ((314159265359/100000000000))) * " + "(" + rational_to_string(v[2]) + ")" + ") * " + "(" + rational_to_string(v[3]) + ")" + ")))) * (-(" + "(" + rational_to_string(v[4]) + ")" + " * ((((2) * ((314159265359/100000000000))) * " + "(" + rational_to_string(v[2]) + ")" + ") * " + "(" + rational_to_string(v[3]) + ")" + ")) / (((" + "(" + rational_to_string(v[1]) + ")" + ") * (" + "(" + rational_to_string(v[1]) + ")" + ")) + (((((2) * ((314159265359/100000000000))) * " + "(" + rational_to_string(v[2]) + ")" + ") * " + "(" + rational_to_string(v[3]) + ")" + ") * ((((2) * ((314159265359/100000000000))) * " + "(" + rational_to_string(v[2]) + ")" + ") * " + "(" + rational_to_string(v[3]) + ")" + "))))))) * cos(((((2) * ((314159265359/100000000000))) * " + "(" + rational_to_string(v[2]) + ")" + ") * " + "(" + rational_to_string(v[0]) + ")" + ") + (atan((-(" + "(" + rational_to_string(v[4]) + ")" + " * ((((2) * ((314159265359/100000000000))) * " + "(" + rational_to_string(v[2]) + ")" + ") * " + "(" + rational_to_string(v[3]) + ")" + ")) / (((" + "(" + rational_to_string(v[1]) + ")" + ") * (" + "(" + rational_to_string(v[1]) + ")" + ")) + (((((2) * ((314159265359/100000000000))) * " + "(" + rational_to_string(v[2]) + ")" + ") * " + "(" + rational_to_string(v[3]) + ")" + ") * ((((2) * ((314159265359/100000000000))) * " + "(" + rational_to_string(v[2]) + ")" + ") * " + "(" + rational_to_string(v[3]) + ")" + ")))) / ((" + "(" + rational_to_string(v[4]) + ")" + " * (" + "(" + rational_to_string(v[1]) + ")" + ")) / (((" + "(" + rational_to_string(v[1]) + ")" + ") * (" + "(" + rational_to_string(v[1]) + ")" + ")) + (((((2) * ((314159265359/100000000000))) * " + "(" + rational_to_string(v[2]) + ")" + ") * " + "(" + rational_to_string(v[3]) + ")" + ") * ((((2) * ((314159265359/100000000000))) * " + "(" + rational_to_string(v[2]) + ")" + ") * " + "(" + rational_to_string(v[3]) + ")" + ")))))))";
}
bool check_input_instantaneousCurrent(const std::vector<double> &v)
{
    if (0.0 > v[0])
        return false;
    if (v[0] > 300.0)
        return false;
    if (1.0 > v[1])
        return false;
    if (v[1] > 50.0)
        return false;
    if (1.0 > v[2])
        return false;
    if (v[2] > 100.0)
        return false;
    if (0.001 > v[3])
        return false;
    if (v[3] > 0.004)
        return false;
    if (1.0 > v[4])
        return false;
    if (v[4] > 12.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> instantaneousCurrent_range = {std::uniform_real_distribution<double>(0.0, 300.0), std::uniform_real_distribution<double>(1.0, 50.0), std::uniform_real_distribution<double>(1.0, 100.0), std::uniform_real_distribution<double>(0.001, 0.004), std::uniform_real_distribution<double>(1.0, 12.0)};
const int instantaneousCurrent_variable_count = 5;


// FPBench NMSE problem 3.2.1, negative
template <class T>
inline T NMSE_problem_3_2_1_negative(const std::vector<T> &value_array)
{
	return (-value_array[1] - sqrt((value_array[1] * value_array[1]) - (value_array[0] * value_array[2]))) / value_array[0];
}
std::string print_NMSE_problem_3_2_1_negative(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(-" + "(" + rational_to_string(v[1]) + ")" + " - sqrt((" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ") - (" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[2]) + ")" + "))) / " + "(" + rational_to_string(v[0]) + ")";
}
bool check_input_NMSE_problem_3_2_1_negative(const std::vector<double> &v)
{
    if ((v[1] * v[1]) < (v[0] * v[2]))
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> NMSE_problem_3_2_1_negative_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int NMSE_problem_3_2_1_negative_variable_count = 3;


// FPBench kepler2
template <class T>
inline T kepler2(const std::vector<T> &value_array)
{
	return (((((((value_array[0] * value_array[3]) * (((((-value_array[0] + value_array[1]) + value_array[2]) - value_array[3]) + value_array[4]) + value_array[5])) + ((value_array[1] * value_array[4]) * (((((value_array[0] - value_array[1]) + value_array[2]) + value_array[3]) - value_array[4]) + value_array[5]))) + ((value_array[2] * value_array[5]) * (((((value_array[0] + value_array[1]) - value_array[2]) + value_array[3]) + value_array[4]) - value_array[5]))) - ((value_array[1] * value_array[2]) * value_array[3])) - ((value_array[0] * value_array[2]) * value_array[4])) - ((value_array[0] * value_array[1]) * value_array[5])) - ((value_array[3] * value_array[4]) * value_array[5]);
}
std::string print_kepler2(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(((((((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[3]) + ")" + ") * (((((-" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") - " + "(" + rational_to_string(v[3]) + ")" + ") + " + "(" + rational_to_string(v[4]) + ")" + ") + " + "(" + rational_to_string(v[5]) + ")" + ")) + ((" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[4]) + ")" + ") * (((((" + "(" + rational_to_string(v[0]) + ")" + " - " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") + " + "(" + rational_to_string(v[3]) + ")" + ") - " + "(" + rational_to_string(v[4]) + ")" + ") + " + "(" + rational_to_string(v[5]) + ")" + "))) + ((" + "(" + rational_to_string(v[2]) + ")" + " * " + "(" + rational_to_string(v[5]) + ")" + ") * (((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") - " + "(" + rational_to_string(v[2]) + ")" + ") + " + "(" + rational_to_string(v[3]) + ")" + ") + " + "(" + rational_to_string(v[4]) + ")" + ") - " + "(" + rational_to_string(v[5]) + ")" + "))) - ((" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[2]) + ")" + ") * " + "(" + rational_to_string(v[3]) + ")" + ")) - ((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[2]) + ")" + ") * " + "(" + rational_to_string(v[4]) + ")" + ")) - ((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ") * " + "(" + rational_to_string(v[5]) + ")" + ")) - ((" + "(" + rational_to_string(v[3]) + ")" + " * " + "(" + rational_to_string(v[4]) + ")" + ") * " + "(" + rational_to_string(v[5]) + ")" + ")";
}
bool check_input_kepler2(const std::vector<double> &v)
{
    if (4.0 > v[0])
        return false;
    if (v[0] > 6.36)
        return false;
    if (4.0 > v[1])
        return false;
    if (v[1] > 6.36)
        return false;
    if (4.0 > v[2])
        return false;
    if (v[2] > 6.36)
        return false;
    if (4.0 > v[3])
        return false;
    if (v[3] > 6.36)
        return false;
    if (4.0 > v[4])
        return false;
    if (v[4] > 6.36)
        return false;
    if (4.0 > v[5])
        return false;
    if (v[5] > 6.36)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> kepler2_range = {std::uniform_real_distribution<double>(4.0, 6.36), std::uniform_real_distribution<double>(4.0, 6.36), std::uniform_real_distribution<double>(4.0, 6.36), std::uniform_real_distribution<double>(4.0, 6.36), std::uniform_real_distribution<double>(4.0, 6.36), std::uniform_real_distribution<double>(4.0, 6.36)};
const int kepler2_variable_count = 6;


// FPBench NMSE problem 3.3.3
template <class T>
inline T NMSE_problem_3_3_3(const std::vector<T> &value_array)
{
	return ((1.0 / (value_array[0] + 1.0)) - (2.0 / value_array[0])) + (1.0 / (value_array[0] - 1.0));
}
std::string print_NMSE_problem_3_3_3(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(((1) / (" + "(" + rational_to_string(v[0]) + ")" + " + (1))) - ((2) / " + "(" + rational_to_string(v[0]) + ")" + ")) + ((1) / (" + "(" + rational_to_string(v[0]) + ")" + " - (1)))";
}
bool check_input_NMSE_problem_3_3_3(const std::vector<double> &v)
{
    return true;
}
const std::vector<std::uniform_real_distribution<double>> NMSE_problem_3_3_3_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int NMSE_problem_3_3_3_variable_count = 1;


// FPBench azimuth
template <class T>
inline T azimuth(const std::vector<T> &value_array)
{
	return atan((cos(value_array[1]) * sin(value_array[3] - value_array[2])) / ((cos(value_array[0]) * sin(value_array[1])) - ((sin(value_array[0]) * cos(value_array[1])) * cos(value_array[3] - value_array[2]))));
}
std::string print_azimuth(const std::vector<gmp::Rational> &v)
{
	return std::string() + "atan((cos(" + "(" + rational_to_string(v[1]) + ")" + ") * sin(" + "(" + rational_to_string(v[3]) + ")" + " - " + "(" + rational_to_string(v[2]) + ")" + ")) / ((cos(" + "(" + rational_to_string(v[0]) + ")" + ") * sin(" + "(" + rational_to_string(v[1]) + ")" + ")) - ((sin(" + "(" + rational_to_string(v[0]) + ")" + ") * cos(" + "(" + rational_to_string(v[1]) + ")" + ")) * cos(" + "(" + rational_to_string(v[3]) + ")" + " - " + "(" + rational_to_string(v[2]) + ")" + "))))";
}
bool check_input_azimuth(const std::vector<double> &v)
{
    if (0.0 > v[0])
        return false;
    if (v[0] > 0.4)
        return false;
    if (0.5 > v[1])
        return false;
    if (v[1] > 1.0)
        return false;
    if (0.0 > v[2])
        return false;
    if (v[2] > 3.14159265)
        return false;
    if (-3.14159265 > v[3])
        return false;
    if (v[3] > -0.5)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> azimuth_range = {std::uniform_real_distribution<double>(0.0, 0.4), std::uniform_real_distribution<double>(0.5, 1.0), std::uniform_real_distribution<double>(0.0, 3.14159265), std::uniform_real_distribution<double>(-3.14159265, -0.5)};
const int azimuth_variable_count = 4;


// FPBench NMSE problem 3.3.7
template <class T>
inline T NMSE_problem_3_3_7(const std::vector<T> &value_array)
{
	return (exp(value_array[0]) - 2.0) + exp(-value_array[0]);
}
std::string print_NMSE_problem_3_3_7(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(exp(" + "(" + rational_to_string(v[0]) + ")" + ") - (2)) + exp(-" + "(" + rational_to_string(v[0]) + ")" + ")";
}
bool check_input_NMSE_problem_3_3_7(const std::vector<double> &v)
{
    return true;
}
const std::vector<std::uniform_real_distribution<double>> NMSE_problem_3_3_7_range = {std::uniform_real_distribution<double>(-700, 700)};
const int NMSE_problem_3_3_7_variable_count = 1;


// FPBench i6
template <class T>
inline T i6(const std::vector<T> &value_array)
{
	return sin(value_array[0] * value_array[1]);
}
std::string print_i6(const std::vector<gmp::Rational> &v)
{
	return std::string() + "sin(" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ")";
}
bool check_input_i6(const std::vector<double> &v)
{
    if (0.1 > v[0])
        return false;
    if (v[0] > 10.0)
        return false;
    if (-5.0 > v[1])
        return false;
    if (v[1] > 5.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> i6_range = {std::uniform_real_distribution<double>(0.1, 10.0), std::uniform_real_distribution<double>(-5.0, 5.0)};
const int i6_variable_count = 2;


// FPBench NMSE example 3.9
template <class T>
inline T NMSE_example_3_9(const std::vector<T> &value_array)
{
	return (1.0 / value_array[0]) - (1.0 / tan(value_array[0]));
}
std::string print_NMSE_example_3_9(const std::vector<gmp::Rational> &v)
{
	return std::string() + "((1) / " + "(" + rational_to_string(v[0]) + ")" + ") - ((1) / tan(" + "(" + rational_to_string(v[0]) + ")" + "))";
}
bool check_input_NMSE_example_3_9(const std::vector<double> &v)
{
    return true;
}
const std::vector<std::uniform_real_distribution<double>> NMSE_example_3_9_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int NMSE_example_3_9_variable_count = 1;


// FPBench NMSE section 3.5
template <class T>
inline T NMSE_section_3_5(const std::vector<T> &value_array)
{
	return exp(value_array[0] * value_array[1]) - 1.0;
}
std::string print_NMSE_section_3_5(const std::vector<gmp::Rational> &v)
{
	return std::string() + "exp(" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ") - (1)";
}
bool check_input_NMSE_section_3_5(const std::vector<double> &v)
{
    return true;
}
const std::vector<std::uniform_real_distribution<double>> NMSE_section_3_5_range = {std::uniform_real_distribution<double>(-25, 25), std::uniform_real_distribution<double>(-25, 25)};
const int NMSE_section_3_5_variable_count = 2;


// FPBench hypot
template <class T>
inline T hypot(const std::vector<T> &value_array)
{
	return sqrt((value_array[0] * value_array[0]) + (value_array[1] * value_array[1]));
}
std::string print_hypot(const std::vector<gmp::Rational> &v)
{
	return std::string() + "sqrt((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[0]) + ")" + ") + (" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + "))";
}
bool check_input_hypot(const std::vector<double> &v)
{
    if (1.0 > v[0])
        return false;
    if (v[0] > 100.0)
        return false;
    if (1.0 > v[1])
        return false;
    if (v[1] > 100.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> hypot_range = {std::uniform_real_distribution<double>(1.0, 100.0), std::uniform_real_distribution<double>(1.0, 100.0)};
const int hypot_variable_count = 2;


// FPBench test04_dqmom9
template <class T>
inline T test04_dqmom9(const std::vector<T> &value_array)
{
	return 0.0 + ((((value_array[3] * (0.0 - value_array[0])) * (-3.0 * ((1.0 * (value_array[6] / value_array[3])) * (value_array[6] / value_array[3])))) * 1.0) + ((((value_array[4] * (0.0 - value_array[1])) * (-3.0 * ((1.0 * (value_array[7] / value_array[4])) * (value_array[7] / value_array[4])))) * 1.0) + ((((value_array[5] * (0.0 - value_array[2])) * (-3.0 * ((1.0 * (value_array[8] / value_array[5])) * (value_array[8] / value_array[5])))) * 1.0) + 0.0)));
}
std::string print_test04_dqmom9(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(0) + ((((" + "(" + rational_to_string(v[3]) + ")" + " * ((0) - " + "(" + rational_to_string(v[0]) + ")" + ")) * (-(3) * (((1) * (" + "(" + rational_to_string(v[6]) + ")" + " / " + "(" + rational_to_string(v[3]) + ")" + ")) * (" + "(" + rational_to_string(v[6]) + ")" + " / " + "(" + rational_to_string(v[3]) + ")" + ")))) * (1)) + ((((" + "(" + rational_to_string(v[4]) + ")" + " * ((0) - " + "(" + rational_to_string(v[1]) + ")" + ")) * (-(3) * (((1) * (" + "(" + rational_to_string(v[7]) + ")" + " / " + "(" + rational_to_string(v[4]) + ")" + ")) * (" + "(" + rational_to_string(v[7]) + ")" + " / " + "(" + rational_to_string(v[4]) + ")" + ")))) * (1)) + ((((" + "(" + rational_to_string(v[5]) + ")" + " * ((0) - " + "(" + rational_to_string(v[2]) + ")" + ")) * (-(3) * (((1) * (" + "(" + rational_to_string(v[8]) + ")" + " / " + "(" + rational_to_string(v[5]) + ")" + ")) * (" + "(" + rational_to_string(v[8]) + ")" + " / " + "(" + rational_to_string(v[5]) + ")" + ")))) * (1)) + (0))))";
}
bool check_input_test04_dqmom9(const std::vector<double> &v)
{
    if (-1.0 >= v[0])
        return false;
    if (v[0] >= 1.0)
        return false;
    if (-1.0 >= v[1])
        return false;
    if (v[1] >= 1.0)
        return false;
    if (-1.0 >= v[2])
        return false;
    if (v[2] >= 1.0)
        return false;
    if (1e-05 >= v[3])
        return false;
    if (v[3] >= 1.0)
        return false;
    if (1e-05 >= v[4])
        return false;
    if (v[4] >= 1.0)
        return false;
    if (1e-05 >= v[5])
        return false;
    if (v[5] >= 1.0)
        return false;
    if (1e-05 >= v[6])
        return false;
    if (v[6] >= 1.0)
        return false;
    if (1e-05 >= v[7])
        return false;
    if (v[7] >= 1.0)
        return false;
    if (1e-05 >= v[8])
        return false;
    if (v[8] >= 1.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> test04_dqmom9_range = {std::uniform_real_distribution<double>(-1.0, 1.0), std::uniform_real_distribution<double>(-1.0, 1.0), std::uniform_real_distribution<double>(-1.0, 1.0), std::uniform_real_distribution<double>(1e-05, 1.0), std::uniform_real_distribution<double>(1e-05, 1.0), std::uniform_real_distribution<double>(1e-05, 1.0), std::uniform_real_distribution<double>(1e-05, 1.0), std::uniform_real_distribution<double>(1e-05, 1.0), std::uniform_real_distribution<double>(1e-05, 1.0)};
const int test04_dqmom9_variable_count = 9;


// FPBench nonlin1
template <class T>
inline T nonlin1(const std::vector<T> &value_array)
{
	return value_array[0] / (value_array[0] + 1.0);
}
std::string print_nonlin1(const std::vector<gmp::Rational> &v)
{
	return std::string() + "" + "(" + rational_to_string(v[0]) + ")" + " / (" + "(" + rational_to_string(v[0]) + ")" + " + (1))";
}
bool check_input_nonlin1(const std::vector<double> &v)
{
    if (0.0 > v[0])
        return false;
    if (v[0] > 999.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> nonlin1_range = {std::uniform_real_distribution<double>(0.0, 999.0)};
const int nonlin1_variable_count = 1;


// FPBench NMSE example 3.4
template <class T>
inline T NMSE_example_3_4(const std::vector<T> &value_array)
{
	return (1.0 - cos(value_array[0])) / sin(value_array[0]);
}
std::string print_NMSE_example_3_4(const std::vector<gmp::Rational> &v)
{
	return std::string() + "((1) - cos(" + "(" + rational_to_string(v[0]) + ")" + ")) / sin(" + "(" + rational_to_string(v[0]) + ")" + ")";
}
bool check_input_NMSE_example_3_4(const std::vector<double> &v)
{
    return true;
}
const std::vector<std::uniform_real_distribution<double>> NMSE_example_3_4_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int NMSE_example_3_4_variable_count = 1;


// FPBench hartman6
template <class T>
inline T hartman6(const std::vector<T> &value_array)
{
	return -((((1.0 * (exp(-((((((10.0 * ((value_array[0] - 0.1312) * (value_array[0] - 0.1312))) + (3.0 * ((value_array[1] - 0.1696) * (value_array[1] - 0.1696)))) + (17.0 * ((value_array[2] - 0.5569) * (value_array[2] - 0.5569)))) + (3.5 * ((value_array[3] - 0.0124) * (value_array[3] - 0.0124)))) + (1.7 * ((value_array[4] - 0.8283) * (value_array[4] - 0.8283)))) + (8.0 * ((value_array[5] - 0.5886) * (value_array[5] - 0.5886))))))) + (1.2 * (exp(-((((((0.05 * ((value_array[0] - 0.2329) * (value_array[0] - 0.2329))) + (10.0 * ((value_array[1] - 0.4135) * (value_array[1] - 0.4135)))) + (17.0 * ((value_array[2] - 0.8307) * (value_array[2] - 0.8307)))) + (0.1 * ((value_array[3] - 0.3736) * (value_array[3] - 0.3736)))) + (8.0 * ((value_array[4] - 0.1004) * (value_array[4] - 0.1004)))) + (14.0 * ((value_array[5] - 0.9991) * (value_array[5] - 0.9991)))))))) + (3.0 * (exp(-((((((3.0 * ((value_array[0] - 0.2348) * (value_array[0] - 0.2348))) + (3.5 * ((value_array[1] - 0.1451) * (value_array[1] - 0.1451)))) + (1.7 * ((value_array[2] - 0.3522) * (value_array[2] - 0.3522)))) + (10.0 * ((value_array[3] - 0.2883) * (value_array[3] - 0.2883)))) + (17.0 * ((value_array[4] - 0.3047) * (value_array[4] - 0.3047)))) + (8.0 * ((value_array[5] - 0.665) * (value_array[5] - 0.665)))))))) + (3.2 * (exp(-((((((17.0 * ((value_array[0] - 0.4047) * (value_array[0] - 0.4047))) + (8.0 * ((value_array[1] - 0.8828) * (value_array[1] - 0.8828)))) + (0.05 * ((value_array[2] - 0.8732) * (value_array[2] - 0.8732)))) + (10.0 * ((value_array[3] - 0.5743) * (value_array[3] - 0.5743)))) + (0.1 * ((value_array[4] - 0.1091) * (value_array[4] - 0.1091)))) + (14.0 * ((value_array[5] - 0.0381) * (value_array[5] - 0.0381))))))));
}
std::string print_hartman6(const std::vector<gmp::Rational> &v)
{
	return std::string() + "-(((((1) * (exp(-(((((((10) * ((" + "(" + rational_to_string(v[0]) + ")" + " - (82/625)) * (" + "(" + rational_to_string(v[0]) + ")" + " - (82/625)))) + ((3) * ((" + "(" + rational_to_string(v[1]) + ")" + " - (106/625)) * (" + "(" + rational_to_string(v[1]) + ")" + " - (106/625))))) + ((17) * ((" + "(" + rational_to_string(v[2]) + ")" + " - (5569/10000)) * (" + "(" + rational_to_string(v[2]) + ")" + " - (5569/10000))))) + ((7/2) * ((" + "(" + rational_to_string(v[3]) + ")" + " - (31/2500)) * (" + "(" + rational_to_string(v[3]) + ")" + " - (31/2500))))) + ((17/10) * ((" + "(" + rational_to_string(v[4]) + ")" + " - (8283/10000)) * (" + "(" + rational_to_string(v[4]) + ")" + " - (8283/10000))))) + ((8) * ((" + "(" + rational_to_string(v[5]) + ")" + " - (2943/5000)) * (" + "(" + rational_to_string(v[5]) + ")" + " - (2943/5000)))))))) + ((6/5) * (exp(-(((((((1/20) * ((" + "(" + rational_to_string(v[0]) + ")" + " - (2329/10000)) * (" + "(" + rational_to_string(v[0]) + ")" + " - (2329/10000)))) + ((10) * ((" + "(" + rational_to_string(v[1]) + ")" + " - (827/2000)) * (" + "(" + rational_to_string(v[1]) + ")" + " - (827/2000))))) + ((17) * ((" + "(" + rational_to_string(v[2]) + ")" + " - (8307/10000)) * (" + "(" + rational_to_string(v[2]) + ")" + " - (8307/10000))))) + ((1/10) * ((" + "(" + rational_to_string(v[3]) + ")" + " - (467/1250)) * (" + "(" + rational_to_string(v[3]) + ")" + " - (467/1250))))) + ((8) * ((" + "(" + rational_to_string(v[4]) + ")" + " - (251/2500)) * (" + "(" + rational_to_string(v[4]) + ")" + " - (251/2500))))) + ((14) * ((" + "(" + rational_to_string(v[5]) + ")" + " - (9991/10000)) * (" + "(" + rational_to_string(v[5]) + ")" + " - (9991/10000))))))))) + ((3) * (exp(-(((((((3) * ((" + "(" + rational_to_string(v[0]) + ")" + " - (587/2500)) * (" + "(" + rational_to_string(v[0]) + ")" + " - (587/2500)))) + ((7/2) * ((" + "(" + rational_to_string(v[1]) + ")" + " - (1451/10000)) * (" + "(" + rational_to_string(v[1]) + ")" + " - (1451/10000))))) + ((17/10) * ((" + "(" + rational_to_string(v[2]) + ")" + " - (1761/5000)) * (" + "(" + rational_to_string(v[2]) + ")" + " - (1761/5000))))) + ((10) * ((" + "(" + rational_to_string(v[3]) + ")" + " - (2883/10000)) * (" + "(" + rational_to_string(v[3]) + ")" + " - (2883/10000))))) + ((17) * ((" + "(" + rational_to_string(v[4]) + ")" + " - (3047/10000)) * (" + "(" + rational_to_string(v[4]) + ")" + " - (3047/10000))))) + ((8) * ((" + "(" + rational_to_string(v[5]) + ")" + " - (133/200)) * (" + "(" + rational_to_string(v[5]) + ")" + " - (133/200))))))))) + ((16/5) * (exp(-(((((((17) * ((" + "(" + rational_to_string(v[0]) + ")" + " - (4047/10000)) * (" + "(" + rational_to_string(v[0]) + ")" + " - (4047/10000)))) + ((8) * ((" + "(" + rational_to_string(v[1]) + ")" + " - (2207/2500)) * (" + "(" + rational_to_string(v[1]) + ")" + " - (2207/2500))))) + ((1/20) * ((" + "(" + rational_to_string(v[2]) + ")" + " - (2183/2500)) * (" + "(" + rational_to_string(v[2]) + ")" + " - (2183/2500))))) + ((10) * ((" + "(" + rational_to_string(v[3]) + ")" + " - (5743/10000)) * (" + "(" + rational_to_string(v[3]) + ")" + " - (5743/10000))))) + ((1/10) * ((" + "(" + rational_to_string(v[4]) + ")" + " - (1091/10000)) * (" + "(" + rational_to_string(v[4]) + ")" + " - (1091/10000))))) + ((14) * ((" + "(" + rational_to_string(v[5]) + ")" + " - (381/10000)) * (" + "(" + rational_to_string(v[5]) + ")" + " - (381/10000)))))))))";
}
bool check_input_hartman6(const std::vector<double> &v)
{
    if (0.0 > v[0])
        return false;
    if (v[0] > 1.0)
        return false;
    if (0.0 > v[1])
        return false;
    if (v[1] > 1.0)
        return false;
    if (0.0 > v[2])
        return false;
    if (v[2] > 1.0)
        return false;
    if (0.0 > v[3])
        return false;
    if (v[3] > 1.0)
        return false;
    if (0.0 > v[4])
        return false;
    if (v[4] > 1.0)
        return false;
    if (0.0 > v[5])
        return false;
    if (v[5] > 1.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> hartman6_range = {std::uniform_real_distribution<double>(0.0, 1.0), std::uniform_real_distribution<double>(0.0, 1.0), std::uniform_real_distribution<double>(0.0, 1.0), std::uniform_real_distribution<double>(0.0, 1.0), std::uniform_real_distribution<double>(0.0, 1.0), std::uniform_real_distribution<double>(0.0, 1.0)};
const int hartman6_variable_count = 6;


// FPBench carthesianToPolar, radius
template <class T>
inline T carthesianToPolar_radius(const std::vector<T> &value_array)
{
	return sqrt((value_array[0] * value_array[0]) + (value_array[1] * value_array[1]));
}
std::string print_carthesianToPolar_radius(const std::vector<gmp::Rational> &v)
{
	return std::string() + "sqrt((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[0]) + ")" + ") + (" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + "))";
}
bool check_input_carthesianToPolar_radius(const std::vector<double> &v)
{
    if (1.0 > v[0])
        return false;
    if (v[0] > 100.0)
        return false;
    if (1.0 > v[1])
        return false;
    if (v[1] > 100.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> carthesianToPolar_radius_range = {std::uniform_real_distribution<double>(1.0, 100.0), std::uniform_real_distribution<double>(1.0, 100.0)};
const int carthesianToPolar_radius_variable_count = 2;


// FPBench triangle
template <class T>
inline T triangle(const std::vector<T> &value_array)
{
	return sqrt((((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[0])) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[1])) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[2]));
}
std::string print_triangle(const std::vector<gmp::Rational> &v)
{
	return std::string() + "sqrt((((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[0]) + ")" + ")) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[1]) + ")" + ")) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[2]) + ")" + "))";
}
bool check_input_triangle(const std::vector<double> &v)
{
    if (9.0 > v[0])
        return false;
    if (v[0] > 9.0)
        return false;
    if (4.71 > v[1])
        return false;
    if (v[1] > 4.89)
        return false;
    if (4.71 > v[2])
        return false;
    if (v[2] > 4.89)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> triangle_range = {std::uniform_real_distribution<double>(9.0, 9.0), std::uniform_real_distribution<double>(4.71, 4.89), std::uniform_real_distribution<double>(4.71, 4.89)};
const int triangle_variable_count = 3;


// FPBench jetEngine
template <class T>
inline T jetEngine(const std::vector<T> &value_array)
{
	return value_array[0] + (((((((((2.0 * value_array[0]) * (((((3.0 * value_array[0]) * value_array[0]) + (2.0 * value_array[1])) - value_array[0]) / ((value_array[0] * value_array[0]) + 1.0))) * ((((((3.0 * value_array[0]) * value_array[0]) + (2.0 * value_array[1])) - value_array[0]) / ((value_array[0] * value_array[0]) + 1.0)) - 3.0)) + ((value_array[0] * value_array[0]) * ((4.0 * (((((3.0 * value_array[0]) * value_array[0]) + (2.0 * value_array[1])) - value_array[0]) / ((value_array[0] * value_array[0]) + 1.0))) - 6.0))) * ((value_array[0] * value_array[0]) + 1.0)) + (((3.0 * value_array[0]) * value_array[0]) * (((((3.0 * value_array[0]) * value_array[0]) + (2.0 * value_array[1])) - value_array[0]) / ((value_array[0] * value_array[0]) + 1.0)))) + ((value_array[0] * value_array[0]) * value_array[0])) + value_array[0]) + (3.0 * (((((3.0 * value_array[0]) * value_array[0]) - (2.0 * value_array[1])) - value_array[0]) / ((value_array[0] * value_array[0]) + 1.0))));
}
std::string print_jetEngine(const std::vector<gmp::Rational> &v)
{
	return std::string() + "" + "(" + rational_to_string(v[0]) + ")" + " + ((((((((((2) * " + "(" + rational_to_string(v[0]) + ")" + ") * ((((((3) * " + "(" + rational_to_string(v[0]) + ")" + ") * " + "(" + rational_to_string(v[0]) + ")" + ") + ((2) * " + "(" + rational_to_string(v[1]) + ")" + ")) - " + "(" + rational_to_string(v[0]) + ")" + ") / ((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[0]) + ")" + ") + (1)))) * (((((((3) * " + "(" + rational_to_string(v[0]) + ")" + ") * " + "(" + rational_to_string(v[0]) + ")" + ") + ((2) * " + "(" + rational_to_string(v[1]) + ")" + ")) - " + "(" + rational_to_string(v[0]) + ")" + ") / ((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[0]) + ")" + ") + (1))) - (3))) + ((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[0]) + ")" + ") * (((4) * ((((((3) * " + "(" + rational_to_string(v[0]) + ")" + ") * " + "(" + rational_to_string(v[0]) + ")" + ") + ((2) * " + "(" + rational_to_string(v[1]) + ")" + ")) - " + "(" + rational_to_string(v[0]) + ")" + ") / ((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[0]) + ")" + ") + (1)))) - (6)))) * ((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[0]) + ")" + ") + (1))) + ((((3) * " + "(" + rational_to_string(v[0]) + ")" + ") * " + "(" + rational_to_string(v[0]) + ")" + ") * ((((((3) * " + "(" + rational_to_string(v[0]) + ")" + ") * " + "(" + rational_to_string(v[0]) + ")" + ") + ((2) * " + "(" + rational_to_string(v[1]) + ")" + ")) - " + "(" + rational_to_string(v[0]) + ")" + ") / ((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[0]) + ")" + ") + (1))))) + ((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[0]) + ")" + ") * " + "(" + rational_to_string(v[0]) + ")" + ")) + " + "(" + rational_to_string(v[0]) + ")" + ") + ((3) * ((((((3) * " + "(" + rational_to_string(v[0]) + ")" + ") * " + "(" + rational_to_string(v[0]) + ")" + ") - ((2) * " + "(" + rational_to_string(v[1]) + ")" + ")) - " + "(" + rational_to_string(v[0]) + ")" + ") / ((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[0]) + ")" + ") + (1)))))";
}
bool check_input_jetEngine(const std::vector<double> &v)
{
    if (-5.0 > v[0])
        return false;
    if (v[0] > 5.0)
        return false;
    if (-20.0 > v[1])
        return false;
    if (v[1] > 5.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> jetEngine_range = {std::uniform_real_distribution<double>(-5.0, 5.0), std::uniform_real_distribution<double>(-20.0, 5.0)};
const int jetEngine_variable_count = 2;


// FPBench sqroot
template <class T>
inline T sqroot(const std::vector<T> &value_array)
{
	return (((1.0 + (0.5 * value_array[0])) - ((0.125 * value_array[0]) * value_array[0])) + (((0.0625 * value_array[0]) * value_array[0]) * value_array[0])) - ((((0.0390625 * value_array[0]) * value_array[0]) * value_array[0]) * value_array[0]);
}
std::string print_sqroot(const std::vector<gmp::Rational> &v)
{
	return std::string() + "((((1) + ((1/2) * " + "(" + rational_to_string(v[0]) + ")" + ")) - (((1/8) * " + "(" + rational_to_string(v[0]) + ")" + ") * " + "(" + rational_to_string(v[0]) + ")" + ")) + ((((1/16) * " + "(" + rational_to_string(v[0]) + ")" + ") * " + "(" + rational_to_string(v[0]) + ")" + ") * " + "(" + rational_to_string(v[0]) + ")" + ")) - (((((5/128) * " + "(" + rational_to_string(v[0]) + ")" + ") * " + "(" + rational_to_string(v[0]) + ")" + ") * " + "(" + rational_to_string(v[0]) + ")" + ") * " + "(" + rational_to_string(v[0]) + ")" + ")";
}
bool check_input_sqroot(const std::vector<double> &v)
{
    if (0.0 > v[0])
        return false;
    if (v[0] > 1.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> sqroot_range = {std::uniform_real_distribution<double>(0.0, 1.0)};
const int sqroot_variable_count = 1;


// FPBench triangle12
template <class T>
inline T triangle12(const std::vector<T> &value_array)
{
	return sqrt((((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[0])) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[1])) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[2]));
}
std::string print_triangle12(const std::vector<gmp::Rational> &v)
{
	return std::string() + "sqrt((((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[0]) + ")" + ")) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[1]) + ")" + ")) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[2]) + ")" + "))";
}
bool check_input_triangle12(const std::vector<double> &v)
{
    if (1.0 > v[0])
        return false;
    if (v[0] > 9.0)
        return false;
    if (1.0 > v[1])
        return false;
    if (v[1] > 9.0)
        return false;
    if (1.0 > v[2])
        return false;
    if (v[2] > 9.0)
        return false;
    if ((v[0] + v[1]) <= (v[2] + 1.0/1000000000000))
        return false;
    if ((v[0] + v[2]) <= (v[1] + 1.0/1000000000000))
        return false;
    if ((v[1] + v[2]) <= (v[0] + 1.0/1000000000000))
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> triangle12_range = {std::uniform_real_distribution<double>(1.0, 9.0), std::uniform_real_distribution<double>(1.0, 9.0), std::uniform_real_distribution<double>(1.0, 9.0)};
const int triangle12_variable_count = 3;


// FPBench triangle10
template <class T>
inline T triangle10(const std::vector<T> &value_array)
{
	return sqrt((((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[0])) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[1])) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[2]));
}
std::string print_triangle10(const std::vector<gmp::Rational> &v)
{
	return std::string() + "sqrt((((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[0]) + ")" + ")) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[1]) + ")" + ")) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[2]) + ")" + "))";
}
bool check_input_triangle10(const std::vector<double> &v)
{
    if (1.0 > v[0])
        return false;
    if (v[0] > 9.0)
        return false;
    if (1.0 > v[1])
        return false;
    if (v[1] > 9.0)
        return false;
    if (1.0 > v[2])
        return false;
    if (v[2] > 9.0)
        return false;
    if ((v[0] + v[1]) <= (v[2] + 1.0/10000000000))
        return false;
    if ((v[0] + v[2]) <= (v[1] + 1.0/10000000000))
        return false;
    if ((v[1] + v[2]) <= (v[0] + 1.0/10000000000))
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> triangle10_range = {std::uniform_real_distribution<double>(1.0, 9.0), std::uniform_real_distribution<double>(1.0, 9.0), std::uniform_real_distribution<double>(1.0, 9.0)};
const int triangle10_variable_count = 3;


// FPBench turbine2
template <class T>
inline T turbine2(const std::vector<T> &value_array)
{
	return ((6.0 * value_array[0]) - (((0.5 * value_array[0]) * (((value_array[1] * value_array[1]) * value_array[2]) * value_array[2])) / (1.0 - value_array[0]))) - 2.5;
}
std::string print_turbine2(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(((6) * " + "(" + rational_to_string(v[0]) + ")" + ") - ((((1/2) * " + "(" + rational_to_string(v[0]) + ")" + ") * (((" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ") * " + "(" + rational_to_string(v[2]) + ")" + ") * " + "(" + rational_to_string(v[2]) + ")" + ")) / ((1) - " + "(" + rational_to_string(v[0]) + ")" + "))) - (5/2)";
}
bool check_input_turbine2(const std::vector<double> &v)
{
    if (-4.5 > v[0])
        return false;
    if (v[0] > -0.3)
        return false;
    if (0.4 > v[1])
        return false;
    if (v[1] > 0.9)
        return false;
    if (3.8 > v[2])
        return false;
    if (v[2] > 7.8)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> turbine2_range = {std::uniform_real_distribution<double>(-4.5, -0.3), std::uniform_real_distribution<double>(0.4, 0.9), std::uniform_real_distribution<double>(3.8, 7.8)};
const int turbine2_variable_count = 3;


// FPBench triangle2
template <class T>
inline T triangle2(const std::vector<T> &value_array)
{
	return sqrt((((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[0])) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[1])) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[2]));
}
std::string print_triangle2(const std::vector<gmp::Rational> &v)
{
	return std::string() + "sqrt((((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[0]) + ")" + ")) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[1]) + ")" + ")) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[2]) + ")" + "))";
}
bool check_input_triangle2(const std::vector<double> &v)
{
    if (1.0 > v[0])
        return false;
    if (v[0] > 9.0)
        return false;
    if (1.0 > v[1])
        return false;
    if (v[1] > 9.0)
        return false;
    if (1.0 > v[2])
        return false;
    if (v[2] > 9.0)
        return false;
    if ((v[0] + v[1]) <= (v[2] + 1.0/100))
        return false;
    if ((v[0] + v[2]) <= (v[1] + 1.0/100))
        return false;
    if ((v[1] + v[2]) <= (v[0] + 1.0/100))
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> triangle2_range = {std::uniform_real_distribution<double>(1.0, 9.0), std::uniform_real_distribution<double>(1.0, 9.0), std::uniform_real_distribution<double>(1.0, 9.0)};
const int triangle2_variable_count = 3;


// FPBench rigidBody1
template <class T>
inline T rigidBody1(const std::vector<T> &value_array)
{
	return ((-(value_array[0] * value_array[1]) - ((2.0 * value_array[1]) * value_array[2])) - value_array[0]) - value_array[2];
}
std::string print_rigidBody1(const std::vector<gmp::Rational> &v)
{
	return std::string() + "((-(" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ") - (((2) * " + "(" + rational_to_string(v[1]) + ")" + ") * " + "(" + rational_to_string(v[2]) + ")" + ")) - " + "(" + rational_to_string(v[0]) + ")" + ") - " + "(" + rational_to_string(v[2]) + ")";
}
bool check_input_rigidBody1(const std::vector<double> &v)
{
    if (-15.0 > v[0])
        return false;
    if (v[0] > 15.0)
        return false;
    if (-15.0 > v[1])
        return false;
    if (v[1] > 15.0)
        return false;
    if (-15.0 > v[2])
        return false;
    if (v[2] > 15.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> rigidBody1_range = {std::uniform_real_distribution<double>(-15.0, 15.0), std::uniform_real_distribution<double>(-15.0, 15.0), std::uniform_real_distribution<double>(-15.0, 15.0)};
const int rigidBody1_variable_count = 3;


// FPBench NMSE problem 3.4.1
template <class T>
inline T NMSE_problem_3_4_1(const std::vector<T> &value_array)
{
    return (1.0 - cos(value_array[0])) / (value_array[0] * value_array[0]);
}
std::string print_NMSE_problem_3_4_1(const std::vector<gmp::Rational> &v)
{
	return std::string() + "((1) - cos(" + "(" + rational_to_string(v[0]) + ")" + ")) / (" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[0]) + ")" + ")";
}
bool check_input_NMSE_problem_3_4_1(const std::vector<double> &v)
{
    return true;
}
const std::vector<std::uniform_real_distribution<double>> NMSE_problem_3_4_1_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int NMSE_problem_3_4_1_variable_count = 1;


// FPBench exp1x_log
template <class T>
inline T exp1x_log(const std::vector<T> &value_array)
{
	return (exp(value_array[0]) - 1.0) / log(exp(value_array[0]));
}
std::string print_exp1x_log(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(exp(" + "(" + rational_to_string(v[0]) + ")" + ") - (1)) / log(exp(" + "(" + rational_to_string(v[0]) + ")" + "))";
}
bool check_input_exp1x_log(const std::vector<double> &v)
{
    if (0.01 > v[0])
        return false;
    if (v[0] > 0.5)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> exp1x_log_range = {std::uniform_real_distribution<double>(0.01, 0.5)};
const int exp1x_log_variable_count = 1;


// FPBench Complex square root
template <class T>
inline T Complex_square_root(const std::vector<T> &value_array)
{
	return 0.5 * sqrt(2.0 * (sqrt((value_array[0] * value_array[0]) + (value_array[1] * value_array[1])) + value_array[0]));
}
std::string print_Complex_square_root(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(1/2) * sqrt((2) * (sqrt((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[0]) + ")" + ") + (" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ")) + " + "(" + rational_to_string(v[0]) + ")" + "))";
}
bool check_input_Complex_square_root(const std::vector<double> &v)
{
    return true;
}
const std::vector<std::uniform_real_distribution<double>> Complex_square_root_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int Complex_square_root_variable_count = 2;


// FPBench carthesianToPolar, theta
template <class T>
inline T carthesianToPolar_theta(const std::vector<T> &value_array)
{
	return (atan(value_array[1] / value_array[0])) * (180.0 / (3.14159265359));
}
std::string print_carthesianToPolar_theta(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(atan(" + "(" + rational_to_string(v[1]) + ")" + " / " + "(" + rational_to_string(v[0]) + ")" + ")) * ((180) / ((314159265359/100000000000)))";
}
bool check_input_carthesianToPolar_theta(const std::vector<double> &v)
{
    if (1.0 > v[0])
        return false;
    if (v[0] > 100.0)
        return false;
    if (1.0 > v[1])
        return false;
    if (v[1] > 100.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> carthesianToPolar_theta_range = {std::uniform_real_distribution<double>(1.0, 100.0), std::uniform_real_distribution<double>(1.0, 100.0)};
const int carthesianToPolar_theta_variable_count = 2;


// FPBench NMSE example 3.7
template <class T>
inline T NMSE_example_3_7(const std::vector<T> &value_array)
{
	return exp(value_array[0]) - 1.0;
}
std::string print_NMSE_example_3_7(const std::vector<gmp::Rational> &v)
{
	return std::string() + "exp(" + "(" + rational_to_string(v[0]) + ")" + ") - (1)";
}
bool check_input_NMSE_example_3_7(const std::vector<double> &v)
{
    return true;
}
const std::vector<std::uniform_real_distribution<double>> NMSE_example_3_7_range = {std::uniform_real_distribution<double>(-700, 700)};
const int NMSE_example_3_7_variable_count = 1;


// FPBench floudas3
template <class T>
inline T floudas3(const std::vector<T> &value_array)
{
	return ((-12.0 * value_array[0]) - (7.0 * value_array[1])) + (value_array[1] * value_array[1]);
}
std::string print_floudas3(const std::vector<gmp::Rational> &v)
{
	return std::string() + "((-(12) * " + "(" + rational_to_string(v[0]) + ")" + ") - ((7) * " + "(" + rational_to_string(v[1]) + ")" + ")) + (" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ")";
}
bool check_input_floudas3(const std::vector<double> &v)
{
    if (0.0 > v[0])
        return false;
    if (v[0] > 2.0)
        return false;
    if (0.0 > v[1])
        return false;
    if (v[1] > 3.0)
        return false;
    if (((-2 * ((v[0] * v[0]) * (v[0] * v[0]))) + 2) < v[1])
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> floudas3_range = {std::uniform_real_distribution<double>(0.0, 2.0), std::uniform_real_distribution<double>(0.0, 3.0)};
const int floudas3_variable_count = 2;


// FPBench NMSE example 3.6
template <class T>
inline T NMSE_example_3_6(const std::vector<T> &value_array)
{
	return (1.0 / sqrt(value_array[0])) - (1.0 / sqrt(value_array[0] + 1.0));
}
std::string print_NMSE_example_3_6(const std::vector<gmp::Rational> &v)
{
	return std::string() + "((1) / sqrt(" + "(" + rational_to_string(v[0]) + ")" + ")) - ((1) / sqrt(" + "(" + rational_to_string(v[0]) + ")" + " + (1)))";
}
bool check_input_NMSE_example_3_6(const std::vector<double> &v)
{
    return true;
}
const std::vector<std::uniform_real_distribution<double>> NMSE_example_3_6_range = {std::uniform_real_distribution<double>(0, RAND_MAX)};
const int NMSE_example_3_6_variable_count = 1;


// FPBench i4
template <class T>
inline T i4(const std::vector<T> &value_array)
{
	return sqrt(value_array[0] + (value_array[1] * value_array[1]));
}
std::string print_i4(const std::vector<gmp::Rational> &v)
{
	return std::string() + "sqrt(" + "(" + rational_to_string(v[0]) + ")" + " + (" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + "))";
}
bool check_input_i4(const std::vector<double> &v)
{
    if (0.1 > v[0])
        return false;
    if (v[0] > 10.0)
        return false;
    if (-5.0 > v[1])
        return false;
    if (v[1] > 5.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> i4_range = {std::uniform_real_distribution<double>(0.1, 10.0), std::uniform_real_distribution<double>(-5.0, 5.0)};
const int i4_variable_count = 2;


// FPBench test02_sum8
template <class T>
inline T test02_sum8(const std::vector<T> &value_array)
{
	return ((((((value_array[0] + value_array[1]) + value_array[2]) + value_array[3]) + value_array[4]) + value_array[5]) + value_array[6]) + value_array[7];
}
std::string print_test02_sum8(const std::vector<gmp::Rational> &v)
{
	return std::string() + "((((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") + " + "(" + rational_to_string(v[3]) + ")" + ") + " + "(" + rational_to_string(v[4]) + ")" + ") + " + "(" + rational_to_string(v[5]) + ")" + ") + " + "(" + rational_to_string(v[6]) + ")" + ") + " + "(" + rational_to_string(v[7]) + ")";
}
bool check_input_test02_sum8(const std::vector<double> &v)
{
    if (1.0 >= v[0])
        return false;
    if (v[0] >= 2.0)
        return false;
    if (1.0 >= v[1])
        return false;
    if (v[1] >= 2.0)
        return false;
    if (1.0 >= v[2])
        return false;
    if (v[2] >= 2.0)
        return false;
    if (1.0 >= v[3])
        return false;
    if (v[3] >= 2.0)
        return false;
    if (1.0 >= v[4])
        return false;
    if (v[4] >= 2.0)
        return false;
    if (1.0 >= v[5])
        return false;
    if (v[5] >= 2.0)
        return false;
    if (1.0 >= v[6])
        return false;
    if (v[6] >= 2.0)
        return false;
    if (1.0 >= v[7])
        return false;
    if (v[7] >= 2.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> test02_sum8_range = {std::uniform_real_distribution<double>(1.0, 2.0), std::uniform_real_distribution<double>(1.0, 2.0), std::uniform_real_distribution<double>(1.0, 2.0), std::uniform_real_distribution<double>(1.0, 2.0), std::uniform_real_distribution<double>(1.0, 2.0), std::uniform_real_distribution<double>(1.0, 2.0), std::uniform_real_distribution<double>(1.0, 2.0), std::uniform_real_distribution<double>(1.0, 2.0)};
const int test02_sum8_variable_count = 8;


// FPBench triangle6
template <class T>
inline T triangle6(const std::vector<T> &value_array)
{
	return sqrt((((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[0])) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[1])) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[2]));
}
std::string print_triangle6(const std::vector<gmp::Rational> &v)
{
	return std::string() + "sqrt((((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[0]) + ")" + ")) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[1]) + ")" + ")) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[2]) + ")" + "))";
}
bool check_input_triangle6(const std::vector<double> &v)
{
    if (1.0 > v[0])
        return false;
    if (v[0] > 9.0)
        return false;
    if (1.0 > v[1])
        return false;
    if (v[1] > 9.0)
        return false;
    if (1.0 > v[2])
        return false;
    if (v[2] > 9.0)
        return false;
    if ((v[0] + v[1]) <= (v[2] + 1.0/1000000))
        return false;
    if ((v[0] + v[2]) <= (v[1] + 1.0/1000000))
        return false;
    if ((v[1] + v[2]) <= (v[0] + 1.0/1000000))
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> triangle6_range = {std::uniform_real_distribution<double>(1.0, 9.0), std::uniform_real_distribution<double>(1.0, 9.0), std::uniform_real_distribution<double>(1.0, 9.0)};
const int triangle6_variable_count = 3;


// FPBench carbonGas
template <class T>
inline T carbonGas(const std::vector<T> &value_array)
{
	return (((35000000.0) + (((0.401) * ((1000.0) / value_array[0])) * ((1000.0) / value_array[0]))) * (value_array[0] - ((1000.0) * (4.27e-05)))) - (((1.3806503e-23) * (1000.0)) * (300.0));
}
std::string print_carbonGas(const std::vector<gmp::Rational> &v)
{
	return std::string() + "((((35000000)) + ((((401/1000)) * (((1000)) / " + "(" + rational_to_string(v[0]) + ")" + ")) * (((1000)) / " + "(" + rational_to_string(v[0]) + ")" + "))) * (" + "(" + rational_to_string(v[0]) + ")" + " - (((1000)) * (427/10000000)))) - (((13806503/1000000000000000000000000000000) * ((1000))) * ((300)))";
}
bool check_input_carbonGas(const std::vector<double> &v)
{
    if (0.1 > v[0])
        return false;
    if (v[0] > 0.5)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> carbonGas_range = {std::uniform_real_distribution<double>(0.1, 0.5)};
const int carbonGas_variable_count = 1;


// FPBench sphere
template <class T>
inline T sphere(const std::vector<T> &value_array)
{
	return value_array[0] + ((value_array[1] * (sin(value_array[2]))) * (cos(value_array[3])));
}
std::string print_sphere(const std::vector<gmp::Rational> &v)
{
	return std::string() + "" + "(" + rational_to_string(v[0]) + ")" + " + ((" + "(" + rational_to_string(v[1]) + ")" + " * (sin(" + "(" + rational_to_string(v[2]) + ")" + "))) * (cos(" + "(" + rational_to_string(v[3]) + ")" + ")))";
}
bool check_input_sphere(const std::vector<double> &v)
{
    if (-10.0 > v[0])
        return false;
    if (v[0] > 10.0)
        return false;
    if (0.0 > v[1])
        return false;
    if (v[1] > 10.0)
        return false;
    if (-1.570796 > v[2])
        return false;
    if (v[2] > 1.570796)
        return false;
    if (-3.14159265 > v[3])
        return false;
    if (v[3] > 3.14159265)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> sphere_range = {std::uniform_real_distribution<double>(-10.0, 10.0), std::uniform_real_distribution<double>(0.0, 10.0), std::uniform_real_distribution<double>(-1.570796, 1.570796), std::uniform_real_distribution<double>(-3.14159265, 3.14159265)};
const int sphere_variable_count = 4;


// FPBench test01_sum3
template <class T>
inline T test01_sum3(const std::vector<T> &value_array)
{
	return (((value_array[0] + value_array[1]) - value_array[2]) + ((value_array[1] + value_array[2]) - value_array[0])) + ((value_array[2] + value_array[0]) - value_array[1]);
}
std::string print_test01_sum3(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") - " + "(" + rational_to_string(v[2]) + ")" + ") + ((" + "(" + rational_to_string(v[1]) + ")" + " + " + "(" + rational_to_string(v[2]) + ")" + ") - " + "(" + rational_to_string(v[0]) + ")" + ")) + ((" + "(" + rational_to_string(v[2]) + ")" + " + " + "(" + rational_to_string(v[0]) + ")" + ") - " + "(" + rational_to_string(v[1]) + ")" + ")";
}
bool check_input_test01_sum3(const std::vector<double> &v)
{
    if (1.0 >= v[0])
        return false;
    if (v[0] >= 2.0)
        return false;
    if (1.0 >= v[1])
        return false;
    if (v[1] >= 2.0)
        return false;
    if (1.0 >= v[2])
        return false;
    if (v[2] >= 2.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> test01_sum3_range = {std::uniform_real_distribution<double>(1.0, 2.0), std::uniform_real_distribution<double>(1.0, 2.0), std::uniform_real_distribution<double>(1.0, 2.0)};
const int test01_sum3_variable_count = 3;


// FPBench test05_nonlin1, test2
template <class T>
inline T test05_nonlin1_test2(const std::vector<T> &value_array)
{
	return 1.0 / (value_array[0] + 1.0);
}
std::string print_test05_nonlin1_test2(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(1) / (" + "(" + rational_to_string(v[0]) + ")" + " + (1))";
}
bool check_input_test05_nonlin1_test2(const std::vector<double> &v)
{
    if (1.00001 >= v[0])
        return false;
    if (v[0] >= 2.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> test05_nonlin1_test2_range = {std::uniform_real_distribution<double>(1.00001, 2.0)};
const int test05_nonlin1_test2_variable_count = 1;


// FPBench kepler1
template <class T>
inline T kepler1(const std::vector<T> &value_array)
{
	return (((((((value_array[0] * value_array[3]) * (((-value_array[0] + value_array[1]) + value_array[2]) - value_array[3])) + (value_array[1] * (((value_array[0] - value_array[1]) + value_array[2]) + value_array[3]))) + (value_array[2] * (((value_array[0] + value_array[1]) - value_array[2]) + value_array[3]))) - ((value_array[1] * value_array[2]) * value_array[3])) - (value_array[0] * value_array[2])) - (value_array[0] * value_array[1])) - value_array[3];
}
std::string print_kepler1(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(((((((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[3]) + ")" + ") * (((-" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") - " + "(" + rational_to_string(v[3]) + ")" + ")) + (" + "(" + rational_to_string(v[1]) + ")" + " * (((" + "(" + rational_to_string(v[0]) + ")" + " - " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") + " + "(" + rational_to_string(v[3]) + ")" + "))) + (" + "(" + rational_to_string(v[2]) + ")" + " * (((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") - " + "(" + rational_to_string(v[2]) + ")" + ") + " + "(" + rational_to_string(v[3]) + ")" + "))) - ((" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[2]) + ")" + ") * " + "(" + rational_to_string(v[3]) + ")" + ")) - (" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[2]) + ")" + ")) - (" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ")) - " + "(" + rational_to_string(v[3]) + ")";
}
bool check_input_kepler1(const std::vector<double> &v)
{
    if (4.0 > v[0])
        return false;
    if (v[0] > 6.36)
        return false;
    if (4.0 > v[1])
        return false;
    if (v[1] > 6.36)
        return false;
    if (4.0 > v[2])
        return false;
    if (v[2] > 6.36)
        return false;
    if (4.0 > v[3])
        return false;
    if (v[3] > 6.36)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> kepler1_range = {std::uniform_real_distribution<double>(4.0, 6.36), std::uniform_real_distribution<double>(4.0, 6.36), std::uniform_real_distribution<double>(4.0, 6.36), std::uniform_real_distribution<double>(4.0, 6.36)};
const int kepler1_variable_count = 4;


// FPBench NMSE example 3.1
template <class T>
inline T NMSE_example_3_1(const std::vector<T> &value_array)
{
	return sqrt(value_array[0] + 1.0) - sqrt(value_array[0]);
}
std::string print_NMSE_example_3_1(const std::vector<gmp::Rational> &v)
{
	return std::string() + "sqrt(" + "(" + rational_to_string(v[0]) + ")" + " + (1)) - sqrt(" + "(" + rational_to_string(v[0]) + ")" + ")";
}
bool check_input_NMSE_example_3_1(const std::vector<double> &v)
{
    return true;
}
const std::vector<std::uniform_real_distribution<double>> NMSE_example_3_1_range = {std::uniform_real_distribution<double>(0, RAND_MAX)};
const int NMSE_example_3_1_variable_count = 1;


// FPBench matrixDeterminant
template <class T>
inline T matrixDeterminant(const std::vector<T> &value_array)
{
	return ((((value_array[0] * value_array[4]) * value_array[8]) + ((value_array[1] * value_array[5]) * value_array[6])) + ((value_array[2] * value_array[3]) * value_array[7])) - ((((value_array[2] * value_array[4]) * value_array[6]) + ((value_array[1] * value_array[3]) * value_array[8])) + ((value_array[0] * value_array[5]) * value_array[7]));
}
std::string print_matrixDeterminant(const std::vector<gmp::Rational> &v)
{
	return std::string() + "((((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[4]) + ")" + ") * " + "(" + rational_to_string(v[8]) + ")" + ") + ((" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[5]) + ")" + ") * " + "(" + rational_to_string(v[6]) + ")" + ")) + ((" + "(" + rational_to_string(v[2]) + ")" + " * " + "(" + rational_to_string(v[3]) + ")" + ") * " + "(" + rational_to_string(v[7]) + ")" + ")) - ((((" + "(" + rational_to_string(v[2]) + ")" + " * " + "(" + rational_to_string(v[4]) + ")" + ") * " + "(" + rational_to_string(v[6]) + ")" + ") + ((" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[3]) + ")" + ") * " + "(" + rational_to_string(v[8]) + ")" + ")) + ((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[5]) + ")" + ") * " + "(" + rational_to_string(v[7]) + ")" + "))";
}
bool check_input_matrixDeterminant(const std::vector<double> &v)
{
    if (-10.0 > v[0])
        return false;
    if (v[0] > 10.0)
        return false;
    if (-10.0 > v[1])
        return false;
    if (v[1] > 10.0)
        return false;
    if (-10.0 > v[2])
        return false;
    if (v[2] > 10.0)
        return false;
    if (-10.0 > v[3])
        return false;
    if (v[3] > 10.0)
        return false;
    if (-10.0 > v[4])
        return false;
    if (v[4] > 10.0)
        return false;
    if (-10.0 > v[5])
        return false;
    if (v[5] > 10.0)
        return false;
    if (-10.0 > v[6])
        return false;
    if (v[6] > 10.0)
        return false;
    if (-10.0 > v[7])
        return false;
    if (v[7] > 10.0)
        return false;
    if (-10.0 > v[8])
        return false;
    if (v[8] > 10.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> matrixDeterminant_range = {std::uniform_real_distribution<double>(-10.0, 10.0), std::uniform_real_distribution<double>(-10.0, 10.0), std::uniform_real_distribution<double>(-10.0, 10.0), std::uniform_real_distribution<double>(-10.0, 10.0), std::uniform_real_distribution<double>(-10.0, 10.0), std::uniform_real_distribution<double>(-10.0, 10.0), std::uniform_real_distribution<double>(-10.0, 10.0), std::uniform_real_distribution<double>(-10.0, 10.0), std::uniform_real_distribution<double>(-10.0, 10.0)};
const int matrixDeterminant_variable_count = 9;


// FPBench NMSE p42, positive
template <class T>
inline T NMSE_p42_positive(const std::vector<T> &value_array)
{
	return (-value_array[1] + sqrt((value_array[1] * value_array[1]) - (4.0 * (value_array[0] * value_array[2])))) / (2.0 * value_array[0]);
}
std::string print_NMSE_p42_positive(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(-" + "(" + rational_to_string(v[1]) + ")" + " + sqrt((" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ") - ((4) * (" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[2]) + ")" + ")))) / ((2) * " + "(" + rational_to_string(v[0]) + ")" + ")";
}
bool check_input_NMSE_p42_positive(const std::vector<double> &v)
{
    if ((v[1] * v[1]) < (4 * (v[0] * v[2])))
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> NMSE_p42_positive_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int NMSE_p42_positive_variable_count = 3;


// FPBench sqrt_add
template <class T>
inline T sqrt_add(const std::vector<T> &value_array)
{
	return 1.0 / (sqrt(value_array[0] + 1.0) + sqrt(value_array[0]));
}
std::string print_sqrt_add(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(1) / (sqrt(" + "(" + rational_to_string(v[0]) + ")" + " + (1)) + sqrt(" + "(" + rational_to_string(v[0]) + ")" + "))";
}
bool check_input_sqrt_add(const std::vector<double> &v)
{
    if (1.0 > v[0])
        return false;
    if (v[0] > 1000.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> sqrt_add_range = {std::uniform_real_distribution<double>(1.0, 1000.0)};
const int sqrt_add_variable_count = 1;


// FPBench NMSE problem 3.4.5
template <class T>
inline T NMSE_problem_3_4_5(const std::vector<T> &value_array)
{
	return (value_array[0] - sin(value_array[0])) / (value_array[0] - tan(value_array[0]));
}
std::string print_NMSE_problem_3_4_5(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(" + "(" + rational_to_string(v[0]) + ")" + " - sin(" + "(" + rational_to_string(v[0]) + ")" + ")) / (" + "(" + rational_to_string(v[0]) + ")" + " - tan(" + "(" + rational_to_string(v[0]) + ")" + "))";
}
bool check_input_NMSE_problem_3_4_5(const std::vector<double> &v)
{
    return true;
}
const std::vector<std::uniform_real_distribution<double>> NMSE_problem_3_4_5_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int NMSE_problem_3_4_5_variable_count = 1;


// FPBench floudas1
template <class T>
inline T floudas1(const std::vector<T> &value_array)
{
	return (((((-25.0 * ((value_array[0] - 2.0) * (value_array[0] - 2.0))) - ((value_array[1] - 2.0) * (value_array[1] - 2.0))) - ((value_array[2] - 1.0) * (value_array[2] - 1.0))) - ((value_array[3] - 4.0) * (value_array[3] - 4.0))) - ((value_array[4] - 1.0) * (value_array[4] - 1.0))) - ((value_array[5] - 4.0) * (value_array[5] - 4.0));
}
std::string print_floudas1(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(((((-(25) * ((" + "(" + rational_to_string(v[0]) + ")" + " - (2)) * (" + "(" + rational_to_string(v[0]) + ")" + " - (2)))) - ((" + "(" + rational_to_string(v[1]) + ")" + " - (2)) * (" + "(" + rational_to_string(v[1]) + ")" + " - (2)))) - ((" + "(" + rational_to_string(v[2]) + ")" + " - (1)) * (" + "(" + rational_to_string(v[2]) + ")" + " - (1)))) - ((" + "(" + rational_to_string(v[3]) + ")" + " - (4)) * (" + "(" + rational_to_string(v[3]) + ")" + " - (4)))) - ((" + "(" + rational_to_string(v[4]) + ")" + " - (1)) * (" + "(" + rational_to_string(v[4]) + ")" + " - (1)))) - ((" + "(" + rational_to_string(v[5]) + ")" + " - (4)) * (" + "(" + rational_to_string(v[5]) + ")" + " - (4)))";
}
bool check_input_floudas1(const std::vector<double> &v)
{
    if (0.0 > v[0])
        return false;
    if (v[0] > 6.0)
        return false;
    if (0.0 > v[1])
        return false;
    if (v[1] > 6.0)
        return false;
    if (1.0 > v[2])
        return false;
    if (v[2] > 5.0)
        return false;
    if (0.0 > v[3])
        return false;
    if (v[3] > 6.0)
        return false;
    if (0.0 > v[4])
        return false;
    if (v[4] > 6.0)
        return false;
    if (0.0 > v[5])
        return false;
    if (v[5] > 10.0)
        return false;
    if (((((v[2] - 3) * (v[2] - 3)) + v[3]) - 4) < 0)
        return false;
    if (((((v[4] - 3) * (v[4] - 3)) + v[5]) - 4) < 0)
        return false;
    if (((2 - v[0]) + (3 * v[1])) < 0)
        return false;
    if (((2 + v[0]) - v[1]) < 0)
        return false;
    if (((6 - v[0]) - v[1]) < 0)
        return false;
    if (((v[0] + v[1]) - 2) < 0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> floudas1_range = {std::uniform_real_distribution<double>(0.0, 6.0), std::uniform_real_distribution<double>(0.0, 6.0), std::uniform_real_distribution<double>(1.0, 5.0), std::uniform_real_distribution<double>(0.0, 6.0), std::uniform_real_distribution<double>(0.0, 6.0), std::uniform_real_distribution<double>(0.0, 10.0)};
const int floudas1_variable_count = 6;


// FPBench NMSE problem 3.3.2
template <class T>
inline T NMSE_problem_3_3_2(const std::vector<T> &value_array)
{
	return tan(value_array[0] + value_array[1]) - tan(value_array[0]);
}
std::string print_NMSE_problem_3_3_2(const std::vector<gmp::Rational> &v)
{
	return std::string() + "tan(" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") - tan(" + "(" + rational_to_string(v[0]) + ")" + ")";
}
bool check_input_NMSE_problem_3_3_2(const std::vector<double> &v)
{
    return true;
}
const std::vector<std::uniform_real_distribution<double>> NMSE_problem_3_3_2_range = {std::uniform_real_distribution<double>((-7074237750381340.0 /  2097152.0) / 2.1, (7074237750381340.0 /  2097152.0) / 2.1), std::uniform_real_distribution<double>((-7074237750381340.0 /  2097152.0) / 2.1, (7074237750381340.0 /  2097152.0) / 2.1)};
const int NMSE_problem_3_3_2_variable_count = 2;


// FPBench intro-example
template <class T>
inline T intro_example(const std::vector<T> &value_array)
{
	return value_array[0] / (value_array[0] + 1.0);
}
std::string print_intro_example(const std::vector<gmp::Rational> &v)
{
	return std::string() + "" + "(" + rational_to_string(v[0]) + ")" + " / (" + "(" + rational_to_string(v[0]) + ")" + " + (1))";
}
bool check_input_intro_example(const std::vector<double> &v)
{
    if (0.0 > v[0])
        return false;
    if (v[0] > 999.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> intro_example_range = {std::uniform_real_distribution<double>(0.0, 999.0)};
const int intro_example_variable_count = 1;


// FPBench test06_sums4, sum2
template <class T>
inline T test06_sums4_sum2(const std::vector<T> &value_array)
{
	return (value_array[0] + value_array[1]) + (value_array[2] + value_array[3]);
}
std::string print_test06_sums4_sum2(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + (" + "(" + rational_to_string(v[2]) + ")" + " + " + "(" + rational_to_string(v[3]) + ")" + ")";
}
bool check_input_test06_sums4_sum2(const std::vector<double> &v)
{
    if (-1e-05 >= v[0])
        return false;
    if (v[0] >= 1.00001)
        return false;
    if (0.0 >= v[1])
        return false;
    if (v[1] >= 1.0)
        return false;
    if (0.0 >= v[2])
        return false;
    if (v[2] >= 1.0)
        return false;
    if (0.0 >= v[3])
        return false;
    if (v[3] >= 1.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> test06_sums4_sum2_range = {std::uniform_real_distribution<double>(-1e-05, 1.00001), std::uniform_real_distribution<double>(0.0, 1.0), std::uniform_real_distribution<double>(0.0, 1.0), std::uniform_real_distribution<double>(0.0, 1.0)};
const int test06_sums4_sum2_variable_count = 4;


// FPBench himmilbeau
template <class T>
inline T himmilbeau(const std::vector<T> &value_array)
{
	return ((((value_array[0] * value_array[0]) + value_array[1]) - 11.0) * (((value_array[0] * value_array[0]) + value_array[1]) - 11.0)) + (((value_array[0] + (value_array[1] * value_array[1])) - 7.0) * ((value_array[0] + (value_array[1] * value_array[1])) - 7.0));
}
std::string print_himmilbeau(const std::vector<gmp::Rational> &v)
{
	return std::string() + "((((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[0]) + ")" + ") + " + "(" + rational_to_string(v[1]) + ")" + ") - (11)) * (((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[0]) + ")" + ") + " + "(" + rational_to_string(v[1]) + ")" + ") - (11))) + (((" + "(" + rational_to_string(v[0]) + ")" + " + (" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ")) - (7)) * ((" + "(" + rational_to_string(v[0]) + ")" + " + (" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ")) - (7)))";
}
bool check_input_himmilbeau(const std::vector<double> &v)
{
    if (-5.0 > v[0])
        return false;
    if (v[0] > 5.0)
        return false;
    if (-5.0 > v[1])
        return false;
    if (v[1] > 5.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> himmilbeau_range = {std::uniform_real_distribution<double>(-5.0, 5.0), std::uniform_real_distribution<double>(-5.0, 5.0)};
const int himmilbeau_variable_count = 2;


// FPBench NMSE problem 3.3.6
template <class T>
inline T NMSE_problem_3_3_6(const std::vector<T> &value_array)
{
	return log(value_array[0] + 1.0) - log(value_array[0]);
}
std::string print_NMSE_problem_3_3_6(const std::vector<gmp::Rational> &v)
{
	return std::string() + "log(" + "(" + rational_to_string(v[0]) + ")" + " + (1)) - log(" + "(" + rational_to_string(v[0]) + ")" + ")";
}
bool check_input_NMSE_problem_3_3_6(const std::vector<double> &v)
{
    return true;
}
const std::vector<std::uniform_real_distribution<double>> NMSE_problem_3_3_6_range = {std::uniform_real_distribution<double>(0, RAND_MAX)};
const int NMSE_problem_3_3_6_variable_count = 1;


// FPBench intro-example-mixed
template <class T>
inline T intro_example_mixed(const std::vector<T> &value_array)
{
	return (value_array[0] / ((value_array[0] + 1.0)));
}
std::string print_intro_example_mixed(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(" + "(" + rational_to_string(v[0]) + ")" + " / ((" + "(" + rational_to_string(v[0]) + ")" + " + (1))))";
}
bool check_input_intro_example_mixed(const std::vector<double> &v)
{
    if (1.0 > v[0])
        return false;
    if (v[0] > 999.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> intro_example_mixed_range = {std::uniform_real_distribution<double>(1.0, 999.0)};
const int intro_example_mixed_variable_count = 1;


// FPBench NMSE problem 3.4.3
template <class T>
inline T NMSE_problem_3_4_3(const std::vector<T> &value_array)
{
	return log((1.0 - value_array[0]) / (1.0 + value_array[0]));
}
std::string print_NMSE_problem_3_4_3(const std::vector<gmp::Rational> &v)
{
	return std::string() + "log(((1) - " + "(" + rational_to_string(v[0]) + ")" + ") / ((1) + " + "(" + rational_to_string(v[0]) + ")" + "))";
}
bool check_input_NMSE_problem_3_4_3(const std::vector<double> &v)
{
    if (-1.0 >= v[0])
        return false;
    if (v[0] >= 1.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> NMSE_problem_3_4_3_range = {std::uniform_real_distribution<double>(-1.0, 1.0)};
const int NMSE_problem_3_4_3_variable_count = 1;


// FPBench exp1x_32
template <class T>
inline T exp1x_32(const std::vector<T> &value_array)
{
	return (exp(value_array[0]) - 1.0) / value_array[0];
}
std::string print_exp1x_32(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(exp(" + "(" + rational_to_string(v[0]) + ")" + ") - (1)) / " + "(" + rational_to_string(v[0]) + ")";
}
bool check_input_exp1x_32(const std::vector<double> &v)
{
    if (0.01 > v[0])
        return false;
    if (v[0] > 0.5)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> exp1x_32_range = {std::uniform_real_distribution<double>(0.01, 0.5)};
const int exp1x_32_variable_count = 1;


// FPBench NMSE problem 3.2.1, positive
template <class T>
inline T NMSE_problem_3_2_1_positive(const std::vector<T> &value_array)
{
	return (-value_array[1] + sqrt((value_array[1] * value_array[1]) - (value_array[0] * value_array[2]))) / value_array[0];
}
std::string print_NMSE_problem_3_2_1_positive(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(-" + "(" + rational_to_string(v[1]) + ")" + " + sqrt((" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ") - (" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[2]) + ")" + "))) / " + "(" + rational_to_string(v[0]) + ")";
}
bool check_input_NMSE_problem_3_2_1_positive(const std::vector<double> &v)
{
    if ((v[1] * v[1]) < (v[0] * v[2]))
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> NMSE_problem_3_2_1_positive_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int NMSE_problem_3_2_1_positive_variable_count = 3;


// FPBench polarToCarthesian, y
template <class T>
inline T polarToCarthesian_y(const std::vector<T> &value_array)
{
	return value_array[0] * sin((value_array[1] * ((3.14159265359) / 180.0)));
}
std::string print_polarToCarthesian_y(const std::vector<gmp::Rational> &v)
{
	return std::string() + "" + "(" + rational_to_string(v[0]) + ")" + " * sin((" + "(" + rational_to_string(v[1]) + ")" + " * (((314159265359/100000000000)) / (180))))";
}
bool check_input_polarToCarthesian_y(const std::vector<double> &v)
{
    if (1.0 > v[0])
        return false;
    if (v[0] > 10.0)
        return false;
    if (0.0 > v[1])
        return false;
    if (v[1] > 360.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> polarToCarthesian_y_range = {std::uniform_real_distribution<double>(1.0, 10.0), std::uniform_real_distribution<double>(0.0, 360.0)};
const int polarToCarthesian_y_variable_count = 2;


// FPBench Rump's example revisited for floating point
template <class T>
inline T Rump_s_example_revisited_for_floating_point(const std::vector<T> &value_array)
{
	return ((((333.75 - (value_array[0] * value_array[0])) * (((value_array[1] * value_array[1]) * (value_array[1] * value_array[1])) * (value_array[1] * value_array[1]))) + ((value_array[0] * value_array[0]) * ((((11.0 * (value_array[0] * value_array[0])) * (value_array[1] * value_array[1])) - (121.0 * ((value_array[1] * value_array[1]) * (value_array[1] * value_array[1])))) - 2.0))) + (5.5 * (((value_array[1] * value_array[1]) * (value_array[1] * value_array[1])) * ((value_array[1] * value_array[1]) * (value_array[1] * value_array[1]))))) + (value_array[0] / (2.0 * value_array[1]));
}
std::string print_Rump_s_example_revisited_for_floating_point(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(((((1335/4) - (" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[0]) + ")" + ")) * (((" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ") * (" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ")) * (" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + "))) + ((" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[0]) + ")" + ") * (((((11) * (" + "(" + rational_to_string(v[0]) + ")" + " * " + "(" + rational_to_string(v[0]) + ")" + ")) * (" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ")) - ((121) * ((" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ") * (" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ")))) - (2)))) + ((11/2) * (((" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ") * (" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ")) * ((" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + ") * (" + "(" + rational_to_string(v[1]) + ")" + " * " + "(" + rational_to_string(v[1]) + ")" + "))))) + (" + "(" + rational_to_string(v[0]) + ")" + " / ((2) * " + "(" + rational_to_string(v[1]) + ")" + "))";
}
bool check_input_Rump_s_example_revisited_for_floating_point(const std::vector<double> &v)
{
    return true;
}
const std::vector<std::uniform_real_distribution<double>> Rump_s_example_revisited_for_floating_point_range = {std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX), std::uniform_real_distribution<double>(-RAND_MAX + 1, RAND_MAX)};
const int Rump_s_example_revisited_for_floating_point_variable_count = 2;


// FPBench triangle8
template <class T>
inline T triangle8(const std::vector<T> &value_array)
{
	return sqrt((((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[0])) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[1])) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[2]));
}
std::string print_triangle8(const std::vector<gmp::Rational> &v)
{
	return std::string() + "sqrt((((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[0]) + ")" + ")) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[1]) + ")" + ")) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[2]) + ")" + "))";
}
bool check_input_triangle8(const std::vector<double> &v)
{
    if (1.0 > v[0])
        return false;
    if (v[0] > 9.0)
        return false;
    if (1.0 > v[1])
        return false;
    if (v[1] > 9.0)
        return false;
    if (1.0 > v[2])
        return false;
    if (v[2] > 9.0)
        return false;
    if ((v[0] + v[1]) <= (v[2] + 1.0/100000000))
        return false;
    if ((v[0] + v[2]) <= (v[1] + 1.0/100000000))
        return false;
    if ((v[1] + v[2]) <= (v[0] + 1.0/100000000))
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> triangle8_range = {std::uniform_real_distribution<double>(1.0, 9.0), std::uniform_real_distribution<double>(1.0, 9.0), std::uniform_real_distribution<double>(1.0, 9.0)};
const int triangle8_variable_count = 3;


// FPBench verhulst
template <class T>
inline T verhulst(const std::vector<T> &value_array)
{
	return ((4.0) * value_array[0]) / (1.0 + (value_array[0] / (1.11)));
}
std::string print_verhulst(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(((4)) * " + "(" + rational_to_string(v[0]) + ")" + ") / ((1) + (" + "(" + rational_to_string(v[0]) + ")" + " / ((111/100))))";
}
bool check_input_verhulst(const std::vector<double> &v)
{
    if (0.1 > v[0])
        return false;
    if (v[0] > 0.3)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> verhulst_range = {std::uniform_real_distribution<double>(0.1, 0.3)};
const int verhulst_variable_count = 1;


// FPBench triangle4
template <class T>
inline T triangle4(const std::vector<T> &value_array)
{
	return sqrt((((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[0])) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[1])) * ((((value_array[0] + value_array[1]) + value_array[2]) / 2.0) - value_array[2]));
}
std::string print_triangle4(const std::vector<gmp::Rational> &v)
{
	return std::string() + "sqrt((((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[0]) + ")" + ")) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[1]) + ")" + ")) * ((((" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ") + " + "(" + rational_to_string(v[2]) + ")" + ") / (2)) - " + "(" + rational_to_string(v[2]) + ")" + "))";
}
bool check_input_triangle4(const std::vector<double> &v)
{
    if (1.0 > v[0])
        return false;
    if (v[0] > 9.0)
        return false;
    if (1.0 > v[1])
        return false;
    if (v[1] > 9.0)
        return false;
    if (1.0 > v[2])
        return false;
    if (v[2] > 9.0)
        return false;
    if ((v[0] + v[1]) <= (v[2] + 1.0/10000))
        return false;
    if ((v[0] + v[2]) <= (v[1] + 1.0/10000))
        return false;
    if ((v[1] + v[2]) <= (v[0] + 1.0/10000))
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> triangle4_range = {std::uniform_real_distribution<double>(1.0, 9.0), std::uniform_real_distribution<double>(1.0, 9.0), std::uniform_real_distribution<double>(1.0, 9.0)};
const int triangle4_variable_count = 3;


// FPBench doppler2
template <class T>
inline T doppler2(const std::vector<T> &value_array)
{
	return (-(331.4 + (0.6 * value_array[2])) * value_array[1]) / (((331.4 + (0.6 * value_array[2])) + value_array[0]) * ((331.4 + (0.6 * value_array[2])) + value_array[0]));
}
std::string print_doppler2(const std::vector<gmp::Rational> &v)
{
	return std::string() + "(-((1657/5) + ((3/5) * " + "(" + rational_to_string(v[2]) + ")" + ")) * " + "(" + rational_to_string(v[1]) + ")" + ") / ((((1657/5) + ((3/5) * " + "(" + rational_to_string(v[2]) + ")" + ")) + " + "(" + rational_to_string(v[0]) + ")" + ") * (((1657/5) + ((3/5) * " + "(" + rational_to_string(v[2]) + ")" + ")) + " + "(" + rational_to_string(v[0]) + ")" + "))";
}
bool check_input_doppler2(const std::vector<double> &v)
{
    if (-125.0 > v[0])
        return false;
    if (v[0] > 125.0)
        return false;
    if (15.0 > v[1])
        return false;
    if (v[1] > 25000.0)
        return false;
    if (-40.0 > v[2])
        return false;
    if (v[2] > 60.0)
        return false;
    return true;
}
const std::vector<std::uniform_real_distribution<double>> doppler2_range = {std::uniform_real_distribution<double>(-125.0, 125.0), std::uniform_real_distribution<double>(15.0, 25000.0), std::uniform_real_distribution<double>(-40.0, 60.0)};
const int doppler2_variable_count = 3;


