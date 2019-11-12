class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

    }

    bool isValidrow(vector<vector<char>>& board)
    {
        map<char, int>rowcount;

        for (int i = 0; i < board.size(); ++i)
        {
            rowcount.clear();
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (rowcount.find(board[i][j]) == rowcount.end())
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }

        return true;               
    }
};