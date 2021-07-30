class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int maxtimeArrival=0;
        int maxtimeLeav=0;
        
        for(int i=0;i<times.size();++i)
        {
            maxtimeArrival=max(maxtimeArrival,times[i][0]);
            maxtimeLeav=max(maxtimeLeav,times[i][1]);
        }
               
        
        vector<vector<int>> timestemp=times;
        vector<int>seats(times.size(),-1);
        
        for(int i=0;i<=maxtimeArrival;++i)
        {
           //在第i个时刻，是否有人离开
            for(int j=0;j<timestemp.size();++j)
            {
                if(timestemp[j][1]==i)
                {
                    for(int k=0;k<seats.size();++k)
                    {
                        if(seats[k]==j)
                        {
                            seats[k]=(-1);
                        }
                    }
                }
            }
            
            //在第i个时刻，是否有人到达
            for(int j=0;j<timestemp.size();++j)
           {
                if(timestemp[j][0]==i)
               {
                    int k=0;
                    for(k=0;k<seats.size();++k)
                   {
                        if(seats[k]==(-1))
                       {
                            seats[k]=j;
                            break;
                       }
                   }
                    if(targetFriend==j)
                       {
                           return k;
                       }
               }
           }
            
        }
        
        return -1;

    }
};