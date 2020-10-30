#include "../../src/interval.hpp"
using namespace std;

// get a timer for each interval type we have
double boost_timer, fic_timer, native_switch_timer, multiplicative_timer, pred_succ_timer;

// although those definition seems redundant
// I'm just trying to make my life easier
// do whatever you want for the spped thest
// see the helper_functions.hpp for input and output deatail
#ifdef USE_FILIB_PLUSPLUS
#define RUN_QUERY(METHOD, INFO, PRINT_METHOD, VARIABLE_COUNT, DISTRIBUTION)                             \
    do                                                                                                  \
    {                                                                                                   \
        for (int i = 0; i < TEST_SIZE; i++)                                                             \
        {                                                                                               \
            PRE_FILL_RANDOM_DOUBLES(DISTRIBUTION, VARIABLE_COUNT);                                      \
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
    RUN_QUERY(addition, "ADDITION", print_addition, 2, distribution_all_range);
    RUN_QUERY(subtraction, "SUBTRACTION", print_subtraction, 2, distribution_all_range);
    RUN_QUERY(multiplication, "MULTIPLICATION", print_multiplication, 2, distribution_all_range);
    RUN_QUERY(division, "DIVISION", print_division, 2, distribution_all_range);
    RUN_QUERY(expr1, "EXPRESSION 1", print_expr1, 10, distribution_all_range);
    RUN_QUERY(expr2, "EXPRESSION 2", print_expr2, 10, distribution_all_range);
    RUN_QUERY(expr3, "EXPRESSION 3", print_expr3, 10, distribution_all_range);
    RUN_QUERY(square_root, "SQUARE ROOT", print_square_root, 1, distribution_positive);
    RUN_QUERY(exponential, "EXPONENTIAL", print_exponential, 1, distribution_exp);
    RUN_QUERY(sin, "SIN", print_sin, 1, distribution_all_range);
    RUN_QUERY(cos, "COS", print_cos, 1, distribution_all_range);
    return 0;
}