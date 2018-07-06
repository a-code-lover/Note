/**
 *基础函数的实现
 *
 */ 
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

struct Node {
    int value;
    Node * next;
};

class Linklist {

};

//KMP
vector<int> kmpProcess(string s) {
    int size = s.size();
    vector<int> lps(size, 0);
    for (int i = 1, len = 0; i < size; ) {
        if (s[i] == s[len]) {
            lps[i++] = ++len;
        }
        else if (len) len = lps[len - 1];
        else i++;
    }
    return lps;
}

int strstr_kmp(string haystack, string needle) {
    int n = haystack.size(), m = needle.size();
    vector<int> lps = kmpProcess(needle);
    for (int i = 0, j = 0; i < n;) {
        if (j < m && haystack[i] == needle[j]) {
            i++; j++;
        }
        if (j == m) return i - m;
        if (haystack[i] != needle[j]) {
            if (j == 0) i++;
            else j = lps[j - 1];
        }
    }
    return -1;
}

//iterativer for binart tree traverssal
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> inorder;
    if (!root) return inorder;
    TreeNode *cur = root;
    stack<TreeNode *> s;
    while (cur || !s.empty()) {
        while (cur) {
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top();
        s.pop();
        inorder.push_back(cur->val);
        cur = cur->right;
    }
}