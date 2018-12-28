#include<stdlib.h>
#include<stdio.h>
typedef struct Node
{
    struct Node* prev;
    void* data;
    int noc;
    struct Node** arr;      //pointer to array of pointers
}node;

//fn to create node

node* createnode(void* data,int noc)        //noc-no of children.
{
    node* pNew=(node*)malloc(sizeof(node));
    pNew->data=data;
    pNew->prev=NULL;
    pNew->noc=noc;
    pNew->arr=NULL;
    return pNew;
}

typedef struct queue
{
	 node* Qdata;
	struct queue* next;
}QUE;

void createqueue(QUE** fr,QUE** re)
{
	*fr=NULL;       //fr front
	*re=NULL;       //rr rear
}
void enqueue(QUE** fr,QUE** re,node* root)
{
	QUE* tmp;
	tmp=(QUE*)malloc(sizeof(QUE));
	tmp->next=NULL;
	tmp->Qdata=root;
	if(*fr==NULL)	//if queue is empty
	{
		*fr=tmp;
		*re=tmp;
	}
	else
	{
		(*re)->next=tmp;
		*re=tmp;
	}
}
node* dequeue(QUE** fr,QUE** re)
{
	QUE* pdlt;
	node* dataout;
	pdlt=*fr;
	dataout=pdlt->Qdata;
	if(*fr==*re)
	{
		*fr=*re=NULL;
	}
	else
	{
		*fr=(*fr)->next;
	}
	free(pdlt);
	return dataout;
}
node* queuefront(QUE** fr)
{
	node* dataout;
	dataout=(*fr)->Qdata;
	return dataout;
}
int emptyqueue(QUE** fr)
{
	if(*fr==NULL)	//if queue is empty
		return 1;
	else			//if queue is not empty
		return 0;
}

//fn to destoy Que

void destroyQ(QUE** fr,QUE** re)
{
	*fr=NULL;
	*re=NULL;
}

//fn to find ancestors upto 2 generations
void ancestors(node** ptrrcv)
{
node *ptr=*ptrrcv;
	if((ptr->prev)!=NULL && ((ptr->prev)->prev)==NULL)
	{
		printf("\n\t%c %s",254,((ptr->prev)->data));
		printf("\n\t%c second ancestor for %s is absent...",254,ptr->data);
	}

	else if(ptr->prev==NULL)
		printf("\n\t%c The Ancestors for %s are absent...\n",254,ptr->data);
	else
	printf("\n\t%c %s\n\t%c %s\n",254,((ptr->prev)->data),254,((ptr->prev)->prev)->data);
}

//fn to print descendents upto 2 generations
void descendents(node** root)
{
	node* ptr;
	int i,cnt;
	QUE *fr,*re;
	createqueue(&fr,&re);
	ptr=*root;
	cnt=0;
	if(ptr->noc==0)
		{
			printf("\n\t%c No descendent for %s\n",254,ptr->data);
		}
	else
	{
	while(ptr)
	{

			for(i=0;i<ptr->noc;i++)
			{
				printf("\n\t%c %s",254,(ptr->arr[i])->data);
				if(cnt==0)
				enqueue(&fr,&re,ptr->arr[i]);
			}
			cnt=1;


		if(!emptyqueue(&fr))
		{
			ptr=dequeue(&fr,&re);
		}
		else
		{
			 ptr=NULL;
		}

	}
	}
	destroyQ(&fr,&re);
}



