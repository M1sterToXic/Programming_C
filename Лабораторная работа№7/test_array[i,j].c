/*
#include <stdio.h>

int main() {
    //char game_pole [3][3] = {1, 2, 3, 4};
    char game_pole [3][3] = {{1, 2, 3}, {3, 4}};

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d ", game_pole[i][j]);
        }
        printf("\n");
    }
}
*/

/*

//Проверка строк\столбцов\размера массива\размера строки

#include <stdio.h>

int main(){
    int game_pole[5][3];

    size_t bytes = sizeof(game_pole);
    size_t row_bytes = sizeof(game_pole[0]);
    size_t rows = sizeof(game_pole) / sizeof(game_pole[0]);
    size_t cols = sizeof(game_pole[0]) / sizeof(game_pole[0][0]);

    printf("%d \n", bytes);
    printf("%d \n", row_bytes);
    printf("%d \n", rows);
    printf("%d \n", cols);
    return 0;
}
*/
/*
#include <stdio.h>

int main(){
    char game_pole[3][3] = {1,2,3,4,5,6,7,8,9};

    char *p_row = game_pole[1];
    printf("%d\n", *(p_row - 2));


    char (*p_ar)[3] = game_pole;

    char x = p_ar[1][2];
    printf("%c", x);

}
*/

