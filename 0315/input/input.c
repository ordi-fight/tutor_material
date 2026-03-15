#include <stdio.h>


int main(){
    int R , C;
    // input %s , output %s
    scanf("%d%d" , &R , &C);
    char mat[R][C+1];
    for(int r = 0 ; r < R ; r++){

        scanf("%s" , mat[r]);
        
    }
    for(int r = 0 ; r < R ; r++){
        printf("%s\n" , mat[r]);
    }

    // input %s , output %c
    scanf("%d%d" , &R , &C);
    char mat[R][C+1];
    for(int r = 0 ; r < R ; r++){

        scanf("%s" , mat[r]);
    }
    for(int r = 0 ; r < R ; r++){
        for(int c = 0 ; c < C ; c++){
            printf("%c" , mat[r][c]);
        }
        printf("\n");
    }
    // input % c , output %s
    scanf("%d%d" , &R , &C);
    getchar();
    char mat[R][C+2];
    for(int r = 0 ; r < R ; r++){
        for(int c = 0 ; c < C + 1; c++){
            scanf("%c" , &mat[r][c]);
        }
        mat[r][C+1] = '\0';
       
        // if (mat[r][C] == '\n'){
        //     mat[r][C + 1] = '\0';
        // }
        // else{
        //     mat[r][C] = '\0';
        // }
        
    }
    mat[R - 1][C] = '\0';
    if(mat[2][3] == '\0')
        printf("yes\n");
    for(int r = 0 ; r < R ; r++){
        
        printf("%s" , mat[r]);
        
    }
    printf("\n");

    // input %c , output %c
    scanf("%d%d" , &R , &C);
    getchar();
    char mat[R][C+1];
    for(int r = 0 ; r < R ; r++){
        for(int c = 0 ; c < C + 1 ; c++){
            scanf("%c" , &mat[r][c]);
        }
    }
    mat[R - 1][C] = '\0';
    for(int r = 0 ; r < R ; r++){
        for(int c = 0 ; c < C+1 ; c++){
            printf("%c" , mat[r][c]);
        }
    } 
}