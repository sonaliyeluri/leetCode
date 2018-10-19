#include <stdio.h>
#include <stdlib.h>

struct list {
	int data;
	struct list *next;
};

struct list *newNode(int data) {
	struct list *ptr = malloc(sizeof(struct list));
	ptr->data = data;
	ptr->next = NULL;
	return ptr;
}

struct list *removeElements (struct list *head, int val) {
	if (head == NULL)
		return NULL;
	while (head != NULL) {
		if(head->data == val)
			head = head->next;
		else
			break;
	}
	struct list *temp;
	temp = head;
	while (temp != NULL) {
		if(temp->next != NULL) 
			if(temp->next->data == val)
				temp->next = temp->next->next;
		temp = temp->next;
	}
	return head;
}

void printList(struct list *head) {
	while(head != NULL) {
		printf("%d ",head->data);
		head = head->next;
	}
	printf("\n");
}

int main() {
	struct list *head;
	head = NULL;
	head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(6);
	head->next->next->next = newNode(3);
	head->next->next->next->next = newNode(4);
	head->next->next->next->next->next = newNode(1);
	head->next->next->next->next->next->next = newNode(6);
	printList(head);
	head = removeElements(head,1);
	printf("List elements after removing element\n");
	printList(head);
	return 0;	
}
