class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());

        if(arr.size()<=2)
        {
            return true;
        }

        for(int i=0;i<arr.size()-2;++i)
        {
            if((arr[i+2]-arr[i+1])!=(arr[i+1]-arr[i]))
            {
                return false;
            }
        }

        return true;
    }
};