#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<math.h>



#define TABLESIZE 5077   


typedef struct linkedList {
	
	char data[35];
	float score;
struct linkedList * prev;
	struct linkedList * next;
	

}LIST;




typedef struct HashTable {
	int isActive;
	char data[35];
	
	
}TABLE;


TABLE HashTable[TABLESIZE] ;

void swap(char** s1, char** s2);
void quickSort(char** arr, int low, int high,int sorting);
int partition(char** arr, int low, int high,int sorting);
void printArray(char** arr, int size);
float password_strength(char* password);
int find(char** arr, char* key, int size,int* is_sorted);
float password_strength(char* password);
int readFile(FILE* fp, const char* fileName, char** arr);


void linkedlist_insert(char* password,float strength );
void display(int limit);
void sort(int sorting );


int hashFunction(char* str);





void initTable();


LIST * head = NULL;
LIST*  tail = NULL;

char* passw_1b[1000] = { NULL };
char* passw_10b[10000] = { NULL };
char* passw_100b[100000] = { NULL };
char* passw_1m[1000000] = { NULL };

char filePath[50] = "10-million-password-list-top/";

int is_sorted_1b, is_sorted_10b, is_sorted_100b, is_sorted_1m;

int main()
{


	FILE* fp = NULL;
	int selection = -1;

	do {
		fp = NULL;
	
		printf("\n\n\n___________________________________________________\n\n");
		printf("                          MENU                       ");
			
		printf("\n___________________________________________________\n");
		
		printf("1-  Search a Password in 100.000 Passwords.\n");
		printf("2-  Sort 10.000 Password\n");
		printf("3-  Insert 1.000.txt in to linked list and check scores \n");
		printf("4-  Insert 1.000 Password in to Hash Table and search\n");

		printf("\n");
		
		printf("5- Search a password in 1 million password\n");

		
		printf("0-  EXIT \n\nYour selection:");
		
		scanf("%d",&selection);
		printf("\n####################################################\n");
		switch (selection) {
			int x,h,i;
			char key[35];
			
			
			
		case 1 :
			if (passw_100b[1] == NULL) {
				 x = readFile(fp, "100000.txt",passw_100b);
			}
			else {
				x = 100000;
			}
			printf("\nEnter a password to find : ");
			
			
			scanf("%s", key);
			
			
			int result = find(passw_100b,key, x,&is_sorted_100b);

			if (result == -1) {
				printf("\n%s Not found\n",key);

			}
			else {
				printf("\n%s exists in the list\n",key);

			}
			
			break;



		case 2:
			
			
			if (passw_10b[1] == NULL) {
				x = readFile(fp, "10000.txt", passw_10b);
			}
			else {
				x = 10000;
			}
		
			printf("\n\n--------  DESCENDING ORDER  (TOP 10)  --------\n\n");
			
			quickSort(passw_10b, 0, x - 1, 0);
			printArray(passw_10b,10);
			printf("\n--------   ASCENDING ORDER  (TOP 10)  --------\n\n");
			quickSort(passw_10b, 0, x - 1, 1);
			printArray(passw_10b,10);

			break;


		
		case 3:
			if (passw_1b[1] == NULL) {
				x = readFile(fp, "1000.txt", passw_1b);
			}
			else {
				x = 1000;
			}
			
			 i;
			
			for(i=0;i<x;i++) {
				
				int strength = password_strength(passw_1b[i]);
				
				linkedlist_insert(passw_1b[i],strength);
			
			}
			
			sort(0);
			display(10);			
			sort(1);
			display(10);
			break;
			
		case 4:
				
			if (passw_1b[1] == NULL) {
				x = readFile(fp, "1000.txt", passw_1b);
			}
			else {
				x = 1000;
			}
			
			 i =0;
			 initTable();
				
			while(i<x) {
				

				insert_hashTable(passw_1b[i]);
				
				i++;
				
				
				
			}
				printf("\n\n ***1000 passwords are inserted into Hash Table***\n\n");
			

			printf("\nPlease enter a password to search in HASH TABLE   :  ");
			scanf("%s",key);
			result = search_hashTable(key);
			
			
			
			if(result==-1) {
				printf("%s NOT FOUND !!!",key);
				
			}else {
				printf("%s is found with %d Collision !!!\n",key,result);
			}

			break;
			
		
		
		
		case 5:
			printf("\nEnter a password to find : ");
			
			
			scanf("%s", key);
			
				if (passw_1m[1] == NULL) {
				 x = readFile(fp, "1000000.txt",passw_1m);
			}
			else {
				x = 1000000;
			}
			
			
			 result = find(passw_1m,key, x,&is_sorted_1m);

			if (result == -1	) {
				printf("\n%s Not found\n",key);

			}
			else {
				printf("\n%s exists in the list\n",key);

			}
			
			break;
			
			

		}

		printf("\n####################################################\n");
	system("pause");
	}while(selection!=0);

	
	return 0;
}

int partition(char** arr, int low, int high,int sorting)
{
	int j;
	char pivot[40];
	
	if(sorting==1){	
		strcpy(pivot,arr[high]) ;   
	}

	if(sorting==0){
		strcpy(pivot,arr[high]) ;   		
	}

	int i = (low - 1);  

	for (j = low; j <= high - 1; j++)
	{
		if (sorting == 1) {

			if (strcmp(arr[j], pivot) < 0)
			{
				i++;
				swap(&arr[i], &arr[j]);
			}
		}
		else if (sorting == 0) {

			if (strcmp(arr[j], pivot) > 0)
			{
				i++;
				swap(&arr[i], &arr[j]);


			}

		}

	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}


void quickSort(char** arr, int low, int high,int sorting  )
{

	if (low < high)
	{
		int pi = partition(arr, low, high,sorting);

		quickSort(arr, low, pi - 1,sorting);
		quickSort(arr, pi + 1, high,sorting);
	}
	
}



float password_strength(char* password) {

	int len = strlen(password);
	
	char ch1;
	int contains_diff_chars =1;
	int not_letters =0, letters =0;
	int c;
	ch1 = password[0];
	
	
	
	for (c = 0; c < len; c++) {

		if ((password[c] > 64 && password[c] < 91) || (password[c] > 96 && password[c] < 123))
			letters++;
		else
			not_letters++;
			
		if (ch1 != password[c] && c != 0 && contains_diff_chars == 0) {
			contains_diff_chars = 2;
		}

	}


	int strength = contains_diff_chars * 5 * (letters * not_letters + len);


	if (len < 5) {
		strength = 0;

	}

	return strength;
}


int find(char** arr, char* key, int size,int* is_sorted) {
	
	if (! *is_sorted) {

		quickSort(arr, 0, size - 1,1);
		*is_sorted = 1;

	}
	
	


	int first = 0;
	int last = size - 1;
	int mid;
	while (first <= last) {
		mid = first + (last - first) / 2;

		if (strcmp(arr[mid],key)<0) {
			first = mid + 1;
		}
		else if (strcmp(arr[mid], key) > 0 ) {
			last = mid - 1;
		}
		else {
			return mid;
		}
	}

	return -1;
}

void swap(char** s1, char** s2)
{

	if (*s1 != *s2) {
	char* temp = *s1;
	*s1 = *s2;
	*s2 = temp;

	}

}


int readFile(FILE* fp, const char* fileName, char** arr) {
	char path_filename[50];
	strcpy(path_filename, filePath);
	int sizeFileName = strlen(fileName);
	strncat(path_filename, fileName, sizeFileName);


	fp = fopen(path_filename, "r+");
	int i = 0;


	while (!feof(fp)) {
		arr[i] = (char*)malloc(sizeof(char) * 30);

		fscanf(fp, "%s\n", arr[i]);

		i++;

	}


	int size = i;
	fclose(fp);
	return size;

}



void printArray(char** arr, int size) {

	int i = 0;
	for (i = 0; i < size; i++) {
		printf("%s ", arr[i]);

		printf("\n");
	}


}

 void linkedlist_insert(char* password,float strength ) {
	struct linkedList* ptr = (LIST*)malloc(sizeof(LIST));
	strcpy(ptr->data,password);
	ptr->score=strength;
	if (ptr == NULL)
	{
		printf("\nThere is an error in Malloc!");
	}
	else {

		if (head == NULL)
		{
			ptr->prev = NULL;
			ptr->next = NULL;
			head = ptr;
			tail = head;
		}
		else {
			struct linkedList* temp = head;
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


void sort(int sorting ) {
	if (head == tail) {
		printf("\nSorting needs minimum 2 variables\n");
		return;
	}

	struct linkedList* iter = head;
	struct linkedList* ptr = head;


	char temp[35];
	float tempScore;

	while (ptr != NULL)

	{
		iter = head;
		while (iter->next != NULL) {
		if(sorting==1) {
			if ( iter->next->score   <  iter->score  ) {
				
				
				                                 
				strcpy(temp,iter->data)	;		
				tempScore=iter->score;
				
				
				
				strcpy(iter->data,iter->next->data)	;
				iter->score= iter->next->score;
				
				
				strcpy(iter->next->data,temp)	;
				iter->next->score=tempScore;
				
				
				
			}
			iter = iter->next;
			}
			
		
		if(sorting==0) {
			if ( iter->next->score   > iter->score  ) {
				                                 
				strcpy(temp,iter->data)	;		
				tempScore=iter->score;
				
				
				
				strcpy(iter->data,iter->next->data)	;
				iter->score= iter->next->score;
				
				
				strcpy(iter->next->data,temp)	;
				iter->next->score=tempScore;
				
				
				
			}
			iter = iter->next;
			}
				
			}
			
			ptr = ptr->next;	
		}

	}



void display(int limit) {
	int i=0;
	struct linkedList* ptr = tail;
	if (ptr == NULL)
	{
		printf("\nList is empty!");
	}
	else {
		while (ptr != NULL,limit>0)
		{
			printf("%d   %s\t%f\n", i++,ptr->data,ptr->score);
			ptr = ptr->prev;
			limit--;
		}
	}
	printf("\n");
}





int hashFunction(char* str) {
	int hashVal=0;
	char ch;
	
	int i=0;
	do{
		ch=str[i];

		hashVal= ((int)	(hashVal + ch+37*i )	 )% TABLESIZE;
		if(hashVal<0) {
			hashVal=hashVal+TABLESIZE;
		}
		
		i++;
	}while(str[i]!='\0');
	
return hashVal;
}


void initTable() {
	int i =0;
	
	
	while(i<TABLESIZE) {
		HashTable[i].isActive = 0;
		i++;
	}
	
	
	
}


int insert_hashTable(char* str) {
	
	
	int hashVal= hashFunction(str);
	
	int i = 0;
	int collision =0;
	
	
	while(HashTable[hashVal].isActive !=0) {
		
		hashVal = (hashVal + (int)pow(i, 2)) % TABLESIZE;
		
		if (hashVal < 0)
			hashVal += TABLESIZE;
		
		collision++;
		i++;
		
	}
	
	strcpy(HashTable[hashVal].data, str);
	HashTable[hashVal].isActive = 1;

	return collision;
	
	
}




int search_hashTable(char* str) {
	
	
	int hashVal= hashFunction(str);
	
	int i = 0;
	int collision =0;
	int flag=0;
	
	
	while(HashTable[hashVal].isActive !=0) {
		
		hashVal = (hashVal + (int)pow(i, 2)) % TABLESIZE;
		
		
		
		
		
		if (hashVal < 0)
			hashVal += TABLESIZE;
			
		if(strcmp(HashTable[hashVal].data,str) == 0 ) {
			flag=1;
			break;
		}

			
		collision++;
		i++;
		
	}
	
	if(flag==1) {
		return collision;
		
	}
	if(flag==0) {
		return -1;
		
		
	}
	
}

