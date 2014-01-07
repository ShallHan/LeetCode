class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(triangle.size() == 1) return triangle[0][0];
        vector<int> vec(triangle.size());
        vec[0] = triangle[0][0];
        for(int i = 1; i < triangle.size(); ++i)
        {
            vector<int> vec_tmp(triangle.size());
            vec_tmp[0] = vec[0] + triangle[i][0];
            for(int j = 1; j < triangle[i].size() - 1; ++j)
            {
                vec_tmp[j] = min(vec[j-1],vec[j]) + triangle[i][j];
            }
            vec_tmp[triangle[i].size() - 1] = vec[triangle[i].size() - 2] + triangle[i][triangle[i].size() - 1];
            vec = vec_tmp;
        }
        int min = INT_MAX;
        for(int i = 0; i < triangle.size(); ++i)
            if(vec[i] < min) min = vec[i];
        return min;
    }
};
