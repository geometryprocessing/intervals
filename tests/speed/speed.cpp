#define USE_SYSTEM_RANDOM // always use system random here
#include "../../src/methods.hpp"
#ifdef FPBENCH_TEST
#include "../../src/FPBench_methods.hpp"
#endif
using namespace std;

// get a timer for each interval type we have
double boost_timer, fic_timer, native_switch_timer, multiplicative_timer, pred_succ_timer;

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
        }                                                                                                                                                       \
        printf("TIME, %s, FILIB C, %lf us, %lfx time that FILIB C version took\n", INFO, fic_timer, fic_timer / fic_timer);                                     \
        printf("TIME, %s, BOOST, %lf us, %lfx time that FILIB C version took\n", INFO, boost_timer, boost_timer / fic_timer);                                   \
        printf("TIME, %s, NATIVE SWITCHED METHOD, %lf us, %lfx time that FILIB C version took\n", INFO, native_switch_timer, native_switch_timer / fic_timer);  \
        printf("TIME, %s, MULTIPLICATIVE METHOD, %lf us, %lfx time that FILIB C version took\n", INFO, multiplicative_timer, multiplicative_timer / fic_timer); \
        printf("TIME, %s, PRED SUCC METHOD, %lf us, %lfx time that FILIB C version took\n", INFO, pred_succ_timer, pred_succ_timer / fic_timer);                \
    }                                                                                                                                                           \
    while (0)
#else
#define RUN_SPEED(METHOD, INFO, VARIABLE_COUNT, DISTRIBUTION, VERIFY_METHOD)                                                  \
    {                                                                                                                         \
        boost_timer = 0;                                                                                                      \
        fic_timer = 0;                                                                                                        \
        native_switch_timer = 0;                                                                                              \
        multiplicative_timer = 0;                                                                                             \
        pred_succ_timer = 0;                                                                                                  \
        for (int i = 0; i < SPEED_TEST_LOOP; i++)                                                                             \
        {                                                                                                                     \
            PRE_FILL_RANDOM_DOUBLES(DISTRIBUTION, VARIABLE_COUNT, VERIFY_METHOD);                                             \
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
    RUN_SPEED(addition, "ADDITION", 2, binary_all_range, check_input_addition);
    RUN_SPEED(subtraction, "SUBTRACTION", 2, binary_all_range, check_input_subtraction);
    RUN_SPEED(multiplication, "MULTIPLICATION", 2, binary_all_range, check_input_multiplication);
    RUN_SPEED(division, "DIVISION", 2, binary_all_range, check_input_division);
    RUN_SPEED(square_root, "SQUARE ROOT", 1, square_root_range, check_input_square_root);
    RUN_SPEED(exponential, "EXPONENTIAL", 1, exp_range, check_input_exponential);
    RUN_SPEED(sin, "SIN", 1, trig_all_range, check_input_sin);
    RUN_SPEED(cos, "COS", 1, trig_all_range, check_input_cos);
    RUN_SPEED(expr1, "ARITHMETIC EXPRESSION 1", 10, comp_all_range, check_input_expr1);
    RUN_SPEED(expr2, "ARITHMETIC EXPRESSION 2", 10, comp_all_range, check_input_expr2);
    RUN_SPEED(expr3, "ARITHMETIC EXPRESSION 3", 10, comp_all_range, check_input_expr3);
    RUN_SPEED(expr4, "ARITHMETIC EXPRESSION 4", expr4_variable_count, expr4_range, check_input_expr4);
    RUN_SPEED(expr5, "ARITHMETIC EXPRESSION 5", expr5_variable_count, expr5_range, check_input_expr5);
    RUN_SPEED(expr6, "ARITHMETIC EXPRESSION 6", expr6_variable_count, expr6_range, check_input_expr6);
    RUN_SPEED(expr7, "ARITHMETIC EXPRESSION 7", expr7_variable_count, expr7_range, check_input_expr7);
    RUN_SPEED(expr8, "ARITHMETIC EXPRESSION 8", expr8_variable_count, expr8_range, check_input_expr8);
    RUN_SPEED(expr9, "ARITHMETIC EXPRESSION 9", expr9_variable_count, expr9_range, check_input_expr9);
    RUN_SPEED(expr10, "ARITHMETIC EXPRESSION 10", expr10_variable_count, expr10_range, check_input_expr10);
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
#ifdef FPBENCH_TEST
    RUN_SPEED(rigidBody2, "rigidBody2", rigidBody2_variable_count, rigidBody2_range, check_input_rigidBody2);
    RUN_SPEED(triangle11, "triangle11", triangle11_variable_count, triangle11_range, check_input_triangle11);
    RUN_SPEED(sine, "sine", sine_variable_count, sine_range, check_input_sine);
    RUN_SPEED(sum, "sum", sum_variable_count, sum_range, check_input_sum);
    RUN_SPEED(test05_nonlin1_r4, "test05_nonlin1, r4", test05_nonlin1_r4_variable_count, test05_nonlin1_r4_range, check_input_test05_nonlin1_r4);
    RUN_SPEED(hartman3, "hartman3", hartman3_variable_count, hartman3_range, check_input_hartman3);
    RUN_SPEED(NMSE_example_3_5, "NMSE example 3.5", NMSE_example_3_5_variable_count, NMSE_example_3_5_range, check_input_NMSE_example_3_5);
    RUN_SPEED(Shoelace_formula, "Shoelace formula", Shoelace_formula_variable_count, Shoelace_formula_range, check_input_Shoelace_formula);
    RUN_SPEED(NMSE_example_3_10, "NMSE example 3.10", NMSE_example_3_10_variable_count, NMSE_example_3_10_range, check_input_NMSE_example_3_10);
    RUN_SPEED(x_by_xy, "x_by_xy", x_by_xy_variable_count, x_by_xy_range, check_input_x_by_xy);
    RUN_SPEED(NMSE_section_3_11, "NMSE section 3.11", NMSE_section_3_11_variable_count, NMSE_section_3_11_range, check_input_NMSE_section_3_11);
    RUN_SPEED(NMSE_problem_3_3_1, "NMSE problem 3.3.1", NMSE_problem_3_3_1_variable_count, NMSE_problem_3_3_1_range, check_input_NMSE_problem_3_3_1);
    RUN_SPEED(floudas2, "floudas2", floudas2_variable_count, floudas2_range, check_input_floudas2);
    RUN_SPEED(test03_nonlin2, "test03_nonlin2", test03_nonlin2_variable_count, test03_nonlin2_range, check_input_test03_nonlin2);
    RUN_SPEED(nonlin2, "nonlin2", nonlin2_variable_count, nonlin2_range, check_input_nonlin2);
    RUN_SPEED(Complex_sine_and_cosine, "Complex sine and cosine", Complex_sine_and_cosine_variable_count, Complex_sine_and_cosine_range, check_input_Complex_sine_and_cosine);
    RUN_SPEED(floudas, "floudas", floudas_variable_count, floudas_range, check_input_floudas);
    RUN_SPEED(NMSE_problem_3_4_2, "NMSE problem 3.4.2", NMSE_problem_3_4_2_variable_count, NMSE_problem_3_4_2_range, check_input_NMSE_problem_3_4_2);
    RUN_SPEED(NMSE_example_3_8, "NMSE example 3.8", NMSE_example_3_8_variable_count, NMSE_example_3_8_range, check_input_NMSE_example_3_8);
    RUN_SPEED(polarToCarthesian_x, "polarToCarthesian, x", polarToCarthesian_x_variable_count, polarToCarthesian_x_range, check_input_polarToCarthesian_x);
    RUN_SPEED(turbine1, "turbine1", turbine1_variable_count, turbine1_range, check_input_turbine1);
    RUN_SPEED(triangle9, "triangle9", triangle9_variable_count, triangle9_range, check_input_triangle9);
    RUN_SPEED(sineOrder3, "sineOrder3", sineOrder3_variable_count, sineOrder3_range, check_input_sineOrder3);
    RUN_SPEED(doppler3, "doppler3", doppler3_variable_count, doppler3_range, check_input_doppler3);
    RUN_SPEED(triangle1, "triangle1", triangle1_variable_count, triangle1_range, check_input_triangle1);
    RUN_SPEED(NMSE_p42_negative, "NMSE p42, negative", NMSE_p42_negative_variable_count, NMSE_p42_negative_range, check_input_NMSE_p42_negative);
    RUN_SPEED(matrixDeterminant2, "matrixDeterminant2", matrixDeterminant2_variable_count, matrixDeterminant2_range, check_input_matrixDeterminant2);
    RUN_SPEED(delta, "delta", delta_variable_count, delta_range, check_input_delta);
    RUN_SPEED(test06_sums4_sum1, "test06_sums4, sum1", test06_sums4_sum1_variable_count, test06_sums4_sum1_range, check_input_test06_sums4_sum1);
    RUN_SPEED(sec4_example, "sec4-example", sec4_example_variable_count, sec4_example_range, check_input_sec4_example);
    RUN_SPEED(logexp, "logexp", logexp_variable_count, logexp_range, check_input_logexp);
    RUN_SPEED(NMSE_problem_3_3_5, "NMSE problem 3.3.5", NMSE_problem_3_3_5_variable_count, NMSE_problem_3_3_5_range, check_input_NMSE_problem_3_3_5);
    RUN_SPEED(NMSE_example_3_3, "NMSE example 3.3", NMSE_example_3_3_variable_count, NMSE_example_3_3_range, check_input_NMSE_example_3_3);
    RUN_SPEED(kepler0, "kepler0", kepler0_variable_count, kepler0_range, check_input_kepler0);
    RUN_SPEED(triangle5, "triangle5", triangle5_variable_count, triangle5_range, check_input_triangle5);
    RUN_SPEED(bspline3, "bspline3", bspline3_variable_count, bspline3_range, check_input_bspline3);
    RUN_SPEED(predatorPrey, "predatorPrey", predatorPrey_variable_count, predatorPrey_range, check_input_predatorPrey);
    RUN_SPEED(turbine3, "turbine3", turbine3_variable_count, turbine3_range, check_input_turbine3);
    RUN_SPEED(triangle7, "triangle7", triangle7_variable_count, triangle7_range, check_input_triangle7);
    RUN_SPEED(doppler1, "doppler1", doppler1_variable_count, doppler1_range, check_input_doppler1);
    RUN_SPEED(triangle3, "triangle3", triangle3_variable_count, triangle3_range, check_input_triangle3);
    RUN_SPEED(Rump_s_example_from_C_program, "Rump's example, from C program", Rump_s_example_from_C_program_variable_count, Rump_s_example_from_C_program_range, check_input_Rump_s_example_from_C_program);
    RUN_SPEED(exp1x, "exp1x", exp1x_variable_count, exp1x_range, check_input_exp1x);
    RUN_SPEED(NMSE_problem_3_4_4, "NMSE problem 3.4.4", NMSE_problem_3_4_4_variable_count, NMSE_problem_3_4_4_range, check_input_NMSE_problem_3_4_4);
    RUN_SPEED(delta4, "delta4", delta4_variable_count, delta4_range, check_input_delta4);
    RUN_SPEED(instantaneousCurrent, "instantaneousCurrent", instantaneousCurrent_variable_count, instantaneousCurrent_range, check_input_instantaneousCurrent);
    RUN_SPEED(NMSE_problem_3_2_1_negative, "NMSE problem 3.2.1, negative", NMSE_problem_3_2_1_negative_variable_count, NMSE_problem_3_2_1_negative_range, check_input_NMSE_problem_3_2_1_negative);
    RUN_SPEED(kepler2, "kepler2", kepler2_variable_count, kepler2_range, check_input_kepler2);
    RUN_SPEED(NMSE_problem_3_3_3, "NMSE problem 3.3.3", NMSE_problem_3_3_3_variable_count, NMSE_problem_3_3_3_range, check_input_NMSE_problem_3_3_3);
    RUN_SPEED(azimuth, "azimuth", azimuth_variable_count, azimuth_range, check_input_azimuth);
    RUN_SPEED(NMSE_problem_3_3_7, "NMSE problem 3.3.7", NMSE_problem_3_3_7_variable_count, NMSE_problem_3_3_7_range, check_input_NMSE_problem_3_3_7);
    RUN_SPEED(i6, "i6", i6_variable_count, i6_range, check_input_i6);
    RUN_SPEED(NMSE_example_3_9, "NMSE example 3.9", NMSE_example_3_9_variable_count, NMSE_example_3_9_range, check_input_NMSE_example_3_9);
    RUN_SPEED(NMSE_section_3_5, "NMSE section 3.5", NMSE_section_3_5_variable_count, NMSE_section_3_5_range, check_input_NMSE_section_3_5);
    RUN_SPEED(hypot, "hypot", hypot_variable_count, hypot_range, check_input_hypot);
    RUN_SPEED(test04_dqmom9, "test04_dqmom9", test04_dqmom9_variable_count, test04_dqmom9_range, check_input_test04_dqmom9);
    RUN_SPEED(nonlin1, "nonlin1", nonlin1_variable_count, nonlin1_range, check_input_nonlin1);
    RUN_SPEED(NMSE_example_3_4, "NMSE example 3.4", NMSE_example_3_4_variable_count, NMSE_example_3_4_range, check_input_NMSE_example_3_4);
    RUN_SPEED(hartman6, "hartman6", hartman6_variable_count, hartman6_range, check_input_hartman6);
    RUN_SPEED(carthesianToPolar_radius, "carthesianToPolar, radius", carthesianToPolar_radius_variable_count, carthesianToPolar_radius_range, check_input_carthesianToPolar_radius);
    RUN_SPEED(triangle, "triangle", triangle_variable_count, triangle_range, check_input_triangle);
    RUN_SPEED(jetEngine, "jetEngine", jetEngine_variable_count, jetEngine_range, check_input_jetEngine);
    RUN_SPEED(sqroot, "sqroot", sqroot_variable_count, sqroot_range, check_input_sqroot);
    RUN_SPEED(triangle12, "triangle12", triangle12_variable_count, triangle12_range, check_input_triangle12);
    RUN_SPEED(triangle10, "triangle10", triangle10_variable_count, triangle10_range, check_input_triangle10);
    RUN_SPEED(turbine2, "turbine2", turbine2_variable_count, turbine2_range, check_input_turbine2);
    RUN_SPEED(triangle2, "triangle2", triangle2_variable_count, triangle2_range, check_input_triangle2);
    RUN_SPEED(rigidBody1, "rigidBody1", rigidBody1_variable_count, rigidBody1_range, check_input_rigidBody1);
    RUN_SPEED(NMSE_problem_3_4_1, "NMSE problem 3.4.1", NMSE_problem_3_4_1_variable_count, NMSE_problem_3_4_1_range, check_input_NMSE_problem_3_4_1);
    RUN_SPEED(exp1x_log, "exp1x_log", exp1x_log_variable_count, exp1x_log_range, check_input_exp1x_log);
    RUN_SPEED(Complex_square_root, "Complex square root", Complex_square_root_variable_count, Complex_square_root_range, check_input_Complex_square_root);
    RUN_SPEED(carthesianToPolar_theta, "carthesianToPolar, theta", carthesianToPolar_theta_variable_count, carthesianToPolar_theta_range, check_input_carthesianToPolar_theta);
    RUN_SPEED(NMSE_example_3_7, "NMSE example 3.7", NMSE_example_3_7_variable_count, NMSE_example_3_7_range, check_input_NMSE_example_3_7);
    RUN_SPEED(floudas3, "floudas3", floudas3_variable_count, floudas3_range, check_input_floudas3);
    RUN_SPEED(NMSE_example_3_6, "NMSE example 3.6", NMSE_example_3_6_variable_count, NMSE_example_3_6_range, check_input_NMSE_example_3_6);
    RUN_SPEED(i4, "i4", i4_variable_count, i4_range, check_input_i4);
    RUN_SPEED(test02_sum8, "test02_sum8", test02_sum8_variable_count, test02_sum8_range, check_input_test02_sum8);
    RUN_SPEED(triangle6, "triangle6", triangle6_variable_count, triangle6_range, check_input_triangle6);
    RUN_SPEED(carbonGas, "carbonGas", carbonGas_variable_count, carbonGas_range, check_input_carbonGas);
    RUN_SPEED(sphere, "sphere", sphere_variable_count, sphere_range, check_input_sphere);
    RUN_SPEED(test01_sum3, "test01_sum3", test01_sum3_variable_count, test01_sum3_range, check_input_test01_sum3);
    RUN_SPEED(test05_nonlin1_test2, "test05_nonlin1, test2", test05_nonlin1_test2_variable_count, test05_nonlin1_test2_range, check_input_test05_nonlin1_test2);
    RUN_SPEED(kepler1, "kepler1", kepler1_variable_count, kepler1_range, check_input_kepler1);
    RUN_SPEED(NMSE_example_3_1, "NMSE example 3.1", NMSE_example_3_1_variable_count, NMSE_example_3_1_range, check_input_NMSE_example_3_1);
    RUN_SPEED(matrixDeterminant, "matrixDeterminant", matrixDeterminant_variable_count, matrixDeterminant_range, check_input_matrixDeterminant);
    RUN_SPEED(NMSE_p42_positive, "NMSE p42, positive", NMSE_p42_positive_variable_count, NMSE_p42_positive_range, check_input_NMSE_p42_positive);
    RUN_SPEED(sqrt_add, "sqrt_add", sqrt_add_variable_count, sqrt_add_range, check_input_sqrt_add);
    RUN_SPEED(NMSE_problem_3_4_5, "NMSE problem 3.4.5", NMSE_problem_3_4_5_variable_count, NMSE_problem_3_4_5_range, check_input_NMSE_problem_3_4_5);
    RUN_SPEED(floudas1, "floudas1", floudas1_variable_count, floudas1_range, check_input_floudas1);
    RUN_SPEED(NMSE_problem_3_3_2, "NMSE problem 3.3.2", NMSE_problem_3_3_2_variable_count, NMSE_problem_3_3_2_range, check_input_NMSE_problem_3_3_2);
    RUN_SPEED(intro_example, "intro-example", intro_example_variable_count, intro_example_range, check_input_intro_example);
    RUN_SPEED(test06_sums4_sum2, "test06_sums4, sum2", test06_sums4_sum2_variable_count, test06_sums4_sum2_range, check_input_test06_sums4_sum2);
    RUN_SPEED(himmilbeau, "himmilbeau", himmilbeau_variable_count, himmilbeau_range, check_input_himmilbeau);
    RUN_SPEED(NMSE_problem_3_3_6, "NMSE problem 3.3.6", NMSE_problem_3_3_6_variable_count, NMSE_problem_3_3_6_range, check_input_NMSE_problem_3_3_6);
    RUN_SPEED(intro_example_mixed, "intro-example-mixed", intro_example_mixed_variable_count, intro_example_mixed_range, check_input_intro_example_mixed);
    RUN_SPEED(NMSE_problem_3_4_3, "NMSE problem 3.4.3", NMSE_problem_3_4_3_variable_count, NMSE_problem_3_4_3_range, check_input_NMSE_problem_3_4_3);
    RUN_SPEED(exp1x_32, "exp1x_32", exp1x_32_variable_count, exp1x_32_range, check_input_exp1x_32);
    RUN_SPEED(NMSE_problem_3_2_1_positive, "NMSE problem 3.2.1, positive", NMSE_problem_3_2_1_positive_variable_count, NMSE_problem_3_2_1_positive_range, check_input_NMSE_problem_3_2_1_positive);
    RUN_SPEED(polarToCarthesian_y, "polarToCarthesian, y", polarToCarthesian_y_variable_count, polarToCarthesian_y_range, check_input_polarToCarthesian_y);
    RUN_SPEED(Rump_s_example_revisited_for_floating_point, "Rump's example revisited for floating point", Rump_s_example_revisited_for_floating_point_variable_count, Rump_s_example_revisited_for_floating_point_range, check_input_Rump_s_example_revisited_for_floating_point);
    RUN_SPEED(triangle8, "triangle8", triangle8_variable_count, triangle8_range, check_input_triangle8);
    RUN_SPEED(verhulst, "verhulst", verhulst_variable_count, verhulst_range, check_input_verhulst);
    RUN_SPEED(triangle4, "triangle4", triangle4_variable_count, triangle4_range, check_input_triangle4);
    RUN_SPEED(doppler2, "doppler2", doppler2_variable_count, doppler2_range, check_input_doppler2);
#endif
}