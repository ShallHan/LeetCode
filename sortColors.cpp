class Solution {
public:
    void sortColors(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> state;
        state.resize(3);
        for(int i = 0; i < n; ++i)
        {
            if(A[i] <= 2)
                state[A[i]] ++;
        }
        int idx = 0;
        for(int i = 0; i < 3; ++i)
        {
            for(int j = 0; j < state[i]; ++j)
                A[idx++] = i;
        }
    }
};
