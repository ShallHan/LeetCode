class Solution {
public:
    string longestPalindrome(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(s.size() == 0) return "";
        string res = s.substr(0, 1);
        for(int i = 1; i < s.size(); ++i)
        {
            //odd
            if(i + 1 < s.size())
            {
                for(int beg = i - 1, end = i + 1; beg >= 0 && end < s.size(); --beg, ++end)
                {
                    if(s[beg] != s[end])
                        break;
                    else
                    {
                        if(end - beg + 1 > res.size())
                            res = s.substr(beg, end - beg + 1);
                    }
                }
            }
            //even
            for(int beg = i - 1, end = i; beg >= 0 && end < s.size(); --beg, ++end)
            {
                if(s[beg] != s[end])
                    break;
                else
                {
                    if(end - beg + 1 > res.size())
                        res = s.substr(beg, end - beg + 1);
                }
            }
        }
        return res;
    }
};
