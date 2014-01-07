class Solution {
public:
    int minCut(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(s.size() == 0)
            return 0;
        vector<vector<bool> > state;
        state.resize(s.size());
        for(int i = 0; i < state.size(); ++i)
        {
            state[i].resize(state.size());
            state[i][i] = true;
        }
        for(int range = 1; range < state.size(); ++range)
        {
            for(int i = 0; i + range < state.size(); ++i)
            {
                if(range >= 2)
                {
                    if(s[i] == s[i + range] && state[i + 1][i + range - 1])
                        state[i][i + range] = true;
                    else
                        state[i][i + range] = false;
                }
                else
                {
                    if(s[i] == s[i + range])
                        state[i][i + range] = true;
                    else
                        state[i][i + range] = false;
                }
            }
        }
        vector<int> f(s.size(), INT_MAX);
        for(int i = 0; i < s.size(); ++i)
        {
            if(state[0][i])
            {
                f[i] = 1;
                continue;
            }
            for(int j = 1; j <= i; ++j)
            {
                if(state[j][i] && f[j - 1] + 1 < f[i])
                    f[i] = f[j - 1] + 1;
            }
        }
        return f[f.size() - 1] - 1;
    }
};
