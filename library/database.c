#include "database.h"

int count = 0;

void print()
{
    puts("");
    puts("===== Student Database =====");
    puts("Please note that you have to save files inorder to view students' records");
    puts("");
    puts("(1) Add students");
    puts("(2) View all students");
    puts("(3) Search student");
    puts("(4) Update student");
    puts("(5) Delete student");
    puts("(6) Save to file");
    puts("(7) Delete file");
    puts("(0) Exit");
    puts("");
}

/*--------------------------------------------------------*/

int addStudents(Register *replace) //Number 1;
{
    printf("How many students are registering? ");
    scanf("%d", &count);
    puts("");
    
    for(int i = 0; i < count; i++)
    {
        printf("Enter student name: ");
        scanf("%49s", replace[i].name);
        printf("Enter student ID: ");
        scanf("%19s", replace[i].id);
        printf("Enter score: ");
        scanf("%d", &replace[i].score);
        puts("");
    }
    return count;
}

/*--------------------------------------------------------*/

int viewAllStudents(Register *replace) //Number 2;
{
    FILE *file = 0;
    int b = 0;
    file = fopen("src/student_data.txt", "r");
    if(file == NULL)
    {
        puts("Error encountered while viewing contents from the file ❌");
        return 1;
    }
    while(fscanf(file, "%49s %19s %d\n", replace[b].name, replace[b].id, &replace[b].score) == 3)
    {
        printf("Name: %s\nID: %s\nScore: %d\n\n", replace[b].name, replace[b].id, replace[b].score);
    }
    fclose(file);
    return 0;
}

/*--------------------------------------------------------*/

int searchStudent(Register *replace)
{
    char target[50];
    int b = 0;
    FILE *file = 0;
    file = fopen("src/student_data.txt", "r");
    if(file == NULL)
    {
        puts("Error opening file");
        return 1;
    }
    
    printf("Enter name of student: ");
    scanf("%49s", target);
    while(fscanf(file, "%49s %19s %d\n", replace[b].name, replace[b].id, &replace[b].score) == 3)
    {
        if(strcmp(replace[b].name, target) == 0)
        {
             printf("Name: %s\nID: %s\nScore: %d\n\n", replace[b].name, replace[b].id, replace[b].score);
        } else {
             puts("No Information about this particular student in the database");
             return 1;
        }
    }
    fclose(file);
    return 0;
}

/*--------------------------------------------------------*/

int saveToFile(Register *replace) //Number 6
{
    FILE *file = 0;
    file = fopen("src/student_data.txt", "a");
    if(file == NULL)
    {
        puts("Error encountered while opening file ❌");
        return 1;
    }
    for(int a = 0; a < count; a++)
    {
        fprintf(file, "%s %s %d\n", replace[a].name, replace[a].id, replace[a].score);
    }
    fclose(file);
    puts("File successfully saved ✅");
    return 0;
}

/*--------------------------------------------------------*/

int deleteFile()
{
    if(remove("src/student_data.txt") == 0)
    {
        puts("");
        puts("File successfully deleted");
        return 1;
    } else {
        puts("");
        puts("Error encountered while deleting file");
        return 0;
    }
}