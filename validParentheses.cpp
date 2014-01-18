class Solution {
public:
    bool isValid(string s) {
        stack<int> s1, s2, s3;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(')
                s1.push(i);
            else if(s[i] == '[')
                s2.push(i);
            else if(s[i] == '{')
                s3.push(i);
            else if(s[i] == ')')
            {
                if(s1.size() == 0) 
                    return false;
                if((!s2.empty() && s2.top() > s1.top()) || (!s3.empty() && s3.top() > s1.top()))
                    return false;
                s1.pop();
            }
            else if(s[i] == ']')
            {
                if(s2.size() == 0)
                    return false;
                if((!s1.empty() && s1.top() > s2.top()) || (!s3.empty() && s3.top() > s2.top()))
                    return false;
                s2.pop();
            }
            else if(s[i] == '}')
            {
                if(s3.size() == 0)
                    return false;
                if((!s1.empty() && s1.top() > s3.top()) || (!s2.empty() && s2.top() > s3.top()))
                    return false;
                s3.pop();
            }
        }
        if(s1.empty()&&s2.empty()&&s3.empty())
            return true;
        return false;
    }
};
