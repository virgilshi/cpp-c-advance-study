#include <iostream>
#include <vector>

using namespace std;

void Print(vector<int> &v){
	for(auto it : v){
		cout << it <<" ";
	}
	cout << endl;
}
int main(int argc, char **argv){
	vector<int> v = {1, 2, 3};
	Print(v);
	
	v.resize((2));
	Print(v);
	return 0;
}
