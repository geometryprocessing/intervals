#include "../../src/methods.hpp"
#ifdef FPBENCH_TEST
#include "../../src/FPBench_methods.hpp"
#endif
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
        }                                                                                               \
    } while (0)
#else
#define RUN_QUERY(METHOD, PRINT_METHOD, VARIABLE_COUNT, DISTRIBUTION, VERIFY_METHOD)      \
    do                                                                                    \
    {                                                                                     \
        for (int i = 0; i < TEST_SIZE; i++)                                               \
        {                                                                                 \
            PRE_FILL_RANDOM_DOUBLES(DISTRIBUTION, VARIABLE_COUNT, VERIFY_METHOD);         \
            PRINT_QUERIES(fic_interval, "FILIB C", METHOD, PRINT_METHOD, VARIABLE_COUNT); \
            PRINT_QUERIES(boost_interval, "BOOST", METHOD, PRINT_METHOD, VARIABLE_COUNT); \
        }                                                                                 \
    } while (0)
#endif

int main(int argc, char *argv[])
{
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/addition_used_rationals.txt");
#endif
    RUN_QUERY(addition, print_addition, 2, binary_all_range, check_input_addition);

#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/subtraction_used_rationals.txt");
#endif
    RUN_QUERY(subtraction, print_subtraction, 2, binary_all_range, check_input_subtraction);

#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/multiplication_used_rationals.txt");
#endif
    RUN_QUERY(multiplication, print_multiplication, 2, binary_all_range, check_input_multiplication);

#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/division_used_rationals.txt");
#endif
    RUN_QUERY(division, print_division, 2, binary_all_range, check_input_division);

#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/square_root_used_rationals.txt");
#endif
    RUN_QUERY(square_root, print_square_root, 1, square_root_range, check_input_square_root);

#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/exponential_used_rationals.txt");
#endif
    RUN_QUERY(exponential, print_exponential, 1, exp_range, check_input_exponential);

#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/sin_used_rationals.txt");
#endif
    RUN_QUERY(sin, print_sin, 1, trig_pi_over_four, check_input_sin);

#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/cos_used_rationals.txt");
#endif
    RUN_QUERY(cos, print_cos, 1, trig_pi_over_four, check_input_cos);

#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/expr1_used_rationals.txt");
#endif
    RUN_QUERY(expr1, print_expr1, 10, comp_all_range, check_input_expr1);

#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/expr2_used_rationals.txt");
#endif
    RUN_QUERY(expr2, print_expr2, 10, comp_all_range, check_input_expr2);

#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/expr3_used_rationals.txt");
#endif
    RUN_QUERY(expr3, print_expr3, 10, comp_all_range, check_input_expr3);

#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/expr4_used_rationals.txt");
#endif
    RUN_QUERY(expr4, print_expr4, expr4_variable_count, expr4_range, check_input_expr4);

#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/expr5_used_rationals.txt");
#endif
    RUN_QUERY(expr5, print_expr5, expr5_variable_count, expr5_range, check_input_expr5);

#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/expr6_used_rationals.txt");
#endif
    RUN_QUERY(expr6, print_expr6, expr6_variable_count, expr6_range, check_input_expr6);

#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/expr7_used_rationals.txt");
#endif
    RUN_QUERY(expr7, print_expr7, expr7_variable_count, expr7_range, check_input_expr7);

#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/expr8_used_rationals.txt");
#endif
    RUN_QUERY(expr8, print_expr8, expr8_variable_count, expr8_range, check_input_expr8);

#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/expr9_used_rationals.txt");
#endif
    RUN_QUERY(expr9, print_expr9, expr9_variable_count, expr9_range, check_input_expr9);

#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/expr10_used_rationals.txt");
#endif
    RUN_QUERY(expr10, print_expr10, expr10_variable_count, expr10_range, check_input_expr10);

#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/extra_function1_used_rationals.txt");
#endif
    RUN_QUERY(extra_function1, print_extra_function1, extra_function1_variable_count, extra_function1_range, check_input_extra_function1);

#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/extra_function2_used_rationals.txt");
#endif
    RUN_QUERY(extra_function2, print_extra_function2, extra_function2_variable_count, extra_function2_range, check_input_extra_function2);

#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/extra_function3_used_rationals.txt");
#endif
    RUN_QUERY(extra_function3, print_extra_function3, extra_function3_variable_count, extra_function3_range, check_input_extra_function3);

#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/extra_function4_used_rationals.txt");
#endif
    RUN_QUERY(extra_function4, print_extra_function4, extra_function4_variable_count, extra_function4_range, check_input_extra_function4);

#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/extra_function5_used_rationals.txt");
#endif
    RUN_QUERY(extra_function5, print_extra_function5, extra_function5_variable_count, extra_function5_range, check_input_extra_function5);

#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/extra_function6_used_rationals.txt");
#endif
    RUN_QUERY(extra_function6, print_extra_function6, extra_function6_variable_count, extra_function6_range, check_input_extra_function6);

#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/extra_function7_used_rationals.txt");
#endif
    RUN_QUERY(extra_function7, print_extra_function7, extra_function7_variable_count, extra_function7_range, check_input_extra_function7);

#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/extra_function8_used_rationals.txt");
#endif
    RUN_QUERY(extra_function8, print_extra_function8, extra_function8_variable_count, extra_function8_range, check_input_extra_function8);

#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/extra_function9_used_rationals.txt");
#endif
    RUN_QUERY(extra_function9, print_extra_function9, extra_function9_variable_count, extra_function9_range, check_input_extra_function9);

#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/extra_function10_used_rationals.txt");
#endif
    RUN_QUERY(extra_function10, print_extra_function10, extra_function10_variable_count, extra_function10_range, check_input_extra_function10);

#ifdef FPBENCH_TEST
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/rigidBody2_used_rationals.txt");
#endif
    RUN_QUERY(rigidBody2, print_rigidBody2, rigidBody2_variable_count, rigidBody2_range, check_input_rigidBody2);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/triangle11_used_rationals.txt");
#endif
    RUN_QUERY(triangle11, print_triangle11, triangle11_variable_count, triangle11_range, check_input_triangle11);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/sine_used_rationals.txt");
#endif
    RUN_QUERY(sine, print_sine, sine_variable_count, sine_range, check_input_sine);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/sum_used_rationals.txt");
#endif
    RUN_QUERY(sum, print_sum, sum_variable_count, sum_range, check_input_sum);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/test05_nonlin1_r4_used_rationals.txt");
#endif
    RUN_QUERY(test05_nonlin1_r4, print_test05_nonlin1_r4, test05_nonlin1_r4_variable_count, test05_nonlin1_r4_range, check_input_test05_nonlin1_r4);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/hartman3_used_rationals.txt");
#endif
    RUN_QUERY(hartman3, print_hartman3, hartman3_variable_count, hartman3_range, check_input_hartman3);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/NMSE_example_3_5_used_rationals.txt");
#endif
    RUN_QUERY(NMSE_example_3_5, print_NMSE_example_3_5, NMSE_example_3_5_variable_count, NMSE_example_3_5_range, check_input_NMSE_example_3_5);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/Shoelace_formula_used_rationals.txt");
#endif
    RUN_QUERY(Shoelace_formula, print_Shoelace_formula, Shoelace_formula_variable_count, Shoelace_formula_range, check_input_Shoelace_formula);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/NMSE_example_3_10_used_rationals.txt");
#endif
    RUN_QUERY(NMSE_example_3_10, print_NMSE_example_3_10, NMSE_example_3_10_variable_count, NMSE_example_3_10_range, check_input_NMSE_example_3_10);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/x_by_xy_used_rationals.txt");
#endif
    RUN_QUERY(x_by_xy, print_x_by_xy, x_by_xy_variable_count, x_by_xy_range, check_input_x_by_xy);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/NMSE_section_3_11_used_rationals.txt");
#endif
    RUN_QUERY(NMSE_section_3_11, print_NMSE_section_3_11, NMSE_section_3_11_variable_count, NMSE_section_3_11_range, check_input_NMSE_section_3_11);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/NMSE_problem_3_3_1_used_rationals.txt");
#endif
    RUN_QUERY(NMSE_problem_3_3_1, print_NMSE_problem_3_3_1, NMSE_problem_3_3_1_variable_count, NMSE_problem_3_3_1_range, check_input_NMSE_problem_3_3_1);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/floudas2_used_rationals.txt");
#endif
    RUN_QUERY(floudas2, print_floudas2, floudas2_variable_count, floudas2_range, check_input_floudas2);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/test03_nonlin2_used_rationals.txt");
#endif
    RUN_QUERY(test03_nonlin2, print_test03_nonlin2, test03_nonlin2_variable_count, test03_nonlin2_range, check_input_test03_nonlin2);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/nonlin2_used_rationals.txt");
#endif
    RUN_QUERY(nonlin2, print_nonlin2, nonlin2_variable_count, nonlin2_range, check_input_nonlin2);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/Complex_sine_and_cosine_used_rationals.txt");
#endif
    RUN_QUERY(Complex_sine_and_cosine, print_Complex_sine_and_cosine, Complex_sine_and_cosine_variable_count, Complex_sine_and_cosine_range, check_input_Complex_sine_and_cosine);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/floudas_used_rationals.txt");
#endif
    RUN_QUERY(floudas, print_floudas, floudas_variable_count, floudas_range, check_input_floudas);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/NMSE_problem_3_4_2_used_rationals.txt");
#endif
    RUN_QUERY(NMSE_problem_3_4_2, print_NMSE_problem_3_4_2, NMSE_problem_3_4_2_variable_count, NMSE_problem_3_4_2_range, check_input_NMSE_problem_3_4_2);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/NMSE_example_3_8_used_rationals.txt");
#endif
    RUN_QUERY(NMSE_example_3_8, print_NMSE_example_3_8, NMSE_example_3_8_variable_count, NMSE_example_3_8_range, check_input_NMSE_example_3_8);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/polarToCarthesian_x_used_rationals.txt");
#endif
    RUN_QUERY(polarToCarthesian_x, print_polarToCarthesian_x, polarToCarthesian_x_variable_count, polarToCarthesian_x_range, check_input_polarToCarthesian_x);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/turbine1_used_rationals.txt");
#endif
    RUN_QUERY(turbine1, print_turbine1, turbine1_variable_count, turbine1_range, check_input_turbine1);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/triangle9_used_rationals.txt");
#endif
    RUN_QUERY(triangle9, print_triangle9, triangle9_variable_count, triangle9_range, check_input_triangle9);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/sineOrder3_used_rationals.txt");
#endif
    RUN_QUERY(sineOrder3, print_sineOrder3, sineOrder3_variable_count, sineOrder3_range, check_input_sineOrder3);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/doppler3_used_rationals.txt");
#endif
    RUN_QUERY(doppler3, print_doppler3, doppler3_variable_count, doppler3_range, check_input_doppler3);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/triangle1_used_rationals.txt");
#endif
    RUN_QUERY(triangle1, print_triangle1, triangle1_variable_count, triangle1_range, check_input_triangle1);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/NMSE_p42_negative_used_rationals.txt");
#endif
    RUN_QUERY(NMSE_p42_negative, print_NMSE_p42_negative, NMSE_p42_negative_variable_count, NMSE_p42_negative_range, check_input_NMSE_p42_negative);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/matrixDeterminant2_used_rationals.txt");
#endif
    RUN_QUERY(matrixDeterminant2, print_matrixDeterminant2, matrixDeterminant2_variable_count, matrixDeterminant2_range, check_input_matrixDeterminant2);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/delta_used_rationals.txt");
#endif
    RUN_QUERY(delta, print_delta, delta_variable_count, delta_range, check_input_delta);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/test06_sums4_sum1_used_rationals.txt");
#endif
    RUN_QUERY(test06_sums4_sum1, print_test06_sums4_sum1, test06_sums4_sum1_variable_count, test06_sums4_sum1_range, check_input_test06_sums4_sum1);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/sec4_example_used_rationals.txt");
#endif
    RUN_QUERY(sec4_example, print_sec4_example, sec4_example_variable_count, sec4_example_range, check_input_sec4_example);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/logexp_used_rationals.txt");
#endif
    RUN_QUERY(logexp, print_logexp, logexp_variable_count, logexp_range, check_input_logexp);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/NMSE_problem_3_3_5_used_rationals.txt");
#endif
    RUN_QUERY(NMSE_problem_3_3_5, print_NMSE_problem_3_3_5, NMSE_problem_3_3_5_variable_count, NMSE_problem_3_3_5_range, check_input_NMSE_problem_3_3_5);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/NMSE_example_3_3_used_rationals.txt");
#endif
    RUN_QUERY(NMSE_example_3_3, print_NMSE_example_3_3, NMSE_example_3_3_variable_count, NMSE_example_3_3_range, check_input_NMSE_example_3_3);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/kepler0_used_rationals.txt");
#endif
    RUN_QUERY(kepler0, print_kepler0, kepler0_variable_count, kepler0_range, check_input_kepler0);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/triangle5_used_rationals.txt");
#endif
    RUN_QUERY(triangle5, print_triangle5, triangle5_variable_count, triangle5_range, check_input_triangle5);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/bspline3_used_rationals.txt");
#endif
    RUN_QUERY(bspline3, print_bspline3, bspline3_variable_count, bspline3_range, check_input_bspline3);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/predatorPrey_used_rationals.txt");
#endif
    RUN_QUERY(predatorPrey, print_predatorPrey, predatorPrey_variable_count, predatorPrey_range, check_input_predatorPrey);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/turbine3_used_rationals.txt");
#endif
    RUN_QUERY(turbine3, print_turbine3, turbine3_variable_count, turbine3_range, check_input_turbine3);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/triangle7_used_rationals.txt");
#endif
    RUN_QUERY(triangle7, print_triangle7, triangle7_variable_count, triangle7_range, check_input_triangle7);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/doppler1_used_rationals.txt");
#endif
    RUN_QUERY(doppler1, print_doppler1, doppler1_variable_count, doppler1_range, check_input_doppler1);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/triangle3_used_rationals.txt");
#endif
    RUN_QUERY(triangle3, print_triangle3, triangle3_variable_count, triangle3_range, check_input_triangle3);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/Rump_s_example_from_C_program_used_rationals.txt");
#endif
    RUN_QUERY(Rump_s_example_from_C_program, print_Rump_s_example_from_C_program, Rump_s_example_from_C_program_variable_count, Rump_s_example_from_C_program_range, check_input_Rump_s_example_from_C_program);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/exp1x_used_rationals.txt");
#endif
    RUN_QUERY(exp1x, print_exp1x, exp1x_variable_count, exp1x_range, check_input_exp1x);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/NMSE_problem_3_4_4_used_rationals.txt");
#endif
    RUN_QUERY(NMSE_problem_3_4_4, print_NMSE_problem_3_4_4, NMSE_problem_3_4_4_variable_count, NMSE_problem_3_4_4_range, check_input_NMSE_problem_3_4_4);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/delta4_used_rationals.txt");
#endif
    RUN_QUERY(delta4, print_delta4, delta4_variable_count, delta4_range, check_input_delta4);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/instantaneousCurrent_used_rationals.txt");
#endif
    RUN_QUERY(instantaneousCurrent, print_instantaneousCurrent, instantaneousCurrent_variable_count, instantaneousCurrent_range, check_input_instantaneousCurrent);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/NMSE_problem_3_2_1_negative_used_rationals.txt");
#endif
    RUN_QUERY(NMSE_problem_3_2_1_negative, print_NMSE_problem_3_2_1_negative, NMSE_problem_3_2_1_negative_variable_count, NMSE_problem_3_2_1_negative_range, check_input_NMSE_problem_3_2_1_negative);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/kepler2_used_rationals.txt");
#endif
    RUN_QUERY(kepler2, print_kepler2, kepler2_variable_count, kepler2_range, check_input_kepler2);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/NMSE_problem_3_3_3_used_rationals.txt");
#endif
    RUN_QUERY(NMSE_problem_3_3_3, print_NMSE_problem_3_3_3, NMSE_problem_3_3_3_variable_count, NMSE_problem_3_3_3_range, check_input_NMSE_problem_3_3_3);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/azimuth_used_rationals.txt");
#endif
    RUN_QUERY(azimuth, print_azimuth, azimuth_variable_count, azimuth_range, check_input_azimuth);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/NMSE_problem_3_3_7_used_rationals.txt");
#endif
    RUN_QUERY(NMSE_problem_3_3_7, print_NMSE_problem_3_3_7, NMSE_problem_3_3_7_variable_count, NMSE_problem_3_3_7_range, check_input_NMSE_problem_3_3_7);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/i6_used_rationals.txt");
#endif
    RUN_QUERY(i6, print_i6, i6_variable_count, i6_range, check_input_i6);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/NMSE_example_3_9_used_rationals.txt");
#endif
    RUN_QUERY(NMSE_example_3_9, print_NMSE_example_3_9, NMSE_example_3_9_variable_count, NMSE_example_3_9_range, check_input_NMSE_example_3_9);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/NMSE_section_3_5_used_rationals.txt");
#endif
    RUN_QUERY(NMSE_section_3_5, print_NMSE_section_3_5, NMSE_section_3_5_variable_count, NMSE_section_3_5_range, check_input_NMSE_section_3_5);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/hypot_used_rationals.txt");
#endif
    RUN_QUERY(hypot, print_hypot, hypot_variable_count, hypot_range, check_input_hypot);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/test04_dqmom9_used_rationals.txt");
#endif
    RUN_QUERY(test04_dqmom9, print_test04_dqmom9, test04_dqmom9_variable_count, test04_dqmom9_range, check_input_test04_dqmom9);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/nonlin1_used_rationals.txt");
#endif
    RUN_QUERY(nonlin1, print_nonlin1, nonlin1_variable_count, nonlin1_range, check_input_nonlin1);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/NMSE_example_3_4_used_rationals.txt");
#endif
    RUN_QUERY(NMSE_example_3_4, print_NMSE_example_3_4, NMSE_example_3_4_variable_count, NMSE_example_3_4_range, check_input_NMSE_example_3_4);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/hartman6_used_rationals.txt");
#endif
    RUN_QUERY(hartman6, print_hartman6, hartman6_variable_count, hartman6_range, check_input_hartman6);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/carthesianToPolar_radius_used_rationals.txt");
#endif
    RUN_QUERY(carthesianToPolar_radius, print_carthesianToPolar_radius, carthesianToPolar_radius_variable_count, carthesianToPolar_radius_range, check_input_carthesianToPolar_radius);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/triangle_used_rationals.txt");
#endif
    RUN_QUERY(triangle, print_triangle, triangle_variable_count, triangle_range, check_input_triangle);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/jetEngine_used_rationals.txt");
#endif
    RUN_QUERY(jetEngine, print_jetEngine, jetEngine_variable_count, jetEngine_range, check_input_jetEngine);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/sqroot_used_rationals.txt");
#endif
    RUN_QUERY(sqroot, print_sqroot, sqroot_variable_count, sqroot_range, check_input_sqroot);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/triangle12_used_rationals.txt");
#endif
    RUN_QUERY(triangle12, print_triangle12, triangle12_variable_count, triangle12_range, check_input_triangle12);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/triangle10_used_rationals.txt");
#endif
    RUN_QUERY(triangle10, print_triangle10, triangle10_variable_count, triangle10_range, check_input_triangle10);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/turbine2_used_rationals.txt");
#endif
    RUN_QUERY(turbine2, print_turbine2, turbine2_variable_count, turbine2_range, check_input_turbine2);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/triangle2_used_rationals.txt");
#endif
    RUN_QUERY(triangle2, print_triangle2, triangle2_variable_count, triangle2_range, check_input_triangle2);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/rigidBody1_used_rationals.txt");
#endif
    RUN_QUERY(rigidBody1, print_rigidBody1, rigidBody1_variable_count, rigidBody1_range, check_input_rigidBody1);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/NMSE_problem_3_4_1_used_rationals.txt");
#endif
    RUN_QUERY(NMSE_problem_3_4_1, print_NMSE_problem_3_4_1, NMSE_problem_3_4_1_variable_count, NMSE_problem_3_4_1_range, check_input_NMSE_problem_3_4_1);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/exp1x_log_used_rationals.txt");
#endif
    RUN_QUERY(exp1x_log, print_exp1x_log, exp1x_log_variable_count, exp1x_log_range, check_input_exp1x_log);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/Complex_square_root_used_rationals.txt");
#endif
    RUN_QUERY(Complex_square_root, print_Complex_square_root, Complex_square_root_variable_count, Complex_square_root_range, check_input_Complex_square_root);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/carthesianToPolar_theta_used_rationals.txt");
#endif
    RUN_QUERY(carthesianToPolar_theta, print_carthesianToPolar_theta, carthesianToPolar_theta_variable_count, carthesianToPolar_theta_range, check_input_carthesianToPolar_theta);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/NMSE_example_3_7_used_rationals.txt");
#endif
    RUN_QUERY(NMSE_example_3_7, print_NMSE_example_3_7, NMSE_example_3_7_variable_count, NMSE_example_3_7_range, check_input_NMSE_example_3_7);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/floudas3_used_rationals.txt");
#endif
    RUN_QUERY(floudas3, print_floudas3, floudas3_variable_count, floudas3_range, check_input_floudas3);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/NMSE_example_3_6_used_rationals.txt");
#endif
    RUN_QUERY(NMSE_example_3_6, print_NMSE_example_3_6, NMSE_example_3_6_variable_count, NMSE_example_3_6_range, check_input_NMSE_example_3_6);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/i4_used_rationals.txt");
#endif
    RUN_QUERY(i4, print_i4, i4_variable_count, i4_range, check_input_i4);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/test02_sum8_used_rationals.txt");
#endif
    RUN_QUERY(test02_sum8, print_test02_sum8, test02_sum8_variable_count, test02_sum8_range, check_input_test02_sum8);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/triangle6_used_rationals.txt");
#endif
    RUN_QUERY(triangle6, print_triangle6, triangle6_variable_count, triangle6_range, check_input_triangle6);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/carbonGas_used_rationals.txt");
#endif
    RUN_QUERY(carbonGas, print_carbonGas, carbonGas_variable_count, carbonGas_range, check_input_carbonGas);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/sphere_used_rationals.txt");
#endif
    RUN_QUERY(sphere, print_sphere, sphere_variable_count, sphere_range, check_input_sphere);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/test01_sum3_used_rationals.txt");
#endif
    RUN_QUERY(test01_sum3, print_test01_sum3, test01_sum3_variable_count, test01_sum3_range, check_input_test01_sum3);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/test05_nonlin1_test2_used_rationals.txt");
#endif
    RUN_QUERY(test05_nonlin1_test2, print_test05_nonlin1_test2, test05_nonlin1_test2_variable_count, test05_nonlin1_test2_range, check_input_test05_nonlin1_test2);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/kepler1_used_rationals.txt");
#endif
    RUN_QUERY(kepler1, print_kepler1, kepler1_variable_count, kepler1_range, check_input_kepler1);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/NMSE_example_3_1_used_rationals.txt");
#endif
    RUN_QUERY(NMSE_example_3_1, print_NMSE_example_3_1, NMSE_example_3_1_variable_count, NMSE_example_3_1_range, check_input_NMSE_example_3_1);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/matrixDeterminant_used_rationals.txt");
#endif
    RUN_QUERY(matrixDeterminant, print_matrixDeterminant, matrixDeterminant_variable_count, matrixDeterminant_range, check_input_matrixDeterminant);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/NMSE_p42_positive_used_rationals.txt");
#endif
    RUN_QUERY(NMSE_p42_positive, print_NMSE_p42_positive, NMSE_p42_positive_variable_count, NMSE_p42_positive_range, check_input_NMSE_p42_positive);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/sqrt_add_used_rationals.txt");
#endif
    RUN_QUERY(sqrt_add, print_sqrt_add, sqrt_add_variable_count, sqrt_add_range, check_input_sqrt_add);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/NMSE_problem_3_4_5_used_rationals.txt");
#endif
    RUN_QUERY(NMSE_problem_3_4_5, print_NMSE_problem_3_4_5, NMSE_problem_3_4_5_variable_count, NMSE_problem_3_4_5_range, check_input_NMSE_problem_3_4_5);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/floudas1_used_rationals.txt");
#endif
    RUN_QUERY(floudas1, print_floudas1, floudas1_variable_count, floudas1_range, check_input_floudas1);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/NMSE_problem_3_3_2_used_rationals.txt");
#endif
    RUN_QUERY(NMSE_problem_3_3_2, print_NMSE_problem_3_3_2, NMSE_problem_3_3_2_variable_count, NMSE_problem_3_3_2_range, check_input_NMSE_problem_3_3_2);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/intro_example_used_rationals.txt");
#endif
    RUN_QUERY(intro_example, print_intro_example, intro_example_variable_count, intro_example_range, check_input_intro_example);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/test06_sums4_sum2_used_rationals.txt");
#endif
    RUN_QUERY(test06_sums4_sum2, print_test06_sums4_sum2, test06_sums4_sum2_variable_count, test06_sums4_sum2_range, check_input_test06_sums4_sum2);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/himmilbeau_used_rationals.txt");
#endif
    RUN_QUERY(himmilbeau, print_himmilbeau, himmilbeau_variable_count, himmilbeau_range, check_input_himmilbeau);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/NMSE_problem_3_3_6_used_rationals.txt");
#endif
    RUN_QUERY(NMSE_problem_3_3_6, print_NMSE_problem_3_3_6, NMSE_problem_3_3_6_variable_count, NMSE_problem_3_3_6_range, check_input_NMSE_problem_3_3_6);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/intro_example_mixed_used_rationals.txt");
#endif
    RUN_QUERY(intro_example_mixed, print_intro_example_mixed, intro_example_mixed_variable_count, intro_example_mixed_range, check_input_intro_example_mixed);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/NMSE_problem_3_4_3_used_rationals.txt");
#endif
    RUN_QUERY(NMSE_problem_3_4_3, print_NMSE_problem_3_4_3, NMSE_problem_3_4_3_variable_count, NMSE_problem_3_4_3_range, check_input_NMSE_problem_3_4_3);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/exp1x_32_used_rationals.txt");
#endif
    RUN_QUERY(exp1x_32, print_exp1x_32, exp1x_32_variable_count, exp1x_32_range, check_input_exp1x_32);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/NMSE_problem_3_2_1_positive_used_rationals.txt");
#endif
    RUN_QUERY(NMSE_problem_3_2_1_positive, print_NMSE_problem_3_2_1_positive, NMSE_problem_3_2_1_positive_variable_count, NMSE_problem_3_2_1_positive_range, check_input_NMSE_problem_3_2_1_positive);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/polarToCarthesian_y_used_rationals.txt");
#endif
    RUN_QUERY(polarToCarthesian_y, print_polarToCarthesian_y, polarToCarthesian_y_variable_count, polarToCarthesian_y_range, check_input_polarToCarthesian_y);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/Rump_s_example_revisited_for_floating_point_used_rationals.txt");
#endif
    RUN_QUERY(Rump_s_example_revisited_for_floating_point, print_Rump_s_example_revisited_for_floating_point, Rump_s_example_revisited_for_floating_point_variable_count, Rump_s_example_revisited_for_floating_point_range, check_input_Rump_s_example_revisited_for_floating_point);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/triangle8_used_rationals.txt");
#endif
    RUN_QUERY(triangle8, print_triangle8, triangle8_variable_count, triangle8_range, check_input_triangle8);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/verhulst_used_rationals.txt");
#endif
    RUN_QUERY(verhulst, print_verhulst, verhulst_variable_count, verhulst_range, check_input_verhulst);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/triangle4_used_rationals.txt");
#endif
    RUN_QUERY(triangle4, print_triangle4, triangle4_variable_count, triangle4_range, check_input_triangle4);
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/doppler2_used_rationals.txt");
#endif
    RUN_QUERY(doppler2, print_doppler2, doppler2_variable_count, doppler2_range, check_input_doppler2);
#endif
}