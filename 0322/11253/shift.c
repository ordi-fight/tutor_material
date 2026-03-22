#include <stdio.h>
#include <string.h>
#include "function.h" // .h in online judge called function.h
void shift(char *start, char *end){
    int len = (end - start) / 1;
    char start_val = *start;
    for(int i = 0 ; i < len ; i++){
       
        *(start + i) = *(start + (i + 1) );
        
    }
    *end = start_val;
}

