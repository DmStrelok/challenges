#include <iostream>

#include "poisonous-plants/test.h"
#include "cube-summation/test.h"
#include "subsequence-weighting/test.h"

int main()
{
    // poisonous_plants::run_test();
    // cube_summation::run_test(cube_summation::cubeSum);
    // cube_summation::run_test(cube_summation::cubeSum2);
    subsequence_weighting::run_test(subsequence_weighting::solve2);

    return 0;
}
