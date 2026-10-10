#ifndef DATABASE_H
#define DATABASE_H

typedef struct
{
char studentName[40];
char studentID[15];
char phoneNumber[15];
float gpa;
} Profile;

void print();
int add_a_new_student(Profile *replace);
int display_all_students(Profile *replace);

#endif
