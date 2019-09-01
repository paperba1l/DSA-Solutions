
/**
 *  @author:      skyhavoc
 *  created:      2019
**/
/*
LeftSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (i>j). If multiple A[j]’s are present in multiple positions, the LeftSpecialValue is the maximum value of j. 

RightSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] (j>i). If multiple A[j]s are present in multiple positions, the RightSpecialValue is the minimum value of j.

Write a program to find the maximum special product of any integer in the array.
*/
int Solution::maxSpecialProduct(vector<int> &A) {
    int n = A.size();
    vector<int> l_arr(n,0), r_arr(n,0);
    
    stack<int> stk, stk2;
    for(int i=0; i<n; i++) {
        while(!stk.empty() and A[i]>A[stk.top()]) {
            int idx = stk.top();
            stk.pop();
            r_arr[idx] = i;
        }
        stk.push(i);
    }

    for(int i=n-1; i>=0; i--) {
        while(!stk2.empty() and A[i]>A[stk2.top()]) {
            int idx = stk2.top();
            stk2.pop();
            l_arr[idx] = i;
        }
        stk2.push(i);
    }
    
    long long mx = -1;
    for(int i=0; i<n; i++){
        mx=max(mx, (l_arr[i]) *1LL* (r_arr[i]));
    }
    return mx%1000000007;
}