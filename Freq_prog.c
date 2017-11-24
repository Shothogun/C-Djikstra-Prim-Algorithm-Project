#include "Freq_prog.h"
#include "Dijktra_prog.h"


void Create_DFD_List (DFD_List* l) //Recebe uma variável dfd_list de aluNodes por referência a fim de criar a sua célula cabeça.
{
	l->first = (Node*) malloc (sizeof (Node));
	l->first->next = NULL; //Aterra os ponteiros da dfd_list.
	l->last = l->first;
}

int If_DFD_List_Empty (DFD_List* l) //Recebe uma dfd_list de aluNodes por refêrência para verificar se ela está vazia.
{					
	if (l->first->next==NULL) //Verifica se a célula cabeça está aterrada.
		return 1;
	else
		return 0;
}

void Insert_Node (DFD_List* l, double distance) //Recebe uma dfd_list de aluNodes por referência e uma variável que contém os dados do aluNode a ser inserido.
{
	l->last->next = (Node*) malloc (sizeof(Node)); //Aloca um espaço para o Nodevo aluNode.
	l->last = l->last->next; //Adiciona um aluNode Node final da dfd_list
	l->last->counter = 1;
	l->last->dist = distance;
	l->last->next = NULL; //Aterra o final da dfd_list
}

int Remove_Node (DFD_List* l, double distance) //Recebe uma dfd_list de aluNodes por referência e a chave do aluNode a ser retirado.
{
	Node *ant;
	Node *rmv = l->first->next;
	if (If_DFD_List_Empty(l))
		return 1; 
	while (rmv->dist != distance) //Percorre toda a dfd_list a procura da chave dada
	{
		ant = rmv;
		if (rmv->next != NULL)
			rmv=rmv->next; 
		else
			return 1;
	}
	ant->next = rmv->next; //Remove o aluNode de chave k.
	free (rmv);
	return 0;
}

void Delete_DFD_List (DFD_List* l) //Recebe uma dfd_list de aluNodes como parâmetro por referência a fim de desalocar todos os espaços alocados.
{
	Node *aux;
	while (!If_DFD_List_Empty(l)) //Percorre toda a dfd_list removendo e desalocando todos os seus elementos.
	{
		aux = l->first->next;
		l->first->next = aux->next;
		free(aux);
	}
	free (l->first); //Desaloca a célula cabeça da dfd_list.
}

DFD_List* Freq (unsigned int N, Graph* G)
{
	unsigned int i, j;
	Node* aux;
	DFD_List dfd_list;
	Create_DFD_List (&dfd_list);
	for (i=1; i<N; i++)
	{
		Dijkstra(G, i);
		for(j = i; j<N; j++)
		{	
			aux = dfd_list.first;
			while(aux->next != NULL)
			{
				aux=aux->next;
				if (aux->dist == G->Vertex[j].key)
				{
					aux->counter += 1;
					break;
				}
			}
			if (aux->next == NULL)
			{
				Insert_Node (&dfd_list, G->Vertex[j].key);
			}
		}
	}
	return &dfd_list;	
}
