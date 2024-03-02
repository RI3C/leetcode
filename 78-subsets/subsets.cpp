class Solution {
public:
    void powerSet(int index, vector<int> &currSet, int n, vector<int>& nums, vector<vector<int>> &ans){
        if(index>=n) {
            ans.push_back(currSet);
            return;
        }
        
        currSet.push_back(nums[index]);
        powerSet(index+1,currSet,n,nums,ans);
        currSet.pop_back();
        powerSet(index+1,currSet,n,nums,ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> currSet;
        int n=nums.size();
        powerSet(0,currSet,n,nums,ans);
        return ans;
    }
};