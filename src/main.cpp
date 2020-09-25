#include <iostream>
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
#include "interval.hpp"

// #ifdef _WIN32
// #pragma comment(lib, "interval.lib")
// #endif

using namespace std;

// the intervals
interval a, b, c;

// the rational numbers
mpq_t a_mpq, b_mpq, c_mpq, result_lower_mpq, result_upper_mpq;

// constants
mpq_t three, four, five, six;

// for the result in rational
mpq_t result_mpq;

// print result of a unary operation
void print_unary_result(interval input, interval result, string operand)
{
    cout << setprecision(numeric_limits<double>::digits10 + 1)
         << "Input interval from " << input.lower() << " to " << input.upper() << endl
         << operand << " result from " << result.lower() << " to " << result.upper() << endl;
    cout << "interval is empty: "
         << (result.lower() > result.upper() ? "true" : "false")
         << endl;
}

// print result of a binary operation
void print_binary_result(interval input_a, interval input_b, interval result, string operand)
{
    cout << setprecision(numeric_limits<double>::digits10 + 1)
         << "Input interval 1 from " << input_a.lower() << " to " << input_a.upper() << endl
         << "Input interval 2 from " << input_b.lower() << " to " << input_b.upper() << endl
         << operand << " result from " << result.lower() << " to " << result.upper() << endl;
    cout << "interval is empty: "
         << (result.lower() > result.upper() ? "true" : "false")
         << endl;
}

void print_rational(string info, mpq_t rat)
{
    printf("%s", info.c_str());
    mpq_out_str(stdout, 10, rat);
}

void print_interval(string info, interval val)
{
    printf("%s", info.c_str());
    printf("lower: %lf, upper: %lf", val.lower(), val.upper());
}

void random_init(interval &interval_num, mpq_t &mpq_num)
{
    int numerator = (rand() % 100 > 50 ? 1 : -1) * (rand() + 1);
    int denominator = (rand() + 1);
    double random_double = (numerator * 1.0) / (denominator * 1.0);
    interval_num = interval(random_double);
    mpq_set_d(mpq_num, random_double);
}

bool within_range(mpq_t lower, mpq_t upper, mpq_t known_value)
{
    return mpq_cmp(known_value, lower) >= 0 && mpq_cmp(known_value, upper) <= 0;
}

bool test_add()
{
    // generate the interval
    interval result = a + b;

    mpq_set_d(result_lower_mpq, result.lower());
    mpq_set_d(result_upper_mpq, result.upper());

    mpq_add(result_mpq, a_mpq, b_mpq);

    if (within_range(result_lower_mpq, result_upper_mpq, result_mpq))
    {
        // printf("Passed addition check, ");
        // print_rational("", result_lower_mpq);
        // printf(" <= ");
        // print_rational("", result_mpq);
        // printf(" <= ");
        // print_rational("", result_upper_mpq);
        // printf("\n");
        return true;
    }
    else
    {
        print_rational("Rational a: ", a_mpq);
        printf("\n");
        print_rational("Rational b: ", b_mpq);
        printf("\n");
        printf("Failed addition check, ");
        print_rational("", result_lower_mpq);
        printf(" <=? ");
        print_rational("", result_mpq);
        printf(" <=? ");
        print_rational("", result_upper_mpq);
        printf("\n");
        return false;
    }
}

bool test_mul()
{
    // generate the interval
    interval result = a * b;

    mpq_set_d(result_lower_mpq, result.lower());
    mpq_set_d(result_upper_mpq, result.upper());

    mpq_mul(result_mpq, a_mpq, b_mpq);

    if (within_range(result_lower_mpq, result_upper_mpq, result_mpq))
    {
        // printf("Passed multiplication check, ");
        // print_rational("", result_lower_mpq);
        // printf(" <= ");
        // print_rational("", result_mpq);
        // printf(" <= ");
        // print_rational("", result_upper_mpq);
        // printf("\n");
        return true;
    }
    else
    {
        print_rational("Rational a: ", a_mpq);
        printf("\n");
        print_rational("Rational b: ", b_mpq);
        printf("\n");
        printf("Failed multiplication check, ");
        print_rational("", result_lower_mpq);
        printf(" <=? ");
        print_rational("", result_mpq);
        printf(" <=? ");
        print_rational("", result_upper_mpq);
        printf("\n");
        return false;
    }
}

bool test_sub()
{
    // generate the interval
    interval result = a - b;

    mpq_set_d(result_lower_mpq, result.lower());
    mpq_set_d(result_upper_mpq, result.upper());

    mpq_sub(result_mpq, a_mpq, b_mpq);

    if (within_range(result_lower_mpq, result_upper_mpq, result_mpq))
    {
        // printf("Passed subtraction check, ");
        // print_rational("", result_lower_mpq);
        // printf(" <= ");
        // print_rational("", result_mpq);
        // printf(" <= ");
        // print_rational("", result_upper_mpq);
        // printf("\n");
        return true;
    }
    else
    {
        print_rational("Rational a: ", a_mpq);
        printf("\n");
        print_rational("Rational b: ", b_mpq);
        printf("\n");
        printf("Failed subtraction check, ");
        print_rational("", result_lower_mpq);
        printf(" <=? ");
        print_rational("", result_mpq);
        printf(" <=? ");
        print_rational("", result_upper_mpq);
        printf("\n");
        return false;
    }
}

bool test_div()
{
    // generate the interval
    interval result = a / b;

    mpq_set_d(result_lower_mpq, result.lower());
    mpq_set_d(result_upper_mpq, result.upper());

    mpq_div(result_mpq, a_mpq, b_mpq);

    if (within_range(result_lower_mpq, result_upper_mpq, result_mpq))
    {
        // printf("Passed division check, ");
        // print_rational("", result_lower_mpq);
        // printf(" <= ");
        // print_rational("", result_mpq);
        // printf(" <= ");
        // print_rational("", result_upper_mpq);
        // printf("\n");
        return true;
    }
    else
    {
        print_rational("Rational a: ", a_mpq);
        printf("\n");
        print_rational("Rational b: ", b_mpq);
        printf("\n");
        printf("Failed division check, ");
        print_rational("", result_lower_mpq);
        printf(" <=? ");
        print_rational("", result_mpq);
        printf(" <=? ");
        print_rational("", result_upper_mpq);
        printf("\n");
        return false;
    }
}

// composite expression 1
// a * b - c / a
bool test_comp1()
{
    interval result = a * b - c / a;

    mpq_set_d(result_lower_mpq, result.lower());
    mpq_set_d(result_upper_mpq, result.upper());

    mpq_t tmp;
    mpq_init(tmp);
    mpq_div(result_mpq, c_mpq, a_mpq);
    mpq_mul(tmp, a_mpq, b_mpq);
    mpq_sub(result_mpq, tmp, result_mpq);

    if (within_range(result_lower_mpq, result_upper_mpq, result_mpq))
    {
        // printf("Passed comp1 check, ");
        // print_rational("", result_lower_mpq);
        // printf(" <= ");
        // print_rational("", result_mpq);
        // printf(" <= ");
        // print_rational("", result_upper_mpq);
        // printf("\n");
        return true;
    }
    else
    {
        print_rational("Rational a: ", a_mpq);
        printf("\n");
        print_rational("Rational b: ", b_mpq);
        printf("\n");
        print_rational("Rational c: ", c_mpq);
        printf("\n");
        printf("Failed comp1 check, ");
        print_rational("", result_lower_mpq);
        printf(" <=? ");
        print_rational("", result_mpq);
        printf(" <=? ");
        print_rational("", result_upper_mpq);
        printf("\n");
        return false;
    }
}

// composite expression 2
// (a + b) * (a - b - c) / (b + c)
bool test_comp2()
{
    interval result = (a + b) * (a - b - c) / (b + c);

    mpq_set_d(result_lower_mpq, result.lower());
    mpq_set_d(result_upper_mpq, result.upper());

    mpq_t tmp1, tmp2;
    mpq_inits(tmp1, tmp2, (mpz_ptr)0);
    mpq_add(result_mpq, a_mpq, b_mpq);
    mpq_sub(tmp1, a_mpq, b_mpq);
    mpq_sub(tmp1, tmp1, c_mpq);
    mpq_add(tmp2, b_mpq, c_mpq);
    mpq_mul(result_mpq, result_mpq, tmp1);
    mpq_div(result_mpq, result_mpq, tmp2);

    if (within_range(result_lower_mpq, result_upper_mpq, result_mpq))
    {
        // printf("Passed comp2 check, ");
        // print_rational("", result_lower_mpq);
        // printf(" <= ");
        // print_rational("", result_mpq);
        // printf(" <= ");
        // print_rational("", result_upper_mpq);
        // printf("\n");
        return true;
    }
    else
    {
        print_rational("Rational a: ", a_mpq);
        printf("\n");
        print_rational("Rational b: ", b_mpq);
        printf("\n");
        print_rational("Rational c: ", c_mpq);
        printf("\n");
        printf("Failed comp2 check, ");
        print_rational("", result_lower_mpq);
        printf(" <=? ");
        print_rational("", result_mpq);
        printf(" <=? ");
        print_rational("", result_upper_mpq);
        printf("\n");
        return false;
    }
}

// composite expression 3
// -5.0 * (a + 3.0) / (b - 4.0) + (a / 6.0)
bool test_comp3()
{
    interval result = -5.0 * (a + 3.0) / (b - 4.0) + (a / 6.0);
    mpq_set_d(result_lower_mpq, result.lower());
    mpq_set_d(result_upper_mpq, result.upper());

    mpq_t tmp1, tmp2, tmp3;
    mpq_inits(tmp1, tmp2, tmp3, (mpz_ptr)0);

    mpq_div(tmp1, a_mpq, six);
    mpq_sub(tmp2, b_mpq, four);
    mpq_add(tmp3, a_mpq, three);
    mpq_div(tmp3, tmp3, tmp2);
    mpq_mul(tmp3, five, tmp3);
    mpq_add(result_mpq, tmp3, tmp1);

    if (within_range(result_lower_mpq, result_upper_mpq, result_mpq))
    {
        // printf("Passed comp3 check, ");
        // print_rational("", result_lower_mpq);
        // printf(" <= ");
        // print_rational("", result_mpq);
        // printf(" <= ");
        // print_rational("", result_upper_mpq);
        // printf("\n");
        return true;
    }
    else
    {
        print_rational("Rational a: ", a_mpq);
        printf("\n");
        print_rational("Rational b: ", b_mpq);
        printf("\n");
        printf("Failed comp3 check, ");
        print_rational("", result_lower_mpq);
        printf(" <=? ");
        print_rational("", result_mpq);
        printf(" <=? ");
        print_rational("", result_upper_mpq);
        printf("\n");
        return false;
    }

    return true;
}

int main(int argc, char *argv[])
{
    srand (13);
    // initialize the numbers in gmp
    mpq_inits(a_mpq, b_mpq, c_mpq, result_lower_mpq, result_upper_mpq, three, four, five, six, (mpz_ptr)0);
    mpq_set_d(three, 3);
    mpq_set_d(four, 4);
    mpq_set_d(five, -5);
    mpq_set_d(six, 6);
    mpq_init(result_mpq);

    for (int i = 0; i < 100000; i++)
    {
        random_init(a, a_mpq);
        random_init(b, b_mpq);
        random_init(c, c_mpq);

        bool result_add = test_add();
        bool result_mul = test_mul();
        bool result_sub = test_sub();
        bool result_div = test_div();
        bool result_comp1 = test_comp1();
        bool result_comp2 = test_comp2();
        bool result_comp3 = test_comp3();
        if (!result_add || !result_mul || !result_sub || !result_div || !result_comp1 || !result_comp2 || !result_comp3)
        {
            printf("Failed test\n");
            return 1;
        }
        if ((i + 1) % 2000 == 0)
        {
            printf("Passed %d tests so far\n", (i + 1));
        }
    }
    printf("Passed all tests\n");
    return 0;
}