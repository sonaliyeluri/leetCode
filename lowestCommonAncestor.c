#include <stdio.h>
#include <stdlib.h>

struct tree {
	int data;
	struct tree *left;
	struct tree *right;
};

struct tree *newNode (int data) {
	struct tree *ptr = malloc(sizeof(struct tree));
	ptr->data = data;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}

struct tree *lowestCommonAncestor(struct tree *root, struct tree *p, struct tree *q) {
	if (root == NULL)
		return NULL;
	if (root->data > p->data && root->data > q->data)
		return lowestCommonAncestor(root->left,p,q);
	if (root->data < p->data && root->data < q->data)
		return lowestCommonAncestor(root->right,p,q);
	return root;
}

int main() {
	struct tree *root;
	root = newNode(6);
	root->left = newNode(2);
	root->right = newNode(8);
	root->left->left = newNode(0);
	root->left->right = newNode(4);
	root->right->left = newNode(7);
	root->right->right = newNode(9);
	root->left->right->left = newNode(3);
	root->left->right->right = newNode(5);
	struct tree *ptr = lowestCommonAncestor(root, root->left->left, root->left->right);
	printf("%d",ptr->data);
	printf("\n");
	return 0;
}
