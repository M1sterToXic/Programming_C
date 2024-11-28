#include <stdio.h>
#include <stdlib.h>

struct complex_num{
    double x;
    double y;
    double mnim;
};

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

int main(){
    double sum = 0; 
    struct complex_num cmn;
    cmn.x = input_x();
    cmn.y = input_y();
    cmn.mnim = input_mnim();
    
    sum = sum_comp(cmn);
    

}





























// struct man{
//     int num;
//     char letter[20];
// };

// int main(){
//     struct man s1 = {13, "fff"};
//     struct man s2;
//     s2 = s1;

//     scanf("%s", &s2.letter);
//     // s1.num = 13;
//     // s1.letter ='fff';

//     printf("%d\n", s1.num);
//     printf("%s\n", s1.letter);
//     printf("%s\n", s2.letter);
    
//     return 0;
// }