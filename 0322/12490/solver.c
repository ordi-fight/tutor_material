#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "function.h"

int toNUM(char* num_str){
    int i;
    for(i = 0 ; i < strlen(num_str) ; i++){

        if ('0' < num_str[i] && num_str[i] <= '9' || num_str[i] == '-'){
            return atoi(num_str + i);
        }
    }
    return 0 ;
    
}

int solver(int **ptr, int *sum, char *s){
    int slen = strlen(s) , idx = 0 , aidx =  0 ;
    char num_str[slen];
    num_str[0] = '\0';
    for(int i = 0 ; i < slen ; i++){
        if ( '0' <= s[i] && s[i] <= '9'){  
            num_str[idx] = s[i];
            idx += 1;
            // printf("i: %d idx: %d num_str: %s\n" ,i , idx , num_str);
            
        }
        else if (s[i] == '-' && (i + 1) < slen && '0' <= s[i + 1] && s[i + 1] <= '9'){
            if (num_str[0] != '\0'){
                num_str[idx] = '\0';
                **(ptr + aidx) = toNUM(num_str);
                aidx += 1;
                int len = strlen(num_str);
                for(int j = 0 ; j < len ; j++){
                    num_str[j] = '\0';
                }
                // printf("i : %d num_str: %s **(ptr + aidx - 1): %d aidx : %d \n" ,i  , num_str , **(ptr + aidx - 1) , aidx );
            }    
            idx = 0;
            num_str[idx] = s[i];
            idx += 1;
            // printf("i: %d idx: %d num_str: %s \n" ,i , idx , num_str);
      

            
        }
        else {
            if (num_str[0] != '\0'){
                **(ptr + aidx) = toNUM(num_str);
                aidx += 1;
                int len = strlen(num_str);
                for(int j = 0 ; j < len; j++){
                    num_str[j] = '\0';
                }
                idx = 0;
            // }
            // printf("i: %d idx: %d num_str: %s **(ptr + aidx - 1): %d aidx: %d n_num: %d \n" ,i , idx , num_str , **(ptr + aidx) , aidx , n_num);
        }
    }
}
    if (num_str[0] != '\0'){
        **(ptr + aidx) = toNUM(num_str);
        aidx += 1;
    }
    for(int i = 0 ; i < aidx ; i++){
        *sum += **(ptr + i);
    }
    return aidx;

}
