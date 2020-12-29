class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        flag=1;
        vector<string>line;
        line.clear();

        for(int i=0;i<n;++i)
        {
            line.push_back("NULL");
        }

        for(int i=0;i<n;++i)
        {
            TicTacTable.push_back(line);
        }       

        player_flag[1]="X";
        player_flag[2]="O"; 
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        TicTacTable[row][col]=player_flag[player];

        //判断是否获胜
        return judeGame(player);        
    }

    int judeGame(int player)
    {
        string playstr=player_flag[player];

        //判断行
        for(int i=0;i<TicTacTable.size();++i)
        {
            int count=0;
            for(int j=0;j<TicTacTable[0].size();++j)
            {
                if(TicTacTable[i][j]==playstr)
                {
                    count++;
                }
            }

            if(TicTacTable.size()==count)
            {
                return player;
            }
        }

        //判断列
        for(int i=0;i<TicTacTable[0].size();++i)
        {
           int count=0;
           for(int j=0;j<TicTacTable[0].size();++j)
           {
               if(TicTacTable[j][i]==playstr)
               {
                   count++;
               }
           }

           if(TicTacTable.size()==count)
           {
               return player;
           }
        }

        //判断对角线
        int count=0;
       for(int i=0;i<TicTacTable.size();++i)
       {
            if(TicTacTable[i][i]==playstr)
            {
                count++;
            }
            if(TicTacTable.size()==count)
           {
               return player;
           }

       }

       count=0;
       for(int i=0;i<TicTacTable.size();++i)
       {
            if(TicTacTable[i][TicTacTable.size()-1-i]==playstr)
            {
                count++;
            }
            if(TicTacTable.size()==count)
           {
               return player;
           }

       }

        return 0;
    }

    int flag;
    map<int,string>player_flag;
    vector<vector<string>>TicTacTable;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */