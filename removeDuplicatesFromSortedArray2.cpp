class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n <= 2)
            return n;
        int slow = 0, fast = 1;
        int cnt = 1;
        for(; fast < n; ++fast) {
            if(A[fast] != A[slow])
            {
                A[++slow] = A[fast];
                cnt = 1;
            }
            else if(A[fast] == A[slow] && cnt == 1)
            {
                A[++slow] = A[fast];
                cnt += 1;
            }
        }
        return slow + 1;
    }
};
