#include <stdio.h>
#include <stdlib.h>

struct list {
	int data;
	struct list *next;
};

struct list *createList() {
	struct list *head;
	head = malloc(sizeof(struct list));
	struct list *temp1, *temp2;
	temp1 = head;
	int i,n;
	printf("Enter Size of list: ");
	scanf("%d",&n);
	printf("\nEnter elements to list..");
	scanf("%d",&temp1->data);
	temp1->next = NULL;
	for (i=1;i<n;i++){
		temp2 = malloc(sizeof(struct list));
		scanf("%d",&temp2->data);
		temp2->next = NULL;
		temp1->next = temp2;
		temp1 = temp2;
	}
	return head;
}

struct list *reverseList(struct list *head) {
	struct list *prev, *next;
	struct list *curr;
	curr = head;
	prev = NULL;
	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
	return head;
}

void printList(struct list *head) {
	while(head != NULL) {
		printf("%d->",head->data);
		head = head->next;
	}
	printf("NULL\n");
}

int main() {
	struct list *head = createList();
	printf("Printing Elements of list\n");
	printList(head);
	head = reverseList(head);
	printList(head);
	printf("\n");
	return 0;
}		
