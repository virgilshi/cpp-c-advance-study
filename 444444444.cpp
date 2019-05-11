#include <stdio.h>
typedef unsigned long long 	uint64_t;
struct box {
	char a : 4;
	char b : 4;
	char c : 5;
}b1;

int main(){
	struct box bx;
	printf("%d ",sizeof(char));
	printf("%d",sizeof(bx));
	return 0;
}
