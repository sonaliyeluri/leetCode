#include <stdio.h>
#include <stdlib.h>

struct tree {
	int data;
	struct tree *left;
	struct tree *right;
	int height;
};

int max (int a, int b) {
	return (a > b)? a : b;
}

struct tree *newNode (int data) {
	struct tree *ptr = malloc(sizeof(struct tree));
	ptr->data = data;
	ptr->left = NULL;
	ptr->right = NULL;
	ptr->height = 1;
}

int height(struct tree *root) {
	if (root == NULL)
		return 0;
	return root->height;
}

struct tree *rightRotate (struct tree *y) {
	struct tree *x = y->left;
	struct tree *T2 = x->right;
	x->right = y;
	y->left = T2;
	
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;
	return x;
}

struct tree *leftRotate (struct tree *x) {
	struct tree *y = x->right;
	struct tree *T2 = y->left;
	y->left = x;
	x->right = T2;
	
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;
	return y;
}

int getBalance(struct tree *root) {
	if(root == NULL)
		return 0;
	return height(root->left)-height(root->right);
}

struct tree *insert(struct tree *root, int data) {
	if (root == NULL)
		return(newNode(data));
	if (data < root->data)
		root->left = insert(root->left,data);
	else if(data > root->data)
		root->right = insert(root->right,data);
	else
		return root;

}
	
