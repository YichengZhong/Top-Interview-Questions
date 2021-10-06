class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        if(timePoints.size()>=1440) return 0;
        vector<int>timeMinList;

        for(int i=0;i<timePoints.size();++i)
        {
            string hour="";
            hour=hour+timePoints[i][0]+timePoints[i][1];
            string min="";
            min=min+timePoints[i][3]+timePoints[i][4];
            int timehour=atoi(hour.c_str());
            int timemin=atoi(min.c_str());
            int timeAAllmin=60*timehour+timemin;

            timeMinList.push_back(timeAAllmin);
        }

        sort(timeMinList.begin(),timeMinList.end());

        int minlen=1440;
        for(int i=1;i<timeMinList.size();++i)
        {
            minlen=min(minlen,abs(timeMinList[i]-timeMinList[i-1]));
        }

        minlen=min(minlen,1440-abs(timeMinList[0]-timeMinList[timeMinList.size()-1]));
        
        return minlen;
    }
};