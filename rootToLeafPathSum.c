#include <stdio.h>
#include <stdlib.h>

struct tree {
	int data;
	struct tree *left;
	struct tree *right;
};

struct tree *newNode(int data) {
	struct tree *ptr = malloc(sizeof(struct tree));
	ptr->data = data;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}

int treePathSumUtil(struct tree *root, int val) {
	if (root == NULL)
		return 0;
	val = val*10+root->data;
	if (root->left == NULL && root->right == NULL)
		return val;
	return treePathSumUtil(root->left,val)+treePathSumUtil(root->right,val);
}

int treePathSum(struct tree *root) {
	return treePathSumUtil(root,0);
}

int main() {
	struct tree *root = newNode(6);
	root->left = newNode(3);
	root->left->left = newNode(2);
	root->left->right = newNode(5);
	root->left->right->left = newNode(7);
	root->left->right->right = newNode(4);
	root->right = newNode(5);
	root->right->right = newNode(4);
	printf("Sum of all root to leaf paths is %d",treePathSum(root));
	printf("\n");
	return 0;
}
