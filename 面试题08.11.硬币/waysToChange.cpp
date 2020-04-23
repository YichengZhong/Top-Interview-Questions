class Solution {
public:
    int num;
    int waysToChange(int n) {
        vector<int>corns;
        corns.clear();
        num=0;

        corns.push_back(1);
        corns.push_back(5);
        corns.push_back(10);
        corns.push_back(25);

        compute(0,n,corns);

        return num;
    }

    void compute(int start, int target, vector<int>corns) 
    {
        int n = corns.size();        
        for(int i = start; i < n; i ++)
        {            
            if(target > 0)
            {                            
                compute(i, target-corns[i],corns);                 
            }            
            else if(target < 0)                
                return;            
            else
            {                
                num++;           
                return;            
            }       
        }    
    }
};