#include "../../src/methods.hpp"
using namespace std;
#ifdef USE_FILIB_PLUSPLUS
#define RUN_QUERY(METHOD, PRINT_METHOD, VARIABLE_COUNT, DISTRIBUTION, VERIFY_METHOD)                    \
    do                                                                                                  \
    {                                                                                                   \
        for (int i = 0; i < TEST_SIZE; i++)                                                             \
        {                                                                                               \
            PRE_FILL_RANDOM_DOUBLES(DISTRIBUTION, VARIABLE_COUNT, VERIFY_METHOD);                       \
            PRINT_QUERIES(fic_interval, "FILIB C", METHOD, PRINT_METHOD, VARIABLE_COUNT);               \
            PRINT_QUERIES(boost_interval, "BOOST", METHOD, PRINT_METHOD, VARIABLE_COUNT);               \
            filib::fp_traits<double, filib::native_switched>::setup();                                  \
            PRINT_QUERIES(fi_native_switched, "NATIVE SWITCHED", METHOD, PRINT_METHOD, VARIABLE_COUNT); \
            filib::fp_traits<double, filib::multiplicative>::setup();                                   \
            PRINT_QUERIES(fi_multiplicative, "MULTIPLICATIVE", METHOD, PRINT_METHOD, VARIABLE_COUNT);   \
            filib::fp_traits<double, filib::pred_succ_rounding>::setup();                               \
            PRINT_QUERIES(fi_pred_succ, "PRED SUCC", METHOD, PRINT_METHOD, VARIABLE_COUNT);             \
            BiasRoundUp();                                                                              \
            PRINT_QUERIES(BIASINTERVAL, "BIAS ROUND UP", METHOD, PRINT_METHOD, VARIABLE_COUNT);         \
            BiasRoundDown();                                                                            \
            PRINT_QUERIES(BIASINTERVAL, "BIAS ROUND DOWN", METHOD, PRINT_METHOD, VARIABLE_COUNT);       \
            BiasRoundNear();                                                                            \
            PRINT_QUERIES(BIASINTERVAL, "BIAS ROUND NEAR", METHOD, PRINT_METHOD, VARIABLE_COUNT);       \
        }                                                                                               \
    } while (0)
#else
#define RUN_QUERY(METHOD, PRINT_METHOD, VARIABLE_COUNT, DISTRIBUTION)                     \
    do                                                                                    \
    {                                                                                     \
        for (int i = 0; i < TEST_SIZE; i++)                                               \
        {                                                                                 \
            PRE_FILL_RANDOM_DOUBLES(DISTRIBUTION, VARIABLE_COUNT);                        \
            PRINT_QUERIES(fic_interval, "FILIB C", METHOD, PRINT_METHOD, VARIABLE_COUNT); \
            PRINT_QUERIES(boost_interval, "BOOST", METHOD, PRINT_METHOD, VARIABLE_COUNT); \
        }                                                                                 \
    } while (0)
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
    read_rationals_from_file("../rational_datas/expr5_used_rationals.txt");
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
    RUN_QUERY(addition, print_addition, 2, binary_all_range, check_input_addition);
    RUN_QUERY(subtraction, print_subtraction, 2, binary_all_range, check_input_subtraction);
    RUN_QUERY(multiplication, print_multiplication, 2, binary_all_range, check_input_multiplication);
    RUN_QUERY(division, print_division, 2, binary_all_range, check_input_division);
    RUN_QUERY(square_root, print_square_root, 1, square_root_range, check_input_square_root);
    RUN_QUERY(exponential, print_exponential, 1, exp_range, check_input_exponential);
    RUN_QUERY(sin, print_sin, 1, trig_pi_over_four, check_input_sin);
    RUN_QUERY(cos, print_cos, 1, trig_pi_over_four, check_input_cos);
    RUN_QUERY(expr1, print_expr1, 10, comp_all_range, check_input_expr1);
    RUN_QUERY(expr2, print_expr2, 10, comp_all_range, check_input_expr2);
    RUN_QUERY(expr3, print_expr3, 10, comp_all_range, check_input_expr3);
    RUN_QUERY(expr4, print_expr4, expr4_variable_count, expr4_range, check_input_expr4);
    RUN_QUERY(expr5, print_expr5, expr5_variable_count, expr5_range, check_input_expr5);
    RUN_QUERY(expr6, print_expr6, expr6_variable_count, expr6_range, check_input_expr6);
    RUN_QUERY(expr7, print_expr7, expr7_variable_count, expr7_range, check_input_expr7);
    RUN_QUERY(expr8, print_expr8, expr8_variable_count, expr8_range, check_input_expr8);
    RUN_QUERY(expr9, print_expr9, expr9_variable_count, expr9_range, check_input_expr9);
    RUN_QUERY(expr10, print_expr10, expr10_variable_count, expr10_range, check_input_expr10);
    RUN_QUERY(extra_function1, print_extra_function1, extra_function1_variable_count, extra_function1_range, check_input_extra_function1);
    RUN_QUERY(extra_function2, print_extra_function2, extra_function2_variable_count, extra_function2_range, check_input_extra_function2);
    RUN_QUERY(extra_function3, print_extra_function3, extra_function3_variable_count, extra_function3_range, check_input_extra_function3);
    RUN_QUERY(extra_function4, print_extra_function4, extra_function4_variable_count, extra_function4_range, check_input_extra_function4);
    RUN_QUERY(extra_function5, print_extra_function5, extra_function5_variable_count, extra_function5_range, check_input_extra_function5);
    RUN_QUERY(extra_function6, print_extra_function6, extra_function6_variable_count, extra_function6_range, check_input_extra_function6);
    RUN_QUERY(extra_function7, print_extra_function7, extra_function7_variable_count, extra_function7_range, check_input_extra_function7);
    RUN_QUERY(extra_function8, print_extra_function8, extra_function8_variable_count, extra_function8_range, check_input_extra_function8);
    RUN_QUERY(extra_function9, print_extra_function9, extra_function9_variable_count, extra_function9_range, check_input_extra_function9);
    RUN_QUERY(extra_function10, print_extra_function10, extra_function10_variable_count, extra_function10_range, check_input_extra_function10);
    return 0;
}
