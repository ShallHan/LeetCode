class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        bool chars[26] = {false};
        int longest = 0;
        int pbegin = 0, pend = 0;
        int tmp_len = 0;
        while(pend < s.size())
        {
            if(chars[s[pend]-'a'] == false)
            {
                chars[s[pend]-'a'] = true;
                ++tmp_len;
                if(tmp_len > longest) longest = tmp_len;
                ++pend;
            }
            else
            {
                for(;pbegin < pend; ++pbegin)
                {
                    --tmp_len;
                    chars[s[pbegin]-'a'] = false;
                    if(s[pbegin] == s[pend])
                    {
                        pbegin++;
                        break;
                    }
                }
            }
        }
        return longest;
    }
};
