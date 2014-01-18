class Solution {
public:
    void swapNum(vector<int> &num, int i, int j)
    {
        while(i < j)
        {
            int tmp = num[i];
            num[i] = num[j];
            num[j] = tmp;
            i++;
            j--;
        }
    }
    void nextPermutation(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(num.size() <= 1) return;
        bool has_next = false;
        int pos = num.size() - 2;
        while(pos >= 0)
        {
            if(num[pos] < num[pos + 1])
            {
                has_next = true;
                break;
            }
            else
                pos--;
        }
        if(has_next)
        {
            int i = num.size() - 1;
            for(; i > pos && num[i] <= num[pos]; --i) {}
            int tmp = num[i];
            num[i] = num[pos];
            num[pos] = tmp;
            swapNum(num, pos+1, num.size() - 1);
        }
        if(!has_next)
        {
            swapNum(num, 0, num.size() - 1);
        }
    }
};
