#include <stdio.h>
#include <string.h>
#include "group.h"
#include "person.h"

int main(void) {
    /* структура GROUP */
    printf("GROUP structure demo \n");

    GROUP gr5[MAX_STUDENTS] = {
        {"Ivanov I.I.",   {1993, 3, 15}, {4, 5, 4}},
        {"Petrov P.P.",   {1991, 6, 20}, {3, 3, 4}},
        {"Sidorov S.S.",  {1990, 11, 1}, {5, 4, 5}},
        {"Kozlov K.K.",   {1992, 8, 10}, {3, 4, 3}},
        {"Morozov M.M.",  {1994, 2, 28}, {4, 4, 4}},
        {"Sokolov S.S.",  {1989, 5, 5},  {5, 5, 5}},
        {"Novikov N.N.",  {1995, 7, 14}, {3, 3, 3}},
        {"Volkov V.V.",   {1988, 12, 31},{4, 5, 4}},
        {"Lebedev L.L.",  {1996, 1, 22}, {3, 4, 4}},
        {"Fedorov F.F.",  {1987, 9, 3},  {5, 4, 5}},
    };
    int n = MAX_STUDENTS;

    printf("\n--- All students ---\n");
    for (int i = 0; i < n; i++) print_student(&gr5[i]);

    printf("\n--- Sorted by GPA (ascending) ---\n");
    sort_by_ses(gr5, n);
    for (int i = 0; i < n; i++) print_student(&gr5[i]);

    printf("\n--- Students under 20 on 01.12.2010 ---\n");
    print_young_students(gr5, n);

    /* структура «Человек»*/
    printf("\n=== PERSON structure demo ===\n");

    Person people[] = {
        {
            "Ivanov", "Ivan", "Ivanovich",
            "Male", "Russian", 178.0f, 75.0f,
            {1990, 5, 15}, "+375-29-000-00-01",
            {"220000", "Belarus", "Minsk region", "Minsk district",
             "Minsk", "Lenina", 1, 10}
        },
        {
            "Petrov", "Petr", "Petrovich",
            "Male", "Russian", 182.0f, 80.0f,
            {2002, 3, 22}, "+375-29-000-00-02",
            {"220001", "Belarus", "Minsk region", "Minsk district",
             "Minsk", "Mira", 5, 20}
        },
        {
            "Sidorova", "Anna", "Ivanovna",
            "Female", "Belarusian", 165.0f, 55.0f,
            {1998, 11, 1}, "+375-29-000-00-03",
            {"220002", "Belarus", "Grodno region", "Grodno district",
             "Grodno", "Pobedy", 3, 7}
        },
    };
    int np = sizeof(people) / sizeof(people[0]);

    const Person *youngest = find_youngest(people, np);
    printf("Youngest person:\n");
    if (youngest) print_person(youngest);

    return 0;
}
