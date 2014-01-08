class Solution {
public:
    bool exist(vector<vector<char> > &board, int i, int j, const string &word, int k)
    {
        if(board[i][j] == word[k])
        {
            if(k == word.size() - 1)
                return true;
            char tmp = board[i][j];
            board[i][j] = '0';
            bool ret = false;
            if(i > 0)
                ret = exist(board, i - 1, j, word, k + 1);
            if(i < board.size() - 1 && !ret)
                ret = exist(board, i + 1, j, word, k + 1);
            if(j > 0 && !ret)
                ret = exist(board, i, j - 1, word, k + 1);
            if(j < board[i].size() - 1 && !ret)
                ret = exist(board, i, j + 1, word, k + 1);
            board[i][j] = tmp;
            return ret;
        }
        else 
            return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        for(int i = 0; i < board.size(); ++i)
            for(int j = 0; j < board[i].size(); ++j)
            {
                if(exist(board, i, j, word, 0))
                    return true;
            }
        return false;
    }
};
