/*

    Author: Ankit Mahale.
   email-id: amahale2@binghamton.edu.
*/


#include "mahale_pa2_floyd.h"
#include "mahale_pa2_floyd1.h"




int main(int argc, char* argv[]){
	char* filename;
	FILE *fp;
	int count_of_vertices=0;

	//command line argument Validation
	if(argc!=2){
		printf("\nWrong count of arguments!");
		exit(0);
	}

	printf("\nFloyd's Algorithm\n");

	//Reading the file name from Command line.
	filename = argv[1];
    //Read the - count of vertices, from given file.
	count_of_vertices = vertices_from_file(filename);

	printf("\n Vertices: %d", count_of_vertices);

	//Create adj matrix vector.
	vector<int> tr (count_of_vertices);
    vector< vector<int> > adj(count_of_vertices, tr);


    vector<int> tr1 (count_of_vertices);
    vector< vector<int> > dist(count_of_vertices, tr1);


    vector<int> tr2 (count_of_vertices);
    vector< vector<int> > path(count_of_vertices, tr2);

	//Initialize the path vector.
	ini_path(path, count_of_vertices);


    print_matrix_adj(filename, adj, count_of_vertices);

    //Find and print the shortest paths for each pair of vertices.
    find_shortest(adj, dist, path, count_of_vertices);
}
