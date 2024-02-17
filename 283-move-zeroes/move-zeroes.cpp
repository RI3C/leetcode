class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0;
        int idx=0, n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=0) nums[idx++]=nums[i];
            else count++;
        }
        for(int i=n-count;i<n;i++) nums[i]=0;
    }
};