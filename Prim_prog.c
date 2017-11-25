#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Prim_prog.h"
#include "Graph.h"

void MST_Prim(Graph* G, unsigned int r){

	// Set keys and parents to initial condition
	Init_sng_src(G);
	
	//Set root start condition
	G->Vertex[r-1].key = 0;
	
	// Creates min-prior queue from graph
	Type_Heap *Q = MPQ_creator(G, r);
	
	// Main loop(until all vertices are analyzed)
	while (Q->size != 0)
	{
		// Extract min key vertex from queue returning its id
		int i = Extract_min(Q);
		
		// Set vertex's flag as out of queue
		G->B_queue[i-1] = 0;
		
		// Set pointer for its vertex
		List *u = &G->Vertex[i-1];
		
		// Access all adjacent vertices 
		for(List_Node *v = u->head->next; v != NULL; v = v->next)
		{
			/* Verify adj. vertex's existence in queue and its key 
			with a else possible path*/ 
			if( G->B_queue[v->id-1] == 1 &&
				v->WT < G->Vertex[v->id-1].key)
			{
				// Updates adj. vertex parent and key
				G->Vertex[v->id-1].pi = i;
				G->Vertex[v->id-1].key = v->WT;
				
				//Decreases same vertex's key from queue
				Decrease_key(Q, Q->position[v->id-1], v->WT);
			}
		}
	}

	// Queue free
	Free_queue(Q);
} 
