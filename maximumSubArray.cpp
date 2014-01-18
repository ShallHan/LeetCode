class Solution {
public:
    int maxSubArray(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(n <= 0) return 0;
        int largest = A[0];
        int sum = A[0];
        for(int i = 1; i < n; ++i)
        {
            int tmp = A[i];
            if(sum > 0)
                tmp += sum;
            sum = tmp;
            if(tmp > largest)
                largest = tmp;
                
        }
        return largest;
    }
};
