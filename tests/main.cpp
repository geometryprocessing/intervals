#include "helper.hpp"
#include "../src/interval.hpp"
#define TEST_SIZE 1000
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
        // comp_square_root();
        // comp_exponential();
        comp_sin();
        // comp_cos();
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
    time_sin();
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
#ifndef USE_SYSTEM_RANDOM
    read_to_ratioanl_list("../numbers.txt");
#endif

    test_gap();
    // test_time();
    // test_sqrt();
    // test_exp();
    // test_trig();

    return 0;
}
