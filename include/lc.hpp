#pragma once
#include <algorithm>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// leetcode data structures

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Node {
   public:
    int val;
    std::vector<Node*> neighbors;
    Node() : val(0) {}
    Node(int _val) : val(_val) {}
    Node(int _val, std::vector<Node*> _neighbors)
        : val(_val), neighbors(_neighbors) {}
};

// builder helpers

// build linked list from initialiser list: make_list({1,2,3})
inline ListNode* make_list(std::initializer_list<int> vals) {
    ListNode dummy;
    ListNode* tail = &dummy;
    for (int v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy.next;
}

// build linked list with cycle: make_cycle_list({3,2,0,-4}, 1)
// pos = index where tail connects back (-1 for no cycle)
inline ListNode* make_cycle_list(std::initializer_list<int> vals, int pos) {
    std::vector<ListNode*> nodes;
    ListNode dummy;
    ListNode* tail = &dummy;
    for (int v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
        nodes.push_back(tail);
    }
    if (pos >= 0 && pos < (int)nodes.size()) {
        tail->next = nodes[pos];
    }
    return dummy.next;
}

// build binary tree from level order with nullopt for null nodes
// make_tree({1, 2, 3, nullopt, 5})
inline TreeNode* make_tree(std::initializer_list<std::optional<int>> vals) {
    std::vector<std::optional<int>> v(vals);
    if (v.empty() || !v[0].has_value()) return nullptr;

    TreeNode* root = new TreeNode(v[0].value());
    std::queue<TreeNode*> q;
    q.push(root);
    size_t i = 1;

    while (!q.empty() && i < v.size()) {
        TreeNode* node = q.front();
        q.pop();

        if (i < v.size()) {
            if (v[i].has_value()) {
                node->left = new TreeNode(v[i].value());
                q.push(node->left);
            }
            i++;
        }
        if (i < v.size()) {
            if (v[i].has_value()) {
                node->right = new TreeNode(v[i].value());
                q.push(node->right);
            }
            i++;
        }
    }
    return root;
}

// printer helpers

inline void print(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        if (i) std::cout << ",";
        std::cout << v[i];
    }
    std::cout << "]\n";
}

inline void print(const std::vector<std::vector<int>>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        if (i) std::cout << ",";
        std::cout << "[";
        for (size_t j = 0; j < v[i].size(); j++) {
            if (j) std::cout << ",";
            std::cout << v[i][j];
        }
        std::cout << "]";
    }
    std::cout << "]\n";
}

inline void print(const std::vector<std::string>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        if (i) std::cout << ",";
        std::cout << "\"" << v[i] << "\"";
    }
    std::cout << "]\n";
}

inline void print(ListNode* head) {
    std::cout << "[";
    bool first = true;
    while (head) {
        if (!first) std::cout << ",";
        std::cout << head->val;
        first = false;
        head = head->next;
    }
    std::cout << "]\n";
}

inline void print(TreeNode* root) {
    if (!root) { std::cout << "[]\n"; return; }
    std::cout << "[";
    std::queue<TreeNode*> q;
    q.push(root);
    std::vector<std::string> parts;
    while (!q.empty()) {
        TreeNode* n = q.front(); q.pop();
        if (n) {
            parts.push_back(std::to_string(n->val));
            q.push(n->left);
            q.push(n->right);
        } else {
            parts.push_back("null");
        }
    }
    // trim trailing nulls
    while (!parts.empty() && parts.back() == "null") parts.pop_back();
    for (size_t i = 0; i < parts.size(); i++) {
        if (i) std::cout << ",";
        std::cout << parts[i];
    }
    std::cout << "]\n";
}

inline void print(bool b) { std::cout << (b ? "true" : "false") << "\n"; }
inline void print(int n) { std::cout << n << "\n"; }
inline void print(long long n) { std::cout << n << "\n"; }
inline void print(double d) { std::cout << d << "\n"; }
inline void print(const std::string& s) { std::cout << "\"" << s << "\"\n"; }

// test harness

static int _tc = 0;
template <typename T>
void expect(T got, T want) {
    _tc++;
    std::ostringstream g, w;
    g << got; w << want;
    if (g.str() == w.str())
        std::cout << "\033[32m✓ TC " << _tc << " passed\033[0m\n";
    else
        std::cout << "\033[31m✗ TC " << _tc << " FAILED: got " << g.str()
             << ", want " << w.str() << "\033[0m\n";
}
