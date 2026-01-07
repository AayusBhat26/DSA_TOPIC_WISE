#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        int maxLevel = 1;
        int currentLevel = 1;
        int maxSum = INT_MIN;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            int currentSum = 0;
            for (int i = 0; i < size; i++)
            {
                TreeNode *currentNode = q.front();
                q.pop();
                currentSum += currentNode->val;
                if (currentNode->left)
                {
                    q.push(currentNode->left);
                }

                if (currentNode->right)
                {
                    q.push(currentNode->right);
                }
            }
            if (currentSum > maxSum)
            {
                maxSum = currentSum;
                maxLevel = currentLevel;
            }
            currentLevel++;
        }
        return maxLevel;
    }
};