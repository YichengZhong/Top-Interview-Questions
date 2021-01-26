class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<vector<int>,int>countmap;
        int count=0;
        
        for(int i=0;i<dominoes.size();++i)
        {
            sort(dominoes[i].begin(),dominoes[i].end());
            countmap[dominoes[i]]++;
        }

        for(auto iter=countmap.begin();iter!=countmap.end();++iter)
        {
            if(iter->second>=2)  count=count+(iter->second-1)*(iter->second)/2;
        }

        return count;
    }
};