class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int *pa = A + m - 1;
        int *pb = B + n - 1;
        int *p = A + m + n - 1;
        while(pa >= A && pb >= B)
        {
            if(*pa > *pb)  
                *p-- = *pa--;
            else
                *p-- = *pb--;
        }
        while(pb >= B)
        {
            *p-- = *pb--;
        }
    }
};
