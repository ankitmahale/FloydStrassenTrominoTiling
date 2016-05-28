/*

    Author: Ankit Mahale.
   email-id: amahale2@binghamton.edu.


*/
#ifndef MAHALE_PA2_TRO1_H_INCLUDED
#define MAHALE_PA2_TRO1_H_INCLUDED

//Place the tromino tiles in correct positions
void placeTiles(vector< vector<int> > &board, int bsize, int iterator_i, int iterator_j, int upper_l_i, int upper_l_j){
	int mid_val = bsize/2;
	for(int i=0;i<bsize;i++)
    {
        r_sq=1111;
    }

    if(bsize == 2){
		tid++;
		for(int i=0;i<bsize;i++)
        for(int j=0;j<bsize;j++)
        if(board[upper_l_i + i][upper_l_j + j] == 0)
		board[upper_l_i + i][upper_l_j + j] = tid;
        return;
	}

	tid++;
	int id = tid;
	if(iterator_i < (upper_l_i + mid_val)){
		board[upper_l_i + mid_val][upper_l_j + mid_val-1] = id;
		board[upper_l_i+ mid_val][upper_l_j + mid_val] = id;
		if(iterator_j < (upper_l_j + mid_val)){
			board[upper_l_i + mid_val-1][upper_l_j + mid_val] = id;
			//hole is in 2nd quadrant.
			placeTiles(board, mid_val, iterator_i, iterator_j, upper_l_i + 0, upper_l_j + 0);
			placeTiles(board, mid_val, mid_val - 1, mid_val, upper_l_i + 0, upper_l_j + mid_val);
			placeTiles(board, mid_val, mid_val, mid_val - 1, upper_l_i + mid_val, upper_l_j + 0);
			placeTiles(board, mid_val, mid_val, mid_val, upper_l_i + mid_val, upper_l_j + mid_val);
		}else{
			board[upper_l_i + mid_val-1][upper_l_j + mid_val-1] = id;
			//hole is in 1st quadrant.
			placeTiles(board, mid_val, iterator_i, iterator_j, upper_l_i + 0, upper_l_j + mid_val);
			placeTiles(board, mid_val, mid_val-1, mid_val-1, upper_l_i + 0, upper_l_j + 0);
			placeTiles(board, mid_val, mid_val, mid_val-1, upper_l_i + mid_val, upper_l_j + 0);
			placeTiles(board, mid_val, mid_val, mid_val, upper_l_i + mid_val, upper_l_j + mid_val);
		}
	}else{
		board[upper_l_i + mid_val-1][upper_l_j + mid_val-1] = id;
		board[upper_l_i + mid_val-1][upper_l_j + mid_val] = id;
		if(iterator_j < (upper_l_j + mid_val)){
			board[upper_l_i + mid_val][upper_l_j + mid_val] = id;
			//hole is in 3rd quadrant.
			placeTiles(board, mid_val, iterator_i, iterator_j, upper_l_i + mid_val, upper_l_j + 0);
			placeTiles(board, mid_val, mid_val-1, mid_val, upper_l_i + 0, upper_l_j + mid_val);
			placeTiles(board, mid_val, mid_val-1, mid_val-1, upper_l_i + 0, upper_l_j + 0);
			placeTiles(board, mid_val, mid_val, mid_val, upper_l_i + mid_val, upper_l_j + mid_val);
		}else{
			board[upper_l_i + mid_val][upper_l_j + mid_val-1] = id;
			//hole is in 4th quadrant.
			placeTiles(board, mid_val, iterator_i, iterator_j, upper_l_i + mid_val, upper_l_j + mid_val);
			placeTiles(board, mid_val, mid_val-1, mid_val, upper_l_i + 0, upper_l_j + mid_val);
			placeTiles(board, mid_val, mid_val-1, mid_val-1, upper_l_i + 0, upper_l_j + 0);
			placeTiles(board, mid_val, mid_val, mid_val-1, upper_l_i + mid_val, upper_l_j + 0);
		}
	}
}



























#endif // MAHALE_PA2_TRO1_H_INCLUDED
