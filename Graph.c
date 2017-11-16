#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "Graph.h"

Heap_node* Parent(Type_Heap* A, unsigned int i)
{
	return &(A->MPQ[(i-1)/2]);
}

Heap_node* Left(Type_Heap* A,unsigned int i)
{
	return &(A->MPQ[2*i+1]);
}

Heap_node* Right(Type_Heap* A, unsigned int i)
{
	return &(A->MPQ[2*i+2]);
}

void swap(Type_Heap* Q, Heap_node* x, Heap_node* y)
{
	Heap_node aux1 = *x;
	*x = *y;
	*y = aux1;

	//Update positions in queue
	unsigned int aux2 = Q->position[x->id-1];
	Q->position[x->id-1] = Q->position[y->id-1];
	Q->position[y->id-1] = aux2;
}

void Min_heapify(Type_Heap* A, unsigned int i)
{

	unsigned int l = 2*i+1, min; 
	unsigned int r = 2*i+2;
	Heap_node *R = Right(A,i);
	Heap_node *L = Left(A,i);

	// Heapify about weight
	if(l <= A->size && 
		(L->key) < (A->MPQ[i].key) ) 
 	{
 		min = l;

 	}
 	else
 	{
 		min = i;
 	}
 	if(r <= A->size && 
 		R->key < (A->MPQ[min].key))
 	{
 		min = r;
 	}

 	if (min != i)
 	{
 		swap(A ,&A->MPQ[i], &A->MPQ[min]);
 		Min_heapify(A, min);
	}
}

int Extract_min(Type_Heap* A){
	if(A->size <= 0)
	{
		return -1;
	}
	if(A->size == 1)
	{
		A->size--;
		return A->MPQ[0].id;
	}

	int root = A->MPQ[0].id;
	A->MPQ[0] = A->MPQ[A->size-1]; 
	A->position[A->MPQ[A->size-1].id-1] = 0; 
	A->size--;
	Min_heapify(A, 0);

	//Return min id
	return root;
}


void Decrease_key(Type_Heap *Q, int i, double new_val)
{
	Q->MPQ[i].key = new_val;

	// Operates while ith is not root and parent is greater than son
	while(i!=0 && Q->MPQ[(i-1)/2].key > Q->MPQ[i].key)
	{
		swap(Q , &Q->MPQ[i], &Q->MPQ[(i-1)/2]);
		i = (i-1)/2;
	}

}

void Init_sng_src(Graph* G)
{
	// Vertices's key, parent and B_queue initialization 
	for(unsigned int i=0; i < (G->size); i++)
	{
		G->B_queue[i] = 1; 
		G->Vertex[i].key = INT_MAX; 
		G->Vertex[i].pi = 0;
	}
}

Graph* Init_graph(unsigned int size)
{	
	// Graph's memory creation and node_head setting from List_Node for each element of array Vertex

	Graph* G = (Graph*) malloc(sizeof(Graph));
	G->size = size;
	G->B_queue = (short*) malloc(size*sizeof(short));
	G->Vertex = (List*) malloc(size*sizeof(List));

	for(unsigned int i=0; i<size; i++)
	{
		G->Vertex[i].head = (List_Node*) malloc(sizeof(List_Node));
		G->Vertex[i].head->id = 0;
		G->Vertex[i].head->WT = 0;
		G->Vertex[i].last = G->Vertex[i].head;
	}

	return G;
}

void Graph_updater(Graph* G, 
				   unsigned int v1,
				   unsigned int v2,
				   double w)
{
	//For vertex 1
	G->Vertex[v1-1].last->next = (List_Node*) malloc(sizeof(List_Node));
	G->Vertex[v1-1].last = G->Vertex[v1-1].last->next;
	G->Vertex[v1-1].last->id = v2;
	G->Vertex[v1-1].last->WT = w;
	G->Vertex[v1-1].last->next = NULL;

	//For vertex 2
	
	G->Vertex[v2-1].last->next = (List_Node*) malloc(sizeof(List_Node));
	G->Vertex[v2-1].last = G->Vertex[v2-1].last->next;
	G->Vertex[v2-1].last->id = v1;
	G->Vertex[v2-1].last->WT = w;
	G->Vertex[v2-1].last->next = NULL;

}

// Turns Graph to Min prior queue
Type_Heap* MPQ_creator(Graph* G, unsigned int r)
{	
	Type_Heap *Q = (Type_Heap*) malloc(sizeof(Type_Heap));
	Q->size = G->size;
	Q->MPQ = (Heap_node*) malloc(Q->size*sizeof(Heap_node));
	Q->position = (unsigned int*) malloc(Q->size*sizeof(unsigned int));

	for(unsigned int i=0; i<Q->size; i++)
	{
		Q->MPQ[i].key = G->Vertex[i].key;
		Q->MPQ[i].id = i+1;
		Q->position[i] = i;
	}

	swap(Q, &Q->MPQ[0], &Q->MPQ[r-1]);

	return Q;
}

void Free_graph(Graph *G)
{
	for(unsigned int i=0; i<G->size; i++){
		List_Node *Aux = G->Vertex[i].head;
		List_Node *next;
		// Free Vertex's linked list
		while(Aux != NULL){
			next = Aux->next;
			free(Aux);
			Aux = next;
		}
		free(Aux);
	}
	//Free Vertex array
	free(G->Vertex);
	//Free B_queue array
	free(G->B_queue);
	//Free G Graph
	free(G);
}

void Free_queue(Type_Heap *Q)
{
	free(Q->MPQ);
	free(Q->position);
	free(Q);
}
