class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> v_out;
        v_out.clear();
        
        if(1==n)
        {
            v_out.push_back(0);
            return v_out;
        }
        
        if(n%2==1)
        {
            int temp=(n/2);
            
            for(int i=(-temp);i<=temp;++i)
            {
                v_out.push_back(i);
            }
        }
        else
        {
            int temp=(n/2);
            for(int i=(-temp);i<=temp;++i)
            {
                if(i!=0)
                {
                    v_out.push_back(i);
                }
            }
        }
        
        return v_out;
        
    }
};