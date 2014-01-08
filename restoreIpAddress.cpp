class Solution {
public:
    void restoreIpAddresses(vector<string> &vec, vector<string> &cur_vec, const string &s, int idx)
    {
        if(cur_vec.size() == 4 && idx == s.size())
        {
            string str;
            str.append(cur_vec[0]);
            for(int i = 1; i < 4; ++i)
                str.append("." + cur_vec[i]);
            vec.push_back(str);
            return;
        }
        if(s.size() - idx > (4 - cur_vec.size()) * 3 || s.size() - idx < 4 - cur_vec.size())
            return;
        if(s[idx] == '0')
        {
            cur_vec.push_back("0");
            restoreIpAddresses(vec, cur_vec, s, idx + 1);
            cur_vec.pop_back();
            return;
        }
        for(int len = 1; len <= 3 && idx + len <= s.size(); ++len)
        {
            int tmp = atoi(s.substr(idx, len).c_str());
            if(tmp >= 0 && tmp <= 255)
            {
                cur_vec.push_back(s.substr(idx, len));
                restoreIpAddresses(vec, cur_vec, s, idx + len);
                cur_vec.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<string> vec;
        vector<string> cur_vec;
        restoreIpAddresses(vec, cur_vec, s, 0);
        return vec;
    }
};
