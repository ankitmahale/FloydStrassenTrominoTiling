/*

    Author: Ankit Mahale.
   email-id: amahale2@binghamton.edu.

This is a master
*/


#ifndef MAHALE_PA2_STRA1_H_INCLUDED
#define MAHALE_PA2_STRA1_H_INCLUDED

// Function for standard matrix multiplication.
void standardMultiplication(vector< vector<int> > &matrixA,vector< vector<int> > &matrixB,vector< vector<int> > &stanRes,int n){
	int i=0,j=0,k=0;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				stanRes[i][j] = stanRes[i][j]	+ matrixA[i][k] * matrixB[k][j];
			}
		}
	}
}

//Fucntion to find the sum of intermediate matrices in strassens
void sum(vector< vector<int> > &matrixA, vector< vector<int> > &matrixB, vector< vector<int> > &sum, int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            sum[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

//Function to substract intermediate matrix in starssens
void subtract(vector< vector<int> > &matrixA, vector< vector<int> > &matrixB, vector< vector<int> > &subtraction, int n) {
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            subtraction[i][j] = matrixA[i][j] - matrixB[i][j];
        }
    }
}

unsigned int nextPowerOfTwo(int n) {
    return pow(2, int(ceil(log2(n))));
}

//For strassens recursive function.
void strassenRecur(vector< vector<int> > &matrixA, vector< vector<int> > &matrixB, vector< vector<int> > &straRes, int n) {

    if (n <= 1) {
        standardMultiplication(matrixA, matrixB, straRes, n);
        return;
    }


    else {
        int newSize = n/2;
        vector<int> in (newSize);
        vector< vector<int> >
            a11(newSize,in), a12(newSize,in), a21(newSize,in), a22(newSize,in),
            b11(newSize,in), b12(newSize,in), b21(newSize,in), b22(newSize,in),
            c11(newSize,in), c12(newSize,in), c21(newSize,in), c22(newSize,in),
            m1(newSize,in), m2(newSize,in), m3(newSize,in), m4(newSize,in),
            m5(newSize,in), m6(newSize,in), m7(newSize,in),
            aResult(newSize,in), bResult(newSize,in);

        int i, j;

        for (i = 0; i < newSize; i++) {
            for (j = 0; j < newSize; j++) {
                a11[i][j] = matrixA[i][j];
                a12[i][j] = matrixA[i][j + newSize];
                a21[i][j] = matrixA[i + newSize][j];
                a22[i][j] = matrixA[i + newSize][j + newSize];

                b11[i][j] = matrixB[i][j];
                b12[i][j] = matrixB[i][j + newSize];
                b21[i][j] = matrixB[i + newSize][j];
                b22[i][j] = matrixB[i + newSize][j + newSize];
            }
        }


        sum(a11, a22, aResult, newSize);
        sum(b11, b22, bResult, newSize);
        strassenRecur(aResult, bResult, m1, newSize);

        sum(a21, a22, aResult, newSize);
        strassenRecur(aResult, b11, m2, newSize);

        subtract(b12, b22, bResult, newSize);
        strassenRecur(a11, bResult, m3, newSize);

        subtract(b21, b11, bResult, newSize);
        strassenRecur(a22, bResult, m4, newSize);

        sum(a11, a12, aResult, newSize);
        strassenRecur(aResult, b22, m5, newSize);

        subtract(a21, a11, aResult, newSize);
        sum(b11, b12, bResult, newSize);
        strassenRecur(aResult, bResult, m6, newSize);

        subtract(a12, a22, aResult, newSize);
        sum(b21, b22, bResult, newSize);
        strassenRecur(aResult, bResult, m7, newSize);


        sum(m3, m5, c12, newSize);
        sum(m2, m4, c21, newSize);

        sum(m1, m4, aResult, newSize);
        sum(aResult, m7, bResult, newSize);
        subtract(bResult, m5, c11, newSize);

        sum(m1, m3, aResult, newSize);
        sum(aResult, m6, bResult, newSize);
        subtract(bResult, m2, c22, newSize);
        for (i = 0; i < newSize ; i++) {
            for (j = 0 ; j < newSize ; j++) {
                straRes[i][j] = c11[i][j];
                straRes[i][j + newSize] = c12[i][j];
                straRes[i + newSize][j] = c21[i][j];
                straRes[i + newSize][j + newSize] = c22[i][j];
            }
        }
    }
}

//Main function of strassens algorithm
void strassenMult(vector< vector<int> > &matrixA,vector< vector<int> > &matrixB,vector< vector<int> > &straRes,int n){

    int m = nextPowerOfTwo(n);


    vector<int> in(m);
    vector< vector<int> > interA(m, in), interB(m, in), interRes(m, in);

    for(int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            interA[i][j] = matrixA[i][j];
            interB[i][j] = matrixB[i][j];
        }
    }

    strassenRecur(interA, interB, interRes, m);

    for(int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            straRes[i][j] = interRes[i][j];
        }
    }
}


bool compare(vector< vector<int> > &matrixA, vector< vector<int> > &matrixB, int n){
	int i=0,j=0;
	bool isUnequal = false;


	for(i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            if(matrixA[i][j]!=matrixB[i][j]){
            	isUnequal = true;
            	break;
            }
        }
    }
    if(isUnequal == true){
    	return false;
    }else{
    	return true;
    }
}
















#endif // MAHALE_PA2_STRA1_H_INCLUDED
