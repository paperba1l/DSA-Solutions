/**
 *  @author:      skyhavoc
 *  created:      2019
 *  problem:      Largest Continuous Sequence Zero Sum
 * Find the largest continuous sequence in a array which sums to zero.
**/
vector<int> Solution::lszero(vector<int> &a) {
    
    long long int sum = 0, str_idx= 2, end_idx=0, n=a.size();
    map<long long int , int> mpp;
    mpp[0] = -1;
    for(int i=0; i<n; i++) {
        sum+=a[i];
        if(sum==0) {
            str_idx = 0;
            end_idx = i;
        }
        else if(mpp.find(sum)!=mpp.end()) {
            if((end_idx-str_idx)<(i-mpp[sum]-1)){
                str_idx = mpp[sum]+1;
                end_idx = i;
            }
        }
        if(mpp.find(sum)==mpp.end()){
            mpp[sum] = i;
        }
    }
    
    vector<int> vec;
    for(int i=str_idx; i<=end_idx; i++) {
        vec.push_back(a[i]);
    }
    return vec;
}
