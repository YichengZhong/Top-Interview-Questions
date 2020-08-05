class Solution {
public:
    int maxArea(vector<int>& height) {
        int out=0;

        int left=0,right=height.size()-1;

        while(left<right)
        {
            int weight=right-left;
            int high=min(height[left],height[right]);

            int tmp=weight*high;
            out=max(out,tmp);

            if(height[left]>height[right])
            {
                right--;
            }
            else
            {
                left++;
            }
        }

        return out;        
    }
};