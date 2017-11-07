#include <stdio.h>
#include "MPQ.h"

Heap_node* Parent(Type_Heap* A, int i)
{
	return &(A->MPQ[(i-1)/2]);
}

Heap_node* Left(Type_Heap* A, int i)
{
	return &(A->MPQ[2*i+1]);
}

Heap_node* Right(Type_Heap* A, int i)
{
	return &(A->MPQ[2*i+2]);
}

void swap(Heap_node* x, Heap_node* y)
{
	Heap_node aux = *x;
	*x = *y;
	*y = aux;
}

void Min_heapify(Type_Heap* A, int i)
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
 		swap(&A->MPQ[i], &A->MPQ[min]);
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
	A->size--;
	Min_heapify(A, 0);

	return root;
}

Type_Heap* MPQ_creator(Graph G)
{


}

