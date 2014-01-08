class Solution {
public:
    void matrixMutiply(int n, int &a11, int &a12, int &a21, int &a22)
    {
        if(n == 1)
        {
            a11 = 1;
            a12 = 1;
            a21 = 1;
            a22 = 0;
            return;
        }
        int t11, t12, t21, t22;
        matrixMutiply(n/2, t11, t12, t21, t22);
        a11 = t11 * t11 + t12 * t21;
        a12 = t11 * t12 + t12 * t22;
        a21 = t21 * t11 + t22 * t21;
        a22 = t21 * t12 + t22 * t22;
        if(n%2 == 1)
        {
            t11 = a11 + a12;
            t12 = a11;
            t21 = a21 + a22;
            t22 = a21;
            a11 = t11;
            a12 = t12;
            a21 = t21;
            a22 = t22;
        }
    }
    int climbStairs(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n<=1) return 1;
        int a11, a12, a21, a22;
        matrixMutiply(n-1, a11, a12, a21, a22);
        return a11 + a12;
    }
};
