#include "studentInfo.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void print()
{
   printf("\n=== STUDENT DATABASE MENU ===\n");
   printf("1. Add New Student\n");
   printf("2. Display All Students\n");
   printf("3. Search Student by ID\n");
   printf("4. Update Student GPA\n");
   printf("5. Delete a Student\n");
   printf("6. Delete File\n");
   printf("7. Save and Exit\n");
}

int addStudent(studentInfo *replace)
{
 char symbol = '\0';
 do
  {
  printf("Enter your name: ");
  fgets(replace->studentName, sizeof(replace->studentName), stdin);
  replace->studentName[strcspn(replace->studentName, "\n")] = '\0';
  printf("Enter your student ID: ");
  scanf("%10s", replace->studentID);
  printf("Enter your contact info: ");
  scanf("%19s", replace->contactInfo);  
  printf("Would you like to add another student? Y[es] or N[o]: ");
  scanf(" %c", &symbol);
  if(!(symbol == 'Y' || symbol == 'y')) 
  {
  break;
  }
 }
 while(true);
return 0;
}

int displayAllStudents(studentInfo *replace)
{
FILE * open_file;
open_file = fopen("storage/studentdb.txt", "r");
if(open_file == NULL)
{
 puts("Display error, no information in the file");
 return 1;
}
while(fscanf(open_file, "Name: %s\nStudent ID: %s\nContact Information: %s\n", replace->studentName, replace->studentID, replace->contactInfo) == 3)
{
 printf("Name: %s\nStudent ID: %s\nContact Information: %s\n", replace->studentName, replace->studentID, replace->contactInfo);
}
fclose(open_file);
puts("");
return 0;
}

int searchStudent(studentInfo *replace)
{
 return 0;
}

int updateStudent(studentInfo *replace)
{
return 0;
}

int deleteStudent(studentInfo *replace)
{
return 0;
}

int deleteFile(studentInfo *replace)
{
if(remove("studentdb.txt") == 0)
{
 puts("File deleted successfully");
}
else
{
puts("Error deleting file: No such file exist");

}
}

int saveAndExit(studentInfo *replace)
{
 FILE * save_file;
save_file = fopen("storage/studentdb.txt", "a");
if(save_file == NULL)
{
 puts("Error saving file");
 return 1;
}
fprintf(save_file, "Name: %s\nStudent ID: %s\nContact Information: %s\n", replace->studentName, replace->studentID, replace->contactInfo);
fclose(save_file);
puts("Information saved to studentdb.txt");
return 0;
}

