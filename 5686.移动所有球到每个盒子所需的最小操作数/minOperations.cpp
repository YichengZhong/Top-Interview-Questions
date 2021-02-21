class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>vout;
        //前缀和        
        for(int i=0;i<boxes.size();++i)
        {
            int sum=0;
            //从左边
            for(int j=0;j<i;++j)
            {
                if(boxes[j]=='1')
                {
                    sum=sum+i-j;
                }
            }
            
            //从右边
            for(int k=i+1;k<boxes.size();++k)
            {
                if(boxes[k]=='1')
                {
                    sum=sum+k-i;
                }
            }
            
            vout.push_back(sum);
        }
        
        return vout;
    }
};