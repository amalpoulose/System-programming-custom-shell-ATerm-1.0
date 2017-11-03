#include "header.h"
QUE *q;
int size;
void contentcmd(char *p)
{
 int i,fd1,fd2;
 char *s[20];
 if(fork()==0)
{
 seperator(s,p,'>');
 space_bgn(*s);
 space_bgn(*(s+1));
 close(1);
 fd1=open(*(s+1),O_WRONLY|O_TRUNC|O_CREAT,0664);
 if((fd2=open(*s,O_RDONLY))!=-1)
 {
 close(fd2);
  execlp("cat","cat",*s,NULL);
 }
 else
 command(*s);
 exit(0);
}
wait(0);
}

