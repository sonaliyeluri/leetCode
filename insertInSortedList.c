#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *newNode(int data) {
	struct node *ptr = malloc(sizeof(struct node));
	ptr->data = data;
	ptr->next = NULL;
	return ptr;
}

struct node *sortedInsert(struct node *head, int data) {
	struct node *temp;
	temp = head;
	struct node *new_Node;
	new_Node = newNode(data);
	if (head == NULL) {
		head = new_Node;
		return head;
	}
	if (head->data > data) {
		new_Node->next = head;
		head = new_Node;
		return head;
	}
	else {
		while(temp != NULL) {
			if(temp->next && temp->next->data > data) {
				new_Node->next = temp->next;
				temp->next = new_Node;
				return head;
			}
			else if(temp->next == NULL && temp->data < data)
				temp->next = new_Node;
			temp = temp->next;
		}
	}
	return head;
}
void printList(struct node *head) {
	while(head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
}

int main() {
	struct node *head = NULL;
	head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(4);
	head->next->next->next = newNode(5);
	printList(head);
	printf("\n");
	head = sortedInsert(head,3);
	printList(head);
	printf("\n");
	return 0;
} 
			
		
