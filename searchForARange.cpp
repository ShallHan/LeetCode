class Solution {
public:
    int search(int A[], int n, int target, bool left)
    {
        int i = 0, j = n - 1;
    	while(i <= j)
    	{
    	    int mid = i + (j - i) / 2;
    	    if(left)
    	    {
    	        if(A[mid] < target)
    		        i = mid + 1;
    		    else if(A[mid] > target)
    		        j = mid - 1;
    		    else
    		        j = mid - 1;
    	    }
    	    else
    	    {
    	        if(A[mid] < target)
    		        i = mid + 1;
    		    else if(A[mid] > target)
    		        j = mid - 1;
    		    else
    		        i = mid + 1;
    	    }
    	}
    	if(left && j+1<n && A[j+1]==target)
    	    return j+1;
    	else if(!left && i-1 >= 0 && A[i-1] == target)
    	    return i-1;
    	return -1;
    }
    
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res;
    	if(A == 0 || n == 0)
        {
    	    res.push_back(-1);
    	    res.push_back(-1);
    	    return res;
    	}
    	int left = search(A, n, target, true);
    	int right = search(A, n, target, false);
    	res.push_back(left);
    	res.push_back(right);
    	return res;
    }
};
