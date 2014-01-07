#include <map>
#include <vector>
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(s.size()==0) return false;
        bool *b = new bool[s.size() + 1]();
        b[0] = true;
        
        map<char, vector<string> > map_dict;
        for(unordered_set<string>::const_iterator iter = dict.begin(); iter != dict.end(); ++iter)
        {
            if(iter->size() == 0) continue;
            map_dict[(*iter)[0]].push_back(*iter);
        }
        
        for(int i = 0; i < s.size() && !b[s.size()]; ++i)
        {
            if(b[i]==false)
                continue;
            char start = s[i];
            if(!map_dict.count(start)) continue;
            const vector<string> &vec(map_dict[start]);
            for(vector<string>::const_iterator iter = vec.begin(); iter != vec.end() && !b[s.size()]; ++iter)
            {
                int len = iter->size();
                if(i + len > s.size()) continue;
                string tmp = s.substr(i, len);
                if(tmp == *iter)
                    b[i + len] = true;
            }
        }
        bool res = b[s.size()];
        delete [] b;
        return res;
    }
};
