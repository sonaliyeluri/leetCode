#include <stdio.h>
#include <stdlib.h>

struct list {
	char data;
	struct list *next;
};

struct list *newNode (char data) {
	struct list *ptr = malloc(sizeof(struct list));
	ptr->data = data;
	ptr->next = NULL;
	return ptr;
}

int compare(struct list *l1, struct list *l2) {
	while (l1 && l2 && (l1->data == l2->data)) {
		l1 = l1->next;
		l2 = l2->next;
	}
	if (l1 && l2)
		return (l1->data > l2->data) ? 1:-1;
	if (l1 && !l2)
		return 1;
	if(!l1 && l2)
		return -1;
	return 0; 
}

void printList(struct list *l) {
	while(l != NULL) {
		printf("%c ",l->data);
		l = l->next;
	}
	printf("\n");
}

int main() {
	struct list *l1;
	struct list *l2;
	l1 = newNode('g');
	l1->next = newNode('e');
	l1->next->next = newNode('e');
	l1->next->next->next = newNode('k');
//	l1->next->next->next->next = newNode('s');
	printList(l1);
	l2 = newNode('g');
	l2->next = newNode('e');
	l2->next->next = newNode('e');
	l2->next->next->next = newNode('k');
	l2->next->next->next->next = newNode('a');
	printList(l2);
	printf("%d\n",compare(l1,l2));
	return 0;
}	
