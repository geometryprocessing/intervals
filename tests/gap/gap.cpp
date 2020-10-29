#include "../../src/interval.hpp"
using namespace std;

// because filib c++ version is not supported everywhere
#ifdef USE_FILIB_PLUSPLUS
#define RUN_GAP(METHOD, INFO, VARIABLE_COUNT, DISTRIBUTION)                                   \
    {                                                                                         \
        for (int i = 0; i < TEST_SIZE; i++)                                                   \
        {                                                                                     \
            PRE_FILL_RANDOM_DOUBLES(DISTRIBUTION, VARIABLE_COUNT);                            \
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
    RUN_GAP(addition, "ADDITION", 2, distribution_all_range);
    RUN_GAP(subtraction, "SUBTRACTION", 2, distribution_all_range);
    RUN_GAP(multiplication, "MULTIPLICATION", 2, distribution_all_range);
    RUN_GAP(division, "DIVISION", 2, distribution_all_range);
    RUN_GAP(expr1, "EXPRESSION 1", 10, distribution_all_range);
    RUN_GAP(expr2, "EXPRESSION 2", 10, distribution_all_range);
    RUN_GAP(expr3, "EXPRESSION 3", 10, distribution_all_range);
    RUN_GAP(square_root, "SQUARE ROOT", 1, distribution_positive);
    RUN_GAP(exponential, "EXPONENTIAL", 1, distribution_exp);
    RUN_GAP(sin, "SIN", 1, distribution_all_range);
    RUN_GAP(cos, "COS", 1, distribution_all_range);
}