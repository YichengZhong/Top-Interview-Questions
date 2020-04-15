class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v_out;
        for(int i=0;i<num+1;++i)
        {
            v_out.push_back(getBitsNum(i));
        }
        
        return v_out;
        
    }
    
    int getBitsNum(int i)
    {
        int count=0;
        
        while(i!=0)
        {
            i=i&(i-1);
            count++;
        }
        
        return count;
    }
};