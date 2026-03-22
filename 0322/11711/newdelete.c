#include<stdio.h>
#include <stdlib.h>
#include"function.h"

unsigned*** new_3d_array(unsigned n,unsigned m,unsigned k){
    unsigned ***p0a = malloc(sizeof(unsigned**)*n);
    unsigned **p1a = malloc(sizeof(unsigned*)*(n*m));
    unsigned *p2a = malloc(sizeof(unsigned)*(n*m*k));
    for(int i = 0 ; i < n;i++){
        *(p0a + i) = p1a + (i*m);
        for(int j = 0 ; j < m; j++){
            *(p1a + m*i + j ) = p2a + m*k*i + k*j;
        }
    }

    return p0a;
}
// you should skip something to avoid overwriting
void delete_3d_array(unsigned ***arr){
    free(arr[0][0]);
    free(arr[0]);
    free(arr);
    arr = NULL; // avoid Dangling Pointer
}

unsigned*** new_3d_array(unsigned n,unsigned m,unsigned k){
    unsigned ***p0a = malloc(sizeof(unsigned**)*n);
    unsigned **p1a = malloc(sizeof(unsigned*)*(n*m));
    unsigned *p2a = malloc(sizeof(unsigned)*(n*m*k));
    for(int i = 0 ; i < n;i++){
        *(p0a + i) = p1a + (i*m);
        for(int j = 0 ; j < m; j++){
            *(p1a + m*i + j ) = p2a + m*k*i + k*j;
        }
    }

    return p0a;
}
// you should skip something to avoid overwriting
void delete_3d_array(unsigned ***arr){
    free(arr[0][0]);
    free(arr[0]);
    free(arr);
    arr = NULL; // avoid Dangling Pointer
}