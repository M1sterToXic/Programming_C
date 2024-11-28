
#include <stdio.h>
#include <string.h>

void reverseWords(char *sentence) {
    int length = strlen(sentence);
    int start = length, end = length;
    // Проходим по строке в обратном порядке
    for (int i = length - 1; i >= 0; i--) {
        // Если встречаем пробел или начало строки
        if (sentence[i] == ' ' || i == 0) {
            start = (i == 0) ? i : i + 1;
            // Выводим слово
            for (int j = start; j < end; j++) {
                putchar(sentence[j]);
            }
            if (i > 0) putchar(' ');  // Добавляем пробел между словами
            end = i;
        }
    }
    putchar('\n');
}

int main() {
    char sentence[] = "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur";
    printf("Original: %s\n", sentence);
    printf("Reversed: ");
    reverseWords(sentence);
    return 0;
}

