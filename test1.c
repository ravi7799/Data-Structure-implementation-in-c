#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct xx
{
int x;
char* name;
};

int main()
{
int x1;
char s1[20];
struct xx *s=malloc(sizeof(struct xx));

scanf("%d",&x1);
scanf("%s",s1);

s->x=x1;
s->name=s1;

printf("%d\n",s->x);
printf("%s",s->name);

return 0;
}