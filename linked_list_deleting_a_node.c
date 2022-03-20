
///////////////////////////////////////////////////////
//mycode
// struct Node* deleteNode1(struct Node *head,int x)
// {
//     int i;
//     struct Node *temp;
//     struct Node *temp2;
    
//     i = 1;
//     temp = head;
//     if (x == 1)
//     {
//         temp = head->next;
//         return (temp);
//     }
//     while (i != x - 1 && x != 1)
//     {
//         head = head->next;
//         i++;
//     }
//     temp2 = head;
//     head = head->next;
//     if (head->next == NULL)
//         temp2->next = NULL;
//     else
//         temp2->next = head->next;
//     return (temp);
// }
//////////////////////////////////
// A complete working C program
// to demonstrate deletion in
// singly linked list
#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node {
	int data;
	struct Node* next;
};

/* Given a reference (pointer to pointer) to the head of a
list and an int, inserts a new node on the front of the
list. */
void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node
		= (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

/* Given a reference (pointer to pointer) to the head of a
list and a key, deletes the first occurrence of key in
linked list */
void deleteNode1(struct Node** head_ref, int key)
{
	// Store head node
	struct Node *temp = *head_ref, *prev;

	// If head node itself holds the key to be deleted
	if (temp != NULL && temp->data == key) {
		*head_ref = temp->next; // Changed head
		free(temp); // free old head
		return;
	}

	// Search for the key to be deleted, keep track of the
	// previous node as we need to change 'prev->next'
	while (temp != NULL && temp->data != key) {
		prev = temp;
		temp = temp->next;
	}

	// If key was not present in linked list
	if (temp == NULL)
		return;

	// Unlink the node from linked list
	prev->next = temp->next;

	free(temp); // Free memory
}
// using recursion

// void deleteNode(struct Node** head_ref, int key)
// {
// 	struct Node* p = *head_ref;
// 	if (*head_ref == NULL)
// 		return;
// 	if (p->data == key)
// 	{
// 		struct Node* t = *head_ref;
// 		p = t->next;
// 		free (t);
// 		return;
// 	}
// 	deleteNode(p->next, key);
// }

// This function prints contents of linked list starting
// from the given node
void printList(struct Node* node)
{
	while (node != NULL) {
		printf(" %d ", node->data);
		node = node->next;
	}
}

// Driver code
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	push(&head, 7);
	push(&head, 1);
	push(&head, 3);
	push(&head, 2);

	puts("Created Linked List: ");
	printList(head);
	deleteNode(&head, 1);
	puts("\nLinked List after Deletion of 1: ");
	printList(head);
	return 0;
}
