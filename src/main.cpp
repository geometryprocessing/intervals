#include <iostream>
#include "interval.h"

void print_cos_result(interval input, interval cos)
{
    printf("Input interval from %f to %f, cosine result from %f to %f\n", input.lower, input.upper, cos.lower, cos.upper);
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

    return 0;
}