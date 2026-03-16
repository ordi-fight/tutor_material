#include <stdio.h>
#include <string.h>

int toNum(char str[]){
    int num = 0;

    num = (str[0] - 'a') * 26 * 26 + (str[1] - 'a') * 26 + (str[2] - 'a');
    return num;
}

void toStr(int num, char str[]){
    str[2] = (num % 26) + 'a';
    num /= 26;
    str[1] = (num % 26) + 'a';
    num /= 26;
    str[0] = (num % 26) + 'a';
    str[3] = '\0';

    return;
}

int main(void){
    int cnt[26 * 26 * 26] = {};
    char str[100001];

    while(scanf("%s", str) != EOF){
        int length = strlen(str);

        for(int i = 0;i < length - 3 + 1;i++){
            int num = toNum(&str[i]);
            cnt[num] += 1;
        }

        for(int i = 0;i < length;i++)
            str[i] = '\0';
    }

    int max[3] = {-1, -1, -1};
    int maxIndex[3] = {-1, -1, -1};

    for(int i = 0;i < 26 * 26 * 26;i++){
        if(cnt[i] > max[0]){
            max[2] = max[1];
            max[1] = max[0];
            max[0] = cnt[i];

            maxIndex[2] = maxIndex[1];
            maxIndex[1] = maxIndex[0];
            maxIndex[0] = i;
        }
        else if(cnt[i] > max[1]){
            max[2] = max[1];
            max[1] = cnt[i];

            maxIndex[2] = maxIndex[1];
            maxIndex[1] = i;
        }
        else if(cnt[i] > max[2]){
            max[2] = cnt[i];

            maxIndex[2] = i;
        }
    }


    char temp[4];
    for(int i = 0;i < 3;i++){
        toStr(maxIndex[i], temp);
        printf("%s\n", temp);
    }
}