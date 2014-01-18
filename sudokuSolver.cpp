class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board, int m, int n) {
        for(int i = 0; i < board.size(); ++i)
            if(i != m && board[i][n] == board[m][n])
                return false;
        for(int j = 0; j < board[m].size(); ++j)
            if(j != n && board[m][j] == board[m][n])
                return false;
        for(int i = 3 * (m/3); i < 3 + 3 * (m/3); ++i)
            for(int j = 3*(n/3); j < 3 + 3*(n/3); ++j)
            {
                if(i == m && j == n)
                    continue;
                if(board[m][n] == board[i][j])
                    return false;
            }
        return true;
    }

    void solveSudoku(vector<vector<char> > &res, vector<vector<char> > &board, int i, int j)
    {
        if(i == board.size())
        {
            res = board;
            return;
        }
        if(board[i][j] == '.')
        {
            for(char c = '1'; c <= '9'; ++c)
            {
                board[i][j] = c;
                if(!isValidSudoku(board, i, j))
                    continue;
                if(j == board[i].size() - 1)
                    solveSudoku(res, board, i + 1, 0);
                else
                    solveSudoku(res, board, i, j + 1);
                if(res.size() != 0)
                    return;
            }
            board[i][j] = '.';
        }
        else
        {
            if(j == board[i].size() - 1)
                solveSudoku(res, board, i + 1, 0);
            else
                solveSudoku(res, board, i, j + 1);
            if(res.size() != 0)
                return;
        }
    }

    void solveSudoku(vector<vector<char> > &board)
    {
        vector<vector<char> > res;
        solveSudoku(res, board, 0, 0);
        board = res;
    }
};
