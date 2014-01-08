class Solution {
public:
    int minDistance(string word1, string word2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > vec;
        vec.resize(word1.size() + 1);
        for(int i = 0; i <= word1.size(); ++i)
            vec[i].resize(word2.size() + 1);
        for(int i = 0; i <= word1.size(); ++i)
            vec[i][0] = i;
        for(int j = 0; j <= word2.size(); ++j)
            vec[0][j] = j;
        for(int i = 1; i <= word1.size(); ++i)
        {
            for(int j = 1; j <= word2.size(); ++j)
            {
                if(word1[i-1] == word2[j-1])
                    vec[i][j] = min(min(vec[i-1][j], vec[i][j-1]) + 1, vec[i-1][j-1]);
                else
                    vec[i][j] = min(min(vec[i-1][j], vec[i][j-1]) + 1, vec[i-1][j-1] + 1);
            }
        }
        return vec[word1.size()][word2.size()];
    }
};
