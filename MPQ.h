#ifndef MPQ_H
#define MPQ_H
#include "Graph.h"


typedef struct Heap_node *Pointer;

typedef struct Heap_node
{
	//Vertex identification
	unsigned int id;
	//Edge's weight
	unsigned int key;
} Heap_node;

typedef struct Type_Heap
{
	// Vertices array
	Heap_node* MPQ;
	// Size of queue
	unsigned int size;
	// Vertex position in queue
	unsigned int* position;
} Type_Heap;

Heap_node* Parent(Type_Heap* A, unsigned int i);
Heap_node* Left(Type_Heap* A, unsigned int i);
Heap_node* Right(Type_Heap* A, unsigned int i);
void swap(Type_Heap* Q, Heap_node* x, Heap_node* y);
void Min_heapify(Type_Heap* A, unsigned int i);
int Extract_min(Type_Heap* A);
Type_Heap* MPQ_creator(Graph G, unsigned int r);
void Decrease_key(Type_Heap *Q, int i, int new_val);


#endif
