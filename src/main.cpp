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

// print result of a unary operation
void print_unary_result(interval input, interval result, std::string operand)
{
    std::cout << std::setprecision(std::numeric_limits<double>::digits10 + 1)
              << "Input interval from " << input.lower << " to " << input.upper << std::endl
              << operand << " result from " << result.lower << " to " << result.upper << std::endl;
    std::cout << "Interval is empty: "
              << (result.lower > result.upper ? "true" : "false")
              << std::endl;
}

// print result of a binary operation
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


// check if a list of values are within the given lower and upper range
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


int main(int argc, char *argv[])
{
    mpz_t n;
    mpz_init(n);
    mpz_set_ui(n, 20);
    printf("n = ");
    mpz_out_str(stdout, 10, n);
    printf("\n");

    return 0;
}