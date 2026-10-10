#include "../include/database.h"
#include "../include/flush.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define COLOR_BLUE "\x1b[34m"
#define DEFAULT "\x1b[0m"


void print(void)
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

int add_a_new_student(Profile *replace)
{
 char sym = '\0';
 do
  {
   printf("Enter student name: ");
   fgets(replace->studentName, sizeof(replace->studentName), stdin);
   printf("Enter student ID: ");
   scanf("%14s", replace->studentID);
   printf("Enter student phone number: ");
   scanf("%14s", replace->phoneNumber);
   printf("Enter student GPA: ");
   scanf("%f", &replace->gpa);
   flush();
   puts("");
   printf("Would you like to continue adding more students? Y[es] or N[o]: ");
   scanf(" %c", &sym);
   flush();
   if(!(sym == 'Y' || sym == 'y'))
    {
     break;
    } 
  }
  while(true);
  return 0;
}

/*----------------------------------------------------------------------------------------------------*/

int display_all_students(Profile *replace)
{
  FILE *display_content = 0;
  display_content = fopen("src/data.txt", "r");
  if(display_content == NULL)
  {
    puts("Error opening file, File doesn't exist!");
    return 1;
  }

  while(fscanf(display_content, "%39s %14s %14s %f\n", replace->studentName, replace->studentID, replace->phoneNumber, &replace->gpa) == 4)
  {
    printf("Name: %s\nID: %s\nPhone Number: %s\nGPA: %.2f\n\n", replace->studentName, replace->studentID, replace->phoneNumber, replace->gpa);
  }

  fclose(display_content);
  return 0;
}

/*----------------------------------------------------------------------------------------------------*/

/*int save_file(Profile *replace)
{
  FILE *save_content = 0;
  save_content = fopen("", "")
  return 0
}*/