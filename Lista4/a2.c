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

int qtdfilhos(BSTNode* rt, int qtd){

    if (rt->left==NULL && rt->right==NULL)
    {
        return qtd;
    }else if (rt->left==NULL && rt->right!=NULL)
    {
        qtd += qtdfilhos(rt->right, qtd+1);
    }else if (rt->left!=NULL && rt->right==NULL)
    {
        qtd += qtdfilhos(rt->left, qtd+1);
    }else if (rt->left!=NULL && rt->right!=NULL)
    {
        qtd += qtdfilhos(rt->left, qtd+1);
        qtd += qtdfilhos(rt->right, qtd+1);

    }
    return qtd;
}


void helpfind(BSTNode* rt, int k, int qtd){
    
    printf("%d", qtd);
    /*if(rt->key == k){
        //se eu encontrei exatamente o elem que buscava
        //basta apenas: qtd(rt->left)
        if (rt->left!=NULL)//tenho filho a esquerda
        {   
            qtd++;
            qtd += qtdfilhos(rt->left, qtd);
        }else printf("%d", qtd);//não tenho filho a esquerda

    }else if (rt->key < k)//menor que a chave
    {
        //qtd = qtd(rt->key) + qtd(k)
        helpfind(rt->right, k, qtd);
    }else if (rt->key > k)//maior que a chave
    {   
        qtd++;
        helpfind(rt->left, k, qtd); 
        //faz isso até encontrar o valor, vai para a direita até encontrar
    }*/
    
}

void find(BST* b, int k){
    int qtd=0;
    helpfind(b->root, k, qtd);
    
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