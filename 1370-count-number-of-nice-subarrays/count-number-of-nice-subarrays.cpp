class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size(), ans=0;
        vector<int> pref(n+1);
        pref[0]=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i=1;i<=n;i++){
            if(nums[i-1]%2) pref[i]=pref[i-1]+1;
            else pref[i]=pref[i-1];
            mp[pref[i]]++;
        }
       // for(auto i: mp) cout<<i.first<<" "<<i.second<<" \n";
        for(int i=0;i<=n;i++){
            if(pref[i]<k) continue;
            else{
                if(mp.find(pref[i]-k)!=mp.end()) ans+=mp[pref[i]-k];
            }
        }
        return ans;
    }
};