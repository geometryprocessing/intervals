#include <iostream>
#include "interval.h"
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
#include <gmpxx.h>
#include <stdlib.h>

using namespace std;

// print result of a unary operation
void print_unary_result(interval input, interval result, string operand)
{
    cout << setprecision(numeric_limits<double>::digits10 + 1)
         << "Input interval from " << input.lower << " to " << input.upper << endl
         << operand << " result from " << result.lower << " to " << result.upper << endl;
    cout << "Interval is empty: "
         << (result.lower > result.upper ? "true" : "false")
         << endl;
}

// print result of a binary operation
void print_binary_result(interval input_a, interval input_b, interval result, string operand)
{
    cout << setprecision(numeric_limits<double>::digits10 + 1)
         << "Input interval 1 from " << input_a.lower << " to " << input_a.upper << endl
         << "Input interval 2 from " << input_b.lower << " to " << input_b.upper << endl
         << operand << " result from " << result.lower << " to " << result.upper << endl;
    cout << "Interval is empty: "
         << (result.lower > result.upper ? "true" : "false")
         << endl;
}
template <class ValueType>
ValueType read_option(const char *option, int argc, char **argv, const char *default_value = nullptr);

template <>
string read_option<string>(const char *option, int argc, char **argv, const char *default_value)
{
    for (int i = 0; i < argc - 1; i++)
    {
        if (!strcmp(argv[i], option))
        {
            return string(argv[i + 1]);
        }
    }
    if (default_value)
        return string(default_value);
    cerr << "Option " << option << " was not provided. Exiting...\n";
    exit(1);
}

template <>
int read_option<int>(const char *option, int argc, char **argv, const char *default_value)
{
    return strtol(read_option<string>(option, argc, argv, default_value).c_str(), NULL, 10);
}
template <>
long read_option<long>(const char *option, int argc, char **argv, const char *default_value)
{
    return strtol(read_option<string>(option, argc, argv, default_value).c_str(), NULL, 10);
}
template <>
float read_option<float>(const char *option, int argc, char **argv, const char *default_value)
{
    return strtod(read_option<string>(option, argc, argv, default_value).c_str(), NULL);
}
template <>
double read_option<double>(const char *option, int argc, char **argv, const char *default_value)
{
    return strtof(read_option<string>(option, argc, argv, default_value).c_str(), NULL);
}

// returns a random rational
// a rational contains two
// numerator, denominator
void random_rational(int &a, int &b)
{
    a = (rand() % 100 > 50 ? 1 : -1) * (rand() + 1);
    b = (rand() + 1);
}

// generate an interval based on numerator and denominator
interval rational_to_interval(int a, int b)
{
    double lower = divide_down(static_cast<double>(a), static_cast<double>(b));
    double upper = divide_up(static_cast<double>(a), static_cast<double>(b));
    interval val = {lower, upper};
    return val;
}

bool within_range(mpq_t lower, mpq_t upper, mpq_t known_value)
{
    return mpq_cmp(known_value, lower) >= 0 && mpq_cmp(known_value, upper) <= 0;
}

bool test_add()
{
    // numerator of a, denominator of a
    // numerator of b, denominator of b
    int an, ad, bn, bd;
    random_rational(an, ad);
    random_rational(bn, bd);

    // generate the interval
    interval a = rational_to_interval(an, ad);
    interval b = rational_to_interval(bn, bd);

    interval result = add_interval(a, b);
    print_binary_result(a, b, result, "Addition");

    // initialize the mpz types and mpq types
    mpz_t an_mpz, ad_mpz, bn_mpz, bd_mpz;
    mpq_t an_mpq, ad_mpq, bn_mpq, bd_mpq, a_mpq, b_mpq, result_lower_mpq, result_upper_mpq;
    mpz_inits(an_mpz, ad_mpz, bn_mpz, bd_mpz, (mpz_ptr)0);
    mpq_inits(an_mpq, ad_mpq, bn_mpq, bd_mpq, a_mpq, b_mpq, result_lower_mpq, result_upper_mpq, (mpz_ptr)0);
    mpz_set_si(an_mpz, an);
    mpz_set_si(ad_mpz, ad);
    mpz_set_si(bn_mpz, bn);
    mpz_set_si(bd_mpz, bd);

    mpq_set_z(an_mpq, an_mpz);
    mpq_set_z(ad_mpq, ad_mpz);
    mpq_set_z(bn_mpq, bn_mpz);
    mpq_set_z(bd_mpq, bd_mpz);

    mpq_div(a_mpq, an_mpq, ad_mpq);
    mpq_div(b_mpq, bn_mpq, bd_mpq);

    printf("Rational a: ");
    mpq_out_str(stdout, 10, a_mpq);
    printf("\n");
    printf("Rational b: ");
    mpq_out_str(stdout, 10, b_mpq);
    printf("\n");

    mpq_set_d(result_lower_mpq, result.lower);
    mpq_set_d(result_upper_mpq, result.upper);

    mpq_t addition_result_mpq;
    mpq_init(addition_result_mpq);
    mpq_add(addition_result_mpq, a_mpq, b_mpq);
    printf("Addition result: ");
    mpq_out_str(stdout, 10, addition_result_mpq);
    printf("\n");
    if (within_range(result_lower_mpq, result_upper_mpq, addition_result_mpq))
    {
        printf("Passed rational check\n");
        return true;
    }
    else
    {
        printf("Failed rational check\n");
        return false;
    }
}

int main(int argc, char *argv[])
{
    for (int i = 0; i < 1000; i++)
    {
        bool result = test_add();
        if (!result)
        {
            printf("Failed test\n");
            return 1;
        }
    }
    return 0;
}