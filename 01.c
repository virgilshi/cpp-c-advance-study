#include <stdarg.h>
#include<stdio.h>

#include  <stdio.h>
#include  <stdarg.h>

#define LOG(format, args...) fprintf(stdout, "%s (%d): "format"\n", __FUNCTION__,__LINE__, ##args)
void test(){
	LOG("enter test %s,%d","hello, world",10);
}
int main(){
	test();
	LOG("here.");
	return 0;
} 

