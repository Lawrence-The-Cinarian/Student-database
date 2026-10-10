#include "../include/database.h"
#include "../include/flush.h"
#include <stdio.h>
#include <stdbool.h>



int main(void)
{
Profile profile = {0};
int option = 0;
char sym = '\0';

do
{
print();
printf("Enter your choice (1-6): ");
scanf("%d", &option);
flush();

switch(option)
{
case 1:
add_a_new_student(&profile);
break;

case 2:
display_all_students(&profile);
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
puts("F");
return 0;

default:
puts("Invalid option");
}
printf("Would you like to continue? Y[es] or N[o]: ");
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
