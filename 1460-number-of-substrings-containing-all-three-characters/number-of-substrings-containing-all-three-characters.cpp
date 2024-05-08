class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char,int> mp;
        int n=s.size();
        int p1=0,p2=0,ans=0;
        while(p1<n && p2<n){
            mp[s[p2]]++;
            while(mp.size()==3) {
                ans+=(n-p2);
                mp[s[p1]]--;
                if(mp[s[p1]]<=0) mp.erase(s[p1]);
                p1++;
            }
            p2++;
        }
        return ans;
    }
};