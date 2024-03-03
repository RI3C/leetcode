class Solution {
public:
    void combo(int x, int target, vector<int> &currSet, vector<vector<int>> &ans, int k){
        if(target==0){
            if(currSet.size()==k) ans.push_back(currSet);
            return;
        }
        for(int num=x;num<=9;num++){
            if(num>target) break;
            currSet.push_back(num);
            combo(num+1,target-num,currSet,ans,k);
            currSet.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> currSet;
        combo(1,n,currSet,ans,k);
        return ans;
    }
};