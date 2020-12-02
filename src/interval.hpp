// any implementation of interval you want to do
// you can do it here
// alternatively you can also link link libraries and define the type here
// but whatever you do, remember you need to define lower and upper function for your interval
// this is for the convenience of yourself so that you don't need to define it over and over
// in the computation part
#pragma once
#include <stdlib.h>
#include <functional>
#include <random>

// ================================================================
// ================================================================
// include filib c version interval
// do not change the order, always put this one first
// otherwise there gonna be some error
// and id rather not deal with those errors
#include "filib/interval.hpp"
typedef interval fic_interval;
#define fic_interval(v) \
    {                   \
        v, v            \
    }
double lower(fic_interval v)
{
    return v.INF;
}
double upper(fic_interval v)
{
    return v.SUP;
}
// ================================================================
// ================================================================

// ==============================================================================================
// ==============================================================================================
// include boost interval
#if defined(__APPLE__)
#warning "__APPLE__ defined so explicitly defining __USE_ISOC99"
#define __USE_ISOC99
#endif
#include "boost/numeric/interval.hpp"
namespace interval_options
{
    typedef boost::numeric::interval_lib::checking_base<double> CheckingPolicy;
} // namespace interval_options
#if defined(__APPLE__)
typedef boost::numeric::interval<
    double,
    boost::numeric::interval_lib::policies<
        boost::numeric::interval_lib::save_state<
            boost::numeric::interval_lib::rounded_transc_std<double>>,
        interval_options::CheckingPolicy>>
    boost_interval;
#else
typedef boost::numeric::interval<
    double,
    boost::numeric::interval_lib::policies<
        boost::numeric::interval_lib::save_state<
            boost::numeric::interval_lib::rounded_transc_std<double>>,
        interval_options::CheckingPolicy>>
    boost_interval;
#endif
double lower(boost_interval v)
{
    return v.lower();
}

double upper(boost_interval v)
{
    return v.upper();
}
// ==============================================================================================
// ==============================================================================================

// ==================================================================================================================
// ==================================================================================================================
// include filib c++ version interval
#ifdef USE_FILIB_PLUSPLUS
#include "interval/interval.hpp"
typedef filib::interval<double, filib::native_switched, filib::i_mode_normal> fi_native_switched;
typedef filib::interval<double, filib::pred_succ_rounding, filib::i_mode_normal> fi_pred_succ;
typedef filib::interval<double, filib::multiplicative, filib::i_mode_normal> fi_multiplicative;
template <typename T>
double lower(T v)
{
    return v.inf();
}

template <typename T>
double upper(T v)
{
    return v.sup();
}
#endif
// ==================================================================================================================
// ==================================================================================================================
#include <BIAS/Bias0.h>
#include <BIAS/BiasF.h>
#include <BiasRnd.h>
#define BIASINTERVAL(v) \
    {                   \
        v, v            \
    }

double lower(BIASINTERVAL v)
{
    return v.inf;
}

double upper(BIASINTERVAL v)
{
    return v.sup;
}

BIASINTERVAL operator+(BIASINTERVAL a, BIASINTERVAL b)
{
    BIASINTERVAL result;
    BiasAddII(&result, &a, &b);
    return result;
}

BIASINTERVAL operator-(BIASINTERVAL a, BIASINTERVAL b)
{
    BIASINTERVAL result;
    BiasSubII(&result, &a, &b);
    return result;
}

BIASINTERVAL operator*(BIASINTERVAL a, BIASINTERVAL b)
{
    BIASINTERVAL result;
    BiasMulII(&result, &a, &b);
    return result;
}

BIASINTERVAL operator/(BIASINTERVAL a, BIASINTERVAL b)
{
    BIASINTERVAL result;
    BiasDivII(&result, &a, &b);
    return result;
}

BIASINTERVAL sqrt(BIASINTERVAL a)
{
    BIASINTERVAL result;
    BiasSqrt(&result, &a);
    return result;
}

BIASINTERVAL exp(BIASINTERVAL a)
{
    BIASINTERVAL result;
    BiasExp(&result, &a);
    return result;
}

BIASINTERVAL sin(BIASINTERVAL a)
{
    BIASINTERVAL result;
    BiasSin(&result, &a);
    return result;
}

BIASINTERVAL cos(BIASINTERVAL a)
{
    BIASINTERVAL result;
    BiasCos(&result, &a);
    return result;
}
