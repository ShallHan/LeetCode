class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.    
        if((s1.size() + s2.size()) != s3.size()) return false;
        if(s3.size() == 0) return true;
        vector<vector<bool> > vec(s1.size() + 1);
        for(int i = 0; i <= s1.size(); ++i)
        {
            vec[i].resize(s2.size() + 1);
            for(int j = 0; j <= s2.size(); ++j)
                vec[i][j] = false;
        }
        vec[0][0] = true;
        for(int i = 0; i <= s1.size(); ++i)
        {
            for(int j = 0; j <= s2.size(); ++j)
            {
                if(i == 0 && j == 0) continue;
                if(i > 0 && s3[i + j - 1] == s1[i - 1] && !vec[i][j])
                    vec[i][j] = vec[i - 1][j];
                if(j > 0 && s3[i + j - 1] == s2[j - 1] && !vec[i][j])
                    vec[i][j] = vec[i][j - 1];
            }
        }
        return vec[s1.size()][s2.size()];
    }
};
