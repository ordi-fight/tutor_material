#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct nnn {
    int child1;
    int child2;
} Node;

Node nodes[200001];
int idxTable[200001];
bool parent[200001];

int findRoot(int N){
    for(int i = 0; i <= N; i++)
        parent[i] = false;
    for(int i = 1; i <= N; i++){
        if(nodes[i].child1 != 0)
            parent[nodes[i].child1] = true;
        if(nodes[i].child2 != 0)
            parent[nodes[i].child2] = true;
    }
    for(int i = 1; i <= N; i++){
        if(!parent[i])
            return i;
    }
    return -1;
}

bool checkInAB(int idx, int l_idx, int r_idx){
    return (idx > l_idx && idx < r_idx);
}

bool checkPositionCorrect(int cur, int l_idx, int r_idx){
    int child1 = nodes[cur].child1, child2 = nodes[cur].child2;
    int cur_idx = idxTable[cur];

    if(child1 != 0 && !checkInAB(idxTable[child1], l_idx, r_idx))
        return false;
    if(child2 != 0 && !checkInAB(idxTable[child2], l_idx, r_idx))
        return false;

    if(child1 != 0 && child2 != 0){
        bool c1_left = checkInAB(idxTable[child1], l_idx, cur_idx);
        bool c2_left = checkInAB(idxTable[child2], l_idx, cur_idx);
        if(c1_left == c2_left)
            return false;
    }

    if(child1 != 0){
        bool c1_left = checkInAB(idxTable[child1], l_idx, cur_idx);
        if(!checkPositionCorrect(child1, c1_left ? l_idx : cur_idx, c1_left ? cur_idx : r_idx))
            return false;
    }
    if(child2 != 0){
        bool c2_left = checkInAB(idxTable[child2], l_idx, cur_idx);
        if(!checkPositionCorrect(child2, c2_left ? l_idx : cur_idx, c2_left ? cur_idx : r_idx))
            return false;
    }
    return true;
}

void findAnswer(int N){
    for(int i = 1; i <= N; i++){
        scanf("%d%d", &nodes[i].child1, &nodes[i].child2);
    }

    int root = findRoot(N);

    for(int i = 0; i < N; i++){
        int number;
        scanf("%d", &number);
        idxTable[number] = i;
    }

    if(root == -1){ 
        printf("NO\n");
        return;
    }

    printf(checkPositionCorrect(root, -1, N) ? "YES\n" : "NO\n");
}

int main(void){
    int N;
    while(scanf("%d", &N) != EOF){
        findAnswer(N);
    }
}