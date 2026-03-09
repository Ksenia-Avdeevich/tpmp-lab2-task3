#include <stdio.h>
#include <stdlib.h>
#include "group.h"
#include "person.h"

#define NUM_PERSONS 3

int main(void) {
    /* Задача 3: структура GROUP */
    int n;
    printf("GROUP structure demo\n");
    printf("Enter number of students (1-%d): ", MAX_STUDENTS);
    scanf("%d", &n);
    if (n < 1 || n > MAX_STUDENTS) n = MAX_STUDENTS;

    GROUP gr5[MAX_STUDENTS];
    for (int i = 0; i < n; i++) input_student(&gr5[i], i);

    printf("\nSorted by GPA (ascending)\n");
    sort_by_ses(gr5, n);
    for (int i = 0; i < n; i++) print_student(&gr5[i]);

    printf("\nStudents under 20 on 01.12.2010\n");
    print_young_students(gr5, n);

    /* Задача 4: структура «Человек»*/
    printf("\n=== PERSON structure demo ===\n");
    Person people[NUM_PERSONS] = {
        {"Ivanov",  "Ivan",  "Ivanovich",  "Male",   "Russian", 178, 75,
         {1990, 5, 15}, "+7-900-000-0001",
         {"220000", "Belarus", "Minsk region", "Minsk district",
          "Minsk", "Lenina", 1, 10}},
        {"Petrov",  "Petr",  "Petrovich",  "Male",   "Russian", 182, 80,
         {2002, 3, 22}, "+7-900-000-0002",
         {"220001", "Belarus", "Minsk region", "Minsk district",
          "Minsk", "Mira", 5, 20}},
        {"Sidorova","Anna",  "Ivanovna",   "Female", "Russian", 165, 55,
         {1998, 11, 1}, "+7-900-000-0003",
         {"220002", "Belarus", "Minsk region", "Minsk district",
          "Minsk", "Pobedy", 3, 7}},
    };

    const Person *youngest = find_youngest(people, NUM_PERSONS);
    printf("Youngest person:\n");
    if (youngest) print_person(youngest);

    return 0;
}
