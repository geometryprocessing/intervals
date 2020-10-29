#pragma once
#include "flags.hpp"

#include "interval.hpp"
#include "Rational.h"
#include "Timer.h"
#include <gmpxx.h>

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

#include <highfive/H5Easy.hpp>
#include <highfive/H5File.hpp>

// all the generator stuffs for random numbers
std::default_random_engine generator;
std::uniform_real_distribution<double> distribution_all_range(-RAND_MAX + 1, RAND_MAX);
std::uniform_real_distribution<double> distribution_within_one(-1, 1);
std::uniform_real_distribution<double> distribution_positive(0, RAND_MAX);
std::uniform_real_distribution<double> distribution_exp(-700, 700);
std::uniform_real_distribution<double> distribution_pi_over_four(0, 41629395862109680461101929914152.0 / 53004193035072394913113926582208.0);

std::vector<double> comp_doubles;              // store the doubles
std::vector<gmp::Rational> comp_gmp_rationals; // store the gmp rationals

std::vector<gmp::Rational> all_used_rationals; // store all the rationals that will be used
int global_used_rational_index = 0;            // to use the rationals stored
int local_used_rational_index = 0;             // to use the rationals stored

double random_double(std::uniform_real_distribution<double> distribution);    // generate a random double based on distribution, or return a pre recorded double
bool within_range(double lower, double upper, gmp::Rational rational_result); // check if a rational is within range of lower and upper
gmp::Rational interval_size(double lower, double upper);                      // return the interval size in rational
void print_rational(gmp::Rational r);                                         // print the rational
void read_to_ratioanl_list(std::string file_name);                            // read a file that contains number used for doing tests
void print_query(double lower, double upper, double input, std::string info); // print a query used for checking in mathematica
inline double benchmarkTimer(std::function<void()> op);                       // a benchmark timer
double random_double(std::uniform_real_distribution<double> distribution);    // get a random double if USE_SYSTEM_RANDOM is defined, otherwise use a pre stored double

double random_double(std::uniform_real_distribution<double> distribution)
{
#ifdef USE_SYSTEM_RANDOM
    double number = distribution(generator);
    return number;
#else
    if (global_used_rational_index + local_used_rational_index >= all_used_rationals.size())
    {
        global_used_rational_index = 0;
        local_used_rational_index = 0;
    }
    gmp::Rational recorded_rat = all_used_rationals[global_used_rational_index + local_used_rational_index];
    local_used_rational_index++;
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
    gmp::Rational lower_rat = gmp::Rational(lower);
    gmp::Rational upper_rat = gmp::Rational(upper);
    print_rational(lower_rat);
    printf(" <= %s", info.c_str());
    printf(" <= ");
    print_rational(upper_rat);
    printf("\n");
}

// compute the interval size and convert it to rational
gmp::Rational interval_size(double lower, double upper)
{
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

// a macro function to fill up the doubles we need, as well as the rationals being used
#define PRE_FILL_RANDOM_DOUBLES(DISTRIBUTION, VARIABLE_COUNT)   \
    do                                                          \
    {                                                           \
        for (int i = 0; i < VARIABLE_COUNT; i++)                \
        {                                                       \
            double r = random_double(DISTRIBUTION);             \
            if (i < comp_doubles.size())                        \
            {                                                   \
                comp_doubles[i] = r;                            \
                comp_gmp_rationals[i] = gmp::Rational(r);       \
            }                                                   \
            else                                                \
            {                                                   \
                comp_doubles.push_back(r);                      \
                comp_gmp_rationals.push_back(gmp::Rational(r)); \
            }                                                   \
        }                                                       \
        local_used_rational_index = 0;                          \
        global_used_rational_index++;                           \
    } while (0)

// print out the gap of the interval
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
#define PRINT_QUERIES(INTERVAL, METHOD, VARIABLE_COUNT, PRINT_METHOD)                \
    do                                                                               \
    {                                                                                \
        std::vector<INTERVAL> used_variables(VARIABLE_COUNT);                        \
        for (int i = 0; i < VARIABLE_COUNT; i++)                                     \
        {                                                                            \
            used_variables[i] = INTERVAL(comp_doubles[i]);                           \
        }                                                                            \
        INTERVAL result = METHOD<INTERVAL>(used_variables);                          \
        print_query(lower(result), upper(result), PRINT_METHOD(comp_gmp_rationals)); \
    } while (0)
