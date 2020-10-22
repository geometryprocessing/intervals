#include "flags.hpp"

#ifdef USE_FILIB_PLUSPLUS
#define COMPUTE_GAP(METHOD, INFO, DISTRIBUTION, VARIABLE_COUNT, COMPUTE_RATIONAL)                                                                                                                             \
    do                                                                                                                                                                                                        \
    {                                                                                                                                                                                                         \
        for (int i = 0; i < VARIABLE_COUNT; i++)                                                                                                                                                              \
        {                                                                                                                                                                                                     \
            double r = random_double(DISTRIBUTION);                                                                                                                                                           \
            comp_doubles[i] = r;                                                                                                                                                                              \
            comp_gmp_rationals[i] = gmp::Rational(r);                                                                                                                                                         \
            comp_our_intervals[i] = interval(r);                                                                                                                                                              \
            comp_boost_intervals[i] = boost_interval(r);                                                                                                                                                      \
            comp_fic_intervals[i] = {r, r};                                                                                                                                                                   \
        }                                                                                                                                                                                                     \
        local_used_rational_index = 0;                                                                                                                                                                        \
        interval our_result = METHOD<interval>(comp_our_intervals);                                                                                                                                           \
        boost_interval boost_result = METHOD<boost_interval>(comp_boost_intervals);                                                                                                                           \
        fic_interval fic_result = METHOD<fic_interval>(comp_fic_intervals);                                                                                                                                   \
        filib::fp_traits<double, filib::native_switched>::setup();                                                                                                                                            \
        std::vector<filib::interval<double, filib::native_switched, filib::i_mode_normal>> native_switched_values;                                                                                            \
        native_switched_values.resize(VARIABLE_COUNT);                                                                                                                                                        \
        for (int i = 0; i < VARIABLE_COUNT; i++)                                                                                                                                                              \
        {                                                                                                                                                                                                     \
            native_switched_values[i] = filib::interval<double, filib::native_switched, filib::i_mode_normal>(comp_doubles[i]);                                                                               \
        }                                                                                                                                                                                                     \
        filib::interval<double, filib::native_switched, filib::i_mode_normal> native_switched_result = METHOD<filib::interval<double, filib::native_switched, filib::i_mode_normal>>(native_switched_values); \
        filib::fp_traits<double, filib::multiplicative>::setup();                                                                                                                                             \
        std::vector<filib::interval<double, filib::multiplicative, filib::i_mode_normal>> multiplicative_values;                                                                                              \
        multiplicative_values.resize(VARIABLE_COUNT);                                                                                                                                                         \
        for (int i = 0; i < VARIABLE_COUNT; i++)                                                                                                                                                              \
        {                                                                                                                                                                                                     \
            multiplicative_values[i] = filib::interval<double, filib::multiplicative, filib::i_mode_normal>(comp_doubles[i]);                                                                                 \
        }                                                                                                                                                                                                     \
        filib::interval<double, filib::multiplicative, filib::i_mode_normal> multiplicative_result = METHOD<filib::interval<double, filib::multiplicative, filib::i_mode_normal>>(multiplicative_values);     \
        filib::fp_traits<double, filib::pred_succ_rounding>::setup();                                                                                                                                         \
        std::vector<filib::interval<double, filib::pred_succ_rounding, filib::i_mode_normal>> pred_succ_values;                                                                                               \
        pred_succ_values.resize(VARIABLE_COUNT);                                                                                                                                                              \
        for (int i = 0; i < VARIABLE_COUNT; i++)                                                                                                                                                              \
        {                                                                                                                                                                                                     \
            pred_succ_values[i] = filib::interval<double, filib::pred_succ_rounding, filib::i_mode_normal>(comp_doubles[i]);                                                                                  \
        }                                                                                                                                                                                                     \
        filib::interval<double, filib::pred_succ_rounding, filib::i_mode_normal> pred_succ_result = METHOD<filib::interval<double, filib::pred_succ_rounding, filib::i_mode_normal>>(pred_succ_values);       \
        if (COMPUTE_RATIONAL)                                                                                                                                                                                 \
        {                                                                                                                                                                                                     \
            gmp::Rational rational_result = METHOD<gmp::Rational>(comp_gmp_rationals);                                                                                                                        \
            if (!within_range(our_result.lower(), our_result.upper(), rational_result))                                                                                                                       \
            {                                                                                                                                                                                                 \
                printf("FAIL, %s, OUR METHOD\n", INFO);                                                                                                                                                       \
            }                                                                                                                                                                                                 \
            if (!within_range(boost_result.lower(), boost_result.upper(), rational_result))                                                                                                                   \
            {                                                                                                                                                                                                 \
                printf("FAIL, %s, BOOST METHOD\n", INFO);                                                                                                                                                     \
            }                                                                                                                                                                                                 \
            if (!within_range(fic_result.INF, fic_result.SUP, rational_result))                                                                                                                               \
            {                                                                                                                                                                                                 \
                printf("FAIL, %s, FILIB C\n", INFO);                                                                                                                                                          \
            }                                                                                                                                                                                                 \
            if (!within_range(native_switched_result.inf(), native_switched_result.sup(), rational_result))                                                                                                   \
            {                                                                                                                                                                                                 \
                printf("FAIL, %s, NATIVE SWITCHED\n", INFO);                                                                                                                                                  \
            }                                                                                                                                                                                                 \
            if (!within_range(multiplicative_result.inf(), multiplicative_result.sup(), rational_result))                                                                                                     \
            {                                                                                                                                                                                                 \
                printf("FAIL, %s, MULTIPLICATIVE\n", INFO);                                                                                                                                                   \
            }                                                                                                                                                                                                 \
            if (!within_range(pred_succ_result.inf(), pred_succ_result.sup(), rational_result))                                                                                                               \
            {                                                                                                                                                                                                 \
                printf("FAIL, %s, PRED SUCC\n", INFO);                                                                                                                                                        \
            }                                                                                                                                                                                                 \
        }                                                                                                                                                                                                     \
        printf("GAP, %s, OUR METHOD, ", INFO);                                                                                                                                                                \
        print_rational(interval_size(our_result.lower(), our_result.upper()));                                                                                                                                \
        printf("\n");                                                                                                                                                                                         \
        printf("GAP, %s, BOOST METHOD, ", INFO);                                                                                                                                                              \
        print_rational(interval_size(boost_result.lower(), boost_result.upper()));                                                                                                                            \
        printf("\n");                                                                                                                                                                                         \
        printf("GAP, %s, FILIB_C METHOD, ", INFO);                                                                                                                                                            \
        print_rational(interval_size(fic_result.INF, fic_result.SUP));                                                                                                                                        \
        printf("\n");                                                                                                                                                                                         \
        printf("GAP, %s, NATIVE SWITCHED, ", INFO);                                                                                                                                                           \
        print_rational(interval_size(native_switched_result.inf(), native_switched_result.sup()));                                                                                                            \
        printf("\n");                                                                                                                                                                                         \
        printf("GAP, %s, MULTIPLICATIVE, ", INFO);                                                                                                                                                            \
        print_rational(interval_size(multiplicative_result.inf(), multiplicative_result.sup()));                                                                                                              \
        printf("\n");                                                                                                                                                                                         \
        printf("GAP, %s, PRED SUCC, ", INFO);                                                                                                                                                                 \
        print_rational(interval_size(pred_succ_result.inf(), pred_succ_result.sup()));                                                                                                                        \
        printf("\n");                                                                                                                                                                                         \
    } while (0)
#else
#define COMPUTE_GAP(METHOD, INFO, DISTRIBUTION, VARIABLE_COUNT, COMPUTE_RATIONAL)           \
    do                                                                                      \
    {                                                                                       \
        for (int i = 0; i < VARIABLE_COUNT; i++)                                            \
        {                                                                                   \
            double r = random_double(DISTRIBUTION);                                         \
            comp_doubles[i] = r;                                                            \
            comp_gmp_rationals[i] = gmp::Rational(r);                                       \
            comp_our_intervals[i] = interval(r);                                            \
            comp_boost_intervals[i] = boost_interval(r);                                    \
            comp_fic_intervals[i] = {r, r};                                                 \
        }                                                                                   \
        local_used_rational_index = 0;                                                      \
        interval our_result = METHOD<interval>(comp_our_intervals);                         \
        boost_interval boost_result = METHOD<boost_interval>(comp_boost_intervals);         \
        fic_interval fic_result = METHOD<fic_interval>(comp_fic_intervals);                 \
        if (COMPUTE_RATIONAL)                                                               \
        {                                                                                   \
            gmp::Rational rational_result = METHOD<gmp::Rational>(comp_gmp_rationals);      \
            if (!within_range(our_result.lower(), our_result.upper(), rational_result))     \
            {                                                                               \
                printf("FAIL, %s, OUR METHOD\n", INFO);                                     \
            }                                                                               \
            if (!within_range(boost_result.lower(), boost_result.upper(), rational_result)) \
            {                                                                               \
                printf("FAIL, %s, BOOST METHOD\n", INFO);                                   \
            }                                                                               \
            if (!within_range(fic_result.INF, fic_result.SUP, rational_result))             \
            {                                                                               \
                printf("FAIL, %s, FILIB C\n", INFO);                                        \
            }                                                                               \
        }                                                                                   \
        printf("GAP, %s, OUR METHOD, ", INFO);                                              \
        print_rational(interval_size(our_result.lower(), our_result.upper()));              \
        printf("\n");                                                                       \
        printf("GAP, %s, BOOST METHOD, ", INFO);                                            \
        print_rational(interval_size(boost_result.lower(), boost_result.upper()));          \
        printf("\n");                                                                       \
        printf("GAP, %s, FILIB_C METHOD, ", INFO);                                          \
        print_rational(interval_size(fic_result.INF, fic_result.SUP));                      \
        printf("\n");                                                                       \
    } while (0)
#endif

#ifdef USE_FILIB_PLUSPLUS
#define SPEED_TEST(METHOD, INFO, DISTRIBUTION, VARIABLE_COUNT)                                                                                                                                                            \
    do                                                                                                                                                                                                                    \
    {                                                                                                                                                                                                                     \
        double our_time = 0;                                                                                                                                                                                              \
        double boost_time = 0;                                                                                                                                                                                            \
        double fic_time = 0;                                                                                                                                                                                              \
        double native_switched_time = 0;                                                                                                                                                                                  \
        double multiplicative_time = 0;                                                                                                                                                                                   \
        double pred_succ_time = 0;                                                                                                                                                                                        \
        for (int i = 0; i < SPEED_TEST_LOOP; i++)                                                                                                                                                                         \
        {                                                                                                                                                                                                                 \
            for (int j = 0; j < VARIABLE_COUNT; j++)                                                                                                                                                                      \
            {                                                                                                                                                                                                             \
                double r = random_double(DISTRIBUTION);                                                                                                                                                                   \
                comp_doubles[j] = r;                                                                                                                                                                                      \
                comp_our_intervals[j] = interval(r);                                                                                                                                                                      \
                comp_boost_intervals[j] = boost_interval(r);                                                                                                                                                              \
                comp_fic_intervals[j] = {r, r};                                                                                                                                                                           \
            }                                                                                                                                                                                                             \
            local_used_rational_index = 0;                                                                                                                                                                                \
            our_time += benchmarkTimer([&]() {                                                                                                                                                                            \
                for (int j = 0; j < SPEED_TEST_LOOP; j++)                                                                                                                                                                 \
                {                                                                                                                                                                                                         \
                    interval our_result = METHOD<interval>(comp_our_intervals);                                                                                                                                           \
                }                                                                                                                                                                                                         \
            });                                                                                                                                                                                                           \
            boost_time += benchmarkTimer([&]() {                                                                                                                                                                          \
                for (int j = 0; j < SPEED_TEST_LOOP; j++)                                                                                                                                                                 \
                {                                                                                                                                                                                                         \
                    boost_interval boost_result = METHOD<boost_interval>(comp_boost_intervals);                                                                                                                           \
                }                                                                                                                                                                                                         \
            });                                                                                                                                                                                                           \
            fic_time += benchmarkTimer([&]() {                                                                                                                                                                            \
                for (int j = 0; j < SPEED_TEST_LOOP; j++)                                                                                                                                                                 \
                {                                                                                                                                                                                                         \
                    fic_interval fic_result = METHOD<fic_interval>(comp_fic_intervals);                                                                                                                                   \
                }                                                                                                                                                                                                         \
            });                                                                                                                                                                                                           \
            filib::fp_traits<double, filib::native_switched>::setup();                                                                                                                                                    \
            std::vector<filib::interval<double, filib::native_switched, filib::i_mode_normal>> native_switched_values;                                                                                                    \
            native_switched_values.resize(VARIABLE_COUNT);                                                                                                                                                                \
            for (int i = 0; i < VARIABLE_COUNT; i++)                                                                                                                                                                      \
            {                                                                                                                                                                                                             \
                native_switched_values[i] = filib::interval<double, filib::native_switched, filib::i_mode_normal>(comp_doubles[i]);                                                                                       \
            }                                                                                                                                                                                                             \
            native_switched_time += benchmarkTimer([&]() {                                                                                                                                                                \
                for (int j = 0; j < SPEED_TEST_LOOP; j++)                                                                                                                                                                 \
                {                                                                                                                                                                                                         \
                    filib::interval<double, filib::native_switched, filib::i_mode_normal> native_switched_result = METHOD<filib::interval<double, filib::native_switched, filib::i_mode_normal>>(native_switched_values); \
                }                                                                                                                                                                                                         \
            });                                                                                                                                                                                                           \
            filib::fp_traits<double, filib::multiplicative>::setup();                                                                                                                                                     \
            std::vector<filib::interval<double, filib::multiplicative, filib::i_mode_normal>> multiplicative_values;                                                                                                      \
            multiplicative_values.resize(VARIABLE_COUNT);                                                                                                                                                                 \
            for (int i = 0; i < VARIABLE_COUNT; i++)                                                                                                                                                                      \
            {                                                                                                                                                                                                             \
                multiplicative_values[i] = filib::interval<double, filib::multiplicative, filib::i_mode_normal>(comp_doubles[i]);                                                                                         \
            }                                                                                                                                                                                                             \
            multiplicative_time += benchmarkTimer([&]() {                                                                                                                                                                 \
                for (int j = 0; j < SPEED_TEST_LOOP; j++)                                                                                                                                                                 \
                {                                                                                                                                                                                                         \
                    filib::interval<double, filib::multiplicative, filib::i_mode_normal> multiplicative_result = METHOD<filib::interval<double, filib::multiplicative, filib::i_mode_normal>>(multiplicative_values);     \
                }                                                                                                                                                                                                         \
            });                                                                                                                                                                                                           \
            filib::fp_traits<double, filib::pred_succ_rounding>::setup();                                                                                                                                                 \
            std::vector<filib::interval<double, filib::pred_succ_rounding, filib::i_mode_normal>> pred_succ_values;                                                                                                       \
            pred_succ_values.resize(VARIABLE_COUNT);                                                                                                                                                                      \
            for (int i = 0; i < VARIABLE_COUNT; i++)                                                                                                                                                                      \
            {                                                                                                                                                                                                             \
                pred_succ_values[i] = filib::interval<double, filib::pred_succ_rounding, filib::i_mode_normal>(comp_doubles[i]);                                                                                          \
            }                                                                                                                                                                                                             \
            pred_succ_time += benchmarkTimer([&]() {                                                                                                                                                                      \
                for (int j = 0; j < SPEED_TEST_LOOP; j++)                                                                                                                                                                 \
                {                                                                                                                                                                                                         \
                    filib::interval<double, filib::pred_succ_rounding, filib::i_mode_normal> pred_succ_result = METHOD<filib::interval<double, filib::pred_succ_rounding, filib::i_mode_normal>>(pred_succ_values);       \
                }                                                                                                                                                                                                         \
            });                                                                                                                                                                                                           \
        }                                                                                                                                                                                                                 \
        printf("TIME, %s, OUR METHOD, ", INFO);                                                                                                                                                                           \
        printf("%lf, %lfx time that filib c version took", our_time, our_time / fic_time);                                                                                                                                \
        printf("\n");                                                                                                                                                                                                     \
        printf("TIME, %s, BOOST METHOD, ", INFO);                                                                                                                                                                         \
        printf("%lf, %lfx time that filib c version took", boost_time, boost_time / fic_time);                                                                                                                            \
        printf("\n");                                                                                                                                                                                                     \
        printf("TIME, %s, FILIB C, ", INFO);                                                                                                                                                                              \
        printf("%lf, %lfx time that filib c version took", fic_time, fic_time / fic_time);                                                                                                                                \
        printf("\n");                                                                                                                                                                                                     \
        printf("TIME, %s, NATIVE SWITCHED, ", INFO);                                                                                                                                                                      \
        printf("%lf, %lfx time that filib c version took", native_switched_time, native_switched_time / fic_time);                                                                                                        \
        printf("\n");                                                                                                                                                                                                     \
        printf("TIME, %s, MULTIPLICATIVE, ", INFO);                                                                                                                                                                       \
        printf("%lf, %lfx time that filib c version took", multiplicative_time, multiplicative_time / fic_time);                                                                                                          \
        printf("\n");                                                                                                                                                                                                     \
        printf("TIME, %s, PRED SUCC, ", INFO);                                                                                                                                                                            \
        printf("%lf, %lfx time that filib c version took", pred_succ_time, pred_succ_time / fic_time);                                                                                                                    \
        printf("\n");                                                                                                                                                                                                     \
    } while (0)
#else
#define SPEED_TEST(METHOD, INFO, DISTRIBUTION, VARIABLE_COUNT)                                  \
    do                                                                                          \
    {                                                                                           \
        double our_time = 0;                                                                    \
        double boost_time = 0;                                                                  \
        double fic_time = 0;                                                                    \
        double native_switched_time = 0;                                                        \
        double multiplicative_time = 0;                                                         \
        double pred_succ_time = 0;                                                              \
        for (int i = 0; i < SPEED_TEST_LOOP; i++)                                               \
        {                                                                                       \
            for (int j = 0; j < VARIABLE_COUNT; j++)                                            \
            {                                                                                   \
                double r = random_double(DISTRIBUTION);                                         \
                comp_doubles[j] = r;                                                            \
                comp_our_intervals[j] = interval(r);                                            \
                comp_boost_intervals[j] = boost_interval(r);                                    \
                comp_fic_intervals[j] = {r, r};                                                 \
            }                                                                                   \
            local_used_rational_index = 0;                                                      \
            our_time += benchmarkTimer([&]() {                                                  \
                for (int j = 0; j < SPEED_TEST_LOOP; j++)                                       \
                {                                                                               \
                    interval our_result = METHOD<interval>(comp_our_intervals);                 \
                }                                                                               \
            });                                                                                 \
            boost_time += benchmarkTimer([&]() {                                                \
                for (int j = 0; j < SPEED_TEST_LOOP; j++)                                       \
                {                                                                               \
                    boost_interval boost_result = METHOD<boost_interval>(comp_boost_intervals); \
                }                                                                               \
            });                                                                                 \
            fic_time += benchmarkTimer([&]() {                                                  \
                for (int j = 0; j < SPEED_TEST_LOOP; j++)                                       \
                {                                                                               \
                    fic_interval fic_result = METHOD<fic_interval>(comp_fic_intervals);         \
                }                                                                               \
            });                                                                                 \
        }                                                                                       \
        printf("TIME, %s, OUR METHOD, ", INFO);                                                 \
        printf("%lf, %lfx time that filib c version took", our_time, our_time / fic_time);      \
        printf("\n");                                                                           \
        printf("TIME, %s, BOOST METHOD, ", INFO);                                               \
        printf("%lf, %lfx time that filib c version took", boost_time, boost_time / fic_time);  \
        printf("\n");                                                                           \
        printf("TIME, %s, FILIB C, ", INFO);                                                    \
        printf("%lf, %lfx time that filib c version took", fic_time, fic_time / fic_time);      \
        printf("\n");                                                                           \
    } while (0)

#endif

#ifdef USE_FILIB_PLUSPLUS
// print the queries for mathematica to verify
// this is for transcendental functions
#define PRINT_QUERIES(METHOD, INFO, DISTRIBUTION, VARIABLE_COUNT)                                                                                                                                       \
    do                                                                                                                                                                                                  \
    {                                                                                                                                                                                                   \
        for (int i = 0; i < VARIABLE_COUNT; i++)                                                                                                                                                        \
        {                                                                                                                                                                                               \
            double r = random_double(DISTRIBUTION);                                                                                                                                                     \
            comp_doubles[i] = r;                                                                                                                                                                        \
            comp_our_intervals[i] = interval(r);                                                                                                                                                        \
            comp_boost_intervals[i] = boost_interval(r);                                                                                                                                                \
            comp_fic_intervals[i] = {r, r};                                                                                                                                                             \
        }                                                                                                                                                                                               \
        local_used_rational_index = 0;                                                                                                                                                                  \
        interval our_result = METHOD<interval>(comp_our_intervals);                                                                                                                                     \
        boost_interval boost_result = METHOD<boost_interval>(comp_boost_intervals);                                                                                                                     \
        fic_interval fic_result = METHOD<fic_interval>(comp_fic_intervals);                                                                                                                             \
        filib::fp_traits<double, filib::pred_succ_rounding>::setup();                                                                                                                                   \
        std::vector<filib::interval<double, filib::pred_succ_rounding, filib::i_mode_normal>> pred_succ_values;                                                                                         \
        pred_succ_values.resize(VARIABLE_COUNT);                                                                                                                                                        \
        for (int i = 0; i < VARIABLE_COUNT; i++)                                                                                                                                                        \
        {                                                                                                                                                                                               \
            pred_succ_values[i] = filib::interval<double, filib::pred_succ_rounding, filib::i_mode_normal>(comp_doubles[i]);                                                                            \
        }                                                                                                                                                                                               \
        filib::interval<double, filib::pred_succ_rounding, filib::i_mode_normal> pred_succ_result = METHOD<filib::interval<double, filib::pred_succ_rounding, filib::i_mode_normal>>(pred_succ_values); \
        print_query(our_result.lower(), our_result.upper(), comp_doubles[0], INFO);                                                                                                                     \
        print_query(boost_result.lower(), boost_result.upper(), comp_doubles[0], INFO);                                                                                                                 \
        print_query(fic_result.INF, fic_result.SUP, comp_doubles[0], INFO);                                                                                                                             \
        print_query(pred_succ_result.inf(), pred_succ_result.sup(), comp_doubles[0], INFO);                                                                                                             \
    } while (0)
#else
#define PRINT_QUERIES(METHOD, INFO, DISTRIBUTION, VARIABLE_COUNT)                       \
    do                                                                                  \
    {                                                                                   \
        for (int i = 0; i < VARIABLE_COUNT; i++)                                        \
        {                                                                               \
            double r = random_double(DISTRIBUTION);                                     \
            comp_doubles[i] = r;                                                        \
            comp_our_intervals[i] = interval(r);                                        \
            comp_boost_intervals[i] = boost_interval(r);                                \
            comp_fic_intervals[i] = {r, r};                                             \
        }                                                                               \
        local_used_rational_index = 0;                                                  \
        interval our_result = METHOD<interval>(comp_our_intervals);                     \
        boost_interval boost_result = METHOD<boost_interval>(comp_boost_intervals);     \
        fic_interval fic_result = METHOD<fic_interval>(comp_fic_intervals);             \
        print_query(our_result.lower(), our_result.upper(), comp_doubles[0], INFO);     \
        print_query(boost_result.lower(), boost_result.upper(), comp_doubles[0], INFO); \
        print_query(fic_result.INF, fic_result.SUP, comp_doubles[0], INFO);             \
    } while (0)
#endif