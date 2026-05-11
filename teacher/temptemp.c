#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _node{

    int number;
    int sub_tree_num;
    char op;
    bool is_number;
    struct _node  *right , *left;
}Node;
int N;

Node * make_node(char val ){
    Node * new_node = (Node *)malloc(sizeof(Node));
    if ('1' <= val && val <= '9'){
        new_node->number = val - '1' + 1;
        new_node->sub_tree_num = val - '0';
        new_node->op = '0';
        new_node->is_number = true;
        new_node->right = NULL;
        new_node->left = NULL;
    }
    else if (val == '+' || val == '-' || val == '*'){
        new_node->number = 0;
        new_node->sub_tree_num = 0;
        new_node->op = val;
        new_node->is_number = false;
        new_node->right = NULL;
        new_node->left = NULL;
    }
    return new_node;

}

char tree_string[300001];
int idx = 0 ; 

void print_out_val (char val ,int idx , char tree_string_char){
  printf("===================\n");
  printf("val = %c " , val);
  printf("idx = %d " , idx);
  printf("tree_string_char = %c " , tree_string_char);
  printf("\n");
}

// int eval(Node * root){
//     if (root ->is_number == true){
//         return root->number;
//     }
//     int left_num = eval(root->left);
//     int right_num  = eval(root->right);
//     if (root->op == '+'){
//         return left_num + right_num;
//     }
    
//     else if (root->op == '-'){
//         return left_num - right_num;
//     }
    
//     else if (root->op == '*'){
//         return left_num * right_num;
//     } 
// }
int eval_have_subtree_num(Node *root){

    int left_num = root->left->sub_tree_num;
    int right_num  = root->right->sub_tree_num;
    if (root->op == '+'){
        return left_num + right_num;
    }
    
    else if (root->op == '-'){
        return left_num - right_num;
    }
    
    else if (root->op == '*'){
        return left_num * right_num;
    } 
}

Node* build_tree(char val){

   if ('1' <= val  && val <= '9'){
    idx += 1;
    return make_node(val);
   }
   Node * oper_node  = make_node(val);
   idx += 1;
   oper_node->left = build_tree(tree_string[idx]);
   oper_node->right = build_tree(tree_string[idx]);
   oper_node->sub_tree_num = eval_have_subtree_num(oper_node);
   return oper_node;
}

Node * left_spin(Node * root){
    Node* final_root = root->right;
    Node *root_right_left_child = (root->right)->left;
    (root->right)->left = root; // root->right
    root->right = root_right_left_child; // root
    final_root->sub_tree_num = eval_have_subtree_num(final_root);
    root->sub_tree_num = eval_have_subtree_num(root);
    return final_root;
}

bool can_left_spin(Node * root){
    if ((root->right)->is_number == true){
        return false;
    }
    return true;
    // return ! root->right->is_number
}
Node*  right_spin(Node * root){
    Node* final_root = root->left;
    Node *root_left_right_child = root->left->right;
    root->left->right = root;
    root->left = root_left_right_child;
    final_root->sub_tree_num = eval_have_subtree_num(final_root);
    root->sub_tree_num = eval_have_subtree_num(root);
    return final_root;
}
bool can_right_spin(Node * root){
    if ((root->left)->is_number == true){
        return false;
    }
    return true;
}

int main(){
    scanf("%d" , &N);
    scanf("%s" , tree_string);
    Node * root = build_tree(tree_string[0]);
    int min_spaning = root->sub_tree_num;
   
    while (can_left_spin(root))
    {   
        root = left_spin(root);
        int eval_val = root->sub_tree_num; 
        if ( eval_val < min_spaning){
            min_spaning = eval_val; 
        }
       
    }
    while (can_right_spin(root))
    {
        root = right_spin(root);
        int eval_val = root->sub_tree_num; 
        if ( eval_val < min_spaning){
            min_spaning = eval_val; 
        }
    }
    printf("%d\n" , min_spaning);
    
    

}