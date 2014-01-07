ass Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stk;
        if(tokens.size() == 0)
            return 0;
        for(int i = 0; i < tokens.size(); ++i)
        {
            if(tokens[i].size() == 1 && (tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' || tokens[i][0] == '/'))
            {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                if(tokens[i][0] == '+')
                    stk.push(a + b);
                else if(tokens[i][0] == '-')
                    stk.push(a - b);
                else if(tokens[i][0] == '*')
                    stk.push(a * b);
                else if(tokens[i][0] == '/')
                    stk.push(a / b);
            }
            else
            {
                stk.push(atoi(tokens[i].c_str()));
            }
        }
        return stk.top();
    }
};
