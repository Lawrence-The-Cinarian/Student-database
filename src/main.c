#include <stdio.h>
#include <stdbool.h>
#include "../library/database.h"

int main(void)
{
Profile profile;
int option = 0;
char sym = '\0';
/*---------------------------------------------------------------*/
do
{
print();
printf("Enter your choice (1-6): ");
scanf("%d", &option);
(void)getchar();
switch(option)
{
case 1:
addANewStudent(&profile);
break;

case 2:
displayAllStudents(&profile);
break;

case 3:
puts("C");
break;

case 4:
puts("D");
break;

case 5:
puts("E");
break;

case 6:
saveAndExit(&profile);
return 0;

default:
puts("Invalid option");
}
printf("Would you like to continue? Y[es] or N[o]: ");
scanf(" %c", &sym);
if(!(sym == 'Y' || sym == 'y'))
{
break;
}
}
while(true);
return 0;
}
