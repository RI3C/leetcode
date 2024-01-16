class Solution {
public:
    string reverseWords(string s) {
        s+=" ";
        vector<string> words;
        int n=s.size();
        string word="";
        int space=0;
        for(int i=0;i<n;i++){
            if(s[i]!=' ') word+=s[i],space=0;
            else {
                if(s[i]==' ' && !space && word!="") {
                    words.push_back(word);
                    word="";
                }
                space=1;
            }
        }
        reverse(words.begin(),words.end());
        string ans="";
        for(string st: words) ans+=st+" ";
        ans.erase(ans.size()-1);
        return ans;
    }
};