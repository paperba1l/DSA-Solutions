'''
 *  @author:      skyhavoc
 *  created:      2019
'''

class Solution:
    # @param A : string
    # @return a strings
    def solve(self, A):
        arr = A.split();
        ans = ""
        if(len(arr)==0):
            return ans
        
        arr.reverse()
        for x in arr:
            ans = ans+x+" "

        return ans[0: -1]