#include <stdio.h>


int main(){
    int R , C;
    scanf("%d %d\n" , &R , &C);
    int mat[R][C];
    for(int r = 0 ; r < R ; r++){
        for(int c = 0 ; c < C ; c++){
            scanf("%d" , &mat[r][c]);
        }
    }
    int oper , k;
    int reduct_r = 0 , reduct_c = 0;
    while(scanf("%d %d" , &oper , &k) !=  EOF){
      // printf("%d %d" , oper , k);
        if(oper == 1){
            
            for(int r = 0 ; r < k; r++){
                for(int c = 0; c < C ; c++){
                    mat[2*k - 1 - r + reduct_r][c] += mat[r + reduct_r][c];
                }
            }
            reduct_r += k;
            
            
        }
        else if(oper == 2){
          int i;
            for(int r = 0 ; r < R; r++){
                i = k;
                for(int c = 0 ; c <  k ; c++){
                  
                    mat[r][(C - reduct_c) - c - 2*i ] += mat[r][(C - reduct_c) - c - 1];
                    i--;
                }
            }
            reduct_c += k;
        }
        else if(oper == 3){
            int i = 0;
            for(int r = 0 ; r < R ; r++){
                for(int c = C - 1 ; c > C - k + i; c--){

                    mat[(r+c) - (C - k  + r) + reduct_r ][C - k  + r - reduct_c] += mat[r + reduct_r][c - reduct_c];
                    mat[r + reduct_r][c - reduct_c] = 0;
                    
                    
                }
                i++;
            }
        }
    }
    // printf("%d\n" , reduct_c);
    for(int r = reduct_r ; r < R ; r++){
        for(int c = 0 ; c < C - reduct_c; c++){

            printf("%d " , mat[r][c]);
            
            
        }
        printf("\n");

    }

}
