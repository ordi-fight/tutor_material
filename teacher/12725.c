#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct nnn
{
    int number;
    char op;
    bool isNumber;
    int total;
    struct nnn* left;
    struct nnn* right;
}Node;

int N;
char input[300001];

Node* buildNode(int number, char op, bool isNumber, int total, Node* left, Node* right){
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->isNumber = isNumber;
    newNode->number = number;
    newNode->op = op;
    newNode->total = total;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

int getNodeNumber(Node* node){
    return (node->isNumber)? node->number:node->total;
}

void nodeOp(Node* node){
    int leftVal = getNodeNumber(node->left), rightVal = getNodeNumber(node->right);
    if(node->op == '+')
        node->total = leftVal + rightVal;
    else if(node->op == '-')
        node->total = leftVal - rightVal;
    else if(node->op == '*')
        node->total = leftVal * rightVal;
}

void readInput(){
    scanf("%d%s", &N, input);
}

Node* buildTree(int *cur){
    if(*cur == N)
        return NULL;
    
    Node* node;
    if(input[*cur] >= '0' && input[*cur] <= '9'){
        node = buildNode(input[*cur] - '0', '\0', true, 0, NULL, NULL);
        (*cur) += 1;
    }
    else{
        node = buildNode(0, input[*cur], false, 0, NULL, NULL);
        (*cur) += 1;
        node->left = buildTree(cur);
        node->right = buildTree(cur);
        nodeOp(node);
    }
    return node;
}

bool checkCanLeftSpin(Node* root){
    return !root->right->isNumber;
}

bool checkCanRightSpin(Node* root){
    return !root->left->isNumber;
}

Node* leftSpin(Node* root){
    Node* newRoot = root->right;
    Node* newRootLeft = newRoot->left;

    root->right = newRootLeft;
    newRoot->left = root;

    nodeOp(root);
    nodeOp(newRoot);
    return newRoot;
}

Node* rightSpin(Node* root){
    Node* newRoot = root->left;
    Node* newRootRight = newRoot->right;

    root->left = newRootRight;
    newRoot->right = root;

    nodeOp(root);
    nodeOp(newRoot);
    return newRoot;
}

int main(void){
    readInput();
    int cur = 0;
    Node* root = buildTree(&cur);
    
    int min = root->total;
    while(checkCanLeftSpin(root)){
        root = leftSpin(root);
        if(root->total < min)
            min = root->total;
    }

    while(checkCanRightSpin(root)){
        root = rightSpin(root);
        if(root->total < min)
            min = root->total;
    }

    printf("%d\n", min);
}
