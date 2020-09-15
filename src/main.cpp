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
template <class ValueType>
ValueType read_option(const char *option, int argc, char **argv, const char *default_value = nullptr);

template <>
std::string read_option<std::string>(const char *option, int argc, char **argv, const char *default_value)
{
    for (int i = 0; i < argc - 1; i++)
    {
        if (!strcmp(argv[i], option))
        {
            return std::string(argv[i + 1]);
        }
    }
    if (default_value)
        return std::string(default_value);
    std::cerr << "Option " << option << " was not provided. Exiting...\n";
    exit(1);
}

template <>
int read_option<int>(const char *option, int argc, char **argv, const char *default_value)
{
    return strtol(read_option<std::string>(option, argc, argv, default_value).c_str(), NULL, 10);
}
template <>
long read_option<long>(const char *option, int argc, char **argv, const char *default_value)
{
    return strtol(read_option<std::string>(option, argc, argv, default_value).c_str(), NULL, 10);
}
template <>
float read_option<float>(const char *option, int argc, char **argv, const char *default_value)
{
    return strtod(read_option<std::string>(option, argc, argv, default_value).c_str(), NULL);
}
template <>
double read_option<double>(const char *option, int argc, char **argv, const char *default_value)
{
    return strtof(read_option<std::string>(option, argc, argv, default_value).c_str(), NULL);
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
    std::cout << "Pass check: " << (within ? "true" : "false") << std::endl;
    std::cout << std::endl;
}

void test_sub(double al, double au, double bl, double bu)
{
    interval i1 = {al, au};
    interval i2 = {bl, bu};
    interval result = subtract_interval(i1, i2);
    print_binary_result(i1, i2, result, "Subtraction");
    bool within = within_range(result.lower, result.upper, {al - bl, al - bu, au - bl, au - bu});
    std::cout << "Pass check: " << (within ? "true" : "false") << std::endl;
    std::cout << std::endl;
}

void test_mult(double al, double au, double bl, double bu)
{
    interval i1 = {al, au};
    interval i2 = {bl, bu};
    interval result = mult_interval(i1, i2);
    print_binary_result(i1, i2, result, "Multiplication");
    bool within = within_range(result.lower, result.upper, {al * bl, al * bu, au * bl, au * bu});
    std::cout << "Pass check: " << (within ? "true" : "false") << std::endl;
    std::cout << std::endl;
}

void test_div(double al, double au, double bl, double bu)
{
    interval i1 = {al, au};
    interval i2 = {bl, bu};
    interval result = div_interval(i1, i2);
    print_binary_result(i1, i2, result, "Division");
    bool within = within_range(result.lower, result.upper, {al / bl, al / bu, au / bl, au / bu});
    std::cout << "Pass check: " << (within ? "true" : "false") << std::endl;
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    int operation = read_option<int>("-o", argc, argv, "0");
    int aln = read_option<int>("--aln", argc, argv, "1"); // a lower numerator
    int ald = read_option<int>("--ald", argc, argv, "1"); // a lower denominator
    int aun = read_option<int>("--aun", argc, argv, "1"); // a upper numerator
    int aud = read_option<int>("--aud", argc, argv, "1"); // a upper denominator
    int bln = read_option<int>("--bln", argc, argv, "1"); // b lower numerator
    int bld = read_option<int>("--bld", argc, argv, "1"); // b lower denominator
    int bun = read_option<int>("--bun", argc, argv, "1"); // b upper numerator
    int bud = read_option<int>("--bud", argc, argv, "1"); // b upper denominator

    // std::cout << "Input interval 1 from " << aln << "/" << ald << " to " << aun << "/" << aud << std::endl;
    // std::cout << "Input interval 2 from " << bln << "/" << bld << " to " << bun << "/" << bud << std::endl;

    double al = div_interval({aln * 1.0, aln * 1.0}, {ald * 1.0, ald * 1.0}).lower;
    double au = div_interval({aun * 1.0, aun * 1.0}, {aud * 1.0, aud * 1.0}).upper;
    double bl = div_interval({bln * 1.0, bln * 1.0}, {bld * 1.0, bld * 1.0}).lower;
    double bu = div_interval({bun * 1.0, bun * 1.0}, {bud * 1.0, bud * 1.0}).upper;

    // make sure the interval is not empty
    if (al > au)
    {
        double tmp = au;
        au = al;
        al = tmp;
    }

    if (bl > bu)
    {
        double tmp = bu;
        bu = bl;
        bl = tmp;
    }

    switch (operation)
    {
    case 0:
        test_add(al, au, bl, bu);
        break;
    case 1:
        test_sub(al, au, bl, bu);
        break;
    case 2:
        test_mult(al, au, bl, bu);
        break;
    case 3:
        test_div(al, au, bl, bu);
        break;
    default:
        test_add(al, au, bl, bu);
        break;
    }

    return 0;
}