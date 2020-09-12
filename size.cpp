#include <bits/stdc++.h> 

using namespace std;

int main() {
	int a;
	int &b = a;
	int *p = &a;
	cout << sizeof(b) << endl;
	cout << sizeof(p) << endl;
}
