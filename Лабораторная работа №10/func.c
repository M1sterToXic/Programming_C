#include <stdio.h>
#include <stdlib.h>
#include "1.h"

double input_x(){
    double x;
    printf("Введите x = ");
    scanf("%lf", &x);
    return x;
}

double input_y(){
    double y;
    printf("Введите y = ");
    scanf("%lf", &y);
    return y;
}

double input_mnim(){
    double mnim;
    printf("Введите мнимую часть = ");
    scanf("%lf", &mnim);
    return mnim;
}


double sum_comp(struct complex_num cmn){
    double Z = cmn.x*cmn.x * (cmn.y + cmn.mnim) - cmn.mnim * cmn.y;
    printf("%0.2lf\n", Z);
    return Z;
}