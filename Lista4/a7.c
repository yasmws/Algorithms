#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#define max(a,b) ((a>b)?a:b)

typedef struct node {
	
    int key;
    struct node *right;
    struct node *left;
    int height;
    int leftChildrenCount;
    int rightChildrenCount; 

} BSTNode;

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
    }else return (h(rt->left) - h(rt->right));
    
}


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


BSTNode* rightRotate(BSTNode* rt){//

    BSTNode* l = rt->left;
    BSTNode* lr = l->right;
    
    l->right = rt;
    rt->left = lr;
    
    rt->height = max(h(rt->left), h(rt->right))+1;
    l->height = max(h(l->left), h(l->right)) +1;

    //corrigindo contagem de filhos
    if (lr != NULL){ 
        rt->leftChildrenCount =  lr->leftChildrenCount + lr->rightChildrenCount + 1;
    }else rt->leftChildrenCount=0;
	
    l->rightChildrenCount = rt->leftChildrenCount + rt->rightChildrenCount + 1;

    return l;
}

BSTNode* leftRotate(BSTNode* rt){//

    BSTNode* r = rt->right;
    BSTNode* rl = r->left;
    
    r->left = rt;
    rt->right = rl;
    
    rt->height = max(h(rt->left), h(rt->right))+1;
    r->height = max(h(r->left), h(r->right)) +1;

    //corrigindo contagem de filhos
    if (rl != NULL){ 
        rt->rightChildrenCount =  rl->leftChildrenCount + rl->rightChildrenCount + 1;
    }else rt->rightChildrenCount=0;
	
    r->leftChildrenCount = rt->leftChildrenCount + rt->rightChildrenCount + 1;
    
    return r;
}

BSTNode *inserthelp(BSTNode *rt, int k) {
	// std bst insertion
	if (rt == NULL) return create_bstnode(k);
	if (k < rt -> key) {
		rt -> left = inserthelp(rt -> left, k);
		rt ->leftChildrenCount++;
	}
	else if (k > rt -> key) {
		rt -> right = inserthelp(rt -> right, k);
		rt ->rightChildrenCount++;
	}
	else return rt;

	rt -> height = max( h(rt -> left), h(rt -> right) ) + 1;

	int balance = getBalance(rt);
    //printf("h:%d k:%d b:%d\n", rt->height, rt->key, balance);

	// 4 cases for unbalanced BSTNode
	if ( (balance > 1) && (k < rt -> left -> key) ) return rightRotate(rt);

	if ( (balance < -1) && (k > rt -> right -> key) ) return leftRotate(rt);

	if ( (balance > 1) && (k > rt -> left -> key) ) {
		rt -> left = leftRotate(rt -> left);
		return rightRotate(rt);
	}

	if ( (balance < -1) && (k < rt -> right -> key) ) {
		rt -> right = rightRotate(rt -> right);
		return leftRotate(rt);
	}

    //printf("%d %d %d\n", rt-leftChildrenCount, rt->key, rt-rightChildrenCount);

	return rt;
}

int findhelp(BSTNode* rt, int k, int* y){//modificar
    int numChildren=0;
    if (rt!=NULL)
    {
        if (rt->key == k)
        {   
        
            numChildren = rt->leftChildrenCount;
          
            return numChildren; 
        }else if (rt->key < k){//menor que a chave//vai para a esquerda   
            
            numChildren = rt->leftChildrenCount + findhelp(rt->right, k, y) + 1;
            return numChildren;

        }else if (rt->key > k){//maior que a chave//vai para a direita
            
            numChildren = findhelp(rt->left, k, y);
            return numChildren; 
        }

    }else{
        (*y) = 1;
        return -1;
    }
}

void find(BSTNode* rt, int k){
    int qtd=0, y=0;

    qtd = findhelp(rt, k, &y);
    //printf("%d", y);
    if (y==1)
    {
        printf("Data tidak ada");
    }else printf("%d", qtd+1);
    
}

int main(){

    //BST* b = create_bst();
    BSTNode *rt = NULL;
    int n, c;
    scanf("%d", &n);
    for (int j = 0; j <n; j++)
    {
        scanf("%d", &c);
        if (c==1)
        {   
            int k;
            scanf("%d", &k);
            rt = inserthelp(rt, k);

        }else if (c==2)
        {  
            int k;
            scanf("%d", &k);
            find(rt, k);
            printf("\n");
            
        }
    }

    free(rt);
    
    return 0;
}