class Solution {
public:
    vector<vector<int>> v_out;
    vector<int> temp_nums;
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        temp_nums=nums;
        help(0,nums.size(),temp_nums);

        set<vector<int>>si(v_out.begin(), v_out.end());
        v_out.assign(si.begin(), si.end());
        
        return v_out;
    }
    
    void help(int k,int size,vector<int> &temp)
    {
        if(k>=size)
        {
            v_out.push_back(temp);
        }
        
        for(int i=k;i<size;++i)
        {
            swap(temp[i],temp[k]);
            help(k+1,size,temp);
            swap(temp[i],temp[k]);        
        }
    }
    
    void swap(int &a,int &b)
    {
        int temp=0;
        temp=a;
        a=b;
        b=temp;
    }
};