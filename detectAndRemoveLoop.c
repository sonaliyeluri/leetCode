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

struct list *detectCycleRemoveLoop(struct list *head) {
	struct list *slow = head;
	struct list *fast = head;
	while (slow && fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast){
			break;
		}
	}
	if (slow == fast)
	{
		slow = head;
		while(slow->next != fast->next) {
			slow = slow->next;
			fast = fast->next;
		}
		fast->next = NULL;
	}
	return head;
}
	
void printList(struct list *head) {
	while(head != NULL) {
		printf("%d ", head->data);
		head= head->next;
	}
	printf("\n");
}

int main() {
	struct list *head;
	head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);
	head->next->next->next->next->next = head->next->next;
	head = detectCycleRemoveLoop(head);
	printList(head);
	return 0;
}
