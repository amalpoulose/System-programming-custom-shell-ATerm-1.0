outfile:main.o queue.o space_remove.o parse.o command.o pipe.o contentcmd.o
	cc main.c queue.c space_remove.c parse.c command.c pipe.c contentcmd.c -o outfile
main.o:main.c
	cc -c main.c
queue.o:queue.c
	cc -c queue.c
space_remove.o:space_remove.c
	cc -c space_remove.c
parse.o:parse.c
	cc -c parse.c 
command.o:command.c
	cc -c command.c
pipe.o:pipe.c
	cc -c pipe.c
contentcmd.0:contentcmd.c
	cc -c contentcmd.c
