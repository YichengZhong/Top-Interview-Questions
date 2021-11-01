class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int count=candyType.size()/2;
        unordered_set<int>sistype;

        for(int i=0;i<candyType.size();++i)
        {
            sistype.insert(candyType[i]);
            if(sistype.size()>=count)
            {
                return count;
            }
        }

        return sistype.size();
    }
};