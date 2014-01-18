class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        map<string, vector<string> > m;
        vector<string> ret;
        for(vector<string>::const_iterator iter = strs.begin(); iter != strs.end(); ++iter)
        {
            string tmp = *iter;
            sort(tmp.begin(), tmp.end());
            m[tmp].push_back(*iter);
        }
        for(map<string, vector<string> >::const_iterator iter = m.begin(); iter != m.end(); ++iter)
        {
            if(iter->second.size() > 1)
            {
                for(vector<string>::const_iterator it = iter->second.begin(); it != iter->second.end(); ++it)
                    ret.push_back(*it);
            }
        }
        return ret;
    }
};
