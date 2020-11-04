#include "../../src/methods.hpp"
using namespace std;

// get a timer for each interval type we have
double boost_timer, fic_timer, native_switch_timer, multiplicative_timer, pred_succ_timer;

// although those definition seems redundant
// I'm just trying to make my life easier
// do whatever you want for the spped thest
// see the helper_functions.hpp for input and output deatail
#ifdef USE_FILIB_PLUSPLUS
#define RUN_SPEED(METHOD, INFO, VARIABLE_COUNT, DISTRIBUTION)                                                                                                   \
    {                                                                                                                                                           \
        boost_timer = 0;                                                                                                                                        \
        fic_timer = 0;                                                                                                                                          \
        native_switch_timer = 0;                                                                                                                                \
        multiplicative_timer = 0;                                                                                                                               \
        pred_succ_timer = 0;                                                                                                                                    \
        for (int i = 0; i < SPEED_TEST_LOOP; i++)                                                                                                               \
        {                                                                                                                                                       \
            PRE_FILL_RANDOM_DOUBLES(DISTRIBUTION, VARIABLE_COUNT);                                                                                              \
            COMPUTE_TIME(fic_interval, METHOD, VARIABLE_COUNT, fic_timer);                                                                                      \
            COMPUTE_TIME(boost_interval, METHOD, VARIABLE_COUNT, boost_timer);                                                                                  \
            filib::fp_traits<double, filib::native_switched>::setup();                                                                                          \
            COMPUTE_TIME(fi_native_switched, METHOD, VARIABLE_COUNT, native_switch_timer);                                                                      \
            filib::fp_traits<double, filib::multiplicative>::setup();                                                                                           \
            COMPUTE_TIME(fi_multiplicative, METHOD, VARIABLE_COUNT, multiplicative_timer);                                                                      \
            filib::fp_traits<double, filib::pred_succ_rounding>::setup();                                                                                       \
            COMPUTE_TIME(fi_pred_succ, METHOD, VARIABLE_COUNT, pred_succ_timer);                                                                                \
        }                                                                                                                                                       \
        printf("TIME, %s, FILIB C, %lf us, %lfx time that FILIB C version took\n", INFO, fic_timer, fic_timer / fic_timer);                                     \
        printf("TIME, %s, BOOST, %lf us, %lfx time that FILIB C version took\n", INFO, boost_timer, boost_timer / fic_timer);                                   \
        printf("TIME, %s, NATIVE SWITCHED METHOD, %lf us, %lfx time that FILIB C version took\n", INFO, native_switch_timer, native_switch_timer / fic_timer);  \
        printf("TIME, %s, MULTIPLICATIVE METHOD, %lf us, %lfx time that FILIB C version took\n", INFO, multiplicative_timer, multiplicative_timer / fic_timer); \
        printf("TIME, %s, PRED SUCC METHOD, %lf us, %lfx time that FILIB C version took\n", INFO, pred_succ_timer, pred_succ_timer / fic_timer);                \
    }                                                                                                                                                           \
    while (0)
#else
#define RUN_SPEED(METHOD, INFO, VARIABLE_COUNT, DISTRIBUTION)                                                                 \
    {                                                                                                                         \
        boost_timer = 0;                                                                                                      \
        fic_timer = 0;                                                                                                        \
        native_switch_timer = 0;                                                                                              \
        multiplicative_timer = 0;                                                                                             \
        pred_succ_timer = 0;                                                                                                  \
        for (int i = 0; i < SPEED_TEST_LOOP; i++)                                                                             \
        {                                                                                                                     \
            PRE_FILL_RANDOM_DOUBLES(DISTRIBUTION, VARIABLE_COUNT);                                                            \
            COMPUTE_TIME(fic_interval, METHOD, VARIABLE_COUNT, fic_timer);                                                    \
            COMPUTE_TIME(boost_interval, METHOD, VARIABLE_COUNT, boost_timer);                                                \
        }                                                                                                                     \
        printf("TIME, %s, FILIB C, %lf us, %lfx time that FILIB C version took\n", INFO, fic_timer, fic_timer / fic_timer);   \
        printf("TIME, %s, BOOST, %lf us, %lfx time that FILIB C version took\n", INFO, boost_timer, boost_timer / fic_timer); \
    }                                                                                                                         \
    while (0)
#endif

int main(int argc, char *argv[])
{
    // we will run each method defined in method.hpp for each available interval library
    RUN_SPEED(addition, "ADDITION", 2, binary_all_range);
    RUN_SPEED(subtraction, "SUBTRACTION", 2, binary_all_range);
    RUN_SPEED(multiplication, "MULTIPLICATION", 2, binary_all_range);
    RUN_SPEED(division, "DIVISION", 2, binary_all_range);
    RUN_SPEED(expr1, "EXPRESSION 1", 10, comp_all_range);
    RUN_SPEED(expr2, "EXPRESSION 2", 10, comp_all_range);
    RUN_SPEED(expr3, "EXPRESSION 3", 10, comp_all_range);
    RUN_SPEED(square_root, "SQUARE ROOT", 1, square_root_range);
    RUN_SPEED(exponential, "EXPONENTIAL", 1, exp_range);
    RUN_SPEED(sin, "SIN", 1, trig_all_range);
    RUN_SPEED(cos, "COS", 1, trig_all_range);

    return 0;
}