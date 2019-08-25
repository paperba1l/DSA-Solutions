/**
 *  @author:      skyhavoc
 *  created:      2019
**/
/*
Given two sequences A, B, count number of unique ways in sequence A, to form a subsequence that is identical to the sequence B.

Subsequence : A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, “ACE” is a subsequence of “ABCDE” while “AEC” is not).
*/
int Solution::numDistinct(string A, string B) {
    int lena = A.length(), lenb = B.length();
    
    // if length of A is less than B, lena>lenb!
    // more character should be there in A to form more subsequence to match B
    if(lena<lenb) return 0;
    
    // O(n) space
    int dp[lena];
    
    for(int i=1; i<=lenb; i++) dp[i] = 0;
    dp[0] = 1;
   
   
    for(int i=1; i<=lena; i++) {
        int dp_diag = 1;
        for(int j=1; j<=lenb; j++) {

            int temp = dp[j];
            
            if(A[i-1]==B[j-1]){
                dp[j] = dp[j] + dp_diag;
            }
            
            dp_diag = temp;
        }
    }
    return dp[lenb];
}