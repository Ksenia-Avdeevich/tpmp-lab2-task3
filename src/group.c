#include "group.h"
#include <stdio.h>
#include <string.h>

void input_student(GROUP *s, int index) {
    printf("Student %d\n", index + 1);
    printf("  Name (Last F.I.): ");
    scanf(" %63[^\n]", s->name);
    printf("  Birth date (YYYY MM DD): ");
    scanf("%d %d %d", &s->dat.year, &s->dat.month, &s->dat.day);
    printf("  Grades (3 values): ");
    for (int i = 0; i < 3; i++) scanf("%d", &s->ses[i]);
}

void print_student(const GROUP *s) {
    printf("  %-20s | %04d-%02d-%02d | Grades: %d %d %d\n",
           s->name, s->dat.year, s->dat.month, s->dat.day,
           s->ses[0], s->ses[1], s->ses[2]);
}

/* Среднее значение успеваемости */
static double avg_ses(const GROUP *s) {
    return (s->ses[0] + s->ses[1] + s->ses[2]) / 3.0;
}

/* Сортировка пузырьком по avg_ses */
void sort_by_ses(GROUP arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (avg_ses(&arr[j]) > avg_ses(&arr[j + 1])) {
                GROUP tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

/* Вывод студентов моложе 20 лет на 01.12.2010 */
void print_young_students(const GROUP arr[], int n) {
    int found = 0;
    /* Реферная дата: 01.12.2010 */
    int ref_year = 2010, ref_month = 12, ref_day = 1;
    for (int i = 0; i < n; i++) {
        int age = ref_year - arr[i].dat.year;
        if (arr[i].dat.month > ref_month ||
            (arr[i].dat.month == ref_month && arr[i].dat.day > ref_day)) {
            age--;
        }
        if (age < 20) {
            print_student(&arr[i]);
            found++;
        }
    }
    if (!found) {
        printf("  No students younger than 20 years found.\n");
    }
}

