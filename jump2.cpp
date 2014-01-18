class Solution {
public:
    int jump(int A[], int n) {
        if(A == 0 || n == 0)
            return -1;
        int step = 0;
        int beg = 0, end = 0;
        while(true)
        {
            if(end >= n - 1)
                return step;
            int tmp_beg = beg, tmp_end = end;
            for(int i = beg; i <= end; ++i)
            {
                if(i + 1 > tmp_beg)
                    tmp_beg = i + 1;
                if(A[i] + i > tmp_end)
                    tmp_end = A[i] + i;
            }
            if(tmp_end == end)
                return -1;
            beg = tmp_beg;
            end = tmp_end;
            ++step;
        }
        return -1;
    }
};
