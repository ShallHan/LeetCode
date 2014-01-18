class Solution {
public:
    double findKth(int *A, int m, int *B, int n, int k) {
        if(n < m)
            return findKth(B, n, A, m, k);
        if(m == 0)
            return B[k - 1];
        if(k == 1)
            return min(A[0], B[0]);
        int i = min(k/2, m);
        int j = k - i;
        int a = A[i - 1];
        int b = B[j - 1];
        if(a == b)
            return a;
        if(a > b)
            return findKth(A, m, B + j, n - j, k - j);
        else
            return findKth(A + i, m - i, B, n, k - i);
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if(m == n && m == 0)
            return 0;
        int len = m + n;
        if(len % 2)
            return findKth(A, m, B, n, len/2 + 1);
        else
	{
            return (findKth(A, m, B, n, len/2) + findKth(A, m, B, n, len/2 + 1)) / 2;
	}
    }
};
