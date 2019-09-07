/**
 *  @author:      skyhavoc
 *  created:      2019
**/
/*
The following code is supposed to rotate the array A by B positions.
*/
vector<int> Solution::rotateArray(vector<int> &A, int B) {
    vector<int> ret; 
    for (int i = 0; i < A.size(); i++) {
        ret.push_back(A[(i + B)%A.size()]);
    }
    return ret; 
}
