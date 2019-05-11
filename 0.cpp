#include<iostream> 
#include <vector>
#include <map>

using namespace std;
string baseNeg2(int N) {
	string ans;
	while(N){
		int reminder=N%(-2);
		if(!reminder) reminder+=2;
		cout<<reminder<<endl;
		N=N/(-2)+1;
	}
	return ans;
}
int main() {
	baseNeg2(2);
}
