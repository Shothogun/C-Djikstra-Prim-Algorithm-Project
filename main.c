#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dijkstra_prog.h"
#include "Prim_prog.h"
#include "Graph.h"
#include "IO.h"
	
int main(int argc, char* argv[]){
	int flag;

	double weight = 0;

	unsigned int size;
	
	unsigned int r = atoi(argv[2]);

	unsigned int end = 0;

	if ( argc > 3)
	{
		end = atoi(argv[3]);
	}

	scanf("%u%*c", &size);

	Graph *G = Init_graph(size);

	flag = read(G);

	if(strcmp(argv[1], "Dijkstra") == 0)
	{
		if(flag == 1){
			printf("Nao é possivel processar arestas negativas\n");
			return 0;
		}
		Dijkstra(G, r);
		print_distance(G, end);
		printf("Distancia:%lf\n", G->Vertex[end-1].key);
	}

	else if (strcmp(argv[1], "MST") == 0)
	{
		MST_Prim(G, r);
		print_MST(G, r, &weight);
		printf("Peso Total:%lf\n", weight);
				
	}

	else if (strcmp(argv[1], "Freq") == 0)
	{

	}

	else
	{
		printf("ERROR");
	}

	

	/*
	for(unsigned int i=0; i<size; i++)
	{
		for(List_Node *v = G->Vertex[i].head->next ; v != NULL; v = v->next)
		{
			printf("Vertice (%u) adj (%u) w (%lf)\n", i+1, v->id, v->WT);
		}
		printf("parent (%u)\n", G->Vertex[i].pi);
	}
	*/

	Free_graph(G);

	return 0;
}
