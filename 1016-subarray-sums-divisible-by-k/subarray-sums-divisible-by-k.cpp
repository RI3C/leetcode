class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pref(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++) pref[i]=pref[i-1]+nums[i];
        unordered_map<int,int> mp;
        mp[0]++;
        int ans=0;
        for(int i=0;i<n;i++){
            int rem=pref[i]%k;
            rem=(rem<0)?rem+k:rem;
            if(mp.find(rem)!=mp.end()) ans+=mp[rem];
            mp[rem]++;
        }
        return ans;
    }
};