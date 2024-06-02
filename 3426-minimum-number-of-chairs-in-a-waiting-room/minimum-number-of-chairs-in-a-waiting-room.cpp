class Solution {
public:
    int minimumChairs(string s) {
        int n=s.size();
        int ans=0;
        for(int chair=1;chair<=n;chair++){
            int temp=chair;
            for(char c: s){
                if(c=='E') temp--;
                else temp++;
                if(temp<0) break;
            }
            if(temp>=0) {
                ans=chair;
                break;
            } 
        }
        return ans;
    }
};