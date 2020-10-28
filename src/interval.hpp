// any implementation of interval you want to do
// you can do it here
// alternatively you can also link link libraries and define the type here
#pragma once
#include <stdlib.h>
#include <functional>
#include <random>

// include filib c version interval
// do not change the order, always put this one first
// otherwise there gonna be some error
// and id rather not deal with those errors
#include "filib/interval.hpp"
typedef interval fic_interval;

// include boost interval
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

// include filib c++ version interval
#define USE_FILIB_PLUSPLUS // weather we will use the filib plus plus version
#ifdef USE_FILIB_PLUSPLUS
#include "interval/interval.hpp"
#endif