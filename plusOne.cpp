class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> ret(digits.size());
        if(digits.size() == 0) return ret;
        int flag = 0;
        ret[digits.size() - 1] = (digits[digits.size() - 1] + 1)%10;
        flag = (digits[digits.size() - 1] + 1)/10;
        for(int i = digits.size() - 2; i >= 0; --i)
        {
            int tmp = digits[i];
            ret[i] = (tmp + flag)%10;
            flag = (tmp + flag)/10;
        }
        if(flag)
            ret.insert(ret.begin(), flag);
        return ret;
    }
};
