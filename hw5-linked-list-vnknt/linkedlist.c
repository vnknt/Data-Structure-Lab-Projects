#include <stdio.h>
#include <stdlib.h>
//Doubly Linked List
struct node
{
	struct node* prev;
	int data;
	struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;

void display();
void insert_beg();
void insert_end();
void delete_beg();
void delete_end();
void insert_after();
void insert_before();
void delete_key();
void sort();

void main() {
	int option;
	do
	{
		printf("\n\n 1: Display the list");
		printf("\n 2: Insert at the beginning");
		printf("\n 3: Insert at the end");
		printf("\n 4: Delete from the beginning");
		printf("\n 5: Delete from the end");
		printf("\n 6: Insert after");
		printf("\n 7: Insert before");
		printf("\n 8: Delete key");
		printf("\n 9: Sort List");

		printf("\n 0: EXIT");
		printf("\n\n Enter your option : ");
		scanf_s("%d", &option);
		switch (option)
		{
		case 1: display();	  break;
		case 2: insert_beg(); break;
		case 3: insert_end(); break;
		case 4: delete_beg(); break;
		case 5: delete_end(); break;
		case 6: insert_after(); break;
		case 7: insert_before(); break;
		case 8: delete_key(); break;
		case 9: sort(); break;
		}
	} while (option != 0);
	return;
}

void display() {
	struct node* ptr = tail;
	if (ptr == NULL)
	{
		printf("\nList is empty!");
	}
	else {
		while (ptr != NULL)
		{
			printf("\t%d", ptr->data);
			ptr = ptr->prev;
		}
	}
	printf("\n");
}

void insert_beg() {
	struct node* ptr;
	ptr = (struct node*)malloc(sizeof(struct node));

	if (ptr == NULL)
	{
		printf("\nThere is an error in Malloc!");
	}
	else {
		printf("\nEnter the node data value: ");
		scanf_s("%d", &ptr->data);

		if (head == NULL)
		{
			ptr->next = NULL;
			head = ptr;
			tail = head;
		}
		else {
			ptr->prev = NULL;
			ptr->next = head;
			head->prev = ptr;

			head = ptr;
		}
	}
}

void insert_end() {
	struct node* ptr;
	ptr = (struct node*)malloc(sizeof(struct node));

	if (ptr == NULL)
	{
		printf("\nThere is an error in Malloc!");
	}
	else {
		printf("\nEnter the node data value: ");
		scanf_s("%d", &ptr->data);

		if (head == NULL)
		{
			ptr->prev = NULL;
			ptr->next = NULL;
			head = ptr;
			tail = head;
		}
		else {
			struct node* temp = head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = ptr;
			ptr->prev = temp;
			ptr->next = NULL;
			tail = ptr;
		}
	}
}

void delete_beg() {
	struct node* ptr = head;
	if (head == NULL)
	{
		printf("\nThere isn't any element in the list!");

	}
	else {
		head = head->next;
		ptr->next = NULL;
		head->prev = NULL;
		free(ptr);
		printf("\nFirst node is deleted!");
	}
}

void delete_end() {
	struct node* ptr, * temp;
	if (head == NULL)
	{
		printf("\nThere isn't any element in the list!");
	}
	else if (head->next == NULL) {
		free(head);
		head = NULL;
		tail = NULL;
	}
	else {
		temp = head;
		ptr = temp->next;

		while (ptr->next != NULL) {
			temp = temp->next;
			ptr = ptr->next;
		}
		temp->next = NULL;
		ptr->prev = NULL;
		free(ptr);
		tail = temp;
	}
}

void insert_after() {

	int pivot;
	int val;
	struct node* iter;
	struct node* temp = (struct node*)malloc(sizeof(struct node));



	if (temp == NULL)
	{
		printf("\nThere is an error in Malloc!");
		return;

	}



	printf("\nSelect a data to insert after it: "); scanf("%d", &pivot);

	printf("Enter a value to add  : "); scanf("%d", &val);

	


	temp->data = val;
	iter = head;


	while (iter != NULL) {
		if (iter->data == pivot) {
			break;
		}
		else
			iter = iter->next;
	}


	if (iter == NULL) {
		printf("\nKey not found");
		return;

	}



	temp->next = iter->next;
	temp->prev = iter;
	if (temp->next != NULL)
		temp->next->prev = temp;
	else
		tail = temp;

	iter->next = temp;




	printf("\n%d is added after %d", val, pivot);



}
void insert_before() {
	int pivot;
	int val;
	struct node* iter;
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));

	if (temp == NULL)
	{
		printf("\nThere is an error in Malloc!");
		return;

	}
	
	printf("\nSelect a data to insert before   : "); scanf("%d", &pivot);

	printf("Enter a value to add  : "); scanf("%d", &val);

	temp->data = val;
	iter = head;


	while (iter != NULL) {
		if (iter->data == pivot) {
			break;
		}
		else
			iter = iter->next;
	}


	if (iter == NULL) {
		printf("\n\nKey not found !");
		return;

	}



	temp->prev = iter->prev;
	if (iter->prev != NULL)
		iter->prev->next = temp;
	else
		head = temp;

	temp->next = iter;
	iter->prev = temp;
	printf("\n\n%d is added before %d", val, pivot);
	return;


}

void delete_key() {


	if (head == NULL) {
		printf("\nThere isn't any element in the list'");

		return;
	}
	
	
	
	int key;
	printf("Please enter a data to delete : "); scanf("%d", &key);

	struct node* iter = head;


	while (iter != NULL) {

		if (iter->data == key) {
			break;

		}
		iter = iter->next;
	}
	if (iter == NULL) {
		printf("\nKey not found\n");
		return;

	}

	  
	if(iter->next!=NULL) {
		iter->next->prev=iter->prev;
	}else {
		tail=iter->prev;
		
	}
	if(iter->prev!=NULL) {
		iter->prev->next=iter->next;
	}else {
		head=iter->next;
	}

	free(iter);
	return;

}


void sort() {
	if (head == tail) {
		printf("\nSorting needs minimum 2 variables\n");
		return;
	}

	struct node* iter = head;
	struct node* ptr = head;


	int temp;


	while (ptr != NULL)

	{
		iter = head;

		while (iter->next != NULL) {

			if (iter->next->data < iter->data) {
				temp = iter->data;
				iter->data = iter->next->data;
				iter->next->data = temp;

			}

			iter = iter->next;

		}

		ptr = ptr->next;

	}

}
