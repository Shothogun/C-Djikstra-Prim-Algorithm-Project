#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Dijkstra_prog.h"
#include "Graph.h"

// Relax subroutine
void Relax(Graph *G, List_Node *v, unsigned int i)
{
	if(G->Vertex[v->id-1].key > G->Vertex[i-1].key + v->WT)
	{
		G->Vertex[v->id-1].pi = i;
		G->Vertex[v->id-1].key = G->Vertex[i-1].key + v->WT;
	}
}

/* Get graph and root vertex's index as argument*/


void Dijkstra(Graph *G, unsigned int r)
{
	// Graph's initialization
	Init_sng_src(G);

	// Set root start condition
	G->Vertex[r-1].key = 0;

	// Queue creation
	Type_Heap *Q = MPQ_creator(G, r);

	// Main loop(until all vertices are analyzed)
	while (Q->size != 0)
	{
		// Extract min key vertex from queue returning its index
		int i = Extract_min(Q);

		// Set vertex's flag as out of queue
		G->B_queue[i-1] = 0;

		// Set pointer for its vertex
		List *u = &G->Vertex[i-1];

		// Access all adjacent vertices 
		for(List_Node *v = u->head->next; v != NULL; v = v->next)
		{
			// If vertex belongs to queue
			if (G->B_queue[v->id-1] == 1)
			{
				// Relax 
				Relax(G,v,i);

				// Decreases key value in queue
				Decrease_key(Q, 
							 Q->position[v->id-1], 
							 G->Vertex[i-1].key + v->WT);
			}
		}
	}
	
	// Free queue
	Free_queue(Q);
}
