#include "../../src/interval.hpp"
using namespace std;
using namespace HighFive;

// get a timer for each interval type we have
double boost_timer, fic_timer, native_switch_timer, multiplicative_timer, pred_succ_timer;

#define RUN_SPEED(METHOD, VARIABLE_COUNT, INFO)                                                                                                                 \
    {                                                                                                                                                           \
        boost_timer = 0;                                                                                                                                        \
        fic_timer = 0;                                                                                                                                          \
        native_switch_timer = 0;                                                                                                                                \
        multiplicative_timer = 0;                                                                                                                               \
        pred_succ_timer = 0;                                                                                                                                    \
        for (int i = 0; i < SPEED_TEST_SIZE; i++)                                                                                                               \
        {                                                                                                                                                       \
            PRE_FILL_RANDOM_DOUBLES(distribution_all_range, VARIABLE_COUNT);                                                                                    \
            COMPUTE_TIME(fic_interval, addition, VARIABLE_COUNT, fic_timer);                                                                                    \
            COMPUTE_TIME(boost_interval, addition, VARIABLE_COUNT, boost_timer);                                                                                \
            filib::fp_traits<double, filib::native_switched>::setup();                                                                                          \
            COMPUTE_TIME(fi_native_switched, addition, VARIABLE_COUNT, native_switch_timer);                                                                    \
            filib::fp_traits<double, filib::multiplicative>::setup();                                                                                           \
            COMPUTE_TIME(fi_multiplicative, addition, VARIABLE_COUNT, multiplicative_timer);                                                                    \
            filib::fp_traits<double, filib::pred_succ_rounding>::setup();                                                                                       \
            COMPUTE_TIME(fi_pred_succ, addition, VARIABLE_COUNT, pred_succ_timer);                                                                              \
        }                                                                                                                                                       \
        printf("TIME, %s, FILIB C, %lf us, %lfx time that FILIB C version took\n", INFO, boost_timer, fic_timer / fic_timer);                                   \
        printf("TIME, %s, BOOST, %lf us, %lfx time that FILIB C version took\n", INFO, boost_timer, boost_timer / fic_timer);                                   \
        printf("TIME, %s, NATIVE SWITCHED METHOD, %lf us, %lfx time that FILIB C version took\n", INFO, native_switch_timer, native_switch_timer / fic_timer);  \
        printf("TIME, %s, MULTIPLICATIVE METHOD, %lf us, %lfx time that FILIB C version took\n", INFO, multiplicative_timer, multiplicative_timer / fic_timer); \
        printf("TIME, %s, PRED SUCC METHOD, %lf us, %lfx time that FILIB C version took\n", INFO, pred_succ_timer, pred_succ_timer / fic_timer);                \
    }                                                                                                                                                           \
    while (0)

int main(int argc, char *argv[])
{
    // we will run each method defined in method.hpp for each available interval library
    RUN_SPEED(addition, 2, "ADDITION");
    RUN_SPEED(subtraction, 2, "SUBTRACTION");
    RUN_SPEED(multiplication, 2, "MULTIPLICATION");
    RUN_SPEED(division, 2, "DIVISION");
    RUN_SPEED(expr1, 10, "EXPRESSION 1");
    RUN_SPEED(expr2, 10, "EXPRESSION 2");
    RUN_SPEED(expr3, 10, "EXPRESSION 3");
    RUN_SPEED(square_root, 1, "SQUARE ROOT");
    RUN_SPEED(exponential, 1, "EXPONENTIAL");
    RUN_SPEED(sin, 1, "SIN");
    RUN_SPEED(cos, 1, "COS");

    return 0;
}