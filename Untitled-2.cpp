#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        Node *pre, *last;
        helper(root, pre, last);
        return pre;
    }
    void helper(Node *nd, Node* &pre, Node* &last) {
        if (nd == NULL) {
            pre = NULL;
            last = NULL;
            return;
        }
         cout << ":" << nd->val << endl;
        pre = last = nd;
        Node *preLeft, *preRight, *lastLeft, *lastRight;
        helper(nd->left, preLeft, lastLeft);
        helper(nd->right, preRight, lastRight);
        nd->left = lastLeft;
        if (lastLeft) lastLeft->right = nd;
        nd->right = preRight;
        if (preRight) preRight->left = nd;
        if (preLeft) pre = preLeft;
        if (lastRight) last = lastRight;
    }
};

int main() {
	Solution s;
	Node* root = new Node(4);
	Node* t = s.treeToDoublyList(root);
	cout << t->val;
}
