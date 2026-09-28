#ifndef STUDENTINFO_H
#define STUDENTINFO_H

typedef struct
{
char studentName[40];
char studentID[11];
char contactInfo[20];
} studentInfo;

void print();
int addStudent(studentInfo *replace);
int displayAllStudents(studentInfo *replace);
int searchStudent(studentInfo *replace);
int updateStudent(studentInfo *replace);
int deleteStudent(studentInfo *replace);
int deleteFile(studentInfo *replace);
int saveAndExit(studentInfo *replace);

#endif
