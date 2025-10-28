#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        map<int, map<int, multiset<int>>> mpp;  // <vertical, <level, multinodes>>
        queue<pair<TreeNode*, pair<int, int>>> q;     // <node, <vertical, level>>
        q.push({root, {0, 0}});

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int vertical = it.second.first;
            int level = it.second.second;
            mpp[vertical][level].insert(node->val);

            if (node->left) q.push({node->left, {vertical - 1, level + 1}});
            if (node->right) q.push({node->right, {vertical + 1, level + 1}});
        }
        for (auto it : mpp) {
            vector<int> col;
            for (auto multinodes : it.second) {
                col.insert(col.end(), multinodes.second.begin(), multinodes.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};