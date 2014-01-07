class Solution {
public:
    int numDistinct(string s, string t) {
        if(s.size()==0 || t.size() ==0) return 0;
        vector<vector<int> > vec(t.size() + 1);
        for(int i = 0; i <= t.size(); ++i)
        {
            vec[i].resize(s.size() + 1);
            vec[i][0] = 0;
        }
        for(int j = 0; j <= s.size(); ++j)
            vec[0][j] = 1;
        for(int i = 0; i < t.size(); ++i)
        {
            for(int j = 0; j < s.size(); ++j)
            {
                if(t[i] == s[j])
                    vec[i+1][j+1] = vec[i][j] + vec[i+1][j];
                else
                    vec[i+1][j+1] = vec[i+1][j];
            }
        }
        return vec[t.size()][s.size()];
    }
};
