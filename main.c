#include "header.h"
 
QUE *q;
int size;

int main(int argc,char **argv)
{ 
	if(argc >= 2)
	{
		if(strcmp(argv[1],"-c")==0)
		{ 
			if(argc>2)
				execvp(argv[2],argv+2);
			return;
		}
	} 
	char *s,*cmd,*path;
	int count=1,i,j,k,l,inx;
	s=malloc(129);
	cmd=malloc(129);
	chdir("/home");
        path=malloc(130);
	while(1)
	{
S:
                getcwd(path,130);
                printf("< %d ATerm: %s >",count,path);
                scanf(" %[^\n]",s);
                if(strlen(s)>128)
                {
                        printf("Characters exceeded the limit\n");
                        goto S;
                }

		//split multiple commands given by ;
		for(i=0,inx=0;i<=strlen(s);i++)
		{
			if(s[i]!=';' &&s[i]!='\0')
				continue;
			//saving command to cmd
			for(j=0;inx<i;j++,inx++)
				cmd[j]=s[inx];

			cmd[j]='\0';
			inx++;       // updating index value to find next command
			//remove space at starting
			space_bgn(cmd);
			//			printf("%s\n",cmd);

			 if(strchr(cmd,'|'))
                        {
                                pipecmd(cmd);
                                goto A;
                        }
                        else if(strchr(cmd,'>'))
                        {
                                contentcmd(cmd);
                                goto A;
                        }
			if(strcmp(cmd,"exit")==0)	
				return;
			else if(strcmp(cmd,"quit")==0)	
				return;
			if(strstr(cmd,"exit ")||strcmp(cmd,"exit")==0)
                                return;
                        else if(strstr(cmd,"quit ")||strcmp(cmd,"quit")==0)     
                                return;
                        else if(strstr(cmd,"curPid ")||strcmp(cmd,"curPid")==0)
                                printf("%d\n",getpid());
                        else if(strstr(cmd,"pPid ")||strcmp(cmd,"pPid")==0)
                                printf("%d\n",getppid());
			else if(strcmp(cmd,"cd")==0)
                                chdir("/home");
			else if((strstr(cmd,"cd "))||(strstr(cmd,"chdir ")))
                        {

                                char *p[60];
                                space_bgn(cmd);
                                seperator(p,cmd,' ');
                                if(chdir(*(p+1))==-1)
                                        perror(*p);
                        }
			
			else
			{
				if(fork()==0)
				{
					command(cmd);
					exit(0);
				}
				wait(0);
			}	
A:;
		}
			enqueue(&q,s,count);
			count++;


	}
return 0;
}
