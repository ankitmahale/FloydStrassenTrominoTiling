/*

    Author: Ankit Mahale.
   email-id: amahale2@binghamton.edu.


*/


#include "mahale_pa2_stra.h"
#include "mahale_pa2_stra1.h"


int main(int argc, char* argv[]){
	int n=0, result=0;

	bool finalResult;
	int i=0,j=0,k=0;


	if(argc!=2){
		printf("\nWrong number of arguments\n");
		exit(0);
	}

	//To check power of 2
	int output = powerOf(atoi(argv[1]));
	if(output == 0){
		printf("\nPower of 2 condition fails\n");
		exit(0);
	}
	n=atoi(argv[1]);

	printf("\n\nStrassen's matrix multiplication algorithm!");

	vector<int> in (n);
    vector< vector<int> > matrixA(n, in), matrixB(n, in), straRes(n, in), stanRes(n, in);

	//Initializing the matrix
	initializeMatrix(matrixA,n);
	initializeMatrix(matrixB,n);
	initializeMatrix(stanRes,n);
	initializeMatrix(straRes,n);

	generateMatrix(matrixA, matrixB, n);


	standardMultiplication(matrixA, matrixB, stanRes, n);


	strassenMult(matrixA, matrixB, straRes, n);

	printf("matrixA is:");
	printMatrix(matrixA, n);
	printf("matrixB is:");
	printMatrix(matrixB, n);
	printf("Strassen multiplication is:");
	printMatrix(straRes, n);
	printf("Standard multiplication is:");
	printMatrix(stanRes, n);


	finalResult = compare(straRes, stanRes,n);

	if(finalResult == true){
		printf("\nStandard matrix multiplication and strassen's matrix multiplication are equal\n");
	}else if(finalResult == false){
		printf("\nStandard matrix multiplication and strassen's matrix multiplication are not equal\n");
	}
}
