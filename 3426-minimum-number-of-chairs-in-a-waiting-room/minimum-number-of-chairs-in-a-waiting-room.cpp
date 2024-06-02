class Solution {
public:
    int minimumChairs(string s) {
        int n=s.size();
        int ans=0, people=0;
        for(char c: s){
            if(c=='E') people++;
            else people--;
            ans=max(ans,people);
        } 
    return ans;
    }
};