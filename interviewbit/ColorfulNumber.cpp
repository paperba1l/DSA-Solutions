/**
 *  @author:      skyhavoc
 *  created:      2019
 *  problem:      For Given Number N find if its COLORFUL number or not
**/

int Solution::colorful(int A) {

    vector<int> vec;
    while(A>0) {
        int d = A%10;
        A/=10;
        vec.push_back(d);
    }
    
    int n = vec.size();
    map<int, int> mpp;
    for(int i=0; i<n; i++) {
        int prod = 1;
        for(int j=i; j<n; j++) {
            prod*=vec[j];
            if(mpp[prod]==0)
                mpp[prod]++;
            else {
                return 0;
            }
        }
    }
    return 1;
}
