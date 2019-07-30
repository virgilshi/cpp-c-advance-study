// some commom MACRO definations
//
#include <stdio.h> 
#include <assert.h> 
#define FAILURE 0  
#define ASSERT_OK(expr, extra)																				\
do{																																			\
	if ((expr) == (FAILURE)) {																						\
		fprintf(stderr, "Error in file(%s), func(%s), line(%d), "extra"\n", \
										(__FILE__), (__func__), (__LINE__)); 								\
		assert(!((expr) == (FAILURE)));																				\
	}																																			\
} while (0)												

int Test(){
	int expr = 0;
	ASSERT_OK(expr, "by sl");
	return 0;
}

int main(){
	return Test();
}
