class Solution {
public:
    bool isPalindrome(const string &s, int beg, int end)
    {
        while(beg < end)
        {
            if(s[beg] != s[end])
                return false;
            ++beg;
            --end;
        }
        return true;
    }
    void partition(const string &s, int idx, vector<string> &vec, vector<vector<string> > &res)
    {
        if(idx >= s.size())
        {
            res.push_back(vec);
            return;
        }
        for(int i = idx; i < s.size(); ++i)
        {
            if(isPalindrome(s, idx, i))
            {
                string tmp = s.substr(idx, i - idx + 1);
                vec.push_back(tmp);
                partition(s, i + 1, vec, res);
                vec.pop_back();
            }
        }
    }
    vector<vector<string> > partition(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<string> > res;
        vector<string> vec;
        if(s.size() == 0)
            return res;
        partition(s, 0, vec, res);
        return res;
    }
};
