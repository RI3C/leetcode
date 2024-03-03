class Solution {
public:
    void subsets(int index, vector<int> &currSet, vector<vector<int>> &ans, vector<int> &nums){
        ans.push_back(currSet);
        for(int idx=index;idx<nums.size();idx++){
            if(idx==index || nums[idx]!=nums[idx-1]){
                currSet.push_back(nums[idx]);
                subsets(idx+1,currSet,ans,nums);
                currSet.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> currSet;
        int n=nums.size();
        subsets(0,currSet,ans,nums);
        return ans;
    }
};