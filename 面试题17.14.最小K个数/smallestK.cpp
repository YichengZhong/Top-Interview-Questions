class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int>v_out;
        v_out.clear();

        if(k<=0) return v_out;

        int min_len=k>arr.size()?arr.size():k;
        for(int i=0;i<min_len;++i)
        {
            v_out.push_back(arr[i]);
        }

        sort(v_out.begin(),v_out.end());

        for(int i=k;i<arr.size();++i)
        {
            if(arr[i]<=v_out.back())
            {
                v_out.pop_back();
                v_out.push_back(arr[i]);

                sort(v_out.begin(),v_out.end());
            }
        }
        return v_out;
    }
};