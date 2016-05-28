/*

    Author: Ankit Mahale.
   email-id: amahale2@binghamton.edu.


*/


#ifndef MAHALE_PA2_FLOYD1_H_INCLUDED
#define MAHALE_PA2_FLOYD1_H_INCLUDED

//Store anf print the adj matrix given by user in file.
void print_matrix_adj(char* filename, vector< vector<int> > &adj, int count_of_vertices){
	FILE *fp = fopen(filename, "r");
	char line[1000];
	char *aRow;
	int i=0, j=0;

	printf("\n\nadj matrix is:\n");
	fgets(line, 100, fp);	//Ignore the line mentioning - count of vertices .

	//Read each line, separate the entries delimites by single white space and store in vector.
	while(fgets(line, 100, fp)!=NULL){
		aRow = strtok(line,",");
		while(aRow != NULL){
			adj[i][j] = atoi(aRow);
			j++;
			aRow = strtok (NULL, " ,");
		}
		i++;
		j = 0;
	}

	//print the adj matrix.
	for(i =0;i<count_of_vertices;i++){
		printf("\n");
		for(j=0;j<count_of_vertices;j++){
			printf("%5d", adj[i][j]);
		}
	}

	fclose(fp);
}

//Find and store the shortest paths between all pairs of vertices.
void find_shortest(vector< vector<int> > &adj, vector< vector<int> > &dist, vector< vector<int> > &path, int count_of_vertices){
	int i=0,j=0, k=0;

	//Copy original dists between vertices.
	for(i = 0; i < count_of_vertices; i++){
		for(j = 0; j < count_of_vertices; j++){
			dist[i][j] = adj[i][j];
		}
	}

	//If shortest path is found, then store the dist of shortest path and the vertex on the path.
	for(k = 0; k < count_of_vertices; k++){
		for(i = 0; i < count_of_vertices; i++){
			for(j = 0; j < count_of_vertices; j++){
				if ((dist[i][k] + dist[k][j]) < dist[i][j]){
					//Store shortest dist.
                    dist[i][j] = dist[i][k] + dist[k][j];

                    //Store vertex in shortest path.
                    path[i][j] = k+1;
                }
			}
		}
	}

	printf("\nShortest matrix is:\n");
    for(i=0;i<count_of_vertices;i++){
		printf("\n");
		for(j=0;j<count_of_vertices;j++){
			printf("%5d", dist[i][j]);
		}
	}

	printf("\nPairs shortest paths:\n");
	for(i=0;i<count_of_vertices;i++){
		printf("\n");
		for(j=0;j<count_of_vertices;j++){
			printf("%5d", path[i][j]);
		}
	}

}





#endif // MAHALE_PA2_FLOYD1_H_INCLUDED
