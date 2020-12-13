# Cross-platform Interval Library Benchmark
This library aims to test an interval library on speed, interval size, and correctness. Consistency and portability shall be trivial once the benchmark is deployed on different platforms.

## Compile and run the code
To use this library:
```bash
git clone https://github.com/geometryprocessing/intervals
cd intervals
mkdir build
cd build && cmake .. -DCMAKE_BUILD_TYPE=Release
make -j4
```

Three binaries should be generated after those steps, they should be `build/tests/gap_bin`, which is for testing interval size, `build/tests/query_bin`, which is for correctness test, and `build/tests/speed_bin`, which is for speed test.

For convenience, we also provide shell script that run the test and generates graphs, which are [test_gap.sh](test_gap.sh), [test_query.sh](test_query.sh) and [test_speed.sh](test_speed.sh). Note that to test correctness, you will need to install wolframEngine.

## Adding new interval library
Adding an new library is done by editing [src/interval.hpp](src/interval.hpp). There are a couple of things you need to define in order of it to work:

### Initialization with single value
If the added library does not include initialization from a single value, you will need to define it in the file. For example, filib does not include a single value initialization since its interval type is a struct, we define it as follow:
```c++
#define fic_interval(v) \
    {                   \
        v, v            \
    }
```
This turns a single value initialization into a struct.

### Defining functions for getting upper and lower bound
Since different libraries have different ways to get the upper and lower bound, we define a universal way of getting those values. Take filib's interval for example, we define the two functions `upper()` and `lower()`:
```c++
double lower(fic_interval v)
{
    return v.INF;
}
double upper(fic_interval v)
{
    return v.SUP;
}
```
### Operator overloading
If the library does not include operator overloading, you will also need to define that yourself. For a concrete example, refer to [src/interval.hpp](https://github.com/geometryprocessing/intervals/blob/BIAS/src/interval.hpp) in [BIAS](https://github.com/geometryprocessing/intervals/tree/BIAS) branch.


## Adding new expression
In this benchmark, we have a total of 134 expressions. 28 of them in [src/methods.hpp](src/methods.hpp) and the rest in [src/FPBench_methods.hpp](src/FPBench_methods.hpp). Those should give you a general idea of what are needed for adding an expression. We will go in detail what and why they are needed here. We will take the `x_by_xy` expression in [src/FPBench_methods.hpp](src/FPBench_methods.hpp) as an example.

### Expression
The most important thing is to define the expression itself, how it is computed. For our example, it is defined as:
```c++
template <class T>
inline T x_by_xy(const std::vector<T> &value_array)
{
	return value_array[0] / (value_array[0] + value_array[1]);
}
```

The template is needed so that different interval types can all use this expression. Since the number of inputs for each expression can be different, we use a vector for input.

### Print method
For correctness check, we need to know how to transfer this expression into a human-readable string. This is done by defining a print method. For this expression, it is defined as:

```c++
std::string print_x_by_xy(const std::vector<gmp::Rational> &v)
{
	return std::string() + "" + "(" + rational_to_string(v[0]) + ")" + " / (" + "(" + rational_to_string(v[0]) + ")" + " + " + "(" + rational_to_string(v[1]) + ")" + ")";
}
```
This should print something like:
```
((2342163972178063/1125899906842624)) / (((2342163972178063/1125899906842624)) + ((4383221097164843/1125899906842624)))
```

The numbers are randomly generated, and then converted to rationals.

### Check input
Some functions may need special input range. Since we extracted this expression from an existing benchmark, the range is predefined. Hence, we just need to setup a function to check if the input is valid. 

For this specific expression, we have `1<=v[0]<=4` and `1<=v[1]<=4`. Hence, the input check is defined as:
```c++
bool check_input_x_by_xy(const std::vector<double> &v)
{
    if (1.0 > v[0])
        return false;
    if (v[0] > 4.0)
        return false;
    if (1.0 > v[1])
        return false;
    if (v[1] > 4.0)
        return false;
    return true;
}
```
If the input range is not specified, and we know that the denominator cannot be 0, we can always write an additional check as:
```c++
if ((v[0] + v[1]) == 0)
    return false;
```

### Input range and number
The input range is also needed for the random generator. For this expression, we have the range predifined, hence we put the range for each input as a vector of distribution:
```c++
const std::vector<std::uniform_real_distribution<double>> x_by_xy_range = {std::uniform_real_distribution<double>(1.0, 4.0), std::uniform_real_distribution<double>(1.0, 4.0)};
```
The number of inputs is also needed, and can be easily defined. For this expression, we know the number of inputs is 2:
```c++
const int x_by_xy_variable_count = 2;
```
## Adding library to tests
For each test, if you want to add library, the syntax is similar. We will go over them here:

### Adding to interval size test
In [tests/gap/gap.cpp](tests/gap/gap.cpp), you will need to add one line to the macro function `RUN_GAP` to include your library. For example, if we want to use filib, the line is:
```c++
COMPUTE_GAP(fic_interval, "FILIB C", METHOD, INFO, VARIABLE_COUNT);
```

The first input is the interval type, the second is the interval name. The rest three inputs are from the expression that we run. You only need to support the first two arguments, the rest are inherited from the macro function.

### Adding to query test

In [tests/query/query.cpp](tests/query/query.cpp), add one line to macro function `RUN_QUERY`:

```c++
PRINT_QUERIES(fic_interval, "FILIB C", METHOD, PRINT_METHOD, VARIABLE_COUNT);
```
Again, you only need to support the first two argument and do not modify the rest.

### Adding to speed test
In [tests/speed/speed.cpp](tests/speed/speed.cpp), you will need to define multiple things, the first is a timer, which is a double. This should be a global variable define at the top of the file:
```c++
double  fic_timer;
```

Then, at each call of RUN_SPEED, the timer should be reset to 0:
```c++
fic_timer = 0;
```

Then, add the line to compute the time:
```c++
COMPUTE_TIME(fic_interval, METHOD, VARIABLE_COUNT, fic_timer);
```

Since we want to know the result at the end, we also need to print out the time:
```c++
printf("TIME, %s, FILIB C, %lf us, %lfx time that FILIB C version took\n", INFO, fic_timer, fic_timer / fic_timer);
```

The print format is not limited to the one we provide above, However, this format is needed for our plotting script to work correctly.

## Add expression to tests
Adding expressions to test is almost the same procedure. We will go over the three tests we have to demonstrate:

### Adding to interval size test
In [tests/gap/gap.cpp](tests/gap/gap.cpp), you will need to add the lines that call this expression. We will use `x_by_xy` as an example.

Since we may have pre-defined values, the first thing is to check if we want to use them by checking if the flag `USE_SYSTEM_RANDOM` EXISTS:
```c++
#ifndef USE_SYSTEM_RANDOM
    read_rationals_from_file("../rational_datas/x_by_xy_used_rationals.txt");
#endif
```
Then, to use the expression:
```c++
RUN_GAP(x_by_xy, "x_by_xy", x_by_xy_variable_count, x_by_xy_range, check_input_x_by_xy);
```

The first argument is the expression itself, the second is the name of the expression, then the number of variables, the range of inputs, and the function name that checks if the inputs are valid. Those things are defined when an expression is defined.

### Adding to query test
In [tests/query/query.cpp](tests/query/query.cpp), you will need to add similar lines to use the expression.

The lines that checks if pre-defined values exists are the same. To use the expression:
```c++
RUN_QUERY(x_by_xy, print_x_by_xy, x_by_xy_variable_count, x_by_xy_range, check_input_x_by_xy);
```

Only the second input changed, which is now the method that prints the query, which we have explained before.

### Adding to speed test
For speed test, we do not need to check if pre-defined values exists since the number of inputs is significantly less. However, you can also use the pre-defined values if you want, the same code works fine. You need to modify [tests/speed/speed.cpp](tests/speed/speed.cpp) for this one.

To use the expression:
```c++
RUN_SPEED(x_by_xy, "x_by_xy", x_by_xy_variable_count, x_by_xy_range, check_input_x_by_xy);
```

The inputs are the same as adding to interval size test
