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
    }return rt->height;
    
}

int getBalance(BSTNode* rt){

    if (rt == NULL)
    {
        return 0;
    }return (h(rt->left) - h(rt->right));
    
}

BSTNode* right_rotate (BSTNode* y) {//ok
	BSTNode* x = y -> left;
	BSTNode* T2 = x -> right;

	x -> right = y;
	y -> left = T2;

	y -> height = max( h(y -> left), h(y -> right) ) + 1;
	x -> height = max( h(x -> left), h(x -> right) ) + 1;
	
	if (T2 != NULL) y ->leftChildrenCount = T2 ->leftChildrenCount+ T2 ->rightChildrenCount + 1; else y ->leftChildrenCount = 0;
	x ->rightChildrenCount = y ->leftChildrenCount + y ->rightChildrenCount + 1;

	return x;
}

BSTNode* left_rotate (BSTNode* x) {//ok
	BSTNode* y = x -> right;
	BSTNode* T2 = y -> left;

	y -> left = x;
	x -> right = T2;

	x -> height = max( h(x -> left), h(x -> right) ) + 1;
	y -> height = max( h(y -> left), h(y -> right) ) + 1;

	if (T2 != NULL) x ->rightChildrenCount = T2 ->leftChildrenCount + T2 ->rightChildrenCount + 1; else x ->rightChildrenCount = 0;
	y ->leftChildrenCount = x ->leftChildrenCount + x ->rightChildrenCount + 1;
	
	return y;
}

BSTNode* inserthelp(BSTNode* root, int key) {//aqui
	
	if (root == NULL) return create_bstnode(key);
	
    if (key < root->key) {
		root->left = inserthelp(root->left, key);
		root->leftChildrenCount++;
        //printf("%d ", root->leftChildrenCount);
	}
	else if (key > root -> key) {
		root -> right = inserthelp(root->right, key);
		root->rightChildrenCount++;
        //printf("%d ", root->rightChildrenCount);
	}

	root -> height = max( h(root ->left), h(root->right) ) + 1;

	int balance = getBalance(root);
    //printf("h:%d k:%d b:%d\n", root->height, root->key, balance);

	// 4 cases for unbalanced node
	if ( (balance > 1) && (key<root->left->key) ) return right_rotate(root);

	if ( (balance < -1) && (key>=root->right->key) ) return left_rotate(root);

	if ( (balance > 1) && (key>=root->left->key) ) {
		root->left = left_rotate(root->left);
		return right_rotate(root);
	}

	if ( (balance < -1) && (key<root->right->key) ) {
		root -> right = right_rotate(root->right);
		return left_rotate(root);
	}

    printf("%d %d %d\n", root->leftChildrenCount, root->key, root->rightChildrenCount);


	return root;
}

int main () {

	int n;
	scanf("%d", &n);
    BST* b = create_bst();
	
	for (int i = 0; i < n; i++) {
		short int op;
		int num;
		scanf("%hd%d", &op, &num);
		if (op == 1) {
		
			b->root = inserthelp(b->root, num);
            printf("%d\n", b->root->key);
		}
		if (op == 2) {
			
            //flag = 0;
			//int rank = find(b, num) + 1;
			//if (flag) printf("Data tidak ada\n"); else printf("%d\n", rank);
			//if (flag) printf("Data tidak ada\n"); else printf("%d\n", rank);
		}
		
	}
	
	return 0;
}
