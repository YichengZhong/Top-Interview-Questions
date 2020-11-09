class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        map<int,vector<vector<int>>>m_distance_point;
        for(int i=0;i<points.size();++i)
        {
            int temp=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            if(m_distance_point.find(temp)==m_distance_point.end())
            {
                vector<vector<int>> v_temp;
                v_temp.clear();

                v_temp.push_back(points[i]);
                m_distance_point[temp]=v_temp;
            }
            else
            {
                m_distance_point[temp].push_back(points[i]);
            }            
        }

        vector<vector<int>>v_out;
        v_out.clear();
        int count=0;

        for(auto iter=m_distance_point.begin();iter!=m_distance_point.end();++iter)
        {
            for(int i=0;i<iter->second.size();++i)
            {
                v_out.push_back((iter->second)[i]);
                count++;
                if(count>=K)
                {
                    return v_out;
                }
            }
        }
        return v_out;
    }
};