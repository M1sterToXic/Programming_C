#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct Toy {
    char name[50];
    int code;
    float price;
};

void writeToFile(const char* filename, struct Toy* toy) {
    FILE* file = fopen(filename, "ab");
    if (file == NULL) {
        printf("Ошибка открытия файла!\n");
        return;
    }

    if (fwrite(toy, sizeof(struct Toy), 1, file) != 1) {
        printf("Ошибка записи в файл!\n");
    }

    fclose(file);
}

void readFromFile(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Ошибка открытия файла!\n");
        return;
    }

    struct Toy toy;
    while (fread(&toy, sizeof(struct Toy), 1, file)) {
        printf("Название: %s, Код: %d, Цена: %.2f\n", toy.name, toy.code, toy.price);
    }

    fclose(file);
}

void searchByName(const char *filename, const char *searchName) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Ошибка: не удалось открыть файл %s\n", filename);
        return;
    }

    struct Toy toy;
    int found = 0;

    while (fread(&toy, sizeof(struct Toy), 1, file)) {
        if (strcmp(toy.name, searchName) == 0) {
            printf("Найден товар: Код: %d, Имя: %s, Цена: %.2f\n", toy.code, toy.name, toy.price);
            found = 1;
        }
    }

    if (!found) {
        printf("Товар с именем '%s' не найден.\n", searchName);
    }

    fclose(file);
}

void searchByPrice(const char *filename, float searchPrice) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Ошибка: не удалось открыть файл %s\n", filename);
        return;
    }

    struct Toy toy;
    int found = 0;

    while (fread(&toy, sizeof(struct Toy), 1, file)) {
        if (toy.price == searchPrice) {
            printf("Найден товар: Код: %d, Имя: %s, Цена: %.2f\n", toy.code, toy.name, toy.price);
            found = 1;
        }
    }

    if (!found) {
        printf("Товар с ценой %.2f не найден.\n", searchPrice);
    }

    fclose(file);
}

void searchByCode(const char* filename, int code) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Ошибка открытия файла!\n");
        return;
    }

    struct Toy toy;
    bool found = false;

    while (fread(&toy, sizeof(struct Toy), 1, file)) {
        if (toy.code == code) {
            printf("Найдена запись:\n");
            printf("Название: %s, Код: %d, Цена: %.2f\n", toy.name, toy.code, toy.price);
            found = true;
            break;
        }
    }

    if (!found) {
        printf("Информация не найдена.\n");
    }

    fclose(file);
}

int main() {
    struct Toy toy;
    int choice = 0;

    while (1) {
        while (1) {
            printf("\nМеню:\n");
            printf("1. Добавить игрушку\n");
            printf("2. Поиск товара\n");
            printf("3. Вывести все игрушки\n");
            printf("4. Выйти\n");
            printf("Выберите номер команды: ");

            if (scanf("%d", &choice) == 1 && choice >= 1 && choice <= 4) {
                break;
            } else {
                printf("Ошибка: введите число от 1 до 4.\n");
                while (getchar() != '\n');  
            }
        }

        switch (choice) {
            case 1:
                while (1) {
                    printf("Введите название игрушки: ");
                    if (scanf("%49s", toy.name) == 1) {
                        break;
                    } else {
                        printf("Ошибка: введите корректное название.\n");
                        while (getchar() != '\n');
                    }
                }

                while (1) {
                    printf("Введите код товара: ");
                    if (scanf("%d", &toy.code) == 1) {
                        break;
                    } else {
                        printf("Ошибка: введите целое число.\n");
                        while (getchar() != '\n');
                    }
                }

                while (1) {
                    printf("Введите цену игрушки: ");
                    if (scanf("%f", &toy.price) == 1) {
                        break;
                    } else {
                        printf("Ошибка: введите число.\n");
                        while (getchar() != '\n');
                    }
                }

                writeToFile("ToysPrice.dat", &toy);
                printf("Данные сохранены!\n");
                break;

                case 2:
                char name[50];
                int searchCode;
                float price;
                int choice_2;
            
                while (1) {
                    printf("Введите по какому из критериев вы хотите найти товар? (Имя - 1, Код - 2, Цена - 3): ");
                    if (scanf("%d", &choice_2) == 1 && choice_2 >= 1 && choice_2 <= 3) {
                        break;
                    } else {
                        printf("Ошибка: введите число от 1 до 3.\n");
                        while (getchar() != '\n');
                    }
                }
            
                switch (choice_2) {
                    case 1:
                        printf("Введите имя товара для поиска: ");
                        while (getchar() != '\n');  
                        fgets(name, sizeof(name), stdin);
                        name[strcspn(name, "\n")] = 0;  
                        searchByName("ToysPrice.dat", name);
                        break;
            
                    case 2:  
                        while (1) {
                            printf("Введите код товара для поиска: ");
                            if (scanf("%d", &searchCode) == 1) {
                                break;
                            } else {
                                printf("Ошибка: введите целое число.\n");
                                while (getchar() != '\n');
                            }
                        }
                        searchByCode("ToysPrice.dat", searchCode);
                        break;
            
                    case 3:
                        while (1) {
                            printf("Введите цену товара для поиска: ");
                            if (scanf("%f", &price) == 1) {
                                break;
                            } else {
                                printf("Ошибка: введите корректное число.\n");
                                while (getchar() != '\n');
                            }
                        }
                        searchByPrice("ToysPrice.dat", price);
                        break;
                }
                break;

                // while (1) {
                //     printf("Введите код товара для поиска: ");
                //     if (scanf("%d", &searchCode) == 1) {
                //         break;
                //     } else {
                //         printf("Ошибка: введите целое число.\n");
                //         while (getchar() != '\n');
                //     }
                // }
                // searchByCode("ToysPrice.dat", searchCode);
                // break;

            case 3:
                printf("\nВсе игрушки:\n");
                readFromFile("ToysPrice.dat");
                break;

            case 4:
                printf("Выход из программы.\n");
                return 0;

            default:
                printf("Ошибка: неправильный выбор. Попробуйте снова.\n");
                break;
        }
    }

    return 0;
}