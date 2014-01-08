class Solution {
public:
    bool search(int A[], int n, int target) {
        int left = 0, right = n - 1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(A[mid] == target)
                return true;
            if(A[mid] > A[left])
            {
                if(target >= A[left] && target < A[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else if(A[left] > A[mid])
            {
                if(target > A[mid] && target <= A[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else
                ++left;
        }
        return false;
    }
};
