#include <bits/stdc++.h> 

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string out;
        vector<string> res;
        helper(n, n, out, res);
        return res;
    }
    void helper(int left, int right, string out, vector<string>& res) {
        if (left == 0 && right == 0) {res.push_back(out); return;}
        if (left < 0 || right < 0) return;
        if (left < right) return;
        helper(left - 1, right, out + ")", res);
        helper(left, right - 1, out + "(", res);
    }
};

int main() {
	Solution s;
	vector<string> res = s.generateParenthesis(3);
	for (auto &a : res) {
		cout << a << endl;
	}
}

