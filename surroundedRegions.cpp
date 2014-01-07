class Solution {
public:
    void DFS(vector< vector<char> > &board, int i, int j)
    {
        if(board[i][j] != 'O') return;
        board[i][j] = '#';
        if(i > 0) DFS(board, i - 1, j);
        if(i < (int)board.size() - 2) DFS(board, i + 1, j);
        if(j > 0) DFS(board, i, j - 1);
        if(j < (int)board[0].size() - 2) DFS(board, i, j + 1);
    }
    void solve(vector<vector<char>> &board) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(board.size() == 0) return;
        for(int j = 0; j < board[0].size(); ++j)
            DFS(board, 0, j);
        for(int j = 0; j < board[0].size(); ++j)
            DFS(board, board.size() - 1, j);
        for(int i = 1; i < board.size(); ++i)
            DFS(board, i, 0);
        for(int i = 1; i < board.size(); ++i)
            DFS(board, i, board[0].size() - 1);
        for(int i = 0; i < board.size(); ++i)
            for(int j = 0; j < board[0].size(); ++j)
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
        for(int i = 0; i < board.size(); ++i)
            for(int j = 0; j < board[0].size(); ++j)
                if(board[i][j] == '#')
                    board[i][j] = 'O';
    }
};
