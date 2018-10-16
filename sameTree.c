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
	
int isSameTree(struct tree *p, struct tree *q) {
	if (p == NULL && q == NULL)
		return 1;
	if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
		return 0;
	return ((p->data == q->data) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}

int main() {
	struct tree *p;
	p = newNode(1);
	p->left = newNode(2);
	p->right = newNode(3);
	struct tree *q;
	q = newNode(1);
        q->left = newNode(3);
        q->right = newNode(2);
	printf("%s",isSameTree(p,q) ? "True" : "False");
	printf("\n");
	return 0;
}
