#include "../../src/interval.hpp"
using namespace std;

int main(int argc, char *argv[])
{
    PRE_FILL_RANDOM_DOUBLES(distribution_all_range, 13);
    PRINT_QUERIES(fic_interval, sin, 1, print_sin);
    return 0;
}