class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int currSum=accumulate(nums.begin(),nums.end(),0);
        int reqSum=(n*(n+1))/2;
        return reqSum-currSum;
    }
};