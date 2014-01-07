class Solution {
public:
    int singleNumber(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> res;
        res.resize(sizeof(int) * 8);
        for(int i = 0; i < n; ++i)
        {
            int j = 0;
            unsigned int number = A[i];
            while(number)
            {
                int tmp = number & 1;
                res[j++] += tmp;
                number = number >> 1;
            }
        }
        for(int i = 0; i < res.size(); ++i)
            res[i] = res[i] % 3;
        int ret = 0;
        for(vector<int>::reverse_iterator iter = res.rbegin(); iter != res.rend(); ++iter)
        {
            ret = (ret << 1) + *iter;
        }
        return ret;
    }
};
