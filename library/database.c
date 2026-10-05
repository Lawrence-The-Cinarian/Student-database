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
    puts("(5) Save to file");
    puts("(6) Delete file");
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
        scanf("%lf", &replace[i].score);
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
    while(fscanf(file, "%49s %19s %lf\n", replace[b].name, replace[b].id, &replace[b].score) == 3)
    {
        printf("Name: %s\nID: %s\nScore: %.2f\n\n", replace[b].name, replace[b].id, replace[b].score);
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
    while(fscanf(file, "%49s %19s %lf\n", replace[b].name, replace[b].id, &replace[b].score) == 3)
    {
        if(strcmp(replace[b].name, target) == 0)
        {
             printf("Name: %s\nID: %s\nScore: %.2f\n\n", replace[b].name, replace[b].id, replace[b].score);
             return 1;
        } 
    }      
     puts("No Information about this particular student in the database");
    
    fclose(file);
    return 0;
}

/*--------------------------------------------------------*/

int updateStudent(Register *replace)
{
    FILE *file = 0;
    char target[50];
    int b = 0;
    int total = 0;
    int found = 0;

    file = fopen("src/student_data.txt", "r");
    if(file == NULL) { puts("Error opening file"); return 1; }

    
    while(fscanf(file, "%49s %19s %lf", replace[total].name, replace[total].id, &replace[total].score) == 3)
        total++;
    fclose(file);

    printf("Enter name of student to update: ");
    scanf("%49s", target);

    for(b = 0; b < total; b++)
    {
        if(strcmp(replace[b].name, target) == 0)
        {
            printf("Current -> Name: %s | ID: %s | Score: %.2f\n\n", replace[b].name, replace[b].id, replace[b].score);
            printf("New name: "); scanf("%49s", replace[b].name);
            printf("New ID: "); scanf("%19s", replace[b].id);
            printf("New score: "); scanf("%lf", &replace[b].score);
            found = 1;
            break;
        }
    }

    if(!found) { puts("Student not found"); return 1; }

    file = fopen("src/student_data.txt", "w");
    if(file == NULL) { puts("Error saving update"); return 1; }
    for(b = 0; b < total; b++)
        fprintf(file, "%s %s %.2f\n", replace[b].name, replace[b].id, replace[b].score);
    fclose(file);
    puts("Student updated successfully ✅");
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
        fprintf(file, "%s %s %.2f\n", replace[a].name, replace[a].id, replace[a].score);
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