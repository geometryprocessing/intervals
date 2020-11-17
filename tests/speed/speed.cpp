#include "../../src/methods.hpp"
using namespace std;

// get a timer for each interval type we have
double boost_timer, fic_timer, native_switch_timer, multiplicative_timer, pred_succ_timer;
double bias_up_timer, bias_down_timer, bias_near_timer;

// although those definition seems redundant
// I'm just trying to make my life easier
// do whatever you want for the spped thest
// see the helper_functions.hpp for input and output deatail
#ifdef USE_FILIB_PLUSPLUS
#define RUN_SPEED(METHOD, INFO, VARIABLE_COUNT, DISTRIBUTION, VERIFY_METHOD)                                                                                    \
    {                                                                                                                                                           \
        boost_timer = 0;                                                                                                                                        \
        fic_timer = 0;                                                                                                                                          \
        native_switch_timer = 0;                                                                                                                                \
        multiplicative_timer = 0;                                                                                                                               \
        pred_succ_timer = 0;                                                                                                                                    \
        bias_up_timer = 0;                                                                                                                                      \
        bias_down_timer = 0;                                                                                                                                    \
        bias_near_timer = 0;                                                                                                                                    \
        for (int i = 0; i < SPEED_TEST_LOOP; i++)                                                                                                               \
        {                                                                                                                                                       \
            PRE_FILL_RANDOM_DOUBLES(DISTRIBUTION, VARIABLE_COUNT, VERIFY_METHOD);                                                                               \
            COMPUTE_TIME(fic_interval, METHOD, VARIABLE_COUNT, fic_timer);                                                                                      \
            COMPUTE_TIME(boost_interval, METHOD, VARIABLE_COUNT, boost_timer);                                                                                  \
            filib::fp_traits<double, filib::native_switched>::setup();                                                                                          \
            COMPUTE_TIME(fi_native_switched, METHOD, VARIABLE_COUNT, native_switch_timer);                                                                      \
            filib::fp_traits<double, filib::multiplicative>::setup();                                                                                           \
            COMPUTE_TIME(fi_multiplicative, METHOD, VARIABLE_COUNT, multiplicative_timer);                                                                      \
            filib::fp_traits<double, filib::pred_succ_rounding>::setup();                                                                                       \
            COMPUTE_TIME(fi_pred_succ, METHOD, VARIABLE_COUNT, pred_succ_timer);                                                                                \
            BiasRoundUp();                                                                                                                                      \
            COMPUTE_TIME(BIASINTERVAL, METHOD, VARIABLE_COUNT, bias_up_timer);                                                                                  \
            BiasRoundDown();                                                                                                                                    \
            COMPUTE_TIME(BIASINTERVAL, METHOD, VARIABLE_COUNT, bias_down_timer);                                                                                \
            BiasRoundNear();                                                                                                                                    \
            COMPUTE_TIME(BIASINTERVAL, METHOD, VARIABLE_COUNT, bias_near_timer);                                                                                \
        }                                                                                                                                                       \
        printf("TIME, %s, FILIB C, %lf us, %lfx time that FILIB C version took\n", INFO, fic_timer, fic_timer / fic_timer);                                     \
        printf("TIME, %s, BOOST, %lf us, %lfx time that FILIB C version took\n", INFO, boost_timer, boost_timer / fic_timer);                                   \
        printf("TIME, %s, NATIVE SWITCHED METHOD, %lf us, %lfx time that FILIB C version took\n", INFO, native_switch_timer, native_switch_timer / fic_timer);  \
        printf("TIME, %s, MULTIPLICATIVE METHOD, %lf us, %lfx time that FILIB C version took\n", INFO, multiplicative_timer, multiplicative_timer / fic_timer); \
        printf("TIME, %s, PRED SUCC METHOD, %lf us, %lfx time that FILIB C version took\n", INFO, pred_succ_timer, pred_succ_timer / fic_timer);                \
        printf("TIME, %s, BIAS UPWARD, %lf us, %lfx time that FILIB C version took\n", INFO, bias_up_timer, bias_up_timer / fic_timer);                         \
        printf("TIME, %s, BIAS DOWNWARD, %lf us, %lfx time that FILIB C version took\n", INFO, bias_down_timer, bias_down_timer / fic_timer);                   \
        printf("TIME, %s, BIAS NEAR, %lf us, %lfx time that FILIB C version took\n", INFO, bias_near_timer, bias_near_timer / fic_timer);                       \
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
    BiasInit();
    BiasFuncInit();
    // we will run each method defined in method.hpp for each available interval library
    RUN_SPEED(addition, "ADDITION", 2, binary_all_range, check_input_addition);
    RUN_SPEED(subtraction, "SUBTRACTION", 2, binary_all_range, check_input_subtraction);
    RUN_SPEED(multiplication, "MULTIPLICATION", 2, binary_all_range, check_input_multiplication);
    RUN_SPEED(division, "DIVISION", 2, binary_all_range, check_input_division);
    RUN_SPEED(square_root, "SQUARE ROOT", 1, square_root_range, check_input_square_root);
    RUN_SPEED(exponential, "EXPONENTIAL", 1, exp_range, check_input_exponential);
    RUN_SPEED(sin, "SIN", 1, trig_all_range, check_input_sin);
    RUN_SPEED(cos, "COS", 1, trig_all_range, check_input_cos);
    RUN_SPEED(expr1, "ARITEMETIC EXPRESSION 1", 10, comp_all_range, check_input_expr1);
    RUN_SPEED(expr2, "ARITEMETIC EXPRESSION 2", 10, comp_all_range, check_input_expr2);
    RUN_SPEED(expr3, "ARITEMETIC EXPRESSION 3", 10, comp_all_range, check_input_expr3);
    RUN_SPEED(expr4, "ARITEMETIC EXPRESSION 4", expr4_variable_count, expr4_range, check_input_expr4);
    RUN_SPEED(expr5, "ARITEMETIC EXPRESSION 5", expr5_variable_count, expr5_range, check_input_expr5);
    RUN_SPEED(expr6, "ARITEMETIC EXPRESSION 6", expr6_variable_count, expr6_range, check_input_expr6);
    RUN_SPEED(expr7, "ARITEMETIC EXPRESSION 7", expr7_variable_count, expr7_range, check_input_expr7);
    RUN_SPEED(expr8, "ARITEMETIC EXPRESSION 8", expr8_variable_count, expr8_range, check_input_expr8);
    RUN_SPEED(expr9, "ARITEMETIC EXPRESSION 9", expr9_variable_count, expr9_range, check_input_expr9);
    RUN_SPEED(expr10, "ARITEMETIC EXPRESSION 10", expr10_variable_count, expr10_range, check_input_expr10);
    RUN_SPEED(extra_function1, "RANDOM EXPRESSION 1", extra_function1_variable_count, extra_function1_range, check_input_extra_function1);
    RUN_SPEED(extra_function2, "RANDOM EXPRESSION 2", extra_function2_variable_count, extra_function2_range, check_input_extra_function2);
    RUN_SPEED(extra_function3, "RANDOM EXPRESSION 3", extra_function3_variable_count, extra_function3_range, check_input_extra_function3);
    RUN_SPEED(extra_function4, "RANDOM EXPRESSION 4", extra_function4_variable_count, extra_function4_range, check_input_extra_function4);
    RUN_SPEED(extra_function5, "RANDOM EXPRESSION 5", extra_function5_variable_count, extra_function5_range, check_input_extra_function5);
    RUN_SPEED(extra_function6, "RANDOM EXPRESSION 6", extra_function6_variable_count, extra_function6_range, check_input_extra_function6);
    RUN_SPEED(extra_function7, "RANDOM EXPRESSION 7", extra_function7_variable_count, extra_function7_range, check_input_extra_function7);
    RUN_SPEED(extra_function8, "RANDOM EXPRESSION 8", extra_function8_variable_count, extra_function8_range, check_input_extra_function8);
    RUN_SPEED(extra_function9, "RANDOM EXPRESSION 9", extra_function9_variable_count, extra_function9_range, check_input_extra_function9);
    RUN_SPEED(extra_function10, "RANDOM EXPRESSION 10", extra_function10_variable_count, extra_function10_range, check_input_extra_function10);
    return 0;
}