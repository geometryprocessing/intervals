#include "../../src/methods.hpp"
using namespace std;

#ifdef USE_FILIB_PLUSPLUS
#define RUN_QUERY(METHOD, PRINT_METHOD, VARIABLE_COUNT, DISTRIBUTION, VERIFY_METHOD)              \
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
        }                                                                                               \
    } while (0)
#else
#define RUN_QUERY(METHOD, PRINT_METHOD, VARIABLE_COUNT, DISTRIBUTION)               \
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
    RUN_QUERY(addition, print_addition, 2, binary_all_range, check_input_addition);
    RUN_QUERY(subtraction, print_subtraction, 2, binary_all_range, check_input_subtraction);
    RUN_QUERY(multiplication, print_multiplication, 2, binary_all_range, check_input_multiplication);
    RUN_QUERY(division, print_division, 2, binary_all_range, check_input_division);
    RUN_QUERY(expr1, print_expr1, 10, comp_all_range, check_input_expr1);
    RUN_QUERY(expr2, print_expr2, 10, comp_all_range, check_input_expr2);
    RUN_QUERY(expr3, print_expr3, 10, comp_all_range, check_input_expr3);
    RUN_QUERY(square_root, print_square_root, 1, square_root_range, check_input_square_root);
    RUN_QUERY(exponential, print_exponential, 1, exp_range, check_input_exponential);
    RUN_QUERY(sin, print_sin, 1, trig_pi_over_four, check_input_sin);
    RUN_QUERY(cos, print_cos, 1, trig_pi_over_four, check_input_cos);
    RUN_QUERY(extra_function1, print_extra_function1, extra_function1_variable_count, extra_function1_range, check_input_extra_function1);
    RUN_QUERY(extra_function2, print_extra_function2, extra_function2_variable_count, extra_function2_range, check_input_extra_function2);
    RUN_QUERY(extra_function3, print_extra_function3, extra_function3_variable_count, extra_function3_range, check_input_extra_function3);
    return 0;
}