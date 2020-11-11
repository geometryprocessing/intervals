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
        }                                                                                     \
    }                                                                                         \
    while (0)
#else
#define RUN_GAP(METHOD, INFO, VARIABLE_COUNT, DISTRIBUTION)                     \
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
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/addition_used_rationals.txt");
    read_rationals_from_file("../rational_datas/subtraction_used_rationals.txt");
    read_rationals_from_file("../rational_datas/multiplication_used_rationals.txt");
    read_rationals_from_file("../rational_datas/division_used_rationals.txt");
    read_rationals_from_file("../rational_datas/expr1_used_rationals.txt");
    read_rationals_from_file("../rational_datas/expr2_used_rationals.txt");
    read_rationals_from_file("../rational_datas/expr3_used_rationals.txt");
    read_rationals_from_file("../rational_datas/square_root_used_rationals.txt");
    read_rationals_from_file("../rational_datas/exponential_used_rationals.txt");
    read_rationals_from_file("../rational_datas/sin_used_rationals.txt");
    read_rationals_from_file("../rational_datas/cos_used_rationals.txt");
    read_rationals_from_file("../rational_datas/extra_function1_used_rationals.txt");
    read_rationals_from_file("../rational_datas/extra_function2_used_rationals.txt");
    read_rationals_from_file("../rational_datas/extra_function3_used_rationals.txt");
    read_rationals_from_file("../rational_datas/extra_function4_used_rationals.txt");
    read_rationals_from_file("../rational_datas/extra_function5_used_rationals.txt");
    read_rationals_from_file("../rational_datas/extra_function6_used_rationals.txt");
    read_rationals_from_file("../rational_datas/extra_function7_used_rationals.txt");
#endif
    RUN_GAP(addition, "ADDITION", 2, binary_all_range, check_input_addition);
    RUN_GAP(subtraction, "SUBTRACTION", 2, binary_all_range, check_input_subtraction);
    RUN_GAP(multiplication, "MULTIPLICATION", 2, binary_all_range, check_input_multiplication);
    RUN_GAP(division, "DIVISION", 2, binary_all_range, check_input_division);
    RUN_GAP(expr1, "EXPRESSION 1", 10, comp_all_range, check_input_expr1);
    RUN_GAP(expr2, "EXPRESSION 2", 10, comp_all_range, check_input_expr2);
    RUN_GAP(expr3, "EXPRESSION 3", 10, comp_all_range, check_input_expr3);
    RUN_GAP(square_root, "SQUARE ROOT", 1, square_root_range, check_input_square_root);
    RUN_GAP(exponential, "EXPONENTIAL", 1, exp_range, check_input_exponential);
    RUN_GAP(sin, "SIN", 1, trig_all_range, check_input_sin);
    RUN_GAP(cos, "COS", 1, trig_all_range, check_input_cos);
    RUN_GAP(extra_function1, "AUTO GENERATED RANDOM EXPRESSION 1", extra_function1_variable_count, extra_function1_range, check_input_extra_function1);
    RUN_GAP(extra_function2, "AUTO GENERATED RANDOM EXPRESSION 2", extra_function2_variable_count, extra_function2_range, check_input_extra_function2);
    RUN_GAP(extra_function3, "AUTO GENERATED RANDOM EXPRESSION 3", extra_function3_variable_count, extra_function3_range, check_input_extra_function3);
}