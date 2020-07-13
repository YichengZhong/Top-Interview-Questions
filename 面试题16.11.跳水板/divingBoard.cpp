class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int>v_out;
        v_out.clear();

        if(k==0)
        {
            return v_out;
        }

        if(shorter==longer)
        {
            int temp=shorter*k;
            v_out.push_back(temp);
            return v_out;
        }

        for(int i=0;i<=k;++i)
        {
            int temp=i*longer+(k-i)*shorter;
            v_out.push_back(temp);
        }

        return v_out;

    }
};