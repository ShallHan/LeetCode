class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n <= 0) return 1;
        int i = 0;
        while(i < n)
        {
            if(A[i] > n || A[i] < 1)
            {
                ++i;
                continue;
            }
            int val = A[i];
            if(A[val - 1] == val)
            {
                ++i;
                continue;
            }
            int tmp = A[val - 1];
            A[val - 1] = val;
            A[i] = tmp;
        }
        i = 1;
        for(; i <= n; ++i)
        {
            if(A[i - 1] != i)
                return i;
        }
        return i;
    }
};
