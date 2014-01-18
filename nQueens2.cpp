class Solution {
public:
    bool judge(vector<int> &state, int idx)
    {
        bool b = true;
        for(int i = 0; i < idx; ++i)
        {
            if(i - idx == state[i] - state[idx] || i - idx == state[idx] - state[i])
                return false;
        }
        return true;
    }
    void solveNQueens(int &cnt, vector<int> &state, int idx)
    {
        if(idx == state.size())
        {
            ++cnt;
            return;
        }
        for(int i = idx; i < state.size(); ++i)
        {
            int tmp = state[idx];
            state[idx] = state[i];
            state[i] = tmp;
	        if(judge(state, idx))
            	solveNQueens(cnt, state, idx + 1);

            tmp = state[idx];
            state[idx] = state[i];
            state[i] = tmp;
        }
    }

    int totalNQueens(int n) {
        vector<int> state;
        if(n <= 0)
            return 0;
        state.resize(n);
        for(int i = 0; i < n; ++i)
        {
            state[i] = i;
        }
        int cnt = 0;
        solveNQueens(cnt, state, 0);
        return cnt;
    }
};
