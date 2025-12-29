#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(const vector<int>& A, const vector<int>& B) {
    const vector<int> *a=&A, *b=&B;
    if (a->size() > b->size()) swap(a,b);
    int n=a->size(), m=b->size();
    int low=0, high=n;
    while (low<=high) {
        int cutA = (low+high)/2;
        int cutB = (n+m+1)/2 - cutA;
        int lA = cutA==0? INT_MIN : (*a)[cutA-1];
        int lB = cutB==0? INT_MIN : (*b)[cutB-1];
        int rA = cutA==n? INT_MAX : (*a)[cutA];
        int rB = cutB==m? INT_MAX : (*b)[cutB];
        if (lA<=rB && lB<=rA) {
            if ((n+m)%2==0) return (max(lA,lB)+min(rA,rB))/2.0;
            else return max(lA,lB);
        } else if (lA > rB) high = cutA - 1; else low = cutA + 1;
    }
    return 0; // unreachable
}

int main() {
    vector<int> a = {1,3};
    vector<int> b = {2};
    cout << fixed << setprecision(5) << findMedianSortedArrays(a,b) << "\n";
    return 0;
}
