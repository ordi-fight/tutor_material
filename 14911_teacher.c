#include <stdio.h>

void sort_array(const int len, int arr[]){
    for(int i = len - 1;i >= 0;i--){
        for(int j = 0;j < i;j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

long long number_of_pair_less_than_k(const int len, const int* arr[2], const int k){
    long long cnt = 0;
    long long idx1 = 0, idx2 = len - 1;
    for(idx1 = 0;idx1 < len;idx1++){
        while(idx2 >= 0 && arr[0][idx1] + arr[1][idx2] >= k)
            idx2 -= 1;
        cnt += idx2 + 1;
    }
    return cnt;
}