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

#define SPEED_TEST_SIZE 100
#define SPEED_TEST_LOOP 1

namespace interval_options
{
    typedef boost::numeric::interval_lib::checking_base<double> CheckingPolicy;
} // namespace interval_options

typedef boost::numeric::interval<
    double,
    boost::numeric::interval_lib::policies<
        boost::numeric::interval_lib::save_state<
            boost::numeric::interval_lib::rounded_arith_std<double>>,
        interval_options::CheckingPolicy>>
    boost_interval;

std::default_random_engine generator;
std::uniform_real_distribution<double> distribution_all_range(-RAND_MAX + 1, RAND_MAX);
std::uniform_real_distribution<double> distribution_within_one(-1, 1);

std::vector<double> comp_doubles;                 // store the doubles
std::vector<gmp::Rational> comp_gmp_rationals;    // store the gmp rationals
std::vector<interval> comp_our_intervals;         // store the intervals for us
std::vector<boost_interval> comp_boost_intervals; // store the intervals for boost

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

#define COMPUTE_GAP(METHOD, INFO, DISTRIBUTION, VARIABLE_COUNT)                                                                                                                                               \
    do                                                                                                                                                                                                        \
    {                                                                                                                                                                                                         \
        for (int i = 0; i < VARIABLE_COUNT; i++)                                                                                                                                                              \
        {                                                                                                                                                                                                     \
            double r = random_double(DISTRIBUTION);                                                                                                                                                           \
            comp_doubles[i] = r;                                                                                                                                                                              \
            comp_gmp_rationals[i] = gmp::Rational(r);                                                                                                                                                         \
            comp_our_intervals[i] = interval(r);                                                                                                                                                              \
            comp_boost_intervals[i] = boost_interval(r);                                                                                                                                                      \
        }                                                                                                                                                                                                     \
        interval our_result = METHOD<interval>(comp_our_intervals);                                                                                                                                           \
        gmp::Rational rational_result = METHOD<gmp::Rational>(comp_gmp_rationals);                                                                                                                            \
        boost_interval boost_result = METHOD<boost_interval>(comp_boost_intervals);                                                                                                                           \
        filib::fp_traits<double, filib::native_switched>::setup();                                                                                                                                            \
        std::vector<filib::interval<double, filib::native_switched, filib::i_mode_normal>> native_switched_values;                                                                                            \
        native_switched_values.resize(VARIABLE_COUNT);                                                                                                                                                        \
        for (int i = 0; i < VARIABLE_COUNT; i++)                                                                                                                                                              \
        {                                                                                                                                                                                                     \
            native_switched_values[i] = filib::interval<double, filib::native_switched, filib::i_mode_normal>(comp_doubles[i]);                                                                               \
        }                                                                                                                                                                                                     \
        filib::interval<double, filib::native_switched, filib::i_mode_normal> native_switched_result = METHOD<filib::interval<double, filib::native_switched, filib::i_mode_normal>>(native_switched_values); \
        filib::fp_traits<double, filib::multiplicative>::setup();                                                                                                                                             \
        std::vector<filib::interval<double, filib::multiplicative, filib::i_mode_normal>> multiplicative_values;                                                                                              \
        multiplicative_values.resize(VARIABLE_COUNT);                                                                                                                                                         \
        for (int i = 0; i < VARIABLE_COUNT; i++)                                                                                                                                                              \
        {                                                                                                                                                                                                     \
            multiplicative_values[i] = filib::interval<double, filib::multiplicative, filib::i_mode_normal>(comp_doubles[i]);                                                                                 \
        }                                                                                                                                                                                                     \
        filib::interval<double, filib::multiplicative, filib::i_mode_normal> multiplicative_result = METHOD<filib::interval<double, filib::multiplicative, filib::i_mode_normal>>(multiplicative_values);     \
        filib::fp_traits<double, filib::pred_succ_rounding>::setup();                                                                                                                                         \
        std::vector<filib::interval<double, filib::pred_succ_rounding, filib::i_mode_normal>> pred_succ_values;                                                                                               \
        pred_succ_values.resize(VARIABLE_COUNT);                                                                                                                                                              \
        for (int i = 0; i < VARIABLE_COUNT; i++)                                                                                                                                                              \
        {                                                                                                                                                                                                     \
            pred_succ_values[i] = filib::interval<double, filib::pred_succ_rounding, filib::i_mode_normal>(comp_doubles[i]);                                                                                  \
        }                                                                                                                                                                                                     \
        filib::interval<double, filib::pred_succ_rounding, filib::i_mode_normal> pred_succ_result = METHOD<filib::interval<double, filib::pred_succ_rounding, filib::i_mode_normal>>(pred_succ_values);       \
        if (!within_range(our_result.lower(), our_result.upper(), rational_result))                                                                                                                           \
        {                                                                                                                                                                                                     \
            printf("FAIL, %s, OUR METHOD\n", INFO);                                                                                                                                                           \
        }                                                                                                                                                                                                     \
        if (!within_range(boost_result.lower(), boost_result.upper(), rational_result))                                                                                                                       \
        {                                                                                                                                                                                                     \
            printf("FAIL, %s, BOOST METHOD\n", INFO);                                                                                                                                                         \
        }                                                                                                                                                                                                     \
        if (!within_range(native_switched_result.inf(), native_switched_result.sup(), rational_result))                                                                                                       \
        {                                                                                                                                                                                                     \
            printf("FAIL, %s, NATIVE SWITCHED\n", INFO);                                                                                                                                                      \
        }                                                                                                                                                                                                     \
        if (!within_range(multiplicative_result.inf(), multiplicative_result.sup(), rational_result))                                                                                                         \
        {                                                                                                                                                                                                     \
            printf("FAIL, %s, MULTIPLICATIVE\n", INFO);                                                                                                                                                       \
        }                                                                                                                                                                                                     \
        if (!within_range(pred_succ_result.inf(), pred_succ_result.sup(), rational_result))                                                                                                                   \
        {                                                                                                                                                                                                     \
            printf("FAIL, %s, PRED SUCC\n", INFO);                                                                                                                                                            \
        }                                                                                                                                                                                                     \
        printf("GAP, %s, OUR METHOD, ", INFO);                                                                                                                                                                \
        print_rational(interval_size(our_result.lower(), our_result.upper()));                                                                                                                                \
        printf("\n");                                                                                                                                                                                         \
        printf("GAP, %s, BOOST METHOD, ", INFO);                                                                                                                                                              \
        print_rational(interval_size(boost_result.lower(), boost_result.upper()));                                                                                                                            \
        printf("\n");                                                                                                                                                                                         \
        printf("GAP, %s, NATIVE SWITCHED, ", INFO);                                                                                                                                                           \
        print_rational(interval_size(native_switched_result.inf(), native_switched_result.sup()));                                                                                                            \
        printf("\n");                                                                                                                                                                                         \
        printf("GAP, %s, MULTIPLICATIVE, ", INFO);                                                                                                                                                            \
        print_rational(interval_size(multiplicative_result.inf(), multiplicative_result.sup()));                                                                                                              \
        printf("\n");                                                                                                                                                                                         \
        printf("GAP, %s, PRED SUCC, ", INFO);                                                                                                                                                                 \
        print_rational(interval_size(pred_succ_result.inf(), pred_succ_result.sup()));                                                                                                                        \
        printf("\n");                                                                                                                                                                                         \
    } while (0)

inline double benchmarkTimer(std::function<void()> op)
{
    igl::Timer t;
    t.start();
    op();
    t.stop();
    return t.getElapsedTimeInMicroSec();
}

#define SPEED_TEST(METHOD, INFO, DISTRIBUTION, VARIABLE_COUNT)                                                                                                                                                            \
    do                                                                                                                                                                                                                    \
    {                                                                                                                                                                                                                     \
        double our_time = 0;                                                                                                                                                                                              \
        double boost_time = 0;                                                                                                                                                                                            \
        double native_switched_time = 0;                                                                                                                                                                                  \
        double multiplicative_time = 0;                                                                                                                                                                                   \
        double pred_succ_time = 0;                                                                                                                                                                                        \
        for (int i = 0; i < SPEED_TEST_LOOP; i++)                                                                                                                                                                         \
        {                                                                                                                                                                                                                 \
            for (int j = 0; j < VARIABLE_COUNT; j++)                                                                                                                                                                      \
            {                                                                                                                                                                                                             \
                double r = random_double(DISTRIBUTION);                                                                                                                                                                   \
                comp_doubles[j] = r;                                                                                                                                                                                      \
                comp_our_intervals[j] = interval(r);                                                                                                                                                                      \
                comp_boost_intervals[j] = boost_interval(r);                                                                                                                                                              \
            }                                                                                                                                                                                                             \
            our_time += benchmarkTimer([&]() {                                                                                                                                                                            \
                for (int j = 0; j < SPEED_TEST_LOOP; j++)                                                                                                                                                                 \
                {                                                                                                                                                                                                         \
                    interval our_result = METHOD<interval>(comp_our_intervals);                                                                                                                                           \
                }                                                                                                                                                                                                         \
            });                                                                                                                                                                                                           \
            boost_time += benchmarkTimer([&]() {                                                                                                                                                                          \
                for (int j = 0; j < SPEED_TEST_LOOP; j++)                                                                                                                                                                 \
                {                                                                                                                                                                                                         \
                    boost_interval boost_result = METHOD<boost_interval>(comp_boost_intervals);                                                                                                                           \
                }                                                                                                                                                                                                         \
            });                                                                                                                                                                                                           \
            filib::fp_traits<double, filib::native_switched>::setup();                                                                                                                                                    \
            std::vector<filib::interval<double, filib::native_switched, filib::i_mode_normal>> native_switched_values;                                                                                                    \
            native_switched_values.resize(VARIABLE_COUNT);                                                                                                                                                                \
            for (int i = 0; i < VARIABLE_COUNT; i++)                                                                                                                                                                      \
            {                                                                                                                                                                                                             \
                native_switched_values[i] = filib::interval<double, filib::native_switched, filib::i_mode_normal>(comp_doubles[i]);                                                                                       \
            }                                                                                                                                                                                                             \
            native_switched_time += benchmarkTimer([&]() {                                                                                                                                                                \
                for (int j = 0; j < SPEED_TEST_LOOP; j++)                                                                                                                                                                 \
                {                                                                                                                                                                                                         \
                    filib::interval<double, filib::native_switched, filib::i_mode_normal> native_switched_result = METHOD<filib::interval<double, filib::native_switched, filib::i_mode_normal>>(native_switched_values); \
                }                                                                                                                                                                                                         \
            });                                                                                                                                                                                                           \
            filib::fp_traits<double, filib::multiplicative>::setup();                                                                                                                                                     \
            std::vector<filib::interval<double, filib::multiplicative, filib::i_mode_normal>> multiplicative_values;                                                                                                      \
            multiplicative_values.resize(VARIABLE_COUNT);                                                                                                                                                                 \
            for (int i = 0; i < VARIABLE_COUNT; i++)                                                                                                                                                                      \
            {                                                                                                                                                                                                             \
                multiplicative_values[i] = filib::interval<double, filib::multiplicative, filib::i_mode_normal>(comp_doubles[i]);                                                                                         \
            }                                                                                                                                                                                                             \
            multiplicative_time += benchmarkTimer([&]() {                                                                                                                                                                 \
                for (int j = 0; j < SPEED_TEST_LOOP; j++)                                                                                                                                                                 \
                {                                                                                                                                                                                                         \
                    filib::interval<double, filib::multiplicative, filib::i_mode_normal> multiplicative_result = METHOD<filib::interval<double, filib::multiplicative, filib::i_mode_normal>>(multiplicative_values);     \
                }                                                                                                                                                                                                         \
            });                                                                                                                                                                                                           \
            filib::fp_traits<double, filib::pred_succ_rounding>::setup();                                                                                                                                                 \
            std::vector<filib::interval<double, filib::pred_succ_rounding, filib::i_mode_normal>> pred_succ_values;                                                                                                       \
            pred_succ_values.resize(VARIABLE_COUNT);                                                                                                                                                                      \
            for (int i = 0; i < VARIABLE_COUNT; i++)                                                                                                                                                                      \
            {                                                                                                                                                                                                             \
                pred_succ_values[i] = filib::interval<double, filib::pred_succ_rounding, filib::i_mode_normal>(comp_doubles[i]);                                                                                          \
            }                                                                                                                                                                                                             \
            pred_succ_time += benchmarkTimer([&]() {                                                                                                                                                                      \
                for (int j = 0; j < SPEED_TEST_LOOP; j++)                                                                                                                                                                 \
                {                                                                                                                                                                                                         \
                    filib::interval<double, filib::pred_succ_rounding, filib::i_mode_normal> pred_succ_result = METHOD<filib::interval<double, filib::pred_succ_rounding, filib::i_mode_normal>>(pred_succ_values);       \
                }                                                                                                                                                                                                         \
            });                                                                                                                                                                                                           \
        }                                                                                                                                                                                                                 \
        printf("TIME, %s, OUR METHOD, ", INFO);                                                                                                                                                                           \
        printf("%lf", our_time);                                                                                                                                                                                          \
        printf("\n");                                                                                                                                                                                                     \
        printf("TIME, %s, BOOST METHOD, ", INFO);                                                                                                                                                                         \
        printf("%lf", boost_time);                                                                                                                                                                                        \
        printf("\n");                                                                                                                                                                                                     \
        printf("TIME, %s, NATIVE SWITCHED, ", INFO);                                                                                                                                                                      \
        printf("%lf", native_switched_time);                                                                                                                                                                              \
        printf("\n");                                                                                                                                                                                                     \
        printf("TIME, %s, MULTIPLICATIVE, ", INFO);                                                                                                                                                                       \
        printf("%lf", multiplicative_time);                                                                                                                                                                               \
        printf("\n");                                                                                                                                                                                                     \
        printf("TIME, %s, PRED SUCC, ", INFO);                                                                                                                                                                            \
        printf("%lf", pred_succ_time);                                                                                                                                                                                    \
        printf("\n");                                                                                                                                                                                                     \
    } while (0)

void comp_addition()
{
    COMPUTE_GAP(addition, "ADDITION", distribution_within_one, 2);
}

void comp_subtraction()
{
    COMPUTE_GAP(subtraction, "SUBTRACTION", distribution_within_one, 2);
}

void comp_multiplication()
{
    COMPUTE_GAP(multiplication, "MULTIPLICATION", distribution_within_one, 2);
}

void comp_division()
{
    COMPUTE_GAP(division, "DIVISION", distribution_within_one, 2);
}

void comp_expr1()
{
    COMPUTE_GAP(expr1, "COMPOSITE EXPRESSION 1", distribution_within_one, 10);
}

void comp_expr2()
{
    COMPUTE_GAP(expr2, "COMPOSITE EXPRESSION 2", distribution_within_one, 10);
}

void comp_expr3()
{
    COMPUTE_GAP(expr3, "COMPOSITE EXPRESSION 3", distribution_within_one, 10);
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