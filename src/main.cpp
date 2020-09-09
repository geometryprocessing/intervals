#include <iostream>
#include "interval.h"
#include <cmath>
#include <limits>
#include <iomanip>

void print_cos_result(interval input, interval cos)
{
    std::cout << std::setprecision(std::numeric_limits<double>::digits10 + 1)
              << "Input interval from " << input.lower << " to " << input.upper
              << ", cosine result from " << cos.lower << " to " << cos.upper
              << std::endl;
    std::cout << "is empty: "
              << (cos.lower > cos.upper ? "true" : "false")
              << std::endl;
}

int main()
{
    interval test_interval = {3.14, 6.28};
    interval cos = cosine_interval(test_interval);
    print_cos_result(test_interval, cos);

    test_interval.lower = 3;
    test_interval.upper = 8;
    cos = cosine_interval(test_interval);
    print_cos_result(test_interval, cos);

    test_interval.lower = -1;
    test_interval.upper = 2.15;
    cos = cosine_interval(test_interval);
    print_cos_result(test_interval, cos);

    test_interval.lower = 3.12;
    test_interval.upper = 3.15;
    cos = cosine_interval(test_interval);
    print_cos_result(test_interval, cos);

    test_interval.lower = -0.2;
    test_interval.upper = 0;
    cos = cosine_interval(test_interval);
    print_cos_result(test_interval, cos);

    test_interval.lower = -0.2;
    test_interval.upper = 0.3;
    cos = cosine_interval(test_interval);
    print_cos_result(test_interval, cos);

    test_interval.lower = 0.79358805865013693;
    test_interval.upper = 0.79358805865013693;
    cos = cosine_interval(test_interval);
    print_cos_result(test_interval, cos);

    test_interval.lower = 3.1758805865013693;
    test_interval.upper = 3.1758805865013693;
    cos = cosine_interval(test_interval);
    print_cos_result(test_interval, cos);


    return 0;
}