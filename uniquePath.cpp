class Solution {
public:
    int uniquePaths(int m, int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(m <= 0 || n <= 0) return 0;
        vector<int> prev(n, 1);
        for(int i = 1; i < m; ++i)
        {
            vector<int> tmp(n, 0);
            tmp[0] = 1;
            for(int j = 1; j < n; ++j)
            {
                tmp[j] = prev[j] + tmp[j-1];
            }
            prev = tmp;
        }
        return prev[n-1];
    }
};
