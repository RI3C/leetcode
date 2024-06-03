class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int prevEnd=-1;
        int prevStart=-1;
        vector<pair<int,int>> mergedMeetings;
        for(auto i: meetings){
            if(i[0]>prevEnd){
                mergedMeetings.push_back({i[0],i[1]});
                prevEnd=i[1];
                prevStart=i[0];
            }
            else{
                int newStart=min(prevStart,i[0]);
                int newEnd=max(prevEnd,i[1]);
                mergedMeetings.pop_back();
                mergedMeetings.push_back({newStart,newEnd});
                prevEnd=newEnd;
                prevStart=newStart;
            }
        }
        int ans=0,totalMeetDays=0;
        for(auto i: mergedMeetings){
            totalMeetDays+=(i.second-i.first+1);
        }
        ans=days-totalMeetDays;
        return ans;
    }
};