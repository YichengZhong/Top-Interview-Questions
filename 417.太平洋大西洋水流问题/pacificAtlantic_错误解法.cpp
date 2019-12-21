class Solution {
public:
    int matrix_rank,matrix_col;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> v_v_out;
        matrix_rank=matrix.size();

        if(0==matrix_rank)
        {
            return v_v_out;
        }

        matrix_col=matrix[0].size();

        int flag=0;//0代表在太平洋，1代表在大西洋，边界上的点认为在太平洋

        for(int i=0;i<matrix_rank;++i)
        {
            for(int j=0;j<matrix_col;++j)
            {
                if(goPacific(matrix,i,j) && goAtlantic(matrix,i,j))
                {
                    vector<int>temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    v_v_out.push_back(temp);
                }
            }
        }

        return v_v_out;
        
    }
    
    //判断是否走到太平洋
    int goPacific(vector<vector<int>>& matrix,int x, int y)
    {
        if(x == 0 || y == 0)
            return 1;

        if(x < 0 || y < 0 || x>matrix_rank || y>matrix_col )
            return 0;

        int temp = matrix[x][y];
        
        int flag_1=0,flag_2=0,flag_3=0,flag_4=0;
        int flag=0;

        if((x+1)<matrix_rank && matrix[x][y]>=matrix[x+1][y])
        {
            flag_1= goPacific(matrix, x+1, y);
        }

        if((x-1)>=0 && matrix[x][y]>=matrix[x-1][y])
        {
            flag_2= goPacific(matrix, x-1, y);
        }

        if((y+1)<matrix_col && matrix[x][y]>=matrix[x][y+1])
        {
            flag_3= goPacific(matrix, x, y+1);
        }

        if((y-1)>=0 && matrix[x][y]>=matrix[x][y-1])
        {
            flag_4= goPacific(matrix, x, y-1);
        }
        
        flag = flag_1 || flag_2 || flag_3 || flag_4 ;
    
        return flag;
    }

    //判断是否走到大西洋
    int goAtlantic(vector<vector<int>>& matrix,int x, int y)
    {
         if(x == (matrix_rank-1) || y == (matrix_col-1))
            return 1;

        if(x < 0 || y < 0 || x>matrix_rank || y>matrix_col )
            return 0;

        int flag_1=0,flag_2=0,flag_3=0,flag_4=0;
        int flag=0;

        if((x+1)<matrix_rank && matrix[x][y]>=matrix[x+1][y])
        {
            flag_1= goAtlantic(matrix, x+1, y);
        }

        if((x-1)>=0 && matrix[x][y]>=matrix[x-1][y])
        {
            flag_2= goAtlantic(matrix, x-1, y);
        }

        if((y+1)<matrix_col && matrix[x][y]>=matrix[x][y+1])
        {
            flag_3= goAtlantic(matrix, x, y+1);
        }

        if((y-1)>=0 && matrix[x][y]>=matrix[x][y-1])
        {
            flag_4= goAtlantic(matrix, x, y-1);
        }
        
        flag = flag_1 || flag_2 || flag_3 || flag_4 ;

        return flag;
    }
};