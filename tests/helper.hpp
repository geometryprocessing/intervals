#pragma once

#include "boost/numeric/interval.hpp"
#include <gmpxx.h>
#include <stdlib.h>
#include "../src/interval.hpp"
#include "interval/interval.hpp"
#include <random>
#include "Rational.h"
#include <cmath>
#include <limits>
#include <iomanip>
#include <cmath>
#include <string>
#include <fenv.h>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include "Timer.h"
#include "macro_functions.hpp"

namespace filib_c
{
#include "filib/interval.hpp"
}
typedef filib_c::interval fic_interval;

#define SPEED_TEST_SIZE 1000
#define SPEED_TEST_LOOP 10000

namespace interval_options
{
    typedef boost::numeric::interval_lib::checking_base<double> CheckingPolicy;
} // namespace interval_options

#if defined(__APPLE__)
typedef boost::numeric::interval<
    double,
    boost::numeric::interval_lib::policies<
        boost::numeric::interval_lib::save_state<
            boost::numeric::interval_lib::rounded_transc_std<double>>,
        interval_options::CheckingPolicy>>
    boost_interval;
#else
typedef boost::numeric::interval<
    double,
    boost::numeric::interval_lib::policies<
        boost::numeric::interval_lib::save_state<
            boost::numeric::interval_lib::rounded_transc_std<double>>,
        interval_options::CheckingPolicy>>
    boost_interval;
#endif

std::default_random_engine generator;
std::uniform_real_distribution<double> distribution_all_range(-RAND_MAX + 1, RAND_MAX);
std::uniform_real_distribution<double> distribution_within_one(-1, 1);
std::uniform_real_distribution<double> distribution_positive(0, RAND_MAX);
std::uniform_real_distribution<double> distribution_exp(-40, 40);
std::uniform_real_distribution<double> distribution_pi_over_four(0, 41629395862109680461101929914152.0 / 53004193035072394913113926582208.0);

std::vector<double> comp_doubles;                 // store the doubles
std::vector<gmp::Rational> comp_gmp_rationals;    // store the gmp rationals
std::vector<interval> comp_our_intervals;         // store the intervals for us
std::vector<boost_interval> comp_boost_intervals; // store the intervals for boost
std::vector<fic_interval> comp_fic_intervals;     // store the intervals for filib c implementation
std::vector<gmp::Rational> all_used_rationals;    // store all the rationals that will be used

// define empty function for a rational file
gmp::Rational sqrt(const gmp::Rational &value)
{
    return gmp::Rational(0);
}

gmp::Rational sin(const gmp::Rational &value)
{
    return gmp::Rational(0);
}

gmp::Rational cos(const gmp::Rational &value)
{
    return gmp::Rational(0);
}

gmp::Rational exp(const gmp::Rational &value)
{
    return gmp::Rational(0);
}

// return a random double
double random_double(std::uniform_real_distribution<double> distribution)
{
    double number = distribution(generator);
    return number;
}

// check if the rational is within the range
bool within_range(double lower, double upper, gmp::Rational rational_result)
{
    gmp::Rational lower_rat = gmp::Rational(lower);
    gmp::Rational upper_rat = gmp::Rational(upper);

    return (lower_rat <= rational_result && upper_rat >= rational_result);
}

template <class T>
inline T addition(const std::vector<T> &value_array)
{
    return value_array[0] + value_array[1];
}

template <class T>
inline T subtraction(const std::vector<T> &value_array)
{
    return value_array[0] - value_array[1];
}

template <class T>
inline T multiplication(const std::vector<T> &value_array)
{
    return value_array[0] * value_array[1];
}

template <class T>
inline T division(const std::vector<T> &value_array)
{
    return value_array[0] / value_array[1];
}

// test equation 1
// a / b * c / d * e / f * g / h * i / j
template <class T>
inline T expr1(const std::vector<T> &value_array)
{
    return value_array[0] / value_array[1] * value_array[2] / value_array[3] * value_array[4] / value_array[5] * value_array[6] / value_array[7] * value_array[8] / value_array[9];
}

// test equation 2
// a * (a + b * c) / (b + c * d) - d * (e + f / g) / (g + h) - i / j
template <class T>
inline T expr2(const std::vector<T> &value_array)
{
    return value_array[0] * (value_array[0] + value_array[1] * value_array[2]) / (value_array[1] + value_array[2] * value_array[3]) - value_array[3] * (value_array[4] + value_array[5] / value_array[6]) / (value_array[6] + value_array[7]) - value_array[8] / value_array[9];
}

// test equation 3
// (a * (a / b ) * (a / b / c) - d * (d / e) * (d / e / f)  + g * (g / h) * (g / h / i)) * j
template <class T>
inline T expr3(const std::vector<T> &value_array)
{
    return (value_array[0] * (value_array[0] / value_array[1]) * (value_array[0] / value_array[1] / value_array[2]) - value_array[3] * (value_array[3] / value_array[4]) * (value_array[3] / value_array[4] / value_array[5]) + value_array[6] * (value_array[6] / value_array[7]) * (value_array[6] / value_array[7] / value_array[8])) * value_array[9];
}

template <class T>
inline T square_root(const std::vector<T> &value_array)
{
    return sqrt(value_array[0]);
}

template <class T>
inline T exponential(const std::vector<T> &value_array)
{
    return exp(value_array[0]);
}

template <class T>
inline T sin(const std::vector<T> &value_array)
{
    return sin(value_array[0]);
}

template <class T>
inline T cos(const std::vector<T> &value_array)
{
    return cos(value_array[0]);
}

// compute the interval size and convert it to rational
gmp::Rational interval_size(double lower, double upper)
{
    gmp::Rational lower_rational = gmp::Rational(lower);
    gmp::Rational upper_rational = gmp::Rational(upper);
    gmp::Rational gap = upper_rational - lower_rational;
    return gap;
}

// print the rational value
void print_rational(gmp::Rational r)
{
    mpq_out_str(stdout, 10, r.value);
}

void print_query(double lower, double upper, double input, std::string info)
{
    gmp::Rational lower_rat = gmp::Rational(lower);
    gmp::Rational upper_rat = gmp::Rational(upper);
    gmp::Rational input_rat = gmp::Rational(comp_doubles[0]);
    print_rational(lower_rat);
    printf(" <= %s(", info.c_str());
    print_rational(input_rat);
    printf(") <= ");
    print_rational(upper_rat);
    printf("\n");
}



inline double benchmarkTimer(std::function<void()> op)
{
    igl::Timer t;
    t.start();
    op();
    t.stop();
    return t.getElapsedTimeInMicroSec();
}





void comp_addition()
{
    COMPUTE_GAP(addition, "ADDITION", distribution_within_one, 2, true);
}

void comp_subtraction()
{
    COMPUTE_GAP(subtraction, "SUBTRACTION", distribution_within_one, 2, true);
}

void comp_multiplication()
{
    COMPUTE_GAP(multiplication, "MULTIPLICATION", distribution_within_one, 2, true);
}

void comp_division()
{
    COMPUTE_GAP(division, "DIVISION", distribution_within_one, 2, true);
}

void comp_expr1()
{
    COMPUTE_GAP(expr1, "COMPOSITE EXPRESSION 1", distribution_within_one, 10, true);
}

void comp_expr2()
{
    COMPUTE_GAP(expr2, "COMPOSITE EXPRESSION 2", distribution_within_one, 10, true);
}

void comp_expr3()
{
    COMPUTE_GAP(expr3, "COMPOSITE EXPRESSION 3", distribution_within_one, 10, true);
}

void comp_square_root()
{
    COMPUTE_GAP(square_root, "SQUARE ROOT", distribution_positive, 1, false);
}

void comp_exponential()
{
    COMPUTE_GAP(exponential, "EXPONENTIAL", distribution_exp, 1, false);
}

void comp_sin()
{
    COMPUTE_GAP(sin, "SIN", distribution_exp, 1, false);
}

void comp_cos()
{
    COMPUTE_GAP(cos, "COS", distribution_exp, 1, false);
}

void time_addition()
{
    SPEED_TEST(addition, "ADDITION", distribution_within_one, 2);
}

void time_subtraction()
{
    SPEED_TEST(subtraction, "SUBTRACTION", distribution_within_one, 2);
}

void time_multiplication()
{
    SPEED_TEST(multiplication, "MULTIPLICATION", distribution_within_one, 2);
}

void time_division()
{
    SPEED_TEST(division, "DIVISION", distribution_within_one, 2);
}

void time_expr1()
{
    SPEED_TEST(expr1, "COMPOSITE EXPRESSION 1", distribution_within_one, 10);
}

void time_expr2()
{
    SPEED_TEST(expr2, "COMPOSITE EXPRESSION 2", distribution_within_one, 10);
}

void time_expr3()
{
    SPEED_TEST(expr3, "COMPOSITE EXPRESSION 3", distribution_within_one, 10);
}

void time_sin()
{
    SPEED_TEST(sin, "SIN", distribution_pi_over_four, 1);
}

void print_square_root()
{
    PRINT_QUERIES(square_root, "Sqrt", distribution_positive, 1);
}

void print_exponential()
{
    PRINT_QUERIES(exponential, "Exp", distribution_exp, 1);
}

void print_sin()
{
    PRINT_QUERIES(sin, "sin", distribution_pi_over_four, 1);
}

void print_cos()
{
    PRINT_QUERIES(cos, "cos", distribution_pi_over_four, 1);
}