#ifndef DATABASE_H
#define DATABASE_H

typedef struct
{
char studentName[40];
char studentID[15];
char phoneNumber[15];
} Profile;

void print();
int addANewStudent(Profile *replace);

#endif
