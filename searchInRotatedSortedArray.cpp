class Solution {
public:
    int search(int A[], int n, int target) {
        int left = 0, right = n - 1;
	while(left <= right)
	{
		int middle = (left + right) / (double)2;
		if(A[middle] == target)
			return middle;
		if(A[middle] >= A[left])
		{
			if(target >= A[left] && target < A[middle])
				right = middle - 1;
			else
				left = middle + 1;
		}
		else
		{
			if(target > A[middle] && target <= A[right])
				left = middle + 1;
			else
				right = middle - 1;
		}
	}
	return -1;
    }
};

