#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

typedef struct node
{
    int key;
    int element;
    struct node *right;
    struct node *left;
}BSTNode;

typedef struct bst
{
    BSTNode* root;
    int node_count;//num de elementos
}BST;

BSTNode* create_bstnode(int k, int e){

    BSTNode* n = (BSTNode*) malloc(1*sizeof(BSTNode));
    if (n!=NULL)
    {
        printf("erro na alocacao");
    }
    
    n->key = k;
    n->element = e;
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

int findhelp(BSTNode* rt, int k){

    if (rt != NULL){
        if (rt->key > k)
        {
            return findhelp(rt->left, k); //recursão p o lado esquerdo
        }else if (rt->key == k)
        {
            return rt->element; //achei o elemento
        }else return findhelp(rt->right, k); //recursão p o lado direito
    }else return -1;
}

int find(BST* b, int k){
    return findhelp(b->root, k);
}

BSTNode* inserthelp(BSTNode* rt, int k, int e){
    if (rt!=NULL)
    {
        if (rt->key > k)
        {
            rt->left = inserthelp(rt->left, k, e);
        }else{
            rt->right = inserthelp(rt->right, k, e);
        }
        return rt;
        
    }else return create_bstnode(k, e);
    
}

void insert(BST* b, int k, int e){

    b->root = inserthelp(b->root, k, e);
    b->node_count++;
}

BSTNode* getmin(BSTNode* rt){
    if (rt->left == NULL)
    {
        return rt;
    }else return getmin(rt->left);
}

BSTNode* deletemin(BSTNode* rt){
    if (rt->left == NULL)
    {
        return rt->right;
    }else{
        rt->left = deletemin(rt->left);
    }
    return rt;
}

BSTNode* removehelp(BSTNode* rt, int k){
    if (rt!=NULL)
    {
        if (rt->key > k)
        {
            rt->left = removehelp(rt->left, k);
        }else if (rt->key < k)
        {
            rt->right = removehelp(rt->right, k);
        }else{
            if (rt->left==NULL)
            {
                return rt->right;
            }else if (rt->right == NULL)
            {
                return rt->left;
            }else{
                BSTNode* temp = create_bstnode(0,0);
                temp = getmin(rt->right);
                rt->key = temp->key;
                rt->right = deletemin(rt->right);
            }
        }
        return rt;
        
    }else return NULL;
    
}

int removed(BST* b, int k){
    int temp = findhelp(b->root, k);
    if (temp != -1)
    {
        b->root = removehelp(b->root, k);
        b->node_count--;
    }
    return temp;
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
       printf("%d ", rt->key);
    }
}

int main(){

    BST* b = create_bst();

    int n; char comando[10];
    scanf("%d", &n);
    for (int j = 0; j <n; j++)
    {
        scanf("%s", comando);
        if (strcmp(comando, "insert")==0)
            {   
                int e, k;
                scanf("%d%d", &k, &e);
                insert(b, k, e);

            }else if (strcmp(comando, "pre")==0)
            {   
                preorder(b->root);
                printf("\n");
            }else if (strcmp(comando, "in")==0)
            {   
               inorder(b->root);
               printf("\n");
            }else if(strcmp(comando, "post")==0)
            {
               posorder(b->root);
               printf("\n");
            }

    }
    
    return 0;
}

