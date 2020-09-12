#include <bits/stdc++.h> 
using namespace std;

int main() {
	vector<int> v = {4,2,7,3,8};
	unordered_map<int, vector<pair<int, int>>> mp;
	int target = 17;
	for (int i = 0; i < v.size(); ++i) {
		for (int j = i + 1; j < v.size(); ++j) {
			mp[v[i]+v[j]].push_back(make_pair(i,j));
		}
	}
	for (int i = 0; i < v.size(); ++i) {
		if (mp.count(target - v[i])) {
			for (auto &a : mp[target - v[i]]) {
				if (a.first != i && a.second != i) {
					cout << v[i] << "," << v[a.first] << "," << v[a.second];
					return 0;
				}
			}
		}
	}
	return 0;
}
