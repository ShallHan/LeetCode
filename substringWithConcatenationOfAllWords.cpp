class Solution {
public:
    /*vector<int> findSubstring(string s, vector<string> &l) {
        vector<int> res;
        if(s.size() == 0 || l.size() == 0)     
            return res;
        int len = l[0].size();
        map<string, int> m;
        for(int i = 0; i < l.size(); ++i)
            m[l[i]]++;
        for(int i = 0; i + len * l.size() <= s.size(); ++i)
        {
            map<string, int> map_tmp = m;
            for(int j = i; j + len <= s.size(); j += len) 
            {
                string str = s.substr(j, len);
                if(map_tmp.count(str))
                {
                    map_tmp[str] --;
                    if(map_tmp[str] == 0)
                        map_tmp.erase(str);
                }
                else
                    break;
                if(map_tmp.size() == 0)
                {
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }*/
    vector<int> findSubstring(string s, vector<string> &l) {
        vector<int> res;
        if(s.size() == 0 || l.size() == 0)     
            return res;
        int len = l[0].size();
        map<string, int> m, map_tmp;
        for(int i = 0; i < l.size(); ++i)
            m[l[i]]++;
        for(int i = 0; i + len * l.size() <= s.size(); ++i)
        {
            map_tmp.clear();
            bool flag = true;
            int j = 0;
            for(; j < l.size(); ++j)
            {
                string str = s.substr(i + j * len, len);
                if(!m.count(str))
                {
                    break;
                }
                map_tmp[str]++;
                if(map_tmp[str]>m[str])
                {
                    break;
                }
            }
            if(j == l.size())
                res.push_back(i);
        }
        return res;
    }
};
