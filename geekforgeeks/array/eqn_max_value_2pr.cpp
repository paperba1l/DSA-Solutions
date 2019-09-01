// Given an array A[ ] your task is to complete the function max_val which finds the maximum value of abs(i – j) * min(arr[i], arr[j]) where i and j vary from 0 to n-1. 
int max_val(int a[], int n)
{
    int l = 0, r= n-1;
    int ans = INT_MIN;
    while(l<r) {
        if(a[l]<a[r]) {
            ans = max(ans, a[l]*(r-l));
            l++;
        }
        else {
            ans = max(ans, a[r]*(r-l));
            r--;
        }
    }
    return ans;
}
// https://www.geeksforgeeks.org/find-maximum-value-of-absi-j-minarri-arrj-in-an-array-arr/
