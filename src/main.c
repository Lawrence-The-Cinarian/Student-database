#include "../library/database.h"


int main(void)
{
    Register student;
    int option = 0;
    char character = '\0';
    
    do
    {
        print();
        printf("Enter your choice from the number above: ");
        scanf("%d", &option);
        
        switch(option)
        {
            case 1:
            addStudents(&student);
            break;
            
            case 2:
            viewAllStudents(&student);
            break;
            
            case 3:
            searchStudent(&student);
            break;
            
            case 4:
            break;
            
            case 5:
            break;
            
            case 6:
            saveToFile(&student);
            break;
            
            case 7:
            deleteFile();
            break;
            
            case 0:
            puts("Exiting....");
            puts(""); sleep(2);
            return 0;
            
            default:
            puts("Invalid option");
        }
        
        
        printf("Would you like to continue? Y[es] or N[o]: ");
        scanf(" %c", &character);
        if(!(character == 'Y' || character == 'y')) break;
    }
    while(true);
    return 0;
}