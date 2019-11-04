class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1;
        
        int max=0,temp=0;
        
        while(left<right)
        {
            temp=(right-left)*(height[left]>height[right]?height[right]:height[left]);
            max=(max>temp?max:temp);
            
            if(height[left]>height[right])
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        
        return max;
        
    }
};