#include "../library/library.h"
#include <stdio.h>
#include <stdbool.h>


int main(void)
{
 int a = 0;
 studentInfo profile;

do
{
 print();
 printf("Enter Choice:");
 scanf("%d", &a);
 (void)getchar();

 switch(a)
 {
   case 1:
   addStudent(&profile);
   break;
   
   case 2:
   displayAllStudents(&profile);
   break;
   
   case 3:
   searchStudent(&profile);
   break;
   
   case 4:
   updateStudent(&profile);
   break;
   
   case 5:
   deleteStudent(&profile);
   break;
   
   case 6:
   deleteFile(&profile);
   break;
   
   case 7:
   saveAndExit(&profile);
   return 0;
   
   default:
   puts("Invalid Option");

 }
}
while(true);
 return 0;
}
