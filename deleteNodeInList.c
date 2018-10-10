#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *newNode(int data) {
	struct node *ptr = malloc(sizeof(struct node));
	ptr->data = data;
	ptr->next = NULL;
	return ptr;
}

void deleteNode(struct node *head, struct node *n) {
	if (head == n) {
		if(head->next == NULL) {
			printf("List cannot be empty\n");
			return;
		}
		head->data = head->next->data;
		head->next = head->next->next;
		n = head->next;
		free(n);
	}
	else {
		struct node *temp;
		temp = head;
		while(temp != NULL && temp->next != n) 
			temp = temp->next;
		if (temp->next == NULL){
			printf("Node does not exist in Linked list\n");
			return;
		}
		temp->next = temp->next->next;
		free(temp->next);
		return;
	}			
}
 
void printList(struct node *head) {
	while (head != NULL) {
		printf("%p %d\n",head,head->data);
		head = head->next;
	}
}

int main() {
	struct node *head;
	head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	printList(head);
	printf("AfterDeleting Node %p\n", head->next->next->next->next);
	deleteNode(head,head->next->next->next->next);
	printList(head);
	return 0;
}
