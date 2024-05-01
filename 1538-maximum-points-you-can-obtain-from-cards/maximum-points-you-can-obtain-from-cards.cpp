class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        vector<int> prefix(n+1);
        prefix[0]=0;
        for(int i=1;i<=n;i++) prefix[i]=prefix[i-1]+cardPoints[i-1];
        if(k==n) return prefix[n];
        else{
            int ans=0;
            for(int i=0;i<=k;i++){
                ans=max(ans, prefix[i]+(prefix[n]-prefix[n-k+i]));
            }
            return ans;
        }
    }
};