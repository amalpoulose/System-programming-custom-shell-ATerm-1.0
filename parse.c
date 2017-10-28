#include "header.h"
QUE *q;
int size ;
void arr_str(char **p,char *s)
{
	int i,j=0,k=0; 
	while(*s!='\0')  
	{
		while(*s==' '||*s=='\0')
			*s++='\0';
		*p++= s;
		while(*s!=' ' &&  *s !='\0')
			s++; 	
	}
	*p='\0';
}

