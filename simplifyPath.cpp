class Solution {
public:
    string simplifyPath(string path) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<string> state;
        if(path.size() == 0 || path[0] != '/')
            return "";
        int beg = 1;
        while(beg < path.size())
        {
            int end = path.find("/", beg);
            if(end == string::npos)
                end = path.size();
            if(end - beg == 0)
            {
                beg = end + 1;
                continue;
            }
            if(end - beg == 1 && path[beg] == '.')
            {
                beg = end + 1;
                continue;
            }
            if(end - beg == 2 && path.substr(beg, 2) == "..")
            {
                if(state.size() > 0)
                    state.pop_back();
                beg = end + 1;
                continue;
            }
            else
            {
                string tmp = path.substr(beg, end - beg);
                state.push_back(tmp);
                beg = end + 1;
            }
        }
        string res;
        if(state.size() == 0)
            return "/";
        for(int i = 0; i < state.size(); ++i)
            res.append("/" + state[i]);
        return res;
    }
};
