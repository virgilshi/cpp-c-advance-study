#include <bits/stdc++.h> 

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        if (n <= 0) return false;
        if (n >= 1 && n <= 3) return true;
        bool a = true, b = true, c = true;
        for (int i = 4; i <= n; ++i) {
            bool ta = a, tb = b;
            a = !(a && b && c);
            b = ta;
            c = tb;
        }
        return a;
    }
};

int main() {
	Solution s;
	cout << s.canWinNim(730530679);
}
