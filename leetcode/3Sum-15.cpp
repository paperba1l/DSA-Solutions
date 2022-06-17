class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n<3) {
            return ans;
        }
        
        for(int i=0; i<n-2; i++) {
            if(i>0 and nums[i-1] == nums[i]) {
                continue;
            }
            
            int l = i+1, r = n-1;
            while(l<r) {
                int sm = nums[l]+nums[r]+nums[i];
                
                if(sm == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while(l<=(n-2) and nums[l] == nums[l+1]) {
                        l++;
                    }
                    
                    while(r>=1 and nums[r-1] == nums[r]) {
                        r--;
                    }
                    
                    r--;
                    l++;
                    
                } else if(sm > 0) {
                    r--;
                } else{
                    l++;
                }
            }
        }
        
        return ans;
    }
};
