class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(matrix.size() == 0) return;
        bool firstRow = false, firstColumn = false;
        if(matrix[0][0] == 0)
        {
            firstColumn = true;
            firstRow = true;
            matrix[0][0] = 1;
        }
        for(int i = 0; i < matrix.size(); ++i)
            if(matrix[i][0] == 0)
            {
                firstColumn = true;
                break;
            }
        for(int j = 0; j < matrix[0].size(); ++j)
            if(matrix[0][j] == 0)
            {
                firstRow = true;
                break;
            }
        for(int i = 1; i < matrix.size(); ++i)
            for(int j = 1; j < matrix[i].size(); ++j)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        for(int i = 0; i < matrix.size(); ++i)
        {
            if(matrix[i][0] == 0)
            {
                for(int j = 0; j < matrix[i].size(); ++j)
                    matrix[i][j] = 0;
            }
        }
        for(int j = 0; j < matrix[0].size(); ++j)
        {
            if(matrix[0][j] == 0)
            {
                for(int i = 0; i < matrix.size(); ++i)
                    matrix[i][j] = 0;
            }
        }
        if(firstRow)
            for(int j = 0; j < matrix[0].size(); ++j)
                matrix[0][j] = 0;
        if(firstColumn)
            for(int i = 0; i < matrix.size(); ++i)
                matrix[i][0] = 0;
    }
};
