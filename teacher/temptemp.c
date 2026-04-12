#include <stdio.h>

int main(void){
    printf("1\n4\n500000\n");
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 500000;j++){
            printf("1 ");
        }
        printf("\n");
    }
}