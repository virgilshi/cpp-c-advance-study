#include <bits/stdc++.h> 

using namespace std;

void print(vector<int> &v) {
	for (auto &a : v) {
		cout << a << " " ;
	}
	cout << endl;
}
int main() {
	vector<int> v = {1,2,3,4,5};
	do {
		print(v);
	} while (next_permutation(v.begin(), v.end()));
}

