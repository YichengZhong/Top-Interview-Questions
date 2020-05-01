class Solution {
public:
    int out;
    int findMinFibonacciNumbers(int k) {
        vector<int>v_Fib;
        v_Fib.clear();
        out=INT_MAX;

        v_Fib.push_back(1);
        v_Fib.push_back(1);

        int temp=v_Fib[0]+v_Fib[1];
        int i=0;
        do
        {
            v_Fib.push_back(temp);
            i++;
            temp=v_Fib[i]+v_Fib[i+1];
        }while(temp<=k);

        vector<int> tmp;
        tmp.clear();
        dfs(0,k,tmp,v_Fib);

        return out;
    }

    void dfs(int start, int target, vector<int>& tmp, vector<int>& candidates)
    {
        int n = candidates.size();        
        for(int i = start; i < n; i ++)
        {            
            if(target > 0)
            {                          
                tmp.push_back(candidates[i]);  
                dfs(i, target-candidates[i], tmp, candidates);    
                tmp.pop_back();                     
            }            
            else if(target < 0)     
            {
                return;   
            }                     
            else
            {                
                if(out>tmp.size())
                {
                    out=tmp.size();
                }         
                return;            
            }       
        }    
    }
};