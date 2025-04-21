#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Использование: %s <имя_файла>\n", argv[0]);
        return 1;
    }

    FILE *f, *outputFile;
    char c[1000];
    char longest_line[1000] = ""; 
    size_t max_length = 0;    

    f = fopen(argv[1], "r");
    if (f == NULL) {
        printf("Не удалось открыть файл %s!\n", argv[1]);
        return 1;
    }
    while (fgets(c, sizeof(c), f)) {
        size_t len = strlen(c);
        if (len > 0 && c[len - 1] == '\n') {
            c[len - 1] = '\0'; // Убираем символ новой строки
            len--;             // Уменьшаем длину на 1
        }

        if (len > max_length) {
            max_length = len;
            strcpy(longest_line, c);
        }
    }

    fclose(f);

    if (max_length > 0) {
        printf("Самая длинная строка: %s\n", longest_line);
        printf("Длина: %zu\n", max_length);

        char reversed_line[1000];
        for (size_t i = 0; i < max_length; i++) {
            reversed_line[i] = longest_line[max_length - 1 - i];
        }
        reversed_line[max_length] = '\0';

        printf("Перевернутая строка: %s\n", reversed_line);

        outputFile = fopen("Lab5.txt", "w");
        if (outputFile == NULL) {
            printf("Не удалось создать файл Lab5.txt!\n");
            return 1;
        }

        fprintf(outputFile, "%s\n", reversed_line);
        fclose(outputFile);

        printf("Перевернутая строка записана в файл Lab5.txt\n");
    } else {
        printf("Файл пуст или не содержит строк.\n");
    }

    return 0;
}