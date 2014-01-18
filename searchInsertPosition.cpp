class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(A == 0 || n == 0)
            return 0;
        int i = 0, j = n - 1;
        while(i <= j)
        {
            int mid = i + (j - i) /2;
            if(A[mid] > target)
                j = mid - 1;
            else if(A[mid] < target)
                i = mid + 1;
            else
                j = mid - 1;
        }
        return j+1;
    }
};
