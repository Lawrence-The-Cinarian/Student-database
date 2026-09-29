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
  printf("Enter student name: ");
  fgets(replace->studentName, sizeof(replace->studentName), stdin);
  replace->studentName[strcspn(replace->studentName, "\n")] = '\0';
  (void)getchar();
  printf("Enter student ID: ");
  scanf("%14s", replace->studentID);
  printf("Enter student phone number: ");
  scanf("%14s", replace->phoneNumber);
 puts("");
 printf("Would you like to continue? Y[es] or N[o]: ");
 scanf(" %c", &sym);
if(!(sym == 'Y' || sym == 'y'))
{
break;
}
 }
  while(true);

}
