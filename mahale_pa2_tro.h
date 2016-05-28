/*

    Author: Ankit Mahale.
   email-id: amahale2@binghamton.edu.


*/

#ifndef MAHALE_PA2_TRO_H_INCLUDED
#define MAHALE_PA2_TRO_H_INCLUDED
#include<stdio.h>
#include<cmath>
#include<string>
#include<vector>
#include<stdlib.h>
#include<time.h>



static int tid = 0;

int r_sq = 3;
int c_sq = 3;

int last_id = 100;

using namespace std;



//Initialize the board.
void initialize(vector< vector<int> > &board, int bsize){
	int i=0,j=0;

	for(i=0;i<bsize;i++){
		for(j=0;j<bsize;j++){
			board[i][j] = 0;
		}
	}
}



//Create a hole randomly in board.
void createHole(vector< vector<int> > &board, int bsize, int &iterator_i, int &iterator_j){
	srand(time(NULL));
	int i=rand()%bsize;
	int j=rand()%(bsize-1);

	//Storing the value with some junk number that cannot exist on borad and cathching the instance with same value in future.
	board[i][j]=1111;
	iterator_i = i;
	iterator_j = j;
}


void printBoard(vector< vector<int> > &board, int n){
	int i=0,j=0;
	char hole = 'X';

    printf("\n");
	for(i=0;i<n;i++){
		printf("\n");
		for(j=0;j<n;j++){
			if(board[i][j] == 1111){
				printf("%4c", hole);
			}else{
				printf("%4d", board[i][j]);
			}
		}
	}
}



#endif // MAHALE_PA2_TRO_H_INCLUDED
