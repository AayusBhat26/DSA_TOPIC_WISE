#include<bits/stdc++.h>
using namespace std;

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
    long long totalTreeSum = 0;
    long long maximumProduct = 0;
    const int MOD = 1e9 + 7;
    int totalSum(TreeNode* node){
        if(node == nullptr) return 0;

        return node->val + totalSum(node->left) + totalSum(node->right);
    }
    long long helper(TreeNode* node){
        if(node == nullptr){
            return 0;
        }
        long long left = helper(node->left);
        long long right = helper(node->right);

        long long subTreeSum = node->val + left + right;
        long long product = subTreeSum * (totalTreeSum - subTreeSum);

        maximumProduct = max(maximumProduct, product);

        return subTreeSum;
    }
    int maxProduct(TreeNode* root) {
        totalTreeSum = totalSum(root);
        helper(root);
        return maximumProduct % MOD;
    }
}