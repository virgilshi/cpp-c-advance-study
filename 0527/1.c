#include <stdio.h>
#include <stdlib.h>

struct node{
	int a;
	union{
		int b;
		char c;
	};
}; 

int main(){
	char name[] = "xiaoming";
	if(strstr(name, "sldmv")){
		printf("OK");
	}else{
		printf("NOT OK");
	}
}
