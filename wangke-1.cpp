#include <bits/stdc++.h> 
using namespace std;

int main() {
	int x;
	cin >> x;
	double left = 0, right = x;
	while (1) {
		double mid = (left + right) / 2;
		double delta = pow(mid, 7) + 0.5 * mid - x;
		if (fabs(delta) < 0.01) {
			printf("%.2lf", mid);
			break; 
		}
		if (delta > 0) {
			right = mid;
		} else {
			left = mid;
		}
	}
	return 0;
}
