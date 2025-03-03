#include <stdio.h>

int main(){
    unsigned int c;
    scanf("%u", &c);
    printf("c = %u -c = %u\n", c, ~c);

    // Вывод побитового представления числа c
    printf("Биты числа c: ");
    for(int i = sizeof(c)*8-1; i >= 0; i--){
        printf("%d", (c >> i) & 1);
    }
    printf("\n");

    // Создаем копию числа для проверки чередования битов
    unsigned int copy_c = c;
    int alternating = 1;  // Флаг для проверки чередования
    int previous_bit = copy_c & 1;  // Получаем самый младший бит

    // Пробегаем только по значимым битам числа (пока есть ненулевые биты)
    for(int i = 1; i < sizeof(copy_c)*8 && copy_c != 0; i++) {
        copy_c >>= 1;  // Сдвигаем число на 1 бит вправо
        int current_bit = copy_c & 1;  // Получаем текущий бит

        if (current_bit == previous_bit) {
            alternating = 0;  // Если текущий бит совпадает с предыдущим, биты не чередуются
            break;
        }

        previous_bit = current_bit;  // Обновляем предыдущий бит
    }

    if (alternating) {
        printf("Биты чередуются.\n");
    } else {
        printf("Биты не чередуются.\n");
    }

    // Вывод побитового представления числа ~c (инверсии числа)
    printf("Инверсия битов числа c: ");
    for(int i = sizeof(c)*8-1; i >= 0; i--){
        printf("%d", (~c >> i) & 1);
    }
    printf("\n");

    return 0;
}
