class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int>v_out=nums;

        sort(v_out.begin(),v_out.end());

        return v_out;
        
    }
};