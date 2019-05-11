#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define KB (1024)
#define MB (KB*1024)
#define GB (MB*1024)

int main(){
	uint64_t n = pow(10,8);
	printf("%lf\n",(double)n*(100+16)/GB);
	printf("%lf\n",(double)360039475305/GB);
	printf("%llu\n",(uint64_t)1<<63-1);
	return 0;
}
