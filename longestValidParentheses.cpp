class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() == 0)
            return 0;
        int longest = 0;
        stack<int> stk;
        vector<int> state(s.size());
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(')
                stk.push(i);
            else
            {
                if(stk.empty())
                    continue;
                int idx = stk.top();
                stk.pop();
                state[i] = i - idx + 1;
                if(idx > 0)
                    state[i] += state[idx - 1];
                if(state[i] > longest)
                    longest = state[i];
            }
        }
        return longest;
    }
};
