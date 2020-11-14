class Solution {
public:
    int maxScores;
    map<int,int>m_index_scores;
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        maxScores=0;
        vector<int>man;
        man.clear();

        helpDFS(scores,ages,man,0,0);

        return maxScores;
    }

    int helpDFS(vector<int>& scores, vector<int>& ages ,vector<int>&man,int index,int sum)
    {
        for(int i=index;i<scores.size();++i)
        {
            int agetemp=ages[i];
            int scoretemp=scores[i];
            int flag=0;

            if(m_index_scores.find(i)!=m_index_scores.end())
            {
                //return m_index_scores[i];
            }

            for(int j=0;j<man.size();++j)
            {
                if(agetemp>ages[man[j]] && scoretemp<scores[man[j]])
                {
                    flag=1;
                    break;
                }
                if(agetemp<ages[man[j]] && scoretemp>scores[man[j]])
                {
                    flag=1;
                    break;
                }
            }

            if(flag==0)
            {
                man.push_back(i);
                helpDFS(scores,ages,man,i+1,sum+scores[i]);
                maxScores=max(maxScores,sum+scores[i]);
                m_index_scores[i]=maxScores;
                man.pop_back();
            }
        }

        return maxScores;
    }
};