#pragma once
#include "flags.hpp"

#include "interval.hpp"
#include "Rational.h"
#include "Timer.h"
#include <gmp.h>

#include <functional>
#include <random>
#include <cmath>
#include <limits>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <fstream>

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// all the generator stuffs for random numbers
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
std::default_random_engine generator;
std::uniform_real_distribution<double> distribution_all_range(-RAND_MAX + 1, RAND_MAX);                                                       // an all range distribution
std::uniform_real_distribution<double> distribution_within_one(-1, 1);                                                                        // distribution between -1 and 1
std::uniform_real_distribution<double> distribution_positive(0, RAND_MAX);                                                                    // only positive numbers
std::uniform_real_distribution<double> distribution_exp(-700, 700);                                                                           // within the reach of exponential
std::uniform_real_distribution<double> distribution_pi_over_four(0, 41629395862109680461101929914152.0 / 53004193035072394913113926582208.0); // 0 to pi/4, which is the kernel sin and cos's range
std::vector<std::uniform_real_distribution<double>> binary_all_range(2, distribution_all_range);                                              // for binary, we need two values from all range
std::vector<std::uniform_real_distribution<double>> comp_all_range(10, distribution_all_range);                                               // for composite, we need 10 values from all range
std::vector<std::uniform_real_distribution<double>> exp_range(1, distribution_exp);                                                           // for exponential, use -700 to 700 (otherwise overflow)
std::vector<std::uniform_real_distribution<double>> square_root_range(1, distribution_positive);                                              // for square root, we need positive
std::vector<std::uniform_real_distribution<double>> trig_all_range(1, distribution_all_range);                                                // all range for trignometry
std::vector<std::uniform_real_distribution<double>> trig_pi_over_four(1, distribution_pi_over_four);                                          // kernel function's range
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// ******************************************************************************************************************************************************************************************************
// all the function declarations
// ******************************************************************************************************************************************************************************************************
double random_double(std::uniform_real_distribution<double> distribution);    // generate a random double based on distribution, or return a pre recorded double
bool within_range(double lower, double upper, gmp::Rational rational_result); // check if a rational is within range of lower and upper
gmp::Rational interval_size(double lower, double upper);                      // return the interval size in rational
void print_rational(gmp::Rational r);                                         // print the rational
void read_to_ratioanl_list(std::string file_name);                            // read a file that contains number used for doing tests
void print_query(double lower, double upper, double input, std::string info); // print a query used for checking in mathematica
inline double benchmarkTimer(std::function<void()> op);                       // a benchmark timer
double random_double(std::uniform_real_distribution<double> distribution);    // get a random double if USE_SYSTEM_RANDOM is defined, otherwise use a pre stored double
// ******************************************************************************************************************************************************************************************************

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// the arrays that will be used to set and store doubles and rational numbers
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
std::vector<double> comp_doubles;              // store the doubles
std::vector<gmp::Rational> comp_gmp_rationals; // store the gmp rationals
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// ******************************************************************************************************************************************************************************************************
// if we want to read pre-defined doubles, we will read them into rational then convert to double
// ******************************************************************************************************************************************************************************************************
std::vector<gmp::Rational> all_used_rationals; // store all the rationals that will be used
int global_used_rational_index = 0;            // to use the rationals stored
// ******************************************************************************************************************************************************************************************************

// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// the beginning of functions
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
double random_double(std::uniform_real_distribution<double> distribution)
{
#ifdef USE_SYSTEM_RANDOM
    double number = distribution(generator);
    return number;
#else
    if (global_used_rational_index >= all_used_rationals.size())
    {
        global_used_rational_index = 0;
    }
    gmp::Rational recorded_rat = all_used_rationals[global_used_rational_index];
    global_used_rational_index++;
    return recorded_rat.to_double();
#endif
}

bool within_range(double lower, double upper, gmp::Rational rational_result)
{
    gmp::Rational lower_rat = gmp::Rational(lower);
    gmp::Rational upper_rat = gmp::Rational(upper);

    return (lower_rat <= rational_result && upper_rat >= rational_result);
}

// print the rational value
void print_rational(gmp::Rational r)
{
    mpq_out_str(stdout, 10, r.value);
}

std::string rational_to_string(gmp::Rational r)
{
    char *s_char = new char[mpz_sizeinbase(mpq_numref(r.value), 10) + mpz_sizeinbase(mpq_denref(r.value), 10) + 3];
    mpq_get_str(s_char, 10, r.value);
    std::string s = s_char;
    s = "(" + s + ")";
    return s;
}

void print_query(double lower, double upper, std::string info)
{
    if (lower != lower || upper < lower)
    {
        // NaN result
        print_rational(gmp::Rational(1));
        printf(" <= %s", info.c_str());
        printf(" <= ");
        print_rational(-1);
        printf("\n");
    }
    else
    {
        gmp::Rational lower_rat = gmp::Rational(lower);
        gmp::Rational upper_rat = gmp::Rational(upper);

        print_rational(lower_rat);
        printf(" <= %s", info.c_str());
        printf(" <= ");
        print_rational(upper_rat);
        printf("\n");
    }
}

// compute the interval size and convert it to rational
gmp::Rational interval_size(double lower, double upper)
{
    if (lower != lower || upper < lower)
    {
        // this is a NaN result
        return gmp::Rational(-2);
    }
    gmp::Rational lower_rational = gmp::Rational(lower);
    gmp::Rational upper_rational = gmp::Rational(upper);
    gmp::Rational gap = upper_rational - lower_rational;
    return gap;
}

inline double benchmarkTimer(std::function<void()> op)
{
    igl::Timer t;
    t.start();
    op();
    t.stop();
    return t.getElapsedTimeInMicroSec();
}
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// ******************************************************************************************************************************************************************************************************
// macro functions
// ******************************************************************************************************************************************************************************************************
// a macro function to fill up the doubles we need, as well as the rationals being used
// INPUT =>
// DISTRIBUTION:   the range of within which the random generator will pick numbers from
// VARIABLE_COUNT: the number of variables need to be filled
// OUTPUT =>
// the random number and their corresponding rantional version will be stored in two arrays
#define PRE_FILL_RANDOM_DOUBLES(DISTRIBUTION, VARIABLE_COUNT, VERIFY_METHOD) \
    do                                                                       \
    {                                                                        \
        for (int i = 0; i < VARIABLE_COUNT; i++)                             \
        {                                                                    \
            double r = random_double(DISTRIBUTION[i]);                       \
            if (i < comp_doubles.size())                                     \
            {                                                                \
                comp_doubles[i] = r;                                         \
                comp_gmp_rationals[i] = gmp::Rational(r);                    \
            }                                                                \
            else                                                             \
            {                                                                \
                comp_doubles.push_back(r);                                   \
                comp_gmp_rationals.push_back(gmp::Rational(r));              \
            }                                                                \
        }                                                                    \
        while (!VERIFY_METHOD(comp_doubles))                                 \
        {                                                                    \
            for (int i = 0; i < VARIABLE_COUNT; i++)                         \
            {                                                                \
                double r = random_double(DISTRIBUTION[i]);                   \
                if (i < comp_doubles.size())                                 \
                {                                                            \
                    comp_doubles[i] = r;                                     \
                    comp_gmp_rationals[i] = gmp::Rational(r);                \
                }                                                            \
                else                                                         \
                {                                                            \
                    comp_doubles.push_back(r);                               \
                    comp_gmp_rationals.push_back(gmp::Rational(r));          \
                }                                                            \
            }                                                                \
        }                                                                    \
    } while (0)

// print out the gap of the interval
// INPUT =>
// INTERVAL:       the type of interval using this method
// TYPE_NAME:      the name of the interval type
// METHOD:         the method we are running, composit expression, sin, cos etc
// INFO:           the method name
// VARIABLE_COUNT: the number of variables needed for this computation
// OUTPUT =>
// print out the gap for this interval type for this method
#define COMPUTE_GAP(INTERVAL, TYPE_NAME, METHOD, INFO, VARIABLE_COUNT) \
    do                                                                 \
    {                                                                  \
        std::vector<INTERVAL> used_variables(VARIABLE_COUNT);          \
        for (int i = 0; i < VARIABLE_COUNT; i++)                       \
        {                                                              \
            used_variables[i] = INTERVAL(comp_doubles[i]);             \
        }                                                              \
        INTERVAL result = METHOD<INTERVAL>(used_variables);            \
        printf("GAP, %s, %s, ", INFO, TYPE_NAME);                      \
        print_rational(interval_size(lower(result), upper(result)));   \
        printf("\n");                                                  \
    } while (0)

// accumulate the time for doing a method
// INPUT =>
// INTERVAL:       the type of interval using this method
// METHOD:         the method we are running, composit expression, sin, cos etc
// VARIABLE_COUNT: the number of variables needed for this computation
// TIMER:          the double number recording the accumulated time in micro seconds
// OUTPUT =>
// the time will be accumulated by TIMER variable, user should decide what to do what the time
// to print or to factor by number of runs, whatever the user choose
#define COMPUTE_TIME(INTERVAL, METHOD, VARIABLE_COUNT, TIMER)       \
    do                                                              \
    {                                                               \
        std::vector<INTERVAL> used_variables(VARIABLE_COUNT);       \
        for (int i = 0; i < VARIABLE_COUNT; i++)                    \
        {                                                           \
            used_variables[i] = INTERVAL(comp_doubles[i]);          \
        }                                                           \
        TIMER += benchmarkTimer([&]() {                             \
            for (int j = 0; j < SPEED_TEST_SIZE; j++)               \
            {                                                       \
                INTERVAL result = METHOD<INTERVAL>(used_variables); \
            }                                                       \
        });                                                         \
    } while (0)

// print the result as a query which can be checked in mathematica
// INPUT =>
// INTERVAL:       the type of interval using this method
// TYPE_NAME:      the name of the interval type
// METHOD:         the method we are running, composit expression, sin, cos etc
// VARIABLE_COUNT: the number of variables needed for this computation
// PRINT_METHOD:   the printing of the method we use, should be one to one correspondent and defined in methods.hpp
// OUTPUT =>
// The query will be printed out and this query can be used for checking correctness
#define PRINT_QUERIES(INTERVAL, TYPE_NAME, METHOD, PRINT_METHOD, VARIABLE_COUNT)     \
    do                                                                               \
    {                                                                                \
        std::vector<INTERVAL> used_variables(VARIABLE_COUNT);                        \
        for (int i = 0; i < VARIABLE_COUNT; i++)                                     \
        {                                                                            \
            used_variables[i] = INTERVAL(comp_doubles[i]);                           \
        }                                                                            \
        INTERVAL result = METHOD<INTERVAL>(used_variables);                          \
        printf("%s: ", TYPE_NAME);                                                   \
        print_query(lower(result), upper(result), PRINT_METHOD(comp_gmp_rationals)); \
    } while (0)
// ******************************************************************************************************************************************************************************************************
