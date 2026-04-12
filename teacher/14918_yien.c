#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int cmp(const void * a , const void * b){
    int * ia = (const void *) a;
    int * ib = (const void *) b;
    return *ia - *ib ;
}

void sort_array(const int len, int arr[]){
    qsort(arr , len , sizeof(int) , cmp);
}

long long number_of_pairs_less_than_k(const int len, const int *arr[2], const int k){
    int idx = len - 1 ; long long int  num = 0;
    for(int i = 0 ; i < len ; i++){ 
        while (idx >= 0 && arr[0][i] + arr[1][idx] >= k){   
            idx--;
            
        }
        num += (idx + 1);
        
    }
    return num;
}
long long number_of_pairs_less_than_or_equal_to_k(const int len, const int *arr[2], const int k){
    int idx = len - 1 ; long long int  num = 0;
    for(int i = 0 ; i < len ; i++){ 
        while (idx >= 0 && arr[0][i] + arr[1][idx] > k){   
            idx--;
            
        }
        num += (idx + 1);
        
    }
    return num;
}
    
long long number_of_valid_average_scores(const int len, const int *arr[3]){
    long long f1[5001] = {}, f2[5001] = {}, f3[5001] = {};
    for(int i = 0;i < len;i++){
        f1[arr[0][i]] += 1;
        f2[arr[1][i]] += 1;
        f3[arr[2][i]] += 1;
    }

    long long ans = 0;
    for(int i = 1;i < 5001;i++){
        for(int j = 1;j < 5001;j++){
            if((i + j) % 2 == 0)
                ans += f1[i] * f2[j] * f3[(i + j) / 2];
        }
    }

    return ans;
}

long long number_of_valid_average_scores_N2(const int len, const int *arr[3]){
    long long hash[5001] = {};
        for(int j = 0;j < len;j++)
            hash[arr[0][j]] += 1;
    long long ans = 0;
    for(int i = 0;i < len;i++){
        int target = arr[2][i] * 2;
        for(int j = 0;j < len;j++){
            if(target - arr[1][j] > 0 && target - arr[1][j] <= 5000)
                ans += hash[target - arr[1][j]];
        }
    }
    return ans;
}