#include "header.h"
QUE *q;
int size;
void command(char *s)
{
	char *p[60];
	space_bgn(s);
	seperator(p,s,' ');

	if(strcmp(*p,"hist")==0)
		hist(q);
	else if(strcmp(*p,"curPid")==0)
		printf("%d\n",getpid());
	else if(strcmp(*p,"pPid")==0)
		printf("%d\n",getppid());
	else if(strcmp(*p,"version")==0)
		printf("Aterm 1.0\ncreated by : Amal Poulose\n");
	else
		defaultcmd(p);

}

void defaultcmd(char **p)
{
	if(execvp(*p,p)==-1)
		printf("%s: command not found\n",*p);
}




