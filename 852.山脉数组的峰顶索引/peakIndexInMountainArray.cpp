class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        vector<int> arr_temp=arr;
        sort(arr_temp.begin(),arr_temp.end());

        for(int i=0;i<arr.size();++i)
        {
            if(arr[i]==arr_temp[arr.size()-1])
            {
                return i;
            }
        }
        return 0;
    }
};