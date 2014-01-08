class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(grid.size() == 0) return 0;
        if(grid[0].size() == 0) return 0;
        vector<vector<int> > vec(grid.size());
        for(int i = 0; i < grid.size(); ++i)
            vec[i].resize(grid[i].size());
        vec[0][0] = grid[0][0];
        for(int i = 1; i < grid.size(); ++i)
        {
            vec[i][0] = vec[i-1][0] + grid[i][0];
        }
        for(int j = 1; j < grid[0].size(); ++j)
        {
            vec[0][j] = vec[0][j-1] + grid[0][j];
        }
        for(int i = 1; i < grid.size(); ++i)
        {
            for(int j = 1; j < grid[i].size(); ++j)
            {
                vec[i][j] = min(vec[i-1][j], vec[i][j-1]) + grid[i][j];
            }
        }
        return vec[grid.size()-1][grid[0].size()-1];
    }
};
