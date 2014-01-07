class Solution {
public:
    int numTrees(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n <= 2) return n;
        vector<int> vec(n+1, -1);
        vec[0] = 1;
        vec[1] = 1;
        vec[2] = 2;
        for(int i = 3; i <= n; ++i)
        {
            int sum = 0;
            for(int j = 0; j < i; ++j)
            {
                sum += vec[j] * vec[i - j - 1];
            }
            vec[i] = sum;
        }
        return vec[n];
    }
};
