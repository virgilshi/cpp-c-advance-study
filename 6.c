#include <stdio.h>
#include <stdlib.h>
typedef struct A{
	int a,c,v,d;
	double b;
}A;
int main(){
	A* tmp;
	tmp=calloc(1,sizeof(tmp));
	printf("%d,%d\n",sizeof(*tmp),sizeof(tmp));
	tmp->a=10;
	printf("a=%d",tmp->a);
	return 0;
}
