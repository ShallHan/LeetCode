class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(matrix.size() <= 1)
            return;
        int len = matrix.size();
        int round = (len + 1)/2;
        for(int rnd = 0; rnd < round; ++rnd)
        {
            for(int i = 0; i < len - rnd * 2 - 1; ++i) 
            {
                int tmp = matrix[rnd][rnd + i];
                matrix[rnd][rnd + i] = matrix[len - rnd - i - 1][rnd];
                matrix[len - rnd - i - 1][rnd] = matrix[len - rnd - 1][len - rnd - i - 1];
                matrix[len - rnd - 1][len - rnd - i - 1] = matrix[rnd + i][len - rnd - 1];
                matrix[rnd + i][len - rnd - 1] = tmp;
            }
        }
    }
};
