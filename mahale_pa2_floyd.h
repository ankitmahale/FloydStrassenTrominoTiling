#ifndef MAHALE_PA2_FLOYD_H_INCLUDED
#define MAHALE_PA2_FLOYD_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>


using namespace std;

void ini_path(vector< vector<int> > &path, int len){
	int i=0,j=0;

	for(i=0;i<len;i++){
		for(j=0;j<len;j++){
			path[i][j] = 0;
		}
	}
}

//Read the - count of vertices, from input file given by user.
int vertices_from_file(char* filename){
	FILE *fp = fopen(filename, "r");
	char ch;
	char count[5]; int count_of_vertices = 0;
	int i=0;

	if(fp == NULL){
		printf("\nFile cannot be opened\n");
		exit(0);
	}

	//Read first line where count of vertices are stored.
	while((ch = fgetc(fp))!='\n'){
		count[i] = ch;
		i++;
	}

	count_of_vertices = atoi(count);
	fclose(fp);

	return count_of_vertices;
}


#endif // MAHALE_PA2_FLOYD_H_INCLUDED
