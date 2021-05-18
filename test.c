#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node * left;
    struct node * right;
}NODE;

typedef struct {
    NODE* root;
}BINARY_TREE;

NODE* createNode(int value);
void insertTree(NODE* r, int v);
void printTree(BINARY_TREE* bt, int nv);
void preOrder(NODE* r);


int main() {
    BINARY_TREE* Btree = (BINARY_TREE*) malloc(sizeof(BINARY_TREE));
    Btree->root = NULL;
    int v;
    while (scanf("%d", &v) != EOF){
        insertTree(Btree->root, v);
        printf("raiz principal -> %p\n", Btree->root);
        printTree(Btree, v);
    }
	return 0;
}

NODE* createNode(int value){
    NODE* node = (NODE*) malloc(sizeof(NODE));
    node->value = value;
	node->left = NULL;
    node->right = NULL;
    return node;
}

void insertTree(NODE* r, int v){
	if (r != NULL){
		printf("\nr!=null\n");
    	if (r->value > v) insertTree(r->left, v);
    	else insertTree(r->right, v);
    	return;
	}
	printf("\nr:-%p-", r);
	r = createNode(v);
	printf("\nr:-%p-\n", r);
	printf("r->v: %d\n", r->value);
}

void printTree(BINARY_TREE* bt, int nv){
	printf("----\nAdicionando %d\n\t", nv);
	preOrder(bt->root);
	printf("\n");
}

void preOrder(NODE* r){
	if (r == NULL) {
		printf("\n2r:-%p-\n", r);
		printf(" () ");
		return;
	}
	printf(" ( %d ", r->value);
	preOrder(r->left);
	preOrder(r->right);
	printf(" )");
}