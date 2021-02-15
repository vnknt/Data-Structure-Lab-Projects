

*********************
Hocam data.txt dosyasını okurken türkçe karakterler olduğundan aramada sorun yaşadım . Türkçe karakter içermeyenleri sorunsuz buluyordum o yüzden MEHMET İPEK ve DENİZ UĞUR isimlerindeki Türkçe karakterleri değiştirdim 
*********************




# Homework 3 Searching

Write a single search program in C which consist the combination of below examples. Put a screenshot of outputs for each search and update this README with outputs also. 

Linear Search in Integer Array  
Binary Search in Integer Array

Linear Search in Struct Array with primary key  
Binary Search in Struct Array with primary key

Linear Search in Struct Array with secondary key  
Binary Search in Struct Array with secondary key


## Input Data:
### Integer Arrays

Integer Array1: 3,44,38,5,47,15,36,26,27,2,46,4,19,50,48  
Integer Array2: 3,44,48,5,47,15,36,26,27,2,48,5,19,50,48

Seperately search for **3,5,48** in both Array1 and Array2.

### Struct Array

Complete data is stored in data.txt file.
Sample of Data:

Number of Student  
Number,Name,Grade  
Number,Name,Grade  

3  
2015556001,Ahmet Yılmaz,75  
2015555002,Mesut Çevik,56  
2014556453,Yılmaz Turgut,100

Seperately search for below data and show all the information belongs to them:

MEHMET İPEK  
DENİZ UĞUR  
2019556465  
2018556011  
100  
73  
0

## Output:










LINEAR SEARCH IN ARRAY 1 :
        3 - 44 - 38 - 5 - 47 - 15 - 36 - 26 - 27 - 2 - 46 - 4 - 19 - 50 - 48 -
        
                   3 is   0 th element of this array

                   5 is   3 th element of this array

                   48 is   14 th element of this array


BINARY  SEARCH IN ARRAY 1 :
        2 - 3 - 4 - 5 - 15 - 19 - 26 - 27 - 36 - 38 - 44 - 46 - 47 - 48 - 50 -
        
                   3 is   1 th element of this array

                   5 is   3 th element of this array

                   48 is   13 th element of this array

LINEAR SEARCH IN ARRAY 2 :
        3 - 44 - 48 - 5 - 47 - 15 - 36 - 26 - 27 - 2 - 48 - 5 - 19 - 50 - 48 -
        
                   3 is   0 th element of this array

                   5 is   3 th element of this array
                   5 is   11 th element of this array

                   48 is   2 th element of this array
                   48 is   10 th element of this array
                   48 is   14 th element of this array


BINARY  SEARCH IN ARRAY 2 :
        2 - 3 - 5 - 5 - 15 - 19 - 26 - 27 - 36 - 44 - 47 - 48 - 48 - 48 - 50 -
        
                   3 is   1 th element of this array

                   5 is   2 th element of this array
                   5 is   3 th element of this array

                   48 is   11 th element of this array
                   48 is   12 th element of this array
                   48 is   13 th element of this array


*******************************************************************************************************************

Linear  search  for secondary key (name = MEHMET IPEK)    ------>  2  result found

        2019555404 MEHMET IPEK 75
        2019556465 MEHMET IPEK 9

Linear  search  for secondary key (name = DENIZ UGUR)    ------>  1  result found

        2018555063 DENIZ UGUR 25

*******************************************************************************************************************

Binary  search  for secondary key (name = DENIZ UGUR)    ------>  1  result found

        2018555063 DENIZ UGUR 25

Binary  search  for secondary key (name = MEHMET IPEK)    ------>  2  result found

        2019555404 MEHMET IPEK 75
        2019556465 MEHMET IPEK 9

*******************************************************************************************************************

Linear search for primary key (2019556465)

        2019556465 MEHMET IPEK 9
Linear search for primary key (2018556011)

        2018556011 ELMAS BAYRAM 6
Binary search for primary key (2019556465)

        2019556465 MEHMET IPEK 9
Binary search for primary key (2018556011)

        2018556011 ELMAS BAYRAM 6

*******************************************************************************************************************

Linear  search  for secondary key (grade = 0)   ------>  3  result found

        2014556020 BUGRACAN BÜYÜKYILMAZ 0
        2016556053 CAN SOYLU 0
        2019555063 BERKE TABAK 0

Linear  search  for secondary key (grade = 100)    ------>  2  result found

        2017556301 SAMAH KURDİ 100
        2019556452 EMRULLAH AKTÜRK 100

Linear  search  for secondary key (grade = 73)    ------>  2  result found

        2017555364 FATMA BOZAGA 73
        2017556072 SONER CAN ZENCİRKIRAN 73

*******************************************************************************************************************

Binary  search  for secondary key (grade = 100)    ------>  2  result found

        2017556301 SAMAH KURDİ 100
        2019556452 EMRULLAH AKTÜRK 100

Binary  search  for secondary key (grade = 73)    ------>  2  result found

        2017555364 FATMA BOZAGA 73
        2017556072 SONER CAN ZENCİRKIRAN 73

Binary  search  for secondary key (grade = 0)    ------>  3  result found

        2014556020 BUGRACAN BÜYÜKYILMAZ 0
        2016556053 CAN SOYLU 0
        2019555063 BERKE TABAK 0
