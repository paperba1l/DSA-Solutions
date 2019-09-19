'''
 *  @author:      skyhavoc
 *  created:      2019
 *  problem:      Array 3 Pointers
 You are given 3 arrays A, B and C. All 3 of the arrays are sorted.

Find i, j, k such that :
max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.
Return t
'''
class Solution:
	# @param A : tuple of integers
	# @param B : tuple of integers
	# @param C : tuple of integers
	# @return an integer
    def minimize(self, A, B, C):
        i = 0
        j = 0
        k = 0
        minmax = float("inf")
        while i < len(A) and j < len(B) and k < len(C):
            max1 = max(A[i], B[j], C[k])
            min1 = min(A[i], B[j], C[k])
            
            minmax = min(minmax, max1-min1)

            if A[i] == min1:
                i += 1
            elif B[j] == min1:
                j += 1
            else:
                k += 1
        
        return minmax
