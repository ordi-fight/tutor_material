#include <stdio.h>
#include <string.h>

char s[100000000];

int str_len(char * s){
    int len = 0;
    while(s[len] != '\0'){
        len += 1;

    }
    return len;
}



int main(void){
    for(int i = 0;i < 100000000;i++)
        s[i] = '0';
    s[100000000 - 1] = '\0';
    
    // printf("%ld" , strlen(s));
    // int i ;
    // for(i = 0 ; i <= 99999999 ; i++){
    //     continue;
    // }
    // printf("%d" , i);
    int len  = str_len(s);
    int x = 0;
    for(int i = 0;i < len ;i++)
        x += 1;
    printf("%d\n", x);
}