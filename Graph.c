#include <stdio.h>
#include "Graph.h"
#include <limits.h>

void Init_sng_src(Graph* G)
{
	for(int i=0; i < (G->N); i++)
	{
		G->B_queue[i] = 1; 
		G->Vertex[i].key = INT_MAX; 
		G->Vertex[i].pi = 0;
	}
}