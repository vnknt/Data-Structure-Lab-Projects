#define _CRT_SECURE_NO_WARNINGS
#define TABLESIZE 977       
#define TABLESIZE2 277     

#include<stdio.h>
#include<math.h>
#include<string.h>



typedef struct {

	int isActive; // 0 kayıt yok 1 kayıt var
	char no[11];
	char name[30];
	int grade;
}Student;

void printFormula();

void callFunction(int function(), char* name, int order);		
									/* parametre olarak Hash fonksiyonu alır,
									bazı global değişkenleri ve hash tablolarını initiliaze eder,
									parametre olarak aldığı fonksiyonu  çalıştırır
									gereksiz kod tekrarını önlemek için bu fonksiyonu kullandım */



int complexHash(Student student, const int tablesize);			
									/* string i ortadan ikiye bölüp ,
									 sağ ve sol tarafın toplamını birbiriyle çarpıp ,
									ortanca elemanın karesi ile toplar  */




int spreaderHash(Student student, const int tablesize);			
									/* string'in tüm elemanlarını toplar ve
									son 3 elemanın toplamı ile  çarpar    */





int primeHash(Student student, const int tablesize);
									/* her karakterin 10 modunu alıp ilk 10 asal sayıdan biri
									ile çarpıp sonuçları birbiriyle toplar */



int parserHash(Student student, const int tablesize);			
									/* dizinin çift sayı indisli elemanlarını toplayıp
									son 3 elemanın toplamı ile çarpar */




int specialHash(Student student, const int tablesize);			
									/*Bölümümüzde öğrenci numaralarının en çok
									4, 7, 8, 9, 10 uncu karakterleri
									ayırt edici olduğundan , sadece bu karakterler
									ile  bir hash değeri üretir*/




void printTheBest();											/*En iyi sonucu tablo olarak yazdırır*/



void initStruct(Student* hashTable, int size);					/* Hash Table ı initiliaze etmek için */





Student hashTable[TABLESIZE];		//GLOBAL HASH TABLE (   TABLESIZE 2 ICIN DE ISLEMLER BU TABLO UZERINDEN YAPILACAK  )
Student students[273];				//Data.txt bu diziye yollanacak , (tekrar tekrar okumamamk için)


char bestNameArray1[25];			//1. Tablo için en iyi hash fonksiyonun adı
double bestPerfArray1 = 0.f;			//1. Tablo için en iyi performans puanı

char bestNameArray2[25];			//2. Tablo için en iyi hash fonksiyonunun adı
double bestPerfArray2 = 0.f;		//2. Tablo için en iyi performans puanı


int collision = 0;					//Toplam çakışma
int maxCollision = 0;					//Maximum çakışma
int directAdding = 0;				//Çakışmasız ekleme





int main() {
	FILE* fp;
	fp = fopen("data.txt", "r");




	int i = 0;
	int line;
	fscanf(fp, "%d\n", &line);	//total student

	while (!feof(fp)) {
		fscanf(fp, "%[^\n,],%[^\n,],%d\n", students[i].no, students[i].name, &students[i].grade);
		i++;
	}


	printFormula();

	callFunction(complexHash, "COMPLEX HASH ", 0);
	callFunction(spreaderHash, "SPREADER HASH ", 1);
	callFunction(primeHash, "PRIME HASH ", 2);
	callFunction(parserHash, "PARSER HASH", 3);
	callFunction(specialHash, "SPECIAL HASH", 4);

	printf("\n\n");
	printTheBest();
	return 0;
}




//END OF MAIN












int complexHash(Student student, const int tableSize) {
	static int counter = 0;

	//HASHING PART

	char* key = student.no;

	int last = 0, first = 0;				//son ve  eleman tanımlama
	int sumRight = 0, sumLeft = 0;


	while (key[last + 1] != '\0') {		//string'in son elamanının indisini bulduk
		last++;
	}
	int middle = last / 2;
	if (middle == 0)
		middle = last;

	int size = last + 1;
	while (first < middle) {
		sumLeft += key[first];			//sol taraf toplamı
		first++;
	}
	while (last > middle) {
		sumRight += key[last];			//sağ taraf toplamı
		last--;
	}

	int hashVal = (sumRight * sumLeft) + key[middle] * middle;		//hash değeri
	hashVal = hashVal % tableSize;
	//INSERTION PART


			//boş ise ekle												 
			// dolu ise sonraki elemana bak ve collision counter ı arttır
	int i = 0;

	while (hashTable[hashVal].isActive != 0) {



		hashVal = (hashVal + 1) % tableSize;
		i++;
		collision++;

	}

	if (i > maxCollision)
		maxCollision = i;
	if (i == 0) {
		directAdding++;
	}

	counter++;
	//printf("%d collision detected %d\n", i, collision);

	strcpy(hashTable[hashVal].no, student.no);
	strcpy(hashTable[hashVal].name, student.name);
	hashTable[hashVal].grade = student.grade;
	hashTable[hashVal].isActive = 1;








	return 0;
}






int spreaderHash(Student student, const int tableSize) {

	char* key = student.no;
	int size = 0;
	int sum = 0;
	int lastThreeVal;

	while (key[size + 1] != '\0') {		//string'in son elamanının indisini bulduk
		sum += key[size];
		size++;
	}


	if (size > 2)
		lastThreeVal = key[size] + key[size - 1] + key[size - 2];
	else
		lastThreeVal = 37;

	int hashVal = sum * lastThreeVal % tableSize;

	//boş ise ekle												 
		// dolu ise sonraki elemana bak ve collision counter ı arttır
	int i = 0;



	while (hashTable[hashVal].isActive != 0) {



		hashVal = (hashVal + 1) % tableSize;
		i++;
		collision++;

	}
	if (i > maxCollision)
		maxCollision = i;
	if (i == 0)
		directAdding++;





	strcpy(hashTable[hashVal].no, student.no);
	strcpy(hashTable[hashVal].name, student.name);
	hashTable[hashVal].grade = student.grade;
	hashTable[hashVal].isActive = 1;







	return hashVal;








}



int parserHash(Student student, const int tableSize) {

	char* key = student.no;


	int last = 0, i = 0, sum = 0, lastThreeVal;

	while (key[last + 1] != '\0') {		//string'in son elamanının indisini bulduk
		last++;
	}

	while (i < last) {
		sum += key[i];
		i += 2;
	}
	if (last > 2)
		lastThreeVal = key[last] + key[last - 1] + key[last - 2];
	else
		lastThreeVal = 37;






	int hashVal = (sum * lastThreeVal) % tableSize;


	i = 0;





	while (hashTable[hashVal].isActive != 0) {


		hashVal = (int)(hashVal + ((int)pow(2, i) % tableSize)) % tableSize;
		if (hashVal < 0) {
			hashVal += tableSize;
		}

		i++;
		collision++;

	}
	if (i > maxCollision)
		maxCollision = i;
	if (i == 0)
		directAdding++;


	//printf("%d collision detected %d\n", i, collision);

	strcpy(hashTable[hashVal].no, student.no);
	strcpy(hashTable[hashVal].name, student.name);
	hashTable[hashVal].grade = student.grade;
	hashTable[hashVal].isActive = 1;


	return 0;

}



int primeHash(Student student, const int tableSize) {
	char* key = student.no;


	int primeNums[30] = { 2,3,5,7,11,13,17,19,23,27 };
	int i;

	int last = 0;



	while (key[last + 1] != '\0') {		//key uzunluğu
		last++;
	}

	i = 0;
	int sum = 0;


	while (i <= last) {
		sum += key[i] * primeNums[i % 10];
		i++;
	}

	int hashVal = sum % tableSize;


	i = 0;





	while (hashTable[hashVal].isActive != 0) {


		hashVal = (int)(hashVal + ((int)pow(2, i) % tableSize)) % tableSize;

		if (hashVal < 0)
			hashVal += tableSize;
		//printf("%d \n", hashVal);
		i++;
		collision++;

	}
	if (i > maxCollision)
		maxCollision = i;
	if (i == 0)
		directAdding++;


	//printf("%d collision detected %d\n", i, collision);

	strcpy(hashTable[hashVal].no, student.no);
	strcpy(hashTable[hashVal].name, student.name);
	hashTable[hashVal].grade = student.grade;
	hashTable[hashVal].isActive = 1;






	return 0;
}







void initStruct(Student* hashTable, int size) {
	int x = 0;
	while (x < size) {
		hashTable[x].isActive = 0;
		x++;
	}
	collision = 0;
	maxCollision = 0;
	directAdding = 0;

}


int specialHash(Student student, const int tableSize) {

	char* key = student.no;

	int val = (key[3] * 2 + key[7] * 5 + key[6] * 7 - 37) * (key[6] * 13 + key[8] * 3 + 37) + key[9] * 37;//2018556038 (8. 6. ve son 3 rakam ayırt edici)
	int counter = 0;


	int hashVal = val % tableSize;


	//INSERTION PART


		//boş ise ekle												 
		// dolu ise sonraki elemana bak ve collision counter ı arttır
	int i = 0;

	while (hashTable[hashVal].isActive != 0) {



		hashVal = (hashVal + (int)pow(i, 2)) % tableSize;
		if (hashVal < 0)
			hashVal += tableSize;

		i++;
		collision++;

	}

	if (i > maxCollision)
		maxCollision = i;
	if (i == 0) {
		directAdding++;
	}

	counter++;
	//printf("%d collision detected %d\n", i, collision);

	strcpy(hashTable[hashVal].no, student.no);
	strcpy(hashTable[hashVal].name, student.name);
	hashTable[hashVal].grade = student.grade;
	hashTable[hashVal].isActive = 1;








}





void callFunction(int function(), char* name, int order) {

	int i = 0;
	int collision_array1, collision_array2;
	int maxCollision_array1, maxCollision_array2;
	int directAdding_array1, directAdding_array2;



	initStruct(hashTable, TABLESIZE);




	while (i < 273) {

		function(students[i], TABLESIZE);
		i++;

	}


	collision_array1 = collision;
	maxCollision_array1 = maxCollision;
	directAdding_array1 = directAdding;



	i = 0;

	initStruct(hashTable, TABLESIZE);
	while (i < 273) {

		function(students[i], TABLESIZE2);

		i++;
	}

	collision_array2 = collision;
	maxCollision_array2 = maxCollision;
	directAdding_array2 = directAdding;


	double performance1 = (double)(TABLESIZE + directAdding_array1 * 3) / (maxCollision_array1 * 30 + collision_array1 + TABLESIZE + directAdding_array1 * 3);
	double performance2 = (double)(TABLESIZE2 + directAdding_array2 * 3) / (maxCollision_array2 * 30 + collision_array2 + TABLESIZE + directAdding_array2 * 3);


	printf("\n\n\n*********************************************************************************************************\n\n");
	printf("\n%s\n\n", name);


	printf("\t\tTABLE SIZE\t\t\t:\t%d\t|\t%d\n", TABLESIZE, TABLESIZE2);

	printf("\t_________________________________________________________________________\n");

	printf("\n\tTotal detected collision\t\t:\t%d\t|\t%d\n", collision_array1, collision_array2);
	printf("\tMaximum  collision for 1 element\t:\t%d\t|\t%d\n", maxCollision_array1, maxCollision_array2);
	printf("\tInsertion without collision\t\t:\t%d\t|\t%d\n", directAdding_array1, directAdding_array2);
	printf("\t_________________________________________________________________________\n");

	printf("\tPerformance \t\t\t\t:\t%.4f\t|\t%.4f", (performance1), (performance2));

	if (bestPerfArray1 < performance1) {
		bestPerfArray1 = performance1;
		strcpy(bestNameArray1, name);

	}
	if (bestPerfArray2 < performance2) {

		bestPerfArray2 = performance2;
		strcpy(bestNameArray2, name);

	}

}





void printTheBest() {
	printf("\n___________________________________________________________________________________________________\n");
	printf("\n*****************************THE BEST FUNCTION FOR BOTH 2 ARRAY SIZE*****************************\n\n");

	printf("\tTABLE SIZE\t:\t%d\t\t|\t\t%d\n", TABLESIZE, TABLESIZE2);

	printf("\t_________________________________________________________________________\n");

	printf("\t\t\t|%s(%.4f)\t|%s(%.4f)\n", bestNameArray1, bestPerfArray1, bestNameArray2, bestPerfArray2);

	printf("\n__________________________________________________________________________________________________\n\n\n");


}

void printFormula() {

	printf("\n\n*******************************PERFORMANCE MEASURING FORMULA*******************************\n");
	printf("\n\t\t\t\t(TABLESIZE + DIRECT INSERTINGx3)\n");
	printf("\t_____________________________________________________________________________________\n\n");
	printf("\t\tMAXIMUM COLLUSION x 30 + TOTALCOLLUSION + TABLESIZE + DIRECT INSERTINGx3 )\n ");

}