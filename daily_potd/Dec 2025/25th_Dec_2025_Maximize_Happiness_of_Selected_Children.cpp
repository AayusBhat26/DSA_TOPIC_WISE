#include<bits/stdc++.h>
using namespace std;
/*
in this question we are supposed to find the maximum happiness by taking k children
there are n children standing in a queue, where the ith child has happiness value happiness[i], we want to select k children from these n children in k turns

In each turn, when you select a child, the happiness value of all the children that have not been selected till now decreases by 1. Note that the happiness value cannot become negative and gets decremented only if it is positive.

Return the maximum sum of the happiness values of the selected children you can achieve by selecting k children.
*/

class Solution {
    long long maximumHappinessSum(vector<int> &h, int k) {
        int n= h.size();
        long long res = 0;
        int decrementer = 0;
        int index = n - 1;
        while(index >= 0 && k > 0){
            int currentValue = h[index] - decrementer;
            if(currentValue <= 0){
                break ;
            }
            res += currentValue;
            index--;
            k--; 
        }
        return res;
    }
};