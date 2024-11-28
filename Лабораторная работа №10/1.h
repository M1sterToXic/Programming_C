#include <stdio.h>
#include <stdlib.h>

struct complex_num{
    double x;
    double y;
    double mnim;
};

double input_x();

double input_y();

double input_mnim();

double sum_comp(struct complex_num cmn);