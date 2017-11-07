#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "MPQ.h"
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
	unsigned int aux2 = Q->position[x->id];
	Q->position[x->id] = Q->position[y->id];
	Q->position[y->id] = aux2;
}

void Min_heapify(Type_Heap* A, unsigned int i)
{
	int min;
	int l = 2*i+1; 
	int r = 2*i+2;
	Heap_node *R = Right(A,r);
	Heap_node *L = Left(A,l);

	if(i == 0){
		return;
	}

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

//Return min id
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
	A->position[A->MPQ[A->size-1].id] = 0; 
	A->size--;
	Min_heapify(A, 0);

	return root;
}

Type_Heap* MPQ_creator(Graph G, unsigned int r)
{	
	Type_Heap *Q;
	Q->size = G.size;
	Q->MPQ = (Heap_node*) malloc(Q->size*sizeof(Heap_node));

	for(int i=0; i<Q->size; i++)
	{
		Q->MPQ[i].key = G.Vertex[i].key;
		Q->MPQ[i].id = i;
		Q->position[i] = i;
	}

	swap(Q, &Q->MPQ[0], &Q->MPQ[r]);
}

void Decrease_key(Type_Heap *Q, int i, int new_val)
{
	Q->MPQ[i].key = new_val;
	// Operates while ith is not root and parent is greater than son
	while(i!=0 && Q->MPQ[(i-1)/2].key > Q->MPQ[i].key)
	{
		swap(Q , &Q->MPQ[i], &Q->MPQ[(i-1/2)]);
		i = (i-1)/2;
	}

}
