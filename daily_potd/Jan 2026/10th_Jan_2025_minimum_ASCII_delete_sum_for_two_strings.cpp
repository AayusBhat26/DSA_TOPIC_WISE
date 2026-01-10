#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int helper(int index1, int index2, string s1, string s2, vector<vector<int>>& dp){
        if(index1== s1.length()) {
            int sum = 0;
            for(int i = index2; i < s2.length(); i++){
                sum += (int)s2[i];
            }
            return sum ;
        }

        if(index2 == s2.length()){
            int sum = 0;
            for(int i = index1; i < s1.length(); i++){
                sum += (int)s1[i];
            }
            return sum ;
        }
        if(dp[index1][index2] != -1){
            return dp[index1][index2];
        }
        if(s1[index1] == s2[index2]){
            return dp[index1][index2] = helper(index1 + 1, index2 + 1, s1, s2, dp);
        }

        int first = (int)s1[index1] + helper(index1 + 1, index2, s1, s2, dp);
        int second = (int)s2[index2] + helper(index1, index2 + 1, s1, s2, dp);

        return dp[index1][index2] = min(first, second);
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        // vector<vector<int>>dp(n + 1, vector<int>(m + 1 , -1));
        // return helper(0, 0, s1, s2, dp);

        vector<vector<int>>dp(n + 1, vector<int>(m + 1 , 0));
        for(int j = m - 1; j >= 0; j--){
            dp[n][j] = dp[n][j+1] + (int)s2[j];
        }

        for(int i = n - 1; i >= 0; i--){
            dp[i][m] = dp[i+1][m] + (int)s1[i];
        }
        for(int i = n - 1 ; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                if(s1[i] == s2[j]){
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else{
                    int first = (int)s1[i] + dp[i + 1][j];
                    int second = (int)s2[j] + dp[i][j+1];
                    dp[i][j] = min(first, second);
                }
            }
        }

        return dp[0][0];
    }
};