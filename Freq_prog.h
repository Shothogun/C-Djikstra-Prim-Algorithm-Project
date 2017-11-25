#ifndef FREQ_PROG_H
#define FREQ_PROG_H

typedef struct Node{
	// Same dist counter
	int counter;

	// Distance parameter
	double dist;

	// Next pointer
	struct Node* next;

}Node;

typedef struct DFD_List {
	Node* first;
	Node* last;
}DFD_List;
//arguments:(dfd_list)
void Create_DFD_List (DFD_List* l);
int If_DFD_List_Empty (DFD_List* l);

//arguments:(dfd_list, distance between both vertices)
void Insert_Node (DFD_List* l, double distance);
int Remove_Node (DFD_List* l, double distance);

//arguments:(dfd_list)
void Delete_DFD_List (DFD_List* l);

//arguments:(Graph size, Graph)
DFD_List* Freq (unsigned int N, Graph* G);

//arguments:(dfd_list)
void freeDFD(DFD_List* dfd_list);

#endif
