class Solution {
public:
    vector<int> constructRectangle(int area) {
        int temp1,temp2;
        for(int i=1;i<=sqrt(area);i++)
        {
            if(area%i==0)
            {
                if(i>area/i)
                    break;
                else{
                    temp1=i;
                    temp2=area/i;
                }
            }
        }
        vector<int> res;
        res.push_back(temp2);
        res.push_back(temp1);
        return res;

    }
};