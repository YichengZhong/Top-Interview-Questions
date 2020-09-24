class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==0)
        {
            return 0;
        }

        while(stones.size()>1)
        {
            sort(stones.begin(),stones.end());
            int temp=stones[stones.size()-1]-stones[stones.size()-2];

            stones.pop_back();
            stones.pop_back();

            if(temp!=0)
            {
                stones.push_back(temp);
            }
        }

        if(stones.size()==0)
        {
            return 0;
        }

        return stones[0];
        
    }
};