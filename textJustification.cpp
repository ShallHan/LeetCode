class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<string> res;
        if(words.size() == 0)
            return res;
        int beg = 0;
        while(beg < words.size())
        {
            int end = beg, len = words[beg].size();
            while(end + 1 < words.size() && len + words[end + 1].size() + 1 <= L)
            {
                end++;
                len += words[end].size() + 1;
            }
            int cnt = end - beg + 1;
            if(cnt == 1)
            {
                string str = words[beg];
                for(int i = 0; i < L - len; ++i)
                    str.push_back(' ');
                res.push_back(str);
            }
            else if(end == words.size() - 1)
            {
                string str;
                for(int i = beg; i <= end; ++i)
                {
                    if(i != beg)
                        str.push_back(' ');
                    str.append(words[i]);
                }
                for(int i = 0; i < L - len; ++i)
                    str.push_back(' ');
                res.push_back(str);
            }
            else
            {
                int interval = (L - len)/(cnt - 1);
                int remain = (L - len)%(cnt - 1);
                string str;
                for(int i = beg; i <= end; ++i)
                {
                    if(i != beg)
                        str.push_back(' ');
                    str.append(words[i]);
                    if(i != end)
                        for(int j = 0; j < interval; ++j)
                            str.push_back(' ');
                    if(i - beg < remain)
                        str.push_back(' ');
                }
                res.push_back(str);
            }
            beg = end + 1;
        }
        return res;
    }
};
