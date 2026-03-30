#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int num1[1024] = {};
int num2[1024] = {};
int len1 = 0, len2 = 0;

void readInput(){
    char str1[1024], str2[1024];
    scanf("%s%s", str1, str2);
    len1 = strlen(str1);
    len2 = strlen(str2);

    for(int i = 0;i < len1;i++)
        num1[i] = str1[len1 - i - 1] - '0';

    for(int i = 0;i < len2;i++)
        num2[i] = str2[len2 - i - 1] - '0';
}

int cmpNum(){
    if(len1 < len2)
        return -1;
    else if(len1 > len2)
        return 1;
    
    for(int i = len1 - 1;i >= 0;i--){
        if(num1[i] > num2[i])
            return 1;
        else if(num1[i] < num2[i])
            return -1;
    }
    return 0;
}

void cut(int *max, int *min, int *len){
    bool addten = false;
    for(int i = 0;i < *len;i++){
        if(addten){
            max[i] -= 1;
            addten = false;
        }
        max[i] = max[i] - min[i];
        if(max[i] < 0){
            addten = true;
            max[i] += 10;
        }
    }

    while(*len > 0 && max[*len - 1] == 0)
        *len -= 1;
}

void printNum(int *num, int len){
    for(int i = 0;i < len;i++)
        printf("%d", num[len - i - 1]);
    printf("\n");
}

void printGCD(){
    int cnt2 = 0;
    int cmp;

    while((cmp = cmpNum()) != 0){
        if(cmp == 1)
            cut(num1, num2, &len1);
        else if(cmp == -1)
            cut(num2, num1, &len2);
    }

    printNum(num1, len1);
}

int main(void){
    readInput();
    printGCD();
}