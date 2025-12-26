#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length();
        vector<int>prefix(n+1, 0); // prefix count of N
        vector<int>suffix(n+1, 0); // suffix count of Y
        /*
            * for prefix count of N, we check if the previous index is N or not,if it is then it would contribute to current index of prefix array

            * for suffix count of N, we check if the current index is Y or not, if it is then it would contribute to current index of suffix array
        */
        // DRY RUN: 
        /*
            YYNY
            prefix count of N means that from current index i, the count of N we have seen till index i - 1
            prefixCount of N => 0 0 0 1
            suffixCount of Y => 3 2 1 1

            sum of N and y =>   3 2 2 2 => minium index = 1
        */
        prefix[0] = 0;
        for(int i = 1; i <= n; i++){
            // carry forward
            prefix[i] = prefix[i-1];
            // if previous index is N, that would contribute to the current index of prefix
            if(customers[i-1] == 'N'){
                prefix[i]++;
            }
        }
        suffix[n] = 0;
        for(int i = n-1; i>=0; i--){
            // carry forward
            suffix[i] = suffix[i+1];
            // if the current index is Y, then it would contribute to the current index
            if(customers[i] == 'Y'){
                suffix[i]++;
            }
        }
        int penalty = INT_MAX;
        int bestHour = 0;

        for(int i = 0; i <= n; i++){
            // calculate the current penalty
            int currentPenalty = suffix[i] + prefix[i];
            // if current penalty is less than minimum penalty we had till now, store it
            if(currentPenalty < penalty){
                bestHour = i ;
                penalty = currentPenalty;
            }
        }
        // return the best hour
        return bestHour;
    }
};