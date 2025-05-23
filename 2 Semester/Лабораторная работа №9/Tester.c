#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "test_func.h"

// Если код в одном файле, можно просто вставить его здесь

// 1. Тест для getMaxTotal (уже был)
static void test_getMaxTotal(void **state) {
    (void)state;
    struct Student testStudents[] = {
        {"A", 80, 85, 90, 255},
        {"B", 70, 75, 80, 225},
        {"C", 90, 95, 100, 285}  // Максимум
    };
    assert_int_equal(getMaxTotal(testStudents, 3), 285);
}

// 2. Тест для addStudent (проверяем заполнение структуры)
static void test_addStudent(void **state) {
    (void)state;
    struct Student s = addStudent("Test", 50, 60, 70);
    
    assert_string_equal(s.name, "Test");
    assert_int_equal(s.math, 50);
    assert_int_equal(s.physics, 60);
    assert_int_equal(s.informatics, 70);
    assert_int_equal(s.total, 180);  // 50+60+70
}

// 3. Тест для radixSort (проверяем сортировку по убыванию)
static void test_radixSort(void **state) {
    (void)state;
    struct Student students[] = {
        {"A", 10, 10, 10, 30},
        {"B", 20, 20, 20, 60},
        {"C", 15, 15, 15, 45}
    };
    
    radixSort(students, 3);
    
    // Должно быть: 60 (B), 45 (C), 30 (A)
    assert_int_equal(students[0].total, 60);
    assert_int_equal(students[1].total, 45);
    assert_int_equal(students[2].total, 30);
}

// 4. Тест для countingSort (проверяем сортировку по разряду)
static void test_countingSort(void **state) {
    (void)state;
    struct Student students[] = {
        {"A", 0, 0, 0, 25},  // Разряд единиц: 5
        {"B", 0, 0, 0, 19},  // Разряд единиц: 9
        {"C", 0, 0, 0, 31}   // Разряд единиц: 1
    };
    
    // Сортируем по единицам (exp=1), должно стать: 19 (9), 25 (5), 31 (1)
    countingSort(students, 3, 1);
    
    assert_int_equal(students[0].total, 19);
    assert_int_equal(students[1].total, 25);
    assert_int_equal(students[2].total, 31);
}

// 5. Тест для printStudentInfo (проверяем вывод)
static void test_printStudentInfo(void **state) {
    (void)state;
    struct Student s = {"Test", 50, 60, 70, 180};
    
    // Перенаправляем stdout в файл (или mock)
    freopen("test_output.txt", "w", stdout);
    printStudentInfo(s);
    fclose(stdout);
    
    // Читаем файл и проверяем вывод
    FILE *f = fopen("test_output.txt", "r");
    char buf[256];
    fgets(buf, sizeof(buf), f);
    fclose(f);
    
    // Проверяем, что строка содержит нужные данные
    assert_true(strstr(buf, "Test") != NULL);
    assert_true(strstr(buf, "50") != NULL);
    assert_true(strstr(buf, "180") != NULL);
    
    // Удаляем временный файл
    unlink("test_output.txt");
}

int main(void) {
    const struct CMUnitTest tests[] = {  // <- Исправлено на CMUnitTest
        cmocka_unit_test(test_getMaxTotal),
        cmocka_unit_test(test_addStudent),
        cmocka_unit_test(test_radixSort),
        cmocka_unit_test(test_countingSort),
        cmocka_unit_test(test_printStudentInfo),
    };
    
    return cmocka_run_group_tests(tests, NULL, NULL);
}