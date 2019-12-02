class Solution {
public:
    int high=0,weight=0;
    bool exist(vector<vector<char>>& board, string word) 
    {
        high = board.size();
        weight = board[0].size();
        for(int i = 0; i < high; i++)
        {
            for(int j = 0; j < weight; ++j)
            {
                if(searchexist(board, word, 0, i, j)) 
                {
                    return true;
                }
            }
        }
        return false;
    }
    int searchexist(vector<vector<char>>& board, string &word, int n, int x, int y)
    {
        if(x < 0 || x > high-1 || y < 0 || y > weight-1 || word[n] != board[x][y])
            return 0;
        if(n == word.size()-1)
            return 1;
        char temp = board[x][y];
        board[x][y] = 0;
        int flag = searchexist(board, word, n+1, x+1, y)
                 ||searchexist(board, word, n+1, x-1, y)
                 ||searchexist(board, word, n+1, x, y+1)
                 ||searchexist(board, word, n+1, x, y-1);
        board[x][y] = temp;
        return flag;
    }

    
};