class Solution {
public:
    static int getF(int x) 
    {
        if (x == 1) 
        {
            return 0;
        }
        
        if (x & 1) 
        {
            return getF(x * 3 + 1) + 1;
        }
        else
        {
            return getF(x / 2) + 1;
        }
    }

   static bool selfcmp(int a,int b)
    {
        if (getF(a) > getF(b))
        {
            return false;
        }
        else if (getF(a) < getF(b))
        {
            return true;
        }
        else
        {
            return a < b;
        }
    }

    int getKth(int lo, int hi, int k) {
        vector<int> nums;
        nums.clear();

        for(int i=lo;i<=hi;++i)
        {
            nums.push_back(i);
        }

        sort(nums.begin(),nums.end(),selfcmp);

        return nums[k-1];
        
    }
};