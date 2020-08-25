class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());

        int BoatesCount=0;
        int right=0,left=people.size()-1;

        while(right<=left)
        {
            BoatesCount++;

            if((people[right]+people[left])<=limit)
            {
                right++;
                left--;
            }
            else
            {
                left--;
            }
        }

        return BoatesCount;

    }
};