class Solution {
public:
    bool judge(vector<int> &state)
    {
        bool b = true;
        for(int i = 0; i < state.size(); ++i)
        {
            for(int j = i + 1; j < state.size(); ++j)
            {
                if(i - j == state[i] - state[j] || i - j == state[j] - state[i])
                    return false;
            }
        }
        return true;
    }
    void solveNQueens(vector<vector<string> > &res, vector<int> &state, int idx)
    {
        if(idx == state.size())
        {
            if(judge(state))
            {
                vector<string> cur_res;
                for(int i = 0; i < state.size(); ++i)
                {
                    string str = "";
                    for(int j = 0; j < state.size(); ++j)
                    {
                        if(state[i] == j)
                            str.push_back('Q');
                        else
                            str.push_back('.');
                    }
                    cur_res.push_back(str);
                }
                res.push_back(cur_res);
            }
            return;
        }
        for(int i = idx; i < state.size(); ++i)
        {
            int tmp = state[idx];
            state[idx] = state[i];
            state[i] = tmp;
            
            solveNQueens(res, state, idx + 1);
            
            tmp = state[idx];
            state[idx] = state[i];
            state[i] = tmp;
        }
    }
    
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > res;
        vector<int> state;
        if(n <= 0)
            return res;
        state.resize(n);
        for(int i = 0; i < n; ++i)
        {
            state[i] = i;
        }
        solveNQueens(res, state, 0);
        return res;
    }
};
