class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        int open=0, count=0;
        int p1=0, p2=0;
        while(p1<n && p2<n){
            if(open && count==0){
                open=0;
                s[p1]='*',s[p2]='*';
                p2++;
                p1=p2;
            }
            if(s[p1]=='(') {
                count++, open=1;
                while(count) {
                p2++;
                if(s[p2]=='(') count++;
                else count--;
                }
            }
        }
        string ans="";
        for(char c: s){
            if(c!='*') ans+=c;
        }
        return ans;
    }
    
};