#include <stdio.h>
#include <stdlib.h>

struct tree {
	int data;
	struct tree *left, *right;
};

struct tree *newNode(int data) {
	struct tree *ptr = malloc(sizeof(struct tree));
	ptr->data = data;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}

struct tree *invertBinaryTree(struct tree *root) {
	struct tree *temp;
	if (root != NULL) {
		invertBinaryTree(root->left);
		invertBinaryTree(root->right);
		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
	return root;
}

void printTree(struct tree *root) {
	if (root != NULL) {
		printf("%d ", root->data);
		printTree(root->left);
		printTree(root->right);
	}
}

int main() {
	struct tree *root = NULL;
	root = newNode(4);
	root->left = newNode(2);
	root->right = newNode(7);
	root->left->left = newNode(1);
	root->left->right = newNode(3);
	root->right->left = newNode(6);
	root->right->right = newNode(9);
	printTree(root);
	root = invertBinaryTree(root);
	printf("\nTree Elements after Inverting\n");
	printTree(root);
	printf("\n");
	return 0;
}
