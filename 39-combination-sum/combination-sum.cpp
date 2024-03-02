class Solution {
public:
    void sumCombo(int index, int target, vector<int> &currSet, vector<vector<int>> &ans, vector<int>& candidates, int n){
        if(index>=n){
            if(target==0) ans.push_back(currSet);
            return;
        }
        if(candidates[index]<=target) {
            currSet.push_back(candidates[index]);
            sumCombo(index,target-candidates[index],currSet,ans,candidates,n);
            currSet.pop_back();
        }
        sumCombo(index+1,target,currSet,ans,candidates,n);
    }
   
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currSet;
        int n=candidates.size();
        sumCombo(0,target,currSet,ans,candidates,n);
        return ans;
    }
};