# Homework 4 Hashing

## Output:





*******************************PERFORMANCE MEASURING FORMULA*******************************

                                (TABLESIZE + DIRECT INSERTINGx3)
        _____________________________________________________________________________________

                MAXIMUM COLLUSION x 30 + TOTALCOLLUSION + TABLESIZE + DIRECT INSERTINGx3 )



*********************************************************************************************************


COMPLEX HASH

                TABLE SIZE                      :       977     |       277
        _________________________________________________________________________

        Total detected collision                :       760     |       2302
        Maximum  collision for 1 element        :       17      |       193
        Insertion without collision             :       77      |       56
        _________________________________________________________________________
        Performance                             :       0.4875  |       0.0482


*********************************************************************************************************


SPREADER HASH

                TABLE SIZE                      :       977     |       277
        _________________________________________________________________________

        Total detected collision                :       438     |       3697
        Maximum  collision for 1 element        :       10      |       228
        Insertion without collision             :       112     |       78
        _________________________________________________________________________
        Performance                             :       0.6402  |       0.0435


*********************************************************************************************************


PRIME HASH

                TABLE SIZE                      :       977     |       277
        _________________________________________________________________________

        Total detected collision                :       269     |       702
        Maximum  collision for 1 element        :       8       |       48
        Insertion without collision             :       182     |       153
        _________________________________________________________________________
        Performance                             :       0.7495  |       0.2057


*********************************************************************************************************


PARSER HASH

                TABLE SIZE                      :       977     |       277
        _________________________________________________________________________

        Total detected collision                :       456     |       1607
        Maximum  collision for 1 element        :       10      |       178
        Insertion without collision             :       87      |       71
        _________________________________________________________________________
        Performance                             :       0.6209  |       0.0602


*********************************************************************************************************


SPECIAL HASH

                TABLE SIZE                      :       977     |       277
        _________________________________________________________________________

        Total detected collision                :       95      |       785
        Maximum  collision for 1 element        :       3       |       71
        Insertion without collision             :       228     |       146
        _________________________________________________________________________
        Performance                             :       0.8998  |       0.1651


___________________________________________________________________________________________________

*****************************THE BEST FUNCTION FOR BOTH 2 ARRAY SIZE*****************************

        TABLE SIZE      :       977             |               277
        _________________________________________________________________________
                        |SPECIAL HASH(0.8998)   |PRIME HASH (0.2057)

__________________________________________________________________________________________________



C:\Users\HP\source\repos\hw4\Debug\hw4.exe (process 13624) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
