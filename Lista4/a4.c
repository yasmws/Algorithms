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
    int leftChildrenCount;
    int rightChildrenCount; 

}BSTNode;

typedef struct bst
{
    BSTNode* root;
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
    n->leftChildrenCount = 0;
    n->rightChildrenCount = 0;

    return n;
}

BST* create_bst(){
    BST* b = (BST*) malloc(1*sizeof(BST));
    if (b == NULL)
    {
        printf("erro na aloc da arvore");
    }
    b->root = NULL;
    return b;
}

int h(BSTNode* rt){
    if (rt == NULL)
    {
        return -1;
    }else return rt->height; 
}

int getBalance(BSTNode* rt){
    if (rt == NULL)
    {
        return 0;
    }else return h(rt->left) - h(rt->right);
}

int findhelp(BSTNode* rt, int k){//modificar
    int numChildren=0;
    if (rt!=NULL)
    {
        if (rt->key == k)
        {   
            //printf("a");
            //só imprimir o num de filhos a esquerda
            numChildren = rt->leftChildrenCount;
            //printf("%d", numChildren);
            return numChildren; 
        }else if (rt->key < k){//menor que a chave//vai para a esquerda   
            //printf("b");
            //printf("%d", rt->leftChildrenCount);
            //soma o numero de filhos a esquerda do nó atual + findhelp(rt->right) + 1(nó atual)
            numChildren = rt->leftChildrenCount + findhelp(rt->right, k) + 1;
            return numChildren;

        }else if (rt->key > k){//maior que a chave//vai para a direita
            //printf("c");
            //só vai para a direita, já que o indice é menor
            numChildren = findhelp(rt->left, k);
            return numChildren; 
        }
    }else return -1;
}

void find(BST* b, int k){
    int a = findhelp(b->root, k);
    /*if (a==-1)
    {
        printf("Data tidak ada");
    }else printf("%d", a+1);*/
   
}

BSTNode* rightRotate(BSTNode* rt){

    BSTNode* l = rt->left;
    BSTNode* lr = l->right;
    
    l->right = rt;
    rt->left = lr;
    
    //corrigindo alturas
    rt->height = max(h(rt->left), h(rt->right))+1;
    l->height = max(h(l->left), h(l->right)) +1;

    //corrigindo contagem de filhos
    if (lr != NULL){ 
        rt->leftChildrenCount =  lr->leftChildrenCount + lr->rightChildrenCount + 1;
    }else rt->leftChildrenCount=0;
	
    l->rightChildrenCount = rt->leftChildrenCount + rt->rightChildrenCount + 1;

    return l;
}

BSTNode* leftRotate(BSTNode* rt){

    BSTNode* r = rt->right;
    BSTNode* rl = r->left;
    
    r->left = rt;
    rt->right = rl;
    
    //corrigindo alturas
    rt->height = max(h(rt->left), h(rt->right))+1;
    r->height = max(h(r->left), h(r->right)) +1;

    //corrigindo contagem de filhos
    if (rl != NULL){ 
        rt->leftChildrenCount =  rl->leftChildrenCount + rl->rightChildrenCount + 1;
    }else rt->leftChildrenCount=0;
	
    r->rightChildrenCount = rt->leftChildrenCount + rt->rightChildrenCount + 1;
    return r;
}

BSTNode* insert(BSTNode* rt, int k){

    if (rt!=NULL)//aqui o problema
    {
        if (rt->key > k)
        {   
            rt->left = insert(rt->left, k);
            rt->leftChildrenCount ++;
            printf("%d ", rt->leftChildrenCount);
        }else if(rt->key < k){
            rt->right = insert(rt->right, k);
            rt->rightChildrenCount++;
            printf("%d ", rt->rightChildrenCount);
        }
        
    }else return create_bstnode(k);

    /*if (rt != NULL){

        if (k < rt->key) {
            rt->left = inserthelp(rt -> left, k);
            rt->leftChildrenCount++;
        }
        else if (k > rt -> key) {
            rt->right = inserthelp(rt -> right, k);
            rt->rightChildrenCount++;
        }

    }else return create_bstnode(k);*/

    //printf("%d %d %d\n", rt->leftChildrenCount, rt->key, rt->rightChildrenCount);

    rt->height = 1 + max(h(rt->left), h(rt->right));
    int balance = getBalance(rt);

    if (balance<-1 && k>=rt->right->key)
    {   
        //printf("a");
        return leftRotate(rt);
    }else if (balance > 1 && k<rt->left->key)
    {   
        //printf("b");
        return rightRotate(rt);
    }else if (balance>1 && k>=rt->left->key)
    {
        //printf("c");
        rt->left = leftRotate(rt->left);
        return rightRotate(rt);
    }else if(balance<-1 && k<rt->right->key)
    {
        //printf("d");
        rt->right = rightRotate(rt->right);
        return leftRotate(rt);
    }

    //printf("%d %d %d\n", rt->leftChildrenCount, rt->key, rt->rightChildrenCount);

    return rt;
    
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
            b->root = insert(b->root, k);

        }else if (c==2)
        {  
            int k;
            scanf("%d", &k);
            find(b, k);
            //printf("\n");
        }
       
    }

    free(b);
    
    return 0;
}