#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if (!root) return s;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (!node) s.append("#,");
            else {
                s.append(to_string(node->val)+',');
                q.push(node->left);
                q.push(node->right);
            }
            
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;

        stringstream ss(data);
        string token;
        getline(ss, token, ',');
        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            getline(ss, token, ',');
            if (token == "#") node->left = NULL;
            else {
                TreeNode* newNode = new TreeNode(stoi(token));
                node->left = newNode;
                q.push(newNode);
            }

            getline(ss, token, ',');
            if (token == "#") node->right = NULL;
            else {
                TreeNode* newNode = new TreeNode(stoi(token));
                node->right = newNode;
                q.push(newNode);
            }
        }
        return root;
    }
};