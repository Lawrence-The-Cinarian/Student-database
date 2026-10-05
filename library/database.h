#ifndef DATABASE_H
#define DATABASE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct
{
    char name[50];
    char id[20];
    double score;
} Register;

void print();
int addStudents(Register *replace);
int viewAllStudents(Register *replace);
int searchStudent(Register *replace);
int updateStudent(Register *replace);
int saveToFile(Register *replace);
int deleteFile();

#endif