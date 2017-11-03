#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


#define MAX 10
#define LINE 128
typedef struct node
{
	char *data;
	int num;
	struct node *next;
}QUE;


void space_bgn(char *);
void pipecmd(char *);
void command(char *);
void command(char *);
void defaultcmd(char **);
void enqueue(QUE **,char*,int);
void dequeue(QUE **);
void seperator(char **,char *,char);
void contentcmd(char *);
