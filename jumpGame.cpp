class Solution {
public:
    bool canJump(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n <= 0) return true;
        if(n == 1) return true;
        if(A[0] <= 0) return false;
        int beg = 1, end = A[0];
        while(true)
        {
            if(end >= n - 1)
                return true;
            int small = beg, large = end;
            for(int i = beg; i <= end; ++i)
            {
                if(A[i] <= 0)
                    continue;
                if(i + 1 > small)
                    small = i + 1;
                if(i + A[i] > large)
                    large = i + A[i];
            }
            if(large == end)
                return false;
            beg = small;
            end = large;
        }
        return false;
    }
};
