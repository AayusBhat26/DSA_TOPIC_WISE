#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int index1, int index2, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp){
        if(index1 >= nums1.size() ||  index2 >= nums2.size()) return INT_MIN;
        if( dp[index1][index2] != INT_MIN){
            return dp[index1][index2];
        }
        int pick = INT_MIN;
        if(index1 < nums1.size() && index2 < nums2.size()){
            int prod = nums1[index1] * nums2[index2];
            int next = helper(index1 + 1, index2 + 1, nums1, nums2, dp);
            pick = max(prod, (next == INT_MIN) ? INT_MIN : prod + next);
        }

        int notpick1 = helper(index1 + 1, index2, nums1, nums2, dp);
        int notpick2 = helper(index1, index2 + 1, nums1, nums2, dp);

        return dp[index1][index2] = max({pick, notpick1, notpick2});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>>dp(n1 + 1, vector<int>(n2 + 1, INT_MIN));
        // return helper(0, 0, nums1, nums2, dp);

        // tabulated code
        for(int i = n1 - 1; i >= 0; i--){
            for(int j = n2 - 1; j >= 0; j--){
                int prod = nums1[i] * nums2[j];
                int pick = prod;
                if(dp[i+1][j+1] != INT_MIN){
                    pick = max(pick, pick + dp[i+1][j+1]);
                }
                int notpick1 = dp[i+1][j];
                int notpick2 = dp[i][j+1];
                dp[i][j] = max({pick, notpick1, notpick2});
            }
        }
        return dp[0][0];

    }
};