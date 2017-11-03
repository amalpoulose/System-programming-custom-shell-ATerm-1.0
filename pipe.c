#include "header.h"
QUE *q;
int size;
void pipecmd(char *p)
{

        int pip[2],i,j;
        char *s[20];
        seperator(s,p,'|');

        if(fork()==0)
        {
                pipe(pip);
                if(fork()==0)
                {
                        close(1);
                        dup(pip[1]);
                        close(pip[0]);

                        command(s[0]);
                        exit(0);
                }
                else
                {
                        close(0);
                        dup(pip[0]);
                        close(pip[1]);
                        command(s[1]);
                }
                wait(0);
                exit(0);

        }
        wait(0);
}
