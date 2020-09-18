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

// numerator of a, denominator of a
// numerator of b, denominator of b
int an, ad, bn, bd, cn, cd;

// for the variable conversions
mpz_t an_mpz, ad_mpz, bn_mpz, bd_mpz, cn_mpz, cd_mpz;
mpq_t an_mpq, ad_mpq, bn_mpq, bd_mpq, cn_mpq, cd_mpq, a_mpq, b_mpq, c_mpq, result_lower_mpq, result_upper_mpq;

// for the result in rational
mpq_t result_mpq;

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

void print_rational(string info, mpq_t rat)
{
    printf("%s: ", info.c_str());
    mpq_out_str(stdout, 10, rat);
    printf("\n");
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
    // generate the interval
    interval a = rational_to_interval(an, ad);
    interval b = rational_to_interval(bn, bd);

    interval result = add_interval(a, b);

    mpq_div(a_mpq, an_mpq, ad_mpq);
    mpq_div(b_mpq, bn_mpq, bd_mpq);

    print_rational("Rational a", a_mpq);
    print_rational("Rational b", b_mpq);
    mpq_set_d(result_lower_mpq, result.lower);
    mpq_set_d(result_upper_mpq, result.upper);

    mpq_add(result_mpq, a_mpq, b_mpq);
    print_rational("Addition rational result", result_mpq);
    print_rational("Interval lower rational", result_lower_mpq);
    print_rational("Interval upper rational", result_upper_mpq);

    if (within_range(result_lower_mpq, result_upper_mpq, result_mpq))
    {
        printf("Passed addition check\n");
        return true;
    }
    else
    {
        printf("Failed addition check\n");
        return false;
    }
}

bool test_mul()
{
    // generate the interval
    interval a = rational_to_interval(an, ad);
    interval b = rational_to_interval(bn, bd);
    interval result = mult_interval(a, b);

    mpq_div(a_mpq, an_mpq, ad_mpq);
    mpq_div(b_mpq, bn_mpq, bd_mpq);

    print_rational("Rational a", a_mpq);
    print_rational("Rational b", b_mpq);
    mpq_set_d(result_lower_mpq, result.lower);
    mpq_set_d(result_upper_mpq, result.upper);

    mpq_mul(result_mpq, a_mpq, b_mpq);
    print_rational("Multiplication rational result", result_mpq);
    print_rational("Interval lower rational", result_lower_mpq);
    print_rational("Interval upper rational", result_upper_mpq);

    if (within_range(result_lower_mpq, result_upper_mpq, result_mpq))
    {
        printf("Passed multiplication check\n");
        return true;
    }
    else
    {
        printf("Failed multiplication check\n");
        return false;
    }
}

bool test_sub()
{
    // generate the interval
    interval a = rational_to_interval(an, ad);
    interval b = rational_to_interval(bn, bd);
    interval result = subtract_interval(a, b);

    mpq_div(a_mpq, an_mpq, ad_mpq);
    mpq_div(b_mpq, bn_mpq, bd_mpq);

    print_rational("Rational a", a_mpq);
    print_rational("Rational b", b_mpq);
    mpq_set_d(result_lower_mpq, result.lower);
    mpq_set_d(result_upper_mpq, result.upper);

    mpq_sub(result_mpq, a_mpq, b_mpq);
    print_rational("Subtraction rational result", result_mpq);
    print_rational("Interval lower rational", result_lower_mpq);
    print_rational("Interval upper rational", result_upper_mpq);

    if (within_range(result_lower_mpq, result_upper_mpq, result_mpq))
    {
        printf("Passed subtraction check\n");
        return true;
    }
    else
    {
        printf("Failed subtraction check\n");
        return false;
    }
}

bool test_div()
{
    // generate the interval
    interval a = rational_to_interval(an, ad);
    interval b = rational_to_interval(bn, bd);
    interval result = div_interval(a, b);

    mpq_div(a_mpq, an_mpq, ad_mpq);
    mpq_div(b_mpq, bn_mpq, bd_mpq);

    print_rational("Rational a", a_mpq);
    print_rational("Rational b", b_mpq);
    mpq_set_d(result_lower_mpq, result.lower);
    mpq_set_d(result_upper_mpq, result.upper);

    mpq_div(result_mpq, a_mpq, b_mpq);
    print_rational("Division rational result", result_mpq);
    print_rational("Interval lower rational", result_lower_mpq);
    print_rational("Interval upper rational", result_upper_mpq);

    if (within_range(result_lower_mpq, result_upper_mpq, result_mpq))
    {
        printf("Passed division check\n");
        return true;
    }
    else
    {
        printf("Failed division check\n");
        return false;
    }
}

// composite expression 1
// a * b - c / a
bool test_comp1()
{
    // initialze c
    random_rational(cn, cd);
    interval a = rational_to_interval(an, ad);
    interval b = rational_to_interval(bn, bd);
    interval c = rational_to_interval(cn, cd);
    interval result = subtract_interval(mult_interval(a, b), div_interval(c, a));

    // setup rational c
    mpz_set_si(cn_mpz, cn);
    mpz_set_si(cd_mpz, cd);
    mpq_set_z(cn_mpq, cn_mpz);
    mpq_set_z(cd_mpq, cd_mpz);

    mpq_div(a_mpq, an_mpq, ad_mpq);
    mpq_div(b_mpq, bn_mpq, bd_mpq);
    mpq_div(c_mpq, cn_mpq, cd_mpq);

    print_rational("Rational a", a_mpq);
    print_rational("Rational b", b_mpq);
    print_rational("Rational c", c_mpq);
    mpq_set_d(result_lower_mpq, result.lower);
    mpq_set_d(result_upper_mpq, result.upper);

    mpz_set_si(cn_mpz, cn);
    mpz_set_si(cd_mpz, cd);

    mpq_set_z(cn_mpq, cn_mpz);
    mpq_set_z(cd_mpq, cd_mpz);

    mpq_t tmp;
    mpq_init(tmp);
    mpq_div(result_mpq, c_mpq, a_mpq);
    mpq_mul(tmp, a_mpq, b_mpq);
    mpq_sub(result_mpq, tmp, result_mpq);
    print_rational("Comp1 rational result", result_mpq);
    print_rational("Interval lower rational", result_lower_mpq);
    print_rational("Interval upper rational", result_upper_mpq);
    if (within_range(result_lower_mpq, result_upper_mpq, result_mpq))
    {
        printf("Passed comp1 check\n");
        return true;
    }
    else
    {
        printf("Failed comp1 check\n");
        return false;
    }
}

// composite expression 1
// (a + b) * (a - b - c) / (b + c)
bool test_comp2()
{
    // initialze c
    random_rational(cn, cd);
    interval a = rational_to_interval(an, ad);
    interval b = rational_to_interval(bn, bd);
    interval c = rational_to_interval(cn, cd);
    interval result = div_interval(mult_interval(add_interval(a, b), subtract_interval(subtract_interval(a, b), c)), add_interval(b, c));

    // setup rational c
    mpz_set_si(cn_mpz, cn);
    mpz_set_si(cd_mpz, cd);
    mpq_set_z(cn_mpq, cn_mpz);
    mpq_set_z(cd_mpq, cd_mpz);

    mpq_div(a_mpq, an_mpq, ad_mpq);
    mpq_div(b_mpq, bn_mpq, bd_mpq);
    mpq_div(c_mpq, cn_mpq, cd_mpq);

    print_rational("Rational a", a_mpq);
    print_rational("Rational b", b_mpq);
    print_rational("Rational c", c_mpq);
    mpq_set_d(result_lower_mpq, result.lower);
    mpq_set_d(result_upper_mpq, result.upper);

    mpz_set_si(cn_mpz, cn);
    mpz_set_si(cd_mpz, cd);

    mpq_set_z(cn_mpq, cn_mpz);
    mpq_set_z(cd_mpq, cd_mpz);

    mpq_t tmp1, tmp2;
    mpq_inits(tmp1, tmp2, (mpz_ptr)0);
    mpq_add(result_mpq, a_mpq, b_mpq);
    mpq_sub(tmp1, a_mpq, b_mpq);
    mpq_sub(tmp1, tmp1, c_mpq);
    mpq_add(tmp2, b_mpq, c_mpq);
    mpq_mul(result_mpq, result_mpq, tmp1);
    mpq_div(result_mpq, result_mpq, tmp2);
    print_rational("Comp2 rational result", result_mpq);
    print_rational("Interval lower rational", result_lower_mpq);
    print_rational("Interval upper rational", result_upper_mpq);
    if (within_range(result_lower_mpq, result_upper_mpq, result_mpq))
    {
        printf("Passed comp2 check\n");
        return true;
    }
    else
    {
        printf("Failed comp2 check\n");
        return false;
    }
}

int main(int argc, char *argv[])
{
    // initialize the numbers in gmp
    mpz_inits(an_mpz, ad_mpz, bn_mpz, bd_mpz, cn_mpz, cd_mpz, (mpz_ptr)0);
    mpq_inits(an_mpq, ad_mpq, bn_mpq, bd_mpq, cn_mpq, cd_mpq, a_mpq, b_mpq, c_mpq, result_lower_mpq, result_upper_mpq, (mpz_ptr)0);
    mpq_init(result_mpq);

    for (int i = 0; i < 100000; i++)
    {
        random_rational(an, ad);
        random_rational(bn, bd);

        // setup the rational numbers
        mpz_set_si(an_mpz, an);
        mpz_set_si(ad_mpz, ad);
        mpz_set_si(bn_mpz, bn);
        mpz_set_si(bd_mpz, bd);

        mpq_set_z(an_mpq, an_mpz);
        mpq_set_z(ad_mpq, ad_mpz);
        mpq_set_z(bn_mpq, bn_mpz);
        mpq_set_z(bd_mpq, bd_mpz);

        bool result_add = test_add();
        bool result_mul = test_mul();
        bool result_sub = test_sub();
        bool result_div = test_div();
        bool result_comp1 = test_comp1();
        bool result_comp2 = test_comp2();
        if (result_add || !result_mul || !result_sub || !result_div || !result_comp1 || !result_comp2)
        {
            printf("Failed test\n");
            return 1;
        }
    }
    return 0;
}