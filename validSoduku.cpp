class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for(int i = 0; i < board.size(); ++i)
        {
            for(int j = 0; j < board[i].size(); ++j)
            {
                if(board[i][j] == '.')
                    continue;
                if(!(board[i][j] >= '1' && board[i][j] <= '9'))
                    return false;
                for(int k = j + 1; k < board[i].size(); ++k)
                {
                    if(board[i][j] == board[i][k])
                        return false;
                }
                for(int k = i + 1; k < board.size(); ++k)
                {
                    if(board[k][j] == board[i][j])
                        return false;
                }
                for(int m = i + 1; m < (i/3 + 1) * 3; ++m)
                {
                    for(int n = (j/3)*3; n < (j/3 + 1) * 3; ++n)
                    {
                        if(board[m][n] == board[i][j])
                            return false;
                    }
                }
            }
        }
        return true;
    }
};
