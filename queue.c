#include "header.h"
QUE *q;
int size;
void enqueue(QUE **ptr,char *n,int no)
{
	static QUE *last,*new;
	if(size==MAX)
		dequeue(ptr);

	new=malloc(sizeof(QUE));
	new->data=malloc(strlen(n)+1);
	new->num=no;
	strcpy(new->data,n);

	if(*ptr==0)
	{
		new->next=*ptr;
		*ptr=new;
	}
	else
	{
		new->next=last->next;
		last->next=new;
	}
	last=new;
	size+=1;
} 

void dequeue(QUE **ptr)
{
	QUE *temp=*ptr;
	(*ptr)=(*ptr)->next;
	free(temp);
	size-=1;
} 

void hist(QUE *ptr)
{
	while(ptr)
	{
		printf("%d.  %s\n",ptr->num,ptr->data);
		ptr=ptr->next;
	}
}

