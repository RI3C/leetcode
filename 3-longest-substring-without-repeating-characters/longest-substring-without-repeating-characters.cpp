class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int length=0, ans=0;
        unordered_set<char> us;
        int p1=0,p2=0;
        while(p1<n && p2<n){
            if(!us.count(s[p2])){
                length++;
                us.insert(s[p2]);
                p2++;
            }
            else{
                ans=max(ans,length);
                while(s[p1]!=s[p2]) us.erase(s[p1]), p1++;
                p1++;
                length=p2-p1+1;
                p2++;
            }
        }
        ans=max(ans,length);
        return ans;
    }
};