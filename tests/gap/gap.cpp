#include "../../src/methods.hpp"
using namespace std;

// because filib c++ version is not supported everywhere
#ifdef USE_FILIB_PLUSPLUS
#define RUN_GAP(METHOD, INFO, VARIABLE_COUNT, DISTRIBUTION, VERIFY_METHOD)                    \
    {                                                                                         \
        for (int i = 0; i < TEST_SIZE; i++)                                                   \
        {                                                                                     \
            PRE_FILL_RANDOM_DOUBLES(DISTRIBUTION, VARIABLE_COUNT, VERIFY_METHOD);             \
            COMPUTE_GAP(fic_interval, "FILIB C", METHOD, INFO, VARIABLE_COUNT);               \
            COMPUTE_GAP(boost_interval, "BOOST", METHOD, INFO, VARIABLE_COUNT);               \
            filib::fp_traits<double, filib::native_switched>::setup();                        \
            COMPUTE_GAP(fi_native_switched, "NATIVE SWITCHED", METHOD, INFO, VARIABLE_COUNT); \
            filib::fp_traits<double, filib::multiplicative>::setup();                         \
            COMPUTE_GAP(fi_multiplicative, "MULTIPLICATIVE", METHOD, INFO, VARIABLE_COUNT);   \
            filib::fp_traits<double, filib::pred_succ_rounding>::setup();                     \
            COMPUTE_GAP(fi_pred_succ, "PRED SUCC", METHOD, INFO, VARIABLE_COUNT);             \
            BiasRoundUp();                                                                    \
            COMPUTE_GAP(BIASINTERVAL, "BIAS ROUND UP", METHOD, INFO, VARIABLE_COUNT);         \
            BiasRoundDown();                                                                  \
            COMPUTE_GAP(BIASINTERVAL, "BIAS ROUND DOWN", METHOD, INFO, VARIABLE_COUNT);       \
            BiasRoundNear();                                                                  \
            COMPUTE_GAP(BIASINTERVAL, "BIAS ROUND NEAR", METHOD, INFO, VARIABLE_COUNT);       \
        }                                                                                     \
    }                                                                                         \
    while (0)
#else
#define RUN_GAP(METHOD, INFO, VARIABLE_COUNT, DISTRIBUTION, VERIFY_METHOD)      \
    {                                                                           \
        for (int i = 0; i < TEST_SIZE; i++)                                     \
        {                                                                       \
            PRE_FILL_RANDOM_DOUBLES(DISTRIBUTION, VARIABLE_COUNT);              \
            COMPUTE_GAP(fic_interval, "FILIB C", METHOD, INFO, VARIABLE_COUNT); \
            COMPUTE_GAP(boost_interval, "BOOST", METHOD, INFO, VARIABLE_COUNT); \
        }                                                                       \
    }                                                                           \
    while (0)
#endif

int main(int argc, char *argv[])
{
    BiasInit();
    BiasFuncInit();
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/addition_used_rationals.txt");
    read_rationals_from_file("../rational_datas/subtraction_used_rationals.txt");
    read_rationals_from_file("../rational_datas/multiplication_used_rationals.txt");
    read_rationals_from_file("../rational_datas/division_used_rationals.txt");
    read_rationals_from_file("../rational_datas/square_root_used_rationals.txt");
    read_rationals_from_file("../rational_datas/exponential_used_rationals.txt");
    read_rationals_from_file("../rational_datas/sin_used_rationals.txt");
    read_rationals_from_file("../rational_datas/cos_used_rationals.txt");
    read_rationals_from_file("../rational_datas/expr1_used_rationals.txt");
    read_rationals_from_file("../rational_datas/expr2_used_rationals.txt");
    read_rationals_from_file("../rational_datas/expr3_used_rationals.txt");
    read_rationals_from_file("../rational_datas/expr4_used_rationals.txt");
    read_rationals_from_file("../rational_datas/expr6_used_rationals.txt");
    read_rationals_from_file("../rational_datas/expr6_used_rationals.txt");
    read_rationals_from_file("../rational_datas/expr7_used_rationals.txt");
    read_rationals_from_file("../rational_datas/expr8_used_rationals.txt");
    read_rationals_from_file("../rational_datas/expr9_used_rationals.txt");
    read_rationals_from_file("../rational_datas/expr10_used_rationals.txt");
    read_rationals_from_file("../rational_datas/extra_function1_used_rationals.txt");
    read_rationals_from_file("../rational_datas/extra_function2_used_rationals.txt");
    read_rationals_from_file("../rational_datas/extra_function3_used_rationals.txt");
    read_rationals_from_file("../rational_datas/extra_function4_used_rationals.txt");
    read_rationals_from_file("../rational_datas/extra_function5_used_rationals.txt");
    read_rationals_from_file("../rational_datas/extra_function6_used_rationals.txt");
    read_rationals_from_file("../rational_datas/extra_function7_used_rationals.txt");
    read_rationals_from_file("../rational_datas/extra_function8_used_rationals.txt");
    read_rationals_from_file("../rational_datas/extra_function9_used_rationals.txt");
    read_rationals_from_file("../rational_datas/extra_function10_used_rationals.txt");
#endif
    RUN_GAP(addition, "ADDITION", 2, binary_all_range, check_input_addition);
    RUN_GAP(subtraction, "SUBTRACTION", 2, binary_all_range, check_input_subtraction);
    RUN_GAP(multiplication, "MULTIPLICATION", 2, binary_all_range, check_input_multiplication);
    RUN_GAP(division, "DIVISION", 2, binary_all_range, check_input_division);
    RUN_GAP(square_root, "SQUARE ROOT", 1, square_root_range, check_input_square_root);
    RUN_GAP(exponential, "EXPONENTIAL", 1, exp_range, check_input_exponential);
    RUN_GAP(sin, "SIN", 1, trig_all_range, check_input_sin);
    RUN_GAP(cos, "COS", 1, trig_all_range, check_input_cos);
    RUN_GAP(expr1, "ARITHMETIC EXPRESSION 1", 10, comp_all_range, check_input_expr1);
    RUN_GAP(expr2, "ARITHMETIC EXPRESSION 2", 10, comp_all_range, check_input_expr2);
    RUN_GAP(expr3, "ARITHMETIC EXPRESSION 3", 10, comp_all_range, check_input_expr3);
    RUN_GAP(expr4, "ARITHMETIC EXPRESSION 4", expr4_variable_count, expr4_range, check_input_expr4);
    RUN_GAP(expr5, "ARITHMETIC EXPRESSION 5", expr5_variable_count, expr5_range, check_input_expr5);
    RUN_GAP(expr6, "ARITHMETIC EXPRESSION 6", expr6_variable_count, expr6_range, check_input_expr6);
    RUN_GAP(expr7, "ARITHMETIC EXPRESSION 7", expr7_variable_count, expr7_range, check_input_expr7);
    RUN_GAP(expr8, "ARITHMETIC EXPRESSION 8", expr8_variable_count, expr8_range, check_input_expr8);
    RUN_GAP(expr9, "ARITHMETIC EXPRESSION 9", expr9_variable_count, expr9_range, check_input_expr9);
    RUN_GAP(expr10, "ARITHMETIC EXPRESSION 10", expr10_variable_count, expr10_range, check_input_expr10);
    RUN_GAP(extra_function1, "RANDOM EXPRESSION 1", extra_function1_variable_count, extra_function1_range, check_input_extra_function1);
    RUN_GAP(extra_function2, "RANDOM EXPRESSION 2", extra_function2_variable_count, extra_function2_range, check_input_extra_function2);
    RUN_GAP(extra_function3, "RANDOM EXPRESSION 3", extra_function3_variable_count, extra_function3_range, check_input_extra_function3);
    RUN_GAP(extra_function4, "RANDOM EXPRESSION 4", extra_function4_variable_count, extra_function4_range, check_input_extra_function4);
    RUN_GAP(extra_function5, "RANDOM EXPRESSION 5", extra_function5_variable_count, extra_function5_range, check_input_extra_function5);
    RUN_GAP(extra_function6, "RANDOM EXPRESSION 6", extra_function6_variable_count, extra_function6_range, check_input_extra_function6);
    RUN_GAP(extra_function7, "RANDOM EXPRESSION 7", extra_function7_variable_count, extra_function7_range, check_input_extra_function7);
    RUN_GAP(extra_function8, "RANDOM EXPRESSION 8", extra_function8_variable_count, extra_function8_range, check_input_extra_function8);
    RUN_GAP(extra_function9, "RANDOM EXPRESSION 9", extra_function9_variable_count, extra_function9_range, check_input_extra_function9);
    RUN_GAP(extra_function10, "RANDOM EXPRESSION 10", extra_function10_variable_count, extra_function10_range, check_input_extra_function10);
}
