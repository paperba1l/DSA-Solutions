int Solution::maxProduct(const vector<int> &A) {
    // important to init with the first element for case when -- A : [ 0 ]
    int ans = A[0], min_so_far = A[0], max_so_far = A[0];

    // start from index 1
    for(int i=1; i<A.size(); i++) {
        // swapping the max_so_far and min_so_far make sure that when A[i] is neg
        // max_so_far is min_so_far and min_so_far max_so_far. 
        if(A[i]<0) {
            swap(max_so_far, min_so_far);
        }
        

        // if A[i] is 0 then we have already calculated the max subarray product
        max_so_far = max(A[i], max_so_far*A[i]);
        min_so_far = min(A[i], min_so_far*A[i]);
        ans = max(max_so_far, ans);
    }
    return ans;
}
