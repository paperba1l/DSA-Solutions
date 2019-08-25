int Solution::numDistinct(string A, string B) {
    int lena = A.length(), lenb = B.length();
    
    // if length of A is less than B, lena>lenb!
    // more character should be there in A to form more subsequence to match B
    if(lena<lenb) return 0;
    
    vector<int> dp[lenb+1];
    for(int i=0; i<=lenb; i++) {
        dp[i].resize(lena+1);
    }
    
    // if B length is zero, then any sequence matches to it
    for(int i=0; i<=lena; i++) {
        dp[0][i] = 1;
    }
    
    // A in column and B in row
    for(int i=1; i<=lenb; i++) {
        for(int j=1; j<=lena; j++) {
            // if we do not choose the jth element then the answer remains dp[i][j-1];
            dp[i][j] = dp[i][j-1];
            
            // if the element match then add answer for A[0..j-1] and B[0..i-1]
            if(A[j-1]==B[i-1]){
                dp[i][j] += dp[i-1][j-1];
            }
        }
    }
    return dp[lenb][lena];
}
