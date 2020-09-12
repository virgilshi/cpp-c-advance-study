#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> v = {1,4,5,6};
	int res = v[0];
	vector<int> allxor(v.size());
	allxor[0] = v[0];
	for (int i = 1; i < v.size(); ++i) {
		allxor[i] = allxor[i - 1] * v[i];
	}
	int left = 0, right = 0;
	for (int i = 0; i < v.size(); ++i) {
		for (int j = i; j < v.size(); ++j) {
			int tmp = (allxor[j] ^ allxor[i] ^ v[i]);
			if (res < tmp) {
				res = tmp;
				left = i;
				right = j;
			}
		}
	}
	cout << left << "," << right << ", maxxor:"  << res;
	return 0;
}
