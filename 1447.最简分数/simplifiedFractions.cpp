class Solution {
public:
    int Euclid_algorithm(int m,int n)
    {
        if(m%n==0)
        {
            return n;
        }
        else
        {
            return Euclid_algorithm(n,m%n);
        }
        
    }

    vector<string> simplifiedFractions(int n) {
        vector<string>v_out;
        v_out.clear();
        
        if(n<=1)
        {
            return v_out;
        }

        for(int i=1;i<n;++i)
        {
            for(int j=2;j<=n;++j)
            {
                if(i>=j)
                {
                    continue;
                }
                else if(i>=2 && Euclid_algorithm(j,i)!=1)
                {
                    continue;
                }
                else
                {
                    string temp=to_string(i)+"/"+to_string(j);
                    v_out.push_back(temp);
                }
            }
        }

        return v_out;

    }
};