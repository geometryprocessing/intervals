#include "../../src/methods.hpp"
using namespace std;

#ifdef USE_FILIB_PLUSPLUS
#define RUN_QUERY(METHOD, INFO, PRINT_METHOD, VARIABLE_COUNT, DISTRIBUTION, VERIFY_METHOD)              \
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
#define RUN_QUERY(METHOD, INFO, PRINT_METHOD, VARIABLE_COUNT, DISTRIBUTION)               \
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
    RUN_QUERY(addition, "ADDITION", print_addition, 2, binary_all_range, check_input_addition);
    RUN_QUERY(subtraction, "SUBTRACTION", print_subtraction, 2, binary_all_range, check_input_subtraction);
    RUN_QUERY(multiplication, "MULTIPLICATION", print_multiplication, 2, binary_all_range, check_input_multiplication);
    RUN_QUERY(division, "DIVISION", print_division, 2, binary_all_range, check_input_division);
    RUN_QUERY(expr1, "EXPRESSION 1", print_expr1, 10, comp_all_range, check_input_expr1);
    RUN_QUERY(expr2, "EXPRESSION 2", print_expr2, 10, comp_all_range, check_input_expr2);
    RUN_QUERY(expr3, "EXPRESSION 3", print_expr3, 10, comp_all_range, check_input_expr3);
    RUN_QUERY(square_root, "SQUARE ROOT", print_square_root, 1, square_root_range, check_input_square_root);
    RUN_QUERY(exponential, "EXPONENTIAL", print_exponential, 1, exp_range, check_input_exponential);
    RUN_QUERY(sin, "SIN", print_sin, 1, trig_pi_over_four, check_input_sin);
    RUN_QUERY(cos, "COS", print_cos, 1, trig_pi_over_four, check_input_cos);
    return 0;
}