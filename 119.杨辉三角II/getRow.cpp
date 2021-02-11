class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return {1};
        if(rowIndex == 1) return {1,1};

        vector<int>vOut;
        vOut.clear();
        vector<int>temp={1,1};

        for(int i=2;i<=rowIndex;++i)
        {
            vOut.push_back(1);
            for(int j=0;j<temp.size()-1;++j)
            {
                int tempVaule=temp[j]+temp[j+1];
                vOut.push_back(tempVaule);
            }
            vOut.push_back(1);
            temp=vOut;
            vOut.clear();
        }

        return temp;
    }
};