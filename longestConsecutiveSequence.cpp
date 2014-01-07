class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        unordered_set<int> s;
        for(int i = 0; i < num.size(); ++i)
        {
            s.insert(num[i]);
        }
        int longest = 0;
        for(int i = 0; i < num.size(); ++i)
        {
            if(s.count(num[i]))
            {
                int len = 1, n = num[i];
                s.erase(n);
                for(int j = n - 1; s.count(j);--j )
                {
                    ++len;
                    s.erase(j);
                }
                for(int j = n + 1; s.count(j); ++j)
                {
                    ++len;
                    s.erase(j);
                }
                if(len > longest)
                    longest = len;
            }
        }
        return longest;
    }
};
