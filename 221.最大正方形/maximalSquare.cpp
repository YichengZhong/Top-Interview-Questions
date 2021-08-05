class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //每次遇到1，作为左上
        if(matrix.size()==0 || matrix[0].size()==0) return 0;

        int maxlen=0;
        for(int i=0;i<matrix.size();++i)
        {
            for(int j=0;j<matrix[0].size();++j)
            {
                if(matrix[i][j]=='1')
                {
                    maxlen=max(maxlen, 1);
                    // 计算可能的最大正方形边长
                    int currentMaxSide = min(matrix.size() - i, matrix[0].size() - j);

                    for(int k=1;k<currentMaxSide;++k)
                    {
                        //斜线
                        bool flag=true;
                        if (matrix[i + k][j + k] == '0') 
                        {
                            flag=false;
                            break;
                        }

                        //新增一行、一列
                        for (int m = 0; m < k; m++) 
                        {
                            if (matrix[i + k][j + m] == '0' || matrix[i + m][j + k] == '0') 
                            {
                                flag = false;
                                break;
                            }
                        }
                        
                        if (flag) 
                        {
                            maxlen = max(maxlen, k + 1);
                        } else
                        {
                            break;
                        }
                    }
                }
            }
        }

        return maxlen * maxlen;
    }
};