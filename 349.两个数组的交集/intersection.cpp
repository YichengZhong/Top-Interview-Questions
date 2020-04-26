class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        set<int> set_output;
        vector<int> vector_output;
        for(int i=0;i<nums1.size();++i)
        {
            for(int j=0;j<nums2.size();++j)
            {
                if(nums1[i]==nums2[j])
                {
                    set_output.insert(nums1[i]);
                }
            }
        }
        
        set<int>::iterator  it; 
        for(it = set_output.begin(); it != set_output.end(); it++)
        {
            vector_output.push_back(*it);
        }
        return vector_output;
    }
};