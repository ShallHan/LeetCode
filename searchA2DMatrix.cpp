class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(matrix.size() == 0) return 0;
        int i = matrix.size() - 1;
        int j = 0;
        while(true)
        {
            if(i < 0 || j > matrix[0].size() - 1)
                return false;
            if(matrix[i][j] == target) 
                return true;
            if(target > matrix[i][j])
                j++;
            else
                i--;
        }
        return false;
    }
};
