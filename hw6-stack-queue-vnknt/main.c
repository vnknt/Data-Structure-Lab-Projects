#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct queue {
	int data;
	struct queue* next;
	
	
}QUEUE;

typedef struct stack{
	int data;
	struct stack* next;
	
}STACK;

QUEUE* front=NULL;
QUEUE* end=NULL;

STACK* last=NULL;

void enqueue(int val) ;
void print_queue() ;

void reverse_odds();
int check_odd(int data);

void destroy_queue()  ;
void push(int val)  ;
int pop() ;


void main() {
	int total_line;
	int val;
	char ch;
	FILE* fp = fopen("data.txt","r+");
	fscanf(fp,"%d\n",&total_line);
	printf("\n%d line will be read \n",total_line);
	int i;
	for(i=0;i<total_line;i++) {
		ch=',';
		while(!feof(fp) && ch!='\n'){
			fscanf(fp,"%d%c",&val,&ch);
			if(is_odd(val))
				push(val);
			enqueue(val);
		}
		
		printf("\n");
		print_queue();
		printf("\n");
		reverse_and_display();
		destroy_queue();
		printf("\n____________________________________________\n");
	}
	
	
	system("pause");
	
}




void enqueue(int val) {
	QUEUE* node = (QUEUE*)malloc(sizeof(QUEUE));
	node->data = val;
	node->next=NULL;
	if(front==NULL && end==NULL) {

		front=node;
		end=node;
		
	}else {
		end->next = node;
		end=node;

	}
}



void print_queue() {
	QUEUE* iter = front;
	while(iter!=NULL) {
		printf("%4d",iter->data);
		iter=iter->next;
	}
}



void reverse_and_display() {
	
		QUEUE* iter = front;
	while(iter!=NULL) {
		if(is_odd(iter->data)){
			iter->data=pop();

		}
		printf("%4d",iter->data);

		iter=iter->next;
	}
} 

int is_odd(int data) {
	if(data%2!=0) 
		return 1;
	else
		return 0;
}





void destroy_queue() {
	if(end==NULL) {
		printf("QUEUE IS EMPTY\n");
	}
	QUEUE* temp;
	while(front!=NULL) {
		temp=front;
		front=front->next;
		free(temp);
	}
	front=NULL;
	end=NULL;
	
}


void push(int val) {
	STACK* temp =(STACK*)malloc(sizeof(STACK));
	temp->data=val;
	temp->next=last;
	last=temp;
}


int pop() {
	if(last==NULL) {
		return -1;
	}else {
		STACK* temp=last;
		int data = last->data ;
		last=last->next;
		free(temp);
		return data;
	}
	
}






