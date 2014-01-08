class Solution {
public:
    string addBinary(string a, string b) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(a.size() < b.size())
        {
            string tmp = a;
            a = b;
            b = tmp;
        }
        if(b.size() == 0) return a;
        string ret = a;
        int i = a.size() -1 , j = b.size() - 1, k = i;
        int flag = 0;
        for(; j>=0; i--, j--, k--)
        {
            int tmp = a[i] - '0' + b[j] - '0' + flag;
            ret[k] = tmp%2 + '0';
            flag = tmp/2;
        }
        for(; i>=0; i--, k--)
        {
            int tmp = a[i] - '0' + flag;
            ret[k] = tmp%2 + '0';
            flag = tmp/2;
        }
        if(flag)
            ret = ret.insert(0, 1, '0' + flag);
        return ret;
    }
};
