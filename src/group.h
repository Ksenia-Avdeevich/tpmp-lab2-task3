#ifndef GROUP_H
#define GROUP_H

#define MAX_STUDENTS 10
#define MAX_SUBJECTS 3
#define MAX_NAME_LEN 64

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    char name[MAX_NAME_LEN];   /* Фамилия и инициалы */
    Date dat;                  /* Дата рождения */
    int ses[MAX_SUBJECTS];     /* Успеваемость (3 оценки) */
} GROUP;

void input_student(GROUP *s, int index);
void print_student(const GROUP *s);
void sort_by_ses(GROUP arr[], int n);
void print_young_students(const GROUP arr[], int n);

#endif /* GROUP_H */
