/*

    Author: Ankit Mahale.
   email-id: amahale2@binghamton.edu.


*/


#include "mahale_pa2_tro.h"
#include "mahale_pa2_tro1.h"
int main(int argc, char* argv[]){
	int k=0, bsize=0, iterator_i = 0, iterator_j = 0;

	//command line arguuments validation
	if(argc!=2){
		printf("\nWrong number of arguments\n");
		exit(0);
	}

	if((atoi(argv[1]))<1){
		printf("\nValue is less than 1 \n");
		exit(0);
	}
	if((atoi(argv[1]))>6){
		printf("\nValue is exceeding 6\n");
		exit(0);
	}

	//size of matrix are valid or not
	k = atoi(argv[1]);

	printf("\nTromino tiling algorithm!\n");

	bsize = pow(2,k);

	//Declare board.
	vector<int> inner(bsize);
    vector< vector<int> > board(bsize, inner);

	//initializing the board
	initialize(board, bsize);

	//generating hoole on the board
	createHole(board, bsize, iterator_i, iterator_j);

	//Place the tile
	tid = 0;
	placeTiles(board, bsize, iterator_i, iterator_j,0,0);

	printf("\nResulting board is:");
	printBoard(board, bsize);

}
