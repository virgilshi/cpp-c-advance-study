#include <iostream>
template <typename T1,typename T2> 
inline T1 max1(T1 const& a, T2 const& b){
	return a < b ? b: a;
}

template <typename T1,typename T2> 
inline T2 min2(T1 const& a, T2 const& b){
	return a < b ? a: b;
}
int main(){
////	std::cout<<(1<<4);
//	int a = 4;
//	double b = 5.6;
//	std::cout<<max1(b,a)<<std::endl	;
//	std::cout<<min2(b,a);
//	return 0;
printf("%d",2%(-2));
}
