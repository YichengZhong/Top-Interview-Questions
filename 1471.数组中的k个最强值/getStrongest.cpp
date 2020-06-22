class Solution {
public:
    static int midNum;
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        vector<int>v_out;

        midNum=arr[(arr.size()-1)/2];

        sort(arr.begin(),arr.end(),my_cmp);

        for(int i=0;i<k;++i)
        {
            v_out.push_back(arr[i]);
        }

        return v_out;
    }

    static bool my_cmp(int a,int b)
    {
        if(fabs(a-midNum)>fabs(b-midNum))
        {
            return true;
        }
        else if(fabs(a-midNum)==fabs(b-midNum) && a>b)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int Solution::midNum = 0;