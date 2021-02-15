#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<locale.h>
typedef struct {
	int number;
	char name[30];
	int  grade;

}Student;




int binarysearchGrade(Student arr[], int key, int size, int result[]);
int binarysearchNumber(Student arr[], int key, int size);
int binarysearchInt(int  arr[], int key, int size, int result[]);



int linearsearchNumber(Student arr[], int x, int a);
int linearsearchGrade(Student arr[], int x, int a, int* result);
int linearsearchName(Student arr[], int x, char* a, int* result);
int linearSearchInt(int arr[], int size, int key, int result[]);
int binarysearchName(Student arr[], char* key, int size, int result[]);



void bubble_sort_grade(Student list[], int n);
void bubble_sort_number(Student list[], int n);
void bubble_sort_name(Student list[], int n);
void bubleSortInt(int arr[], int n);


void swapInt(int* x, int* y);
void swapStudent(Student* x, Student* y);
void initResult(int result[], int size);




void prntInfo(Student arr[], int i);
void printResult(Student arr[], int result[]);
void printResultPrimary(Student arr[], int index);
void printIntResult(int arr[], int result[]);
void printArray(int arr[], int size);







int main() {
	setlocale(LC_ALL, "tr_TR.UTF-8");

	Student students[273];
	int sizeStudent = sizeof(students) / sizeof(students[0]);


	int result[273];
	initResult(result, sizeStudent);

	FILE* fp;
	fp = fopen("data.txt", "rb");

	int i = 0;


	int resultInt[20];
	int sizeR = 20;

	initResult(resultInt, sizeR);



	int array1[] = { 3,44,38,5,47,15,36,26,27,2,46,4,19,50,48 };
	int size1 = sizeof(array1) / sizeof(array1[0]);

	int array2[] = { 3,44,48,5,47,15,36,26,27,2,48,5,19,50,48 };
	int size2 = sizeof(array2) / sizeof(array2[0]);


	printf("LINEAR SEARCH IN ARRAY 1 :\n");


	initResult(resultInt, sizeR);

	printArray(array1, size1);
	initResult(resultInt, sizeR);
	int result1 = linearSearchInt(array1, size1, 3, resultInt);
	printIntResult(array1, resultInt);



	initResult(resultInt, sizeR);
	result1 = linearSearchInt(array1, size1, 5, resultInt);
	printIntResult(array1, resultInt);



	initResult(resultInt, sizeR);
	result1 = linearSearchInt(array1, size1, 48, resultInt);
	printIntResult(array1, resultInt);




	// 




	printf("\nBINARY  SEARCH IN ARRAY 1 :\n");


	initResult(resultInt, sizeR);

	bubleSortInt(array1, size1);
	printArray(array1, size1);
	binarySearchInt(array1, 3, size1, resultInt);
	printIntResult(array1, resultInt);


	initResult(resultInt, sizeR);
	bubleSortInt(array1, size1);
	binarySearchInt(array1, 5, size1, resultInt);
	printIntResult(array1, resultInt);

	initResult(resultInt, sizeR);
	bubleSortInt(array1, size1);
	binarySearchInt(array1, 48, size1, resultInt);
	printIntResult(array1, resultInt);




	printf("LINEAR SEARCH IN ARRAY 2 :\n");


	initResult(resultInt, sizeR);

	printArray(array2, size2);
	initResult(resultInt, sizeR);
	result1 = linearSearchInt(array2, size2, 3, resultInt);
	printIntResult(array2, resultInt);



	initResult(resultInt, sizeR);
	result1 = linearSearchInt(array2, size2, 5, resultInt);
	printIntResult(array2, resultInt);



	initResult(resultInt, sizeR);
	result1 = linearSearchInt(array2, size2, 48, resultInt);
	printIntResult(array2, resultInt);




	printf("\nBINARY  SEARCH IN ARRAY 2 :\n");


	initResult(resultInt, sizeR);

	bubleSortInt(array2, size2);
	printArray(array2, size2);
	binarySearchInt(array2, 3, size2, resultInt);
	printIntResult(array2, resultInt);

	initResult(resultInt, sizeR);
	bubleSortInt(array2, size2);
	binarySearchInt(array2, 5, size2, resultInt);
	printIntResult(array2, resultInt);

	initResult(resultInt, sizeR);
	bubleSortInt(array2, size2);
	binarySearchInt(array2, 48, size2, resultInt);
	printIntResult(array2, resultInt);




	printf("\n*******************************************************************************************************************\n");


	while (!feof(fp)) {

		fscanf(fp, "%d,%[^\n,],%d\n", &students[i].number, students[i].name, &students[i].grade);

		i++;
	}





	printf("\nLinear  search  for secondary key (name = MEHMET IPEK) ");
	char name[30];

	strcpy(name, "MEHMET IPEK");

	int nameR = linearsearchName(students, sizeStudent, name, result);
	printf("   ------>  %d  result found\n", nameR);
	printResult(students, result);

	initResult(result, sizeStudent);













	printf("\nLinear  search  for secondary key (name = DENIZ UGUR) ");
	strcpy(name, "DENIZ UGUR");
	nameR = linearsearchName(students, sizeStudent, name, result);
	printf("   ------>  %d  result found\n", nameR);
	printResult(students, result);



	printf("\n*******************************************************************************************************************\n");





	printf("\nBinary  search  for secondary key (name = DENIZ UGUR) ");
	strcpy(name, "DENIZ UGUR");

	bubble_sort_name(students, sizeStudent);
	initResult(result, sizeStudent);
	nameR = binarysearchName(students, name, sizeStudent, result);
	printf("   ------>  %d  result found\n", nameR);
	printResult(students, result);







	printf("\nBinary  search  for secondary key (name = MEHMET IPEK) ");
	strcpy(name, "MEHMET IPEK");

	bubble_sort_name(students, sizeStudent);
	initResult(result, sizeStudent);
	nameR = binarysearchName(students, name, sizeStudent, result);
	printf("   ------>  %d  result found\n", nameR);
	printResult(students, result);


















	printf("\n*******************************************************************************************************************\n");


	printf("\n");


	printf("Linear search for primary key (2019556465) \n");
	int x1 = linearsearchNumber(students, sizeStudent, 2019556465);

	printResultPrimary(students, x1);


	printf("Linear search for primary key (2018556011)\n");
	int x2 = linearsearchNumber(students, sizeStudent, 2018556011);

	printResultPrimary(students, x2);


	printf("Binary search for primary key (2019556465)\n");
	bubble_sort_number(students, sizeStudent);
	x1 = binarysearchNumber(students, 2019556465, sizeStudent);
	printResultPrimary(students, x1);

	printf("Binary search for primary key (2018556011)\n");
	bubble_sort_number(students, sizeStudent);
	x1 = binarysearchNumber(students, 2018556011, sizeStudent);
	printResultPrimary(students, x1);

	printf("\n*******************************************************************************************************************\n");


	printf("\nLinear  search  for secondary key (grade = 0)");
	initResult(result, sizeStudent);
	x1 = linearsearchGrade(students, sizeStudent, 0, result);
	printf("   ------>  %d  result found\n", x1);
	printResult(students, result);


	printf("\nLinear  search  for secondary key (grade = 100) ");
	initResult(result, sizeStudent);
	x1 = linearsearchGrade(students, sizeStudent, 100, result);
	printf("   ------>  %d  result found\n", x1);
	printResult(students, result);




	printf("\nLinear  search  for secondary key (grade = 73) ");
	initResult(result, sizeStudent);
	x1 = linearsearchGrade(students, sizeStudent, 73, result);
	printf("   ------>  %d  result found\n", x1);
	printResult(students, result);

	printf("\n*******************************************************************************************************************\n");


	printf("\nBinary  search  for secondary key (grade = 100) ");

	initResult(result, sizeStudent);
	bubble_sort_grade(students, sizeStudent);
	x1 = binarysearchGrade(students, 100, sizeStudent, result);
	printf("   ------>  %d  result found\n", x1);
	printResult(students, result);




	printf("\nBinary  search  for secondary key (grade = 73) ");


	initResult(result, sizeStudent);
	bubble_sort_grade(students, sizeStudent);
	x1 = binarysearchGrade(students, 73, sizeStudent, result);
	printf("   ------>  %d  result found\n", x1);
	printResult(students, result);


	printf("\nBinary  search  for secondary key (grade = 0) ");


	initResult(result, sizeStudent);
	bubble_sort_grade(students, sizeStudent);
	x1 = binarysearchGrade(students, 0, sizeStudent, result);
	printf("   ------>  %d  result found\n", x1);
	printResult(students, result);



}
int binarysearchNumber(Student arr[], int key, int size) {
	int first = 0;
	int last = size - 1;
	int mid;
	while (first <= last) {
		mid = first + (last - first) / 2;

		if (arr[mid].number < key) {
			first = mid + 1;
		}
		else if (arr[mid].number > key) {
			last = mid - 1;
		}
		else {
			return mid;
		}
	}


	return -1;
}


void initResult(int result[], int size) {

	int i;
	for (i = 0; i < size; i++) {
		result[i] = -1;


	}



}


void bubble_sort_name(Student list[], int n)
{
	int c, d;


	for (c = 0; c < n - 1; c++) {
		for (d = 0; d < n - c - 1; d++) {
			if (strcmp(list[d].name, list[d + 1].name) > 0) {



				swapStudent(&list[d], &list[d + 1]);

			}
		}
	}
}


void prntInfo(Student arr[], int i) {


	if (i == -1) {
		printf("Not found");


	}
	else {
		printf("%d  %s  %d", arr[i].number, arr[i].name, arr[i].grade);


	}

}

/*
grade binary
name  binary
*/

int binarysearchGrade(Student arr[], int key, int size, int result[]) {
	int first = 0;
	int last = size - 1;
	int mid;
	int i = 0;
	int flag = 0;
	while (first <= last) {
		mid = (first + last) / 2;

		if (arr[mid].grade < key) {
			first = mid + 1;
		}
		else if (arr[mid].grade > key) {
			last = mid - 1;
		}
		else {
			while (arr[mid - 1].grade == key) {
				mid--;		// ilk elemaný bulmak için
			}
			while (arr[mid].grade == key) {  // son elemana kadar result a aktar
				result[i] = mid;
				i++;
				mid++;
			}
			return i;
		}
	}
	if (flag)
		return i;
	else
		return -1;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int linearsearchNumber(Student arr[], int x, int a)
{
	int i;
	for (i = 0; i < x; i++) {

		if (arr[i].number == a)
			return i;


	}
	return -1;

}


int linearsearchGrade(Student arr[], int x, int a, int* result)

{
	int i;
	int j = 0;

	for (i = 0; i < x; i++) {

		if (arr[i].grade == a) {
			result[j] = i;
			j++;
		}

	}

	return j;

}


int linearsearchName(Student arr[], int x, char* a, int* result)

{
	int i;
	int j = 0;

	for (i = 0; i < x; i++) {

		if (strcmp(arr[i].name, a) == 0) {
			result[j] = i;
			j++;
		}

	}

	return j;

}


void bubble_sort_grade(Student list[], int n)
{
	int c, d;
	for (c = 0; c < n - 1; c++) {
		for (d = 0; d < n - c - 1; d++) {
			if (list[d].grade > list[d + 1].grade) {

				swapStudent(&list[d], &list[d + 1]);


			}
		}
	}
}

void bubble_sort_number(Student list[], int n)
{
	int c, d;
	for (c = 0; c < n - 1; c++) {
		for (d = 0; d < n - c - 1; d++) {
			if (list[d].number > list[d + 1].number) {

				swapStudent(&list[d], &list[d + 1]);


			}
		}
	}
}
void swapStudent(Student* x, Student* y) {

	Student temp;
	temp = *x;
	*x = *y;
	*y = temp;


}
void printResult(Student arr[], int result[]) {
	int i = 0;
	printf("\n");
	while (result[i] != -1) {

		printf("\t%d %s %d \n", arr[result[i]].number, arr[result[i]].name, arr[result[i]].grade);
		i++;

	}

	if (i == 0)
		printf("Not found\n");


}

void printResultPrimary(Student arr[], int index) {
	if (index != -1)
		printf("\t%d %s %d \n", arr[index].number, arr[index].name, arr[index].grade);
	else
		printf("Not found\n");

}












int binarysearchInt(int  arr[], int key, int size, int result[]) {
	int first = 0;
	int last = size - 1;
	int mid;
	int i = 0;

	while (first <= last) {
		mid = (first + last) / 2;

		if (arr[mid] < key) {
			first = mid + 1;
		}
		else if (arr[mid] > key) {
			last = mid - 1;
		}
		else {
			while (arr[mid - 1] == key) {
				mid--;		// ilk elemaný bulmak için
			}
			while (arr[mid] == key) {  // son elemana kadar result a aktar
				result[i] = mid;
				i++;
				mid++;
			}
			return i;
		}
	}

	return -1;
}





int binarysearchName(Student arr[], char* key, int size, int result[]) {
	int first = 0;
	int last = size - 1;
	int mid;
	int i = 0;
	int flag = 0;
	while (first <= last) {
		mid = (first + last) / 2;

		if (strcmp(arr[mid].name, key) < 0) {
			first = mid + 1;
		}
		else if (strcmp(arr[mid].name, key) > 0) {
			last = mid - 1;
		}
		else {
			while (strcmp(arr[mid - 1].name, key) == 0) {
				mid--;		// ilk elemaný bulmak için

			}
			while (strcmp(arr[mid].name, key) == 0) {  // son elemana kadar result a aktar
				result[i] = mid;

				i++;
				mid++;

			}
			return i;
		}
	}


	return -1;
}



void printArray(int arr[], int size) {
	int i;
	printf("\t");
	for (i = 0; i < size; i++) {

		printf("%d - ", arr[i]);

	}
	printf("\n");
}


int linearSearchInt(int arr[], int size, int key, int result[]) {
	int i = 0;
	int j = 0;

	while (i < size) {
		if (arr[i] == key) {
			result[j] = i;
			j++;
		}
		i++;
	}
	if (j == 0)
		return -1;
	else
		return j;

}


void printIntResult(int arr[], int result[]) {
	int i = 0;

	while (result[i] != -1) {
		printf("\t");	printf("\t");
		printf("   %d is   %d th element of this array\n", arr[result[i]], result[i]);
		i++;
	}
	printf("\n");
}

int binarySearchInt(int  arr[], int key, int size, int result[]) {
	int first = 0;
	int last = size - 1;
	int mid;
	int i = 0;

	while (first <= last) {
		mid = (first + last) / 2;

		if (arr[mid] < key) {
			first = mid + 1;
		}
		else if (arr[mid] > key) {
			last = mid - 1;
		}
		else {
			while (arr[mid - 1] == key) {
				mid--;		// ilk elemaný bulmak için
			}
			while (arr[mid] == key) {  // son elemana kadar result a aktar
				result[i] = mid;
				i++;
				mid++;
			}
			return i;
		}
	}

	return -1;
}


void bubleSortInt(int arr[], int n) {

	int c, d;
	for (c = 0; c < n - 1; c++) {
		for (d = 0; d < n - c - 1; d++) {
			if (arr[d] > arr[d + 1]) {
				swapInt(&arr[d], &arr[d + 1]);
			}
		}
	}
}


void swapInt(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;

}

