class Solution {
public:
    int trap(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n <= 2) return 0;
        int left = A[0], right = A[n - 1];
        int pl = 1, pr = n - 2;
        int res = 0;
        while(pl <= pr)
        {
            if(left < right)
            {
                if(A[pl] >= left)
                {
                    left = A[pl];
                }
                else
                {
                    res += left - A[pl];
                }
                pl++;
            }
            else
            {
                if(A[pr] >= right)
                {
                    right = A[pr];
                }
                else
                {
                    res += right - A[pr];
                }
                pr--;
            }
        }
        return res;
    }
};
