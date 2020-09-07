class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<long long, int> map;
        int n=nums1.size();
        int m=nums2.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                long long ind=(long long)nums1[i]*nums1[j];
                if(map.count(ind))
                {
                    map[ind]++;
                }
                else 
                {
                    map[ind]=1;
                }
                
            }
        }
        for(int i=0;i<m;i++)
        {
            long long ind=(long long)nums2[i]*nums2[i];
            if(map.count(ind))
            {
                ans+=map[ind];
            }
            
        }

        map.clear();
        
        for(int i=0;i<m;i++)
        {
            for(int j=i+1;j<m;j++)
            {
                long long ind=(long long)nums2[i]*nums2[j];
                if(map.count(ind))
                {
                    map[ind]++;
                }               
                else 
                {
                    map[ind]=1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            long long ind=(long long)nums1[i]*nums1[i];
            if(map.count(ind))
            {
                ans+=map[ind];
            }
            
        }
        return ans;
    }
};