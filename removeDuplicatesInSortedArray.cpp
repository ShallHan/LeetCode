class Solution
{
public:
    int removeDuplicates(int A[], int n)
    {
    	if(n <= 1) return n;
        int *pi = A, *pj = A + 1;
	for(int j = 1; j < n; ++j)
	{
		if(*pj == *pi)
			++pj;
		else
		{
			++pi;
			*pi = *pj++;
		}
	}
	return pi - A + 1;
    }
};
