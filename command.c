#include "header.h"
QUE *q;
int size;
void command(char *s)
{
	char *p[60];
	space_bgn(s);
	arr_str(p,s);

	if(strcmp(*p,"hist")==0)
		hist(q);
	else
		defaultcmd(p);

}

void defaultcmd(char **p)
{
	if(execvp(*p,p)==-1)
		printf("%s: command not found\n",*p);
}

void seperator(char *s1,char *s2,char *p,char ch)
{
	int i;
	for(i=0;p[i]!=ch;i++)
		s1[i]=p[i];
	s1[i]='\0';
}

