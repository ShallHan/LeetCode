class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int *pi = A, *pj = A;
	while(pj < (A+n) )
	{
		if(*pj != elem)
		{
			*pi = *pj;
			++pi;
		}
		++pj;
	}
	return pi - A;
    }
};
