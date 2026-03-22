#include <stdio.h>
#include <string.h>


int main(){
    int i = 0;
    char s[] = "abcd\0";
    while(i < strlen(s)){
        s[i] = '\0';
        i++;
    }
    printf("%d" , i);
}