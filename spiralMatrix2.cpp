class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix;
        if(n == 0) return matrix;
        matrix.resize(n);
        for(int i = 0; i < n; ++i)
            matrix[i].resize(n);

        int number = 1;
        int round = n/2;
        for(int rnd = 0; rnd < round; ++rnd)
        {
            int m = matrix[0].size() - 1 - 2 * rnd;
            int n = matrix.size() - 1 - 2*rnd;
            for(int i = 0; i < m; ++i)
                matrix[rnd][rnd + i] = number++;
            for(int i = 0; i < n; ++i)
                matrix[rnd + i][matrix[0].size() - 1 - rnd] = number++;
            for(int i = 0; i < m; ++i)
                matrix[matrix.size() - 1 - rnd][matrix[0].size() - 1 - rnd - i] = number++;
            for(int i = 0; i < n; ++i)
                matrix[matrix.size() - 1 - rnd - i][rnd] = number++;
        }
        if(matrix.size() >= matrix[0].size() && matrix[0].size()%2)
        {
            for(int i = round; i < matrix.size() - round; ++i)
                matrix[i][matrix[0].size()/2] = number++;
        }
        else if(matrix[0].size() > matrix.size() && matrix.size()%2)
        {
            for(int j = round; j < matrix[0].size() - round; ++j)
                matrix[matrix.size()/2][j] = number++;
        }
        return matrix;
    }
};
