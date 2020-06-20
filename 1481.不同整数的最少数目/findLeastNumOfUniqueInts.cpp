class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>m_num_count;

        for(int i=0;i<arr.size();++i)
        {
            m_num_count[arr[i]]++;
        }

        vector<int> cnt;

        for (auto& p : m_num_count) 
        {
            cnt.push_back(p.second);
        }
        
        sort(cnt.begin(), cnt.end());

        int ans = cnt.size();
        for (auto& c : cnt) 
        {
            if (c > k) 
            {
                break;
            }
            
            k -= c;
            --ans;
        }
        return ans;
       

    }
};