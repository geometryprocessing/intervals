#include <iostream>
#include "interval.h"
#include <cmath>
#include <limits>
#include <iomanip>
#include <cmath>
#include <string>
#include <fenv.h>
#include <vector>

void print_unary_result(interval input, interval cos_result, std::string operand)
{
    std::cout << std::setprecision(std::numeric_limits<double>::digits10 + 1)
              << "Input interval from " << input.lower << " to " << input.upper << std::endl
              << operand << " result from " << cos_result.lower << " to " << cos_result.upper << std::endl;
    std::cout << "Interval is empty: "
              << (cos_result.lower > cos_result.upper ? "true" : "false")
              << std::endl;
}

void print_binary_result(interval input_a, interval input_b, interval result, std::string operand)
{
    std::cout << std::setprecision(std::numeric_limits<double>::digits10 + 1)
              << "Input interval 1 from " << input_a.lower << " to " << input_a.upper << std::endl
              << "Input interval 2 from " << input_b.lower << " to " << input_b.upper << std::endl
              << operand << " result from " << result.lower << " to " << result.upper << std::endl;
    std::cout << "Interval is empty: "
              << (result.lower > result.upper ? "true" : "false")
              << std::endl;
}

void test_cos(double lower, double upper)
{
    interval test_interval = {lower, upper};
    interval cos_result = cosine_interval(test_interval);
    print_unary_result(test_interval, cos_result, "Cosine");
    std::cout << std::setprecision(std::numeric_limits<double>::digits10 + 1)
              << "Cosine of lower is: " << cos(lower) << std::endl
              << "Cosine of upper is: " << cos(upper) << std::endl
              << std::endl;
}

bool within_range(double lower, double upper, std::vector<double> values)
{
    for (int i = 0; i < values.size(); i++)
    {
        if (values[i] < lower || values[i] > upper)
        {
            return false;
        }
    }
    return true;
}

void test_add(double al, double au, double bl, double bu)
{
    interval i1 = {al, au};
    interval i2 = {bl, bu};
    interval result = add_interval(i1, i2);
    print_binary_result(i1, i2, result, "Addition");
    double computed_lower = al + bl;
    double computed_upper = au + bu;
    bool within = within_range(result.lower, result.upper, {computed_lower, computed_upper});
    std::cout << "Pass check:" << (within ? "true" : "false") << std::endl;
    std::cout << std::endl;
}

void test_mult(double al, double au, double bl, double bu)
{
    interval i1 = {al, au};
    interval i2 = {bl, bu};
    interval result = mult_interval(i1, i2);
    print_binary_result(i1, i2, result, "Multiplication");
    bool within = within_range(result.lower, result.upper, {al * bl, al * bu, au * bl, au * bu});
    std::cout << "Pass check:" << (within ? "true" : "false") << std::endl;
    std::cout << std::endl;
}

void test_div(double al, double au, double bl, double bu)
{
    interval i1 = {al, au};
    interval i2 = {bl, bu};
    interval result = div_interval(i1, i2);
    print_binary_result(i1, i2, result, "Division");
    bool within = within_range(result.lower, result.upper, {al / bl, al / bu, au / bl, au / bu});
    std::cout << "Pass check:" << (within ? "true" : "false") << std::endl;
    std::cout << std::endl;
}

int main()
{
    // test_cos(3.14, 6.28);
    // test_cos(3, 8);
    // test_cos(-1, 2.15);
    // test_cos(3.12, 3.15);
    // test_cos(-0.2, 0);
    // test_cos(-0.2, 0.3);
    // test_cos(0.79358805865013693, 0.79358805865013693);
    // test_cos((24.0 / 17.0), (24.0 / 17.0));

    test_add(-(24.0 / 17.0), (24.0 / 17.0), 104, 257);

    test_mult(-(24.0 / 17.0), -(4.0 / 13.0), -3012, 298);
    test_mult(-3, -2, -3, -2);

    test_div(-1, 1, -2, 3);

    return 0;
}