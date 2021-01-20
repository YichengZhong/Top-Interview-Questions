class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());

        vector<int>out;
        for(int i=0;i<k;++i)
        {
            out.push_back(arr[i]);
        }

        return out;
    }
};