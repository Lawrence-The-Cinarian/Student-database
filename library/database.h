#ifndef DATABASE_H
#define DATABASE_H

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct
{
    char name[50];
    char id[20];
    int score;
} Register;

void print();
int addStudents(Register *replace);
int viewAllStudents(Register *replace);
int saveToFile(Register *replace);
int deleteFile(Register *replace);

#endif