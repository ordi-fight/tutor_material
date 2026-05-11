#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct nnn
{
    int number;
    struct nnn* left;
    struct nnn* right;
}Node;

char input[300000];

Node* buildNode(int number, Node* left, Node* right){
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->number = number;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

void readInput(){
    scanf("%s", input);
}

Node* buildTree(int *cur){
    int number = 0;
    while(input[*cur] >= '0' && input[*cur] <= '9'){
        number *= 10;
        number += input[*cur] - '0';
        (*cur) += 1;
    }

    Node* node = buildNode(number, NULL, NULL);
    if(input[*cur] == ':'){
        *cur += 1;
    } else if(input[*cur] == '?'){
        *cur += 1;
        node->left = buildTree(cur);
        node->right = buildTree(cur);
    }

    return node;
}

void computeResult(Node* root){
    char table[3004];
    scanf("%s", &table[1]);
    Node* cur = root;
    while(cur->left != NULL && cur->right !=NULL){
        if(table[cur->number] == '1')
            cur = cur->left;
        else
            cur = cur-> right;
    }
    printf("%c\n", table[cur->number]);
}

void runIteration(Node* root){
    int T;
    scanf("%d", &T);
    for(int i = 0;i < T;i++)
        computeResult(root);
}

int main(void){
    readInput();
    int cur = 0;
    Node* root = buildTree(&cur);
    runIteration(root);
}
