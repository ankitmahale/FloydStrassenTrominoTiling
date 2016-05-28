/*

    Author: Ankit Mahale.
   email-id: amahale2@binghamton.edu.


*/


#ifndef MAHALE_PA2_STRA_H_INCLUDED
#define MAHALE_PA2_STRA_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>
#include<cmath>
#include<vector>

using namespace std;

//check if power of 2
int powerOf (int n)
{
 while (((n % 2) == 0) && n > 1)
   n /= 2;
 return (n == 1);
}



//Initializing the matrix
void initializeMatrix(vector< vector<int> > &matrix, int n){
	int i=0,j=0;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			matrix[i][j] = 0;
		}
	}
}

//Generating random matrices.
void generateMatrix(vector< vector<int> > &matrixA,vector< vector<int> > &matrixB,int n){
	int i=0,j=0;

    srand(time(NULL));
    for(i = 0; i<n; i++){
        for(j = 0; j<n; j++){

            matrixA[i][j] = rand()%10;
            matrixB[i][j] = rand()%20;
		}
	}
}

//Printing the value of the matrix
void printMatrix(vector< vector<int> > &matrix, int n){
	int i=0,j=0;

	printf("\n");
	for(i=0;i<n;i++){
		printf("\n");
		for(j=0;j<n;j++){
			printf("\t%d", matrix[i][j]);
		}
	}
	printf("\n");
}



#endif // MAHALE_PA2_STRA_H_INCLUDED
