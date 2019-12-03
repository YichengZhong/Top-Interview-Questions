class Solution {
public:
int count=0;
int direction[2][2]={{1,0},{0,1}};
    int uniquePaths(int m, int n) {
        count=0;
        vector<vector<int>>v_flag;
        for(int i=0;i<m;++i)
        {
            vector<int>temp;
            for(int j=0;j<n;++j)
            {
                temp.push_back(0);
            }

            v_flag.push_back(temp);
        }


        dfs(0,0,m,n,v_flag);

        return count;       
    }

    void dfs(int x,int y,int m,int n,vector<vector<int>>&v_flag)
    {
        if(x==m-1 && y==n-1)
        {
            count++;
        }

        if((x<m)&&(y<n))
        {
            v_flag[x][y]=1;
            for(int i=0;i<2;++i)
            {
                int xnew=x+direction[i][0];
                int ynew=y+direction[i][1];

                if((xnew<m)&&(ynew<n)&&v_flag[xnew][ynew]==0)
                {
                    dfs(xnew,ynew,m,n,v_flag);
                }
            }

            v_flag[x][y]=0;

        }


        return ;

        
    }
};