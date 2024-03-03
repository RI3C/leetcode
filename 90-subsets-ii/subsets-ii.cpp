class Solution {
public:
    void subsets(int index, vector<int> &currSet, set<vector<int>> &ans, vector<int> &nums){
        if(index>=nums.size()){
            ans.insert(currSet);
            return;
        }
        for(int idx=index;idx<nums.size();idx++){
            if(idx==index || nums[idx]!=nums[idx-1]){
                currSet.push_back(nums[idx]);
                subsets(idx+1,currSet,ans,nums);
                currSet.pop_back();
                subsets(idx+1,currSet,ans,nums);
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        vector<int> currSet;
        int n=nums.size();
        subsets(0,currSet,ans,nums);
        vector<vector<int>> reqAns;
        for(auto it: ans) reqAns.push_back(it);
        return reqAns;
    }
};