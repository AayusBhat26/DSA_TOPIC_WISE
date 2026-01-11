#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAreaOfHistogram(vector<int>& heights){
        stack<int>st;
        int maxArea = 0;
        int n = heights.size();

        for(int i = 0; i <= n; i++){
            int currentHeight = (i == n) ? 0 : heights[i];

            while(!st.empty() && currentHeight < heights[st.top()]){
                int h = heights[st.top()];
                st.pop();
                int width ;

                if(st.empty()){
                    width = i;
                }
                else{
                    width = i - st.top() - 1;
                }
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }

        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>heights(m, 0);
        int res = 0;
        for(int i =  0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == '1'){
                    heights[j]++;
                }
                else{
                    heights[j] = 0;
                }
            }
            res = max(res, maxAreaOfHistogram(heights));
        }

        return res;
    }
};