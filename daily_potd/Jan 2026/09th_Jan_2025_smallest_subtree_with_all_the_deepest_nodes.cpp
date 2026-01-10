#include<bits/stdc++.h>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    pair<int, TreeNode*> helper(TreeNode* node){
        if(node == nullptr) return {0, nullptr};

        pair<int, TreeNode*> left = helper(node->left);

        pair<int, TreeNode*> right = helper(node->right);

        if(left.first == right.first){
            return {left.first + 1, node};
        }

        if(left.first > right.first){
            return {left.first + 1, left.second};
        }


        return {right.first + 1, right.second};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        pair<int, TreeNode*>res = helper(root);

        return res.second;
    }
};