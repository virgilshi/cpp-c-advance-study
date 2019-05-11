#include <stdarg.h>
#include<stdio.h>

#include  <stdio.h>
#include  <stdarg.h>

//#define DEBUG_LOG(argv) 																\
//				do{																										\
//					printf("%s (%d) : %s\n", __FUNCTION__, __LINE__, argv); \
//				}while(0); 																						\

#define PRINT_LOG(format, args...) fprintf(stdout, "%s (%d): "#format"\n", __FUNCTION__,__LINE__, ##args)
void test(){
	PRINT_LOG("enter test %s,%d","hello, world",10);
}
int main(){
	test();
	PRINT_LOG("here.");
	// fprintf(stdout, "Warning""divider == 0""/n");
	return 0;
} 
