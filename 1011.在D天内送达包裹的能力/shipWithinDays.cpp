class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        //采用二分搜索
        int left=weights[0];
        int right=0;

        for(int i=0;i<weights.size();++i)
        {
            left=max(left,weights[i]);
            right=right+weights[i];
        }

        while(left<=right)
        {
            int mid=(left+right)/2;

            if(CheckWeight(D,mid,weights))
            {
                cout<<"CheckWeight is True:mid="<<mid<<endl;
                right=mid-1;
            }
            else
            {
                cout<<"CheckWeight is false:mid="<<mid<<endl;
                left=mid+1;
            }

            cout<<"left:"<<left<<endl;
            cout<<"right:"<<right<<endl;
        }

        return left;

    }

    bool CheckWeight(int D,int weight,vector<int>& weights)
    {
        int temp=0;
        int D_count=1;
        for(int i=0;i<weights.size();++i)
        {
            if((temp+weights[i])>weight)
            {
                D_count++;
                temp=weights[i];
            }
            else
            {
                temp=temp+weights[i];
            }
        }

        if(D_count>D)
        {
            return false;
        }

        return true;
    }
};