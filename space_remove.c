#include "header.h"
QUE *q;
int size ;
void space_bgn(char *cmd)
{
	int i;
	//remove spaces in begining 
	for(i=0;cmd[i];i++)
	{
		if(cmd[i]==' ')
			continue;
		strcpy(cmd,cmd+i);
		break; 
	}
	//remove spaces at end
	for(i=strlen(cmd)-1;i;i--)
	{
		if(cmd[i]==' ')
		{
			cmd[i]='\0';
			continue;
		}
		break;
	}
}
