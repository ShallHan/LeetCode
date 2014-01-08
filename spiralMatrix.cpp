class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if(matrix.size() == 0)
            return res;
        int round = min(matrix.size(), matrix[1].size())/2;
        for(int rnd = 0; rnd < round; ++rnd)
        {
            int m = matrix[0].size() - 1 - 2 * rnd;
            int n = matrix.size() - 1 - 2*rnd;
            for(int i = 0; i < m; ++i)
                res.push_back(matrix[rnd][rnd + i]);
            for(int i = 0; i < n; ++i)
                res.push_back(matrix[rnd + i][matrix[0].size() - 1 - rnd]);
            for(int i = 0; i < m; ++i)
                res.push_back(matrix[matrix.size() - 1 - rnd][matrix[0].size() - 1 - rnd - i]);
            for(int i = 0; i < n; ++i)
                res.push_back(matrix[matrix.size() - 1 - rnd - i][rnd]);
        }
        if(matrix.size() >= matrix[0].size() && matrix[0].size()%2)
        {
            for(int i = round; i < matrix.size() - round; ++i)
                res.push_back(matrix[i][matrix[0].size()/2]);
        }
        else if(matrix[0].size() > matrix.size() && matrix.size()%2)
        {
            for(int j = round; j < matrix[0].size() - round; ++j)
                res.push_back(matrix[matrix.size()/2][j]);
        }
        return res;
    }
};
