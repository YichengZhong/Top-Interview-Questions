class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

    }

    bool isValidRow(vector<vector<char>>& board)
    {
        map<char, int>rowcount;

        for (int i = 0; i < 9; ++i)
        {
            rowcount.clear();
            for (int j = 0; j < 9; ++j)
            {
                if (rowcount.find(board[i][j]) == rowcount.end())
                {
                    rowcount[board[i][j]]=1;
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
	
	bool isValidRank(vector<vector<char>>& board)
    {
        map<char, int>rankcount;

        for (int i = 0; i < 9; ++i)
        {
            rankcount.clear();
            for (int j = 0; j <9; ++j)
            {
                if (rankcount.find(board[j][i]) == rankcount.end())
                {
                    rankcount[board[j][i]]=1;
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
	
	bool isValidBox(vector<vector<char>>& board)
	{
		map<char, int>boxcount;
	}
};