class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        multimap<int, int>m_end_start;
        int int_out = 0;

        for (int i = 0; i < startTime.size(); ++i)
        {
            m_end_start.insert(make_pair(startTime[i], endTime[i]));
        }

        for (auto iter = m_end_start.begin(); iter != m_end_start.end(); ++iter)
        {
            if (iter->first <= queryTime && iter->second >= queryTime)
            {
                int_out++;
            }
        }

        return int_out;

    }
};