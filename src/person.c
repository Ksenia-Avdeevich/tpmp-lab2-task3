#include "person.h"
#include <stdio.h>

void print_person(const Person *p) {
    printf("  %s %s %s\n", p->last_name, p->first_name, p->middle_name);
    printf("  Gender: %s, Nationality: %s\n", p->gender, p->nationality);
    printf("  Height: %.1f cm, Weight: %.1f kg\n", p->height, p->weight);
    printf("  Birth: %04d-%02d-%02d\n",
           p->birth.year, p->birth.month, p->birth.day);
    printf("  Phone: %s\n", p->phone);
    printf("  Address: %s, %s, %s, %s, %s, %s, %d/%d\n",
           p->address.postal_code, p->address.country, p->address.region,
           p->address.district, p->address.city, p->address.street,
           p->address.house, p->address.apartment);
}

/* Возвращает 1, если a моложе b */
int compare_age(const Person *a, const Person *b) {
    if (a->birth.year != b->birth.year) return a->birth.year > b->birth.year;
    if (a->birth.month != b->birth.month) return a->birth.month > b->birth.month;
    return a->birth.day > b->birth.day;
}

const Person *find_youngest(const Person arr[], int n) {
    if (n == 0) return NULL;
    const Person *youngest = &arr[0];
    for (int i = 1; i < n; i++) {
        if (compare_age(&arr[i], youngest)) youngest = &arr[i];
    }
    return youngest;
}
