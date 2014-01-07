#include <vector>
#include <map>

class Solution {
public:
    void wordBreak(string &s, map<char, vector<string> > &map_dict, vector<string> &res, vector<string> &cur_res, int idx, vector<bool> &state)
    {
        if(idx == s.size())
        {
            string str = cur_res[0];
            for(int i = 1; i < cur_res.size(); ++i)
                str.append(" " + cur_res[i]);
            res.push_back(str);
            return;
        }
        if(!map_dict.count(s[idx]))
            return;
        vector<string> &dict(map_dict[s[idx]]);
        for(int i = 0; i < dict.size(); ++i)
        {
            if(idx + dict[i].size() <= s.size() && state[idx + dict[i].size()])
            {
                string tmp = s.substr(idx, dict[i].size());
                if(tmp == dict[i])
                {
                    int beforeChange = res.size();
                    cur_res.push_back(tmp);
                    wordBreak(s, map_dict, res, cur_res, idx + tmp.size(), state);
                    cur_res.pop_back();
                    if(res.size() == beforeChange)
                        state[idx + tmp.size()]  = false;
                }
            }
        }
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<string> res;
        if(s.size() == 0) return res;

        map<char, vector<string> > map_dict;
        for(unordered_set<string>::const_iterator iter = dict.begin(); iter != dict.end(); ++iter)
        {
            if(iter->size() == 0) continue;
            map_dict[(*iter)[0]].push_back(*iter);
        }
        vector<bool> state(s.size() + 1, true);
        vector<string> cur_res;
        wordBreak(s, map_dict, res, cur_res, 0, state);
        return res;
    }
};
