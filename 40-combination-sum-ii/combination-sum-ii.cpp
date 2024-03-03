class Solution {
public:
    void sumCombo(int index, int target, vector<int> &currSet, vector<int> &candidates, vector<vector<int>> &ans){
        if(target==0) {
            ans.push_back(currSet);
            return;
        }
        
        for(int idx=index; idx<candidates.size(); idx++){
            if(candidates[idx]>target) break;
            if(idx==index || candidates[idx]!=candidates[idx-1]){
                currSet.push_back(candidates[idx]);
                sumCombo(idx+1,target-candidates[idx],currSet,candidates,ans);
                currSet.pop_back();
            }
        }
    }

    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> currSet;
        sumCombo(0,target,currSet,candidates,ans);
        return ans;    
    }
};