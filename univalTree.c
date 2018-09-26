#include <stdio.h>
#include <stdlib.h>

struct tree {
	int data;
	struct tree *left;
	struct tree *right;
};

struct tree *getNode (int data) {
	struct tree *ptr;
	ptr = malloc(sizeof(struct tree));
	ptr->data = data;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}

int isUnival(struct tree *root) {
	if (root == NULL)
		return 1;
	if (root->left && root->left->data != root->data)
		return 0;
	if (root->right && root->right->data != root->data)
		return 0;
	return isUnival(root->left)&&isUnival(root->right);
}

int main() {
	struct tree *root;
	root = getNode(5);
	root->left = getNode(5);
	root->right = getNode(5);
	root->left->left = getNode(5);
	root->left->right = getNode(5);
	root->right->left = getNode(5);
	root->right->right = getNode(1);
	int unival = isUnival(root);
	if (unival == 1)
		printf("\nUnival Tree\n");
	else
		printf("\nNot Unival Tree\n");
}
