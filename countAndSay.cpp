class Solution {
public:
    string countAndSay(string &str)
    {
        int idx = 0;
        string ret;
        while(idx < str.size())
        {
            int cnt = 0;
            int i = idx;
            for(; i < str.size(); ++i)
            {
                if(str[i] != str[idx])
                    break;
                ++cnt;
            }
            ret.push_back(cnt+'0');
            ret.push_back(str[idx]);
            idx = i;
        }
        return ret;
    }
    string countAndSay(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        string str = "1";
        int idx = 1;
        while(idx < n)
        {
            str = countAndSay(str);
            ++idx;
        }
        return str;
    }
};
