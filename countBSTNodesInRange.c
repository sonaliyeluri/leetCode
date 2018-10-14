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

int countBstNodes (struct tree *root, int low , int high) {
	if (root == NULL)
		return 0;
	if (root->data == low && root->data == high)
		return 1;
	if (root->data >= low && root->data <= high)
		return 1+countBstNodes(root->left,low,high)+countBstNodes(root->right,low,high);
	else if (root->data < low)
		return countBstNodes(root->right,low,high);
	else
		return countBstNodes(root->left,low,high);
}

int main() {
	struct tree *root;
	root = newNode(10);
	root->left = newNode(5);
	root->left->left = newNode(1);
	root->right = newNode(50);
	root->right->left = newNode(40);
	root->right->right = newNode(100);
	int count = countBstNodes(root, 5, 45);
	printf("No.of BST nodes in the range [5, 45] :%d",count);
	printf("\n");
	return 0;
}
 
