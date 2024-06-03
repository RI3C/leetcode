class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n=meetings.size();
        vector<pair<int,int>> initialMeetings;
        for(auto i: meetings){
            initialMeetings.push_back({i[0],i[1]});
        }
        sort(initialMeetings.begin(),initialMeetings.end());
        int prevEnd=-1;
        int prevStart=-1;
        vector<pair<int,int>> mergedMeetings;
        for(auto i: initialMeetings){
            if(i.first>prevEnd){
                mergedMeetings.push_back(i);
                prevEnd=i.second;
                prevStart=i.first;
            }
            else{
                int newStart=min(prevStart,i.first);
                int newEnd=max(prevEnd,i.second);
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