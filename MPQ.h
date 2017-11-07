#ifndef MPQ_H
#define MPQ_H
#include "Graph.h"

typedef struct Heap_node *Pointer;

typedef struct Heap_node
{
	//Vertex identification
	int id;
	//Edge's weight
	int key;
} Heap_node;

typedef struct Type_Heap
{
	Heap_node* MPQ;
	int size;
} Type_Heap;

Heap_node* Parent(Type_Heap* A, int i);
Heap_node* Left(Type_Heap* A, int i);
Heap_node* Right(Type_Heap* A, int i);
void swap(Heap_node* x, Heap_node* y);
void Min_heapify(Type_Heap* A, int i);
int Extract_min(Type_Heap* A);



#endif
