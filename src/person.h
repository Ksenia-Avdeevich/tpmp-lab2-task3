#ifndef PERSON_H
#define PERSON_H

#define MAX_STR 64

typedef struct {
    int year;
    int month;
    int day;
} BirthDate;

typedef struct {
    char postal_code[16];
    char country[MAX_STR];
    char region[MAX_STR];
    char district[MAX_STR];
    char city[MAX_STR];
    char street[MAX_STR];
    int  house;
    int  apartment;
} Address;

typedef struct {
    char      last_name[MAX_STR];
    char      first_name[MAX_STR];
    char      middle_name[MAX_STR];
    char      gender[16];
    char      nationality[MAX_STR];
    float     height;
    float     weight;
    BirthDate birth;
    char      phone[32];
    Address   address;
} Person;

void print_person(const Person *p);
int  compare_age(const Person *a, const Person *b);
const Person *find_youngest(const Person arr[], int n);

#endif /* PERSON_H */
