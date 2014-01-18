class Solution {
public:
    int reverse(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int flag = 1;
        if(x < 0)
        {
            flag = -1;
            x = -x;
        }
        int ret = 0;
        while(x > 0)
        {
            int tmp = x % 10;
            ret = ret * 10 + tmp;
            x /= 10;
        }
        return ret * flag;
    }
};
