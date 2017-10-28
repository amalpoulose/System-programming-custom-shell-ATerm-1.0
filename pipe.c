#include "header.h"
QUE *q;
int size;
void pipecmd(char *p)
{
	if(fork()==0)
	{
		int pip[2],i,j;
		char s1[20],s2[20];
		seperator(s1,s2,p,'|');
		pipe(pip);
		if(fork()==0)
		{
			close(1);
			dup(pip[1]);
			close(pip[0]);
			command(s1);
			exit(0);
		}
		else
		{
			close(0);
			dup(pip[0]);
			close(pip[1]);
			command(s2);
		}
		wait(0);
		exit(0);

	}
	wait(0);
}

