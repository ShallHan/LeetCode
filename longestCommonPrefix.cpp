class Solution {
public:
    string common(const string &str1, const string &str2)
    {
        string ret;
        for(int i = 0; i < min(str1.size(), str2.size()); ++i)
        {
            if(str1[i]==str2[i])
                ret.push_back(str1[i]);
            else
                break;
        }
        return ret;
    }
    string longestCommonPrefix(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string ret;
        if(strs.size() == 0) return ret;
        ret = strs[0];
        for(int i = 1; i < strs.size(); ++i)
        {
            ret = common(ret, strs[i]);
            if(ret.size() == 0)
                return ret;
        }
        return ret;
    }
};
