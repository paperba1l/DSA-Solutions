/*
 * https://leetcode.com/problems/two-sum/
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mpp;
        vector<int> vec;
        for(int i=0; i<nums.size(); i++) {
            if(mpp.find(target-nums[i])!=mpp.end()) {
                vec.push_back(i);
                vec.push_back(mpp[target-nums[i]]);
                break;
            }
           
            mpp[nums[i]] = i;
            
        }
        return vec;
    }
};