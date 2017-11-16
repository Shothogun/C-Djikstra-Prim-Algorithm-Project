#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Prim_prog.h"
#include "Graph.h"
#include "IO.h"

int main(int argc, char* argv[]){
	int flag;

	double weight = 0;

	unsigned int size;
	
	unsigned int r = 1;

	scanf("%u%*c", &size);

	Graph *G = Init_graph(size);

	flag = read(G);

	MST_Prim(G, r);
	
	print_MST(G, r, &weight);
	printf("Peso Total:%lf\n", weight);


	Free_graph(G);

	return 0;
}
