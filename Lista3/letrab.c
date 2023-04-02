#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

typedef struct node
{
    int key;
    struct node *right;
    struct node *left;
}BSTNode;

typedef struct bst
{
    BSTNode* root;
    int node_count;//num de elementos
}BST;

BSTNode* create_bstnode(int k){

    BSTNode* n = (BSTNode*) malloc(1*sizeof(BSTNode));
    if (n==NULL)
    {
        printf("erro na alocacao");
    }
    
    n->key = k;
    n->left = NULL;
    n->right = NULL;

    return n;
}

BST* create_bst(){

    BST* b = (BST*) malloc(1*sizeof(BST));
    if (b == NULL)
    {
        printf("erro na aloc da arvore");
    }

    b->root = NULL;
    b->node_count = 0;
    return b;
}

BSTNode* inserthelp(BSTNode* rt, int k){
    if (rt!=NULL)
    {
        if (rt->key > k)
        {
            rt->left = inserthelp(rt->left, k);
        }else{
            rt->right = inserthelp(rt->right, k);
        }
        return rt;
        
    }else return create_bstnode(k);
    
}

void insert(BST* b, int k){

    b->root = inserthelp(b->root, k);
    b->node_count++;
}

void preorder(BSTNode* rt){
    if (rt!=NULL)
    {   
        printf("%d ", rt->key);
        preorder(rt->left);
        preorder(rt->right);
    }
}

void inorder(BSTNode* rt){
    if (rt!=NULL)
    {
        inorder(rt->left);
        printf("%d ", rt->key);
        inorder(rt->right);
    }
}

void posorder(BSTNode* rt){
    if (rt!=NULL)
    {
       posorder(rt->left); 
       posorder(rt->right);
       printf("%d\n", rt->key);
    }
}

int main(){

    BST* b = create_bst();

    int n, k, i=0;
    while(scanf("%d", &k) > 0)
    { 
        insert(b, k);

    }

    posorder(b->root);
    
    return 0;
}
