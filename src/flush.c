#include "../include/flush.h"
#include <stdio.h>

int flush()
{
    do 
    { 
        int c; 
        while ((c = getchar()) != '\n' && c != EOF); 
    } 
    while (0);
    return 0;
}