class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int>v_left;
        vector<int>v_right;

        vector<int>v_out;
        v_out.clear();

        if(a.size()==0)
        {
            return v_out;
        }

        v_left.clear();
        v_left.push_back(1);
        v_right.clear();
        v_right.push_back(1);

        int temp=1;
        for(int i=0;i<a.size();++i)
        {
            temp=temp*a[i];
            v_left.push_back(temp);
        }

        temp=1;
        for(int i=a.size()-1;i!=0;--i)
        {
            temp=temp*a[i];
            v_right.push_back(temp);
        }


        for(int i=0;i<a.size();++i)
        {
            v_out.push_back(v_left[i]*v_right[a.size()-1-i]);
        }

        return v_out;

    }
};