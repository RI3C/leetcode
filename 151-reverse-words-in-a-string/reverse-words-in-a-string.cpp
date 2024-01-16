class Solution {
public:
    string reverseWords(string s) {
        s+=" ";
        vector<string> words;
        int n=s.size();
        string word="";
        int space=0;
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]!=' ') word+=s[i],space=0;
            else {
                if(s[i]==' ' && !space && word!="") {
                    ans=" "+word+ans;
                    word="";
                }
                space=1;
            }
        }
        ans.erase(ans.begin());
        return ans;
    }
};