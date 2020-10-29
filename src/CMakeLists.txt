set(SOURCES
    interval.cpp
    interval.hpp
    helper_functions.hpp
    flats.hpp
    Rational.h
    Timer.h
    methods.hpp
)

prepend_current_path(SOURCES)
intervals_copy_headers(${SOURCES})
intervals_set_source_group(${SOURCES})
target_sources(intervals PUBLIC ${SOURCES})