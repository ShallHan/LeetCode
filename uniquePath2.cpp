class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0) return 0;
        vector<int> prev(obstacleGrid[0].size(), 0);
        for(int i = 0; i < obstacleGrid.size(); ++i)
        {
            vector<int> tmp(obstacleGrid[i].size(), 0);
            if(i == 0) {
                if(obstacleGrid[0][0] == 0)
                    tmp[0] = 1;
            }
            else if(obstacleGrid[i][0] == 0)
                tmp[0] = prev[0];
            for(int j = 1; j < obstacleGrid[i].size(); ++j)
            {
                if(obstacleGrid[i][j] == 1)
                    tmp[j] = 0;
                else
                    tmp[j] = tmp[j-1] + prev[j];
            }
            prev = tmp;
        }
        return prev[obstacleGrid[0].size() - 1];
    }
};
