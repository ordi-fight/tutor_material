#include <stdio.h>
#include <string.h>
typedef struct word {
    char pattern[4];
    int cnt ;
}Word;
// try to 編號
// Word words[26 * 26 * 26];
// for(int i = 0;i < 26 * 26 * 26;i++){
//     words[i].pattern
// }

int main(){
    
    Word letter_arr[40000];
    char letter[100001];
    int size = 0;

    while(scanf("%s" , letter) != EOF){
        int len = strlen(letter);
        if (len == 3){
            if(size == 0){
                strcpy(letter_arr[0].pattern , letter);
                letter_arr[0].cnt = 1;
                size += 1;
            }
            else{
                int i ;
                for(i = 0 ; i < size ; i++){
                    if (!strcmp(letter_arr[i].pattern , letter)){
                        letter_arr[i].cnt += 1;
                        break;
                    }
                }
                if(i == size){
                    strcpy(letter_arr[size].pattern , letter);
                    letter_arr[size].cnt = 1;
                    size += 1;
                }
            }
        }
        
        else if (len > 3){
            char pattern_candi[4];
            for(int i = 0 ; i < len - 2 ; i++){
                for(int j = 0 ; j < 3 ; j++){
                    pattern_candi[j] = letter[i+j]; 
                }
                
                pattern_candi[3] = '\0';
                printf("pattern_candi = %s\n" , pattern_candi);
                int k ;
                for(k = 0 ; k < size ; k++){
                    if (!strcmp(letter_arr[k].pattern , pattern_candi)){
                        letter_arr[k].cnt += 1;
                        break;
                    }
                }
                if(k == size){
                    strcpy(letter_arr[size].pattern , pattern_candi);
                    letter_arr[size].cnt = 1;
                    size += 1;
                }
                for(int j = 0 ; j < 3 ; j++){
                    pattern_candi[i] = '\0';
                }
                
            }
            
        }
    char pattern_candi[4];
        for(int i = 0 ; i < len - 2 ; i++){
            for(int j = 0 ; j < 3 ; j++){
                pattern_candi[j] = letter[i+j]; 
            }
            
            pattern_candi[3] = '\0';
            printf("pattern_candi = %s\n" , pattern_candi);
            int k ;
            for(k = 0 ; k < size ; k++){
                if (!strcmp(letter_arr[k].pattern , pattern_candi)){
                    letter_arr[k].cnt += 1;
                    break;
                }
            }
            if(k == size){
                strcpy(letter_arr[size].pattern , pattern_candi);
                letter_arr[size].cnt = 1;
                size += 1;
            }
            for(int j = 0 ; j < 3 ; j++){
                pattern_candi[i] = '\0';
            }
            
        }
    for(int i = 0 ; i < size ; i++){
        printf("%d" , i);
        printf( "%s ", letter_arr[i].pattern);
        printf( "%d\n", letter_arr[i].cnt);

    }
    printf("-----------------\n");
    }

    


}