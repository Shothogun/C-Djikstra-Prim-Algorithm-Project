#include <stdio.h>
#include <stdlib.h>
#include "Prim_prog.h"
#include "Graph.h"

int main(int argc, char* argv[]){
	unsigned int size, v1, v2;
	double w;
	
	unsigned int r = 7;

	//scanf("%u%*c", &r);

	scanf("%u%*c", &size);

	Graph *G = Init_graph(size);

	while( scanf("%u %u %lf", &v1, &v2, &w) == 3)
	{
		Graph_updater(G, v1, v2, w);
	}


	MST_Prim(G, r);

	for(int i=0; i<size; i++)
	{
		for(List_Node *v = G->Vertex[i].head->next ; v != NULL; v = v->next)
		{
			printf("Vertice (%u) adj (%u) w (%lf)\n", i+1, v->id, v->WT);
		}
		printf("parent (%u)\n", G->Vertex[i].pi);
	}
	
	Free_graph(G);

	return 0;
}