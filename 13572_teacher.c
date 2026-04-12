#include <stdio.h>
#include <string.h>

char str[1000001];
char ans[1000001];
int len;
int table[26];

void initData(){
    scanf("%s", str);
    len = strlen(str);
    for(int i = 0;i < 26;i++){
        table[i] = i;
    }
}

void buildTable(){
    int Q;
    char origin[4], target[4];

    scanf("%d", &Q);
    for(int i = 0;i < Q;i++){
        scanf("%s%s", origin, target);
        for(int i = 0;i < 26;i++){
            if(table[i] == origin[0] - 'a')
                table[i] = target[0] - 'a';
        }
    }
}

void transformStr(){

    for(int i = 0;i < len;i++)
        ans[i] = table[str[i] - 'a'] + 'a';
    ans[len] = '\0';
}

int main(void){
    initData();
    buildTable();
    transformStr();
    printf("%s\n", ans);
}