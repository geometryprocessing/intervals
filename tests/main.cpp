#include "helper.hpp"
#include "../src/interval.hpp"
#define TEST_SIZE 100000000
using namespace std;

void test_gap()
{
    for (int i = 0; i < TEST_SIZE; i++)
    {
        comp_addition();
        comp_subtraction();
        comp_multiplication();
        comp_division();
        comp_expr1();
        comp_expr2();
        comp_expr3();
        comp_square_root();
        comp_exponential();
    }
}

void test_time()
{
    time_addition();
    time_subtraction();
    time_multiplication();
    time_division();
    time_expr1();
    time_expr2();
    time_expr3();
}

void test_sqrt()
{
    for (int i = 0; i < TEST_SIZE; i++)
    {
        print_square_root();
    }
}

void test_exp()
{
    for (int i = 0; i < TEST_SIZE; i++)
    {
        print_exponential();
    }
}

void test_trig()
{
    for (int i = 0; i < TEST_SIZE; i++)
    {
        print_sin();
    }
    for (int i = 0; i < TEST_SIZE; i++)
    {
        print_cos();
    }
}

int main(int argc, char *argv[])
{
    generator.seed(13);
    comp_doubles.resize(10);
    comp_gmp_rationals.resize(10);
    comp_our_intervals.resize(10);
    comp_boost_intervals.resize(10);
    comp_fic_intervals.resize(10);

    // test_gap();
    // test_time();
    // test_sqrt();
    // test_exp();
    // test_trig();


    double large_number = 1;
    double small_number = 1;
    for (int i = 0; i < 54; i++)
    {
        large_number *= 2.0;
    }
    for (int i = 0; i < 16; i++)
    {
        small_number /= 2.0;
    }
    // gmp::Rational large_number_rational = gmp::Rational(0.79358805865013693);
    // // gmp::Rational small_number_rational = gmp::Rational(small_number);
    // gmp::Rational result_rational = cos(large_number_rational);
    // print_rational(large_number_rational);
    // printf("\n");
    // print_rational(small_number_rational);
    // printf("\n");
    // print_rational(result_rational);
    // printf("\n");
    boost_interval large_number_boost = boost_interval(0.79358805865013693);
    // boost_interval small_number_boost = boost_interval(small_number);
    boost_interval result_boost = cos(large_number_boost);
    printf("boost result: ");
    print_rational(result_boost.lower());
    printf(" <= cos(0.79358805865013693) <= ");
    print_rational(result_boost.upper());
    printf("\n");

    interval large_number_ours = interval(0.79358805865013693);
    // interval small_number_ours = interval(small_number);
    interval result_ours = cos(large_number_ours);
    printf("our result: ");
    print_rational(result_ours.lower());
    printf(" <= cos(0.79358805865013693) <= ");
    print_rational(result_ours.upper());
    printf("\n");

    fic_interval large_number_fic = {0.79358805865013693, 0.79358805865013693};
    // fic_interval small_number_fic = {small_number, small_number};
    fic_interval result_fic = cos(large_number_fic);
    printf("filib c result: ");
    print_rational(result_fic.INF);
    printf(" <= cos(0.79358805865013693) <= ");
    print_rational(result_fic.SUP);
    printf("\n");

    filib::fp_traits<double, filib::multiplicative>::setup();
    filib::interval<double, filib::multiplicative, filib::i_mode_normal> large_number_multiplicative = filib::interval<double, filib::multiplicative, filib::i_mode_normal>(0.79358805865013693);
    // filib::interval<double, filib::multiplicative, filib::i_mode_normal> small_number_multiplicative = filib::interval<double, filib::multiplicative, filib::i_mode_normal>(small_number);
    filib::interval<double, filib::multiplicative, filib::i_mode_normal> result_multiplicative = cos(large_number_multiplicative);
    printf("filib multiplicative result: ");
    print_rational(result_multiplicative.inf());
    printf(" <= cos(0.79358805865013693) <= ");
    print_rational(result_multiplicative.sup());
    printf("\n");

    return 0;
}
