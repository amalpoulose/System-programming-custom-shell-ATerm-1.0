void seperator(char **s,char *p,char ch)
{
while(*p!='\0')
{
 while(*p==ch || *p=='\0')
   *p++='\0';
 *s++=p;
 while(*p!=ch && *p!='\0')
 p++;
 
}
*s='\0';
}
