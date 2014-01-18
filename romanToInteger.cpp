class Solution {
public:
    int getRomanValue(char c) {
        switch(c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
    int romanToInt(string s) {
        if(s.size() == 0)
            return 0;
        int prev = getRomanValue(s[0]);
        int ret = prev;
        for(int i = 1; i < s.size(); ++i)
        {
            int cur = getRomanValue(s[i]);
            if(cur == prev)
                ret += cur;
            else if(cur < prev) {
                ret += cur;
                prev = cur;
            } else {
                ret -= 2*prev;
                ret += cur;
                prev = cur;
            }
        }
        return ret;
    }
};
