class Solution {
public:
    vector<int> grayCode(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> vec;
        vec.push_back(0);
        for(int i = 0; i < n; ++i) {
            int high = 1<<i;
            for(int j = vec.size() - 1; j >= 0; --j)
            {
                vec.push_back(high + vec[j]);
            }
        }
        return vec;
    }
};
