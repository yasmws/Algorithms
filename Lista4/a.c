#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#define max(a,b) ((a>b)?a:b)

typedef struct node
{
    int key;
    struct node *right;
    struct node *left;
    int height;
    int index;  

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
    n->height = -1;
    n->index = -1;

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

int h(BSTNode* rt){

    if (rt == NULL)
    {
        return -1;
    }return rt->height;
    
}

int getBalance(BSTNode* rt){

    if (rt == NULL)
    {
        return 0;
    }return h(rt->left) - h(rt->right);
    
}

int inorder(BSTNode* rt, int array[], int indice){
    
    if (rt!=NULL)
    {   
        indice++;
        indice = inorder(rt->left, array, indice);
        array[(indice)] = rt->key;
        indice++;
        indice = inorder(rt->right, array, indice);
    }

    return indice;
}

void find(BST* b, int k){
    int a[b->node_count], i;
    for (i = 0; i <b->node_count; i++)
    {
        a[i] = 0;
    }
    
    int indice=0, j =0, flag = 0; i = 0;
    indice = inorder(b->root, a, indice);
    for (int i = 0; i <indice; i++)
    {
        if(a[i]!=0){
            j++;
            if(a[i]==k){
                printf("%d", j);
                flag = 1;
            }
        }
    }
    if(flag==0){
        printf("Data tidak ada");
    }
}

BSTNode* rightRotate(BSTNode* rt){

    BSTNode* l = rt->left;
    BSTNode* lr = l->right;
    
    l->right = rt;
    rt->left = lr;
    
    rt->height = max(h(rt->left), h(rt->right))+1;
    l->height = max(h(l->left), h(l->right)) +1;

    return l;
}

BSTNode* leftRotate(BSTNode* rt){

    BSTNode* r = rt->right;
    BSTNode* rl = r->left;
    
    r->left = rt;
    rt->right = rl;
    
    rt->height = max(h(rt->left), h(rt->right))+1;
    r->height = max(h(r->left), h(r->right)) +1;

    return r;
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

    rt->height = 1 + max(h(rt->left), h(rt->right));
    int balance = getBalance(rt);

    if (balance<-1 && k>=rt->right->key)
    {
        return leftRotate(rt);
    }else if (balance > 1 && k<rt->left->key)
    {
        return rightRotate(rt);
    }else if (balance>1 && k>=rt->left->key)
    {
        rt->right = leftRotate(rt->left);
        return rightRotate(rt);
    }else if(balance<-1 && k<rt->right->key)
    {
        rt->right = rightRotate(rt->right);
        return leftRotate(rt);
    }

    return rt;
    
}

void insert(BST* b, int k){

    b->root = inserthelp(b->root, k);
    b->node_count++;
}

int main(){

    BST* b = create_bst();

    int n, c;
    scanf("%d", &n);
    for (int j = 0; j <n; j++)
    {
        scanf("%d", &c);
        if (c==1)
        {   
            int k;
            scanf("%d", &k);
            insert(b, k);

        }else if (c==2)
        {  
            int k;
            scanf("%d", &k);
            find(b, k);
            printf("\n");
        }
    }

    free(b);
    
    return 0;
}