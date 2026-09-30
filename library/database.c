#include "database.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define COLOR_BLUE "\x1b[34m"
#define DEFAULT "\x1b[0m"


void print()
{
printf(COLOR_BLUE "\t\n=== STUDENT DATABASE MENU ===\n" DEFAULT);
printf("1. Add New Student\n");
printf("2. Display All Students\n");
printf("3. Search Student by ID\n");
printf("4. Update Student GPA\n");
printf("5. Delete a Student\n");
printf("6. Save and Exit\n");
}

/*----------------------------------------------------------------------------------------------------*/

int addANewStudent(Profile *replace)
{
 char sym = '\0';
 do
  {
  (void)getchar();
  printf("Enter student name: ");
  fgets(replace->studentName, sizeof(replace->studentName), stdin);
  replace->studentName[strcspn(replace->studentName, "\n")] = '\0';
  printf("Enter student ID: ");
  fgets(replace->studentID, sizeof(replace->studentID), stdin);
  replace->studentID[strcspn(replace->studentID, "\n")] = '\0';
  printf("Enter student phone number: ");
  fgets(replace->phoneNumber, sizeof(replace->phoneNumber), stdin);
  replace->phoneNumber[strcspn(replace->phoneNumber, "\n")] = '\0';
  puts("");
  printf("Would you like to add another student? Y[es] or N[o]: ");
  scanf(" %c", &sym);
  if(!(sym == 'Y' || sym == 'y'))
  {
  break;
  }
 }
 while(true);
return 0;
}

/*----------------------------------------------------------------------------------------------------*/

int displayAllStudents(Profile *replace)
{
 FILE *open_file = fopen("src/student_data.txt", "r");
 if(open_file == NULL)
 {
  puts("Error reading file!");
  return 1;
 }

 while(fscanf(open_file, "%39s %14s %14s", replace->studentName, replace->studentID, replace->phoneNumber) == 3)
 {
  printf("Name: %s\nStudent-ID: %s\nStudent phone number: %s\n\n", replace->studentName, replace->studentID, replace->phoneNumber);
 }
fclose(open_file);
return 0;
}

/*----------------------------------------------------------------------------------------------------*/

int saveAndExit(Profile *replace)
{
 FILE *save_file = fopen("src/student_data.txt", "a");
 if(save_file == NULL)
 {
  puts("Error saving file");
  return 1;
 }

 fprintf(save_file, "Name: %s\nStudent-ID: %s\nStudent phone number: %s\n\n", replace->studentName, replace->studentID, replace->phoneNumber);
 fclose(save_file);
 puts("Saved successfully");
return 0;
}
