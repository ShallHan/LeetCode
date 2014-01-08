class Solution {
public:
    void subsets(vector<int> &s, int k, vector<int> &vec ,vector<vector<int> > &res)
    {
        if(k == s.size())
        {
            res.push_back(vec);
            return;
        }
        subsets(s, k + 1, vec, res);
        vec.push_back(s[k]);
        subsets(s, k + 1, vec, res);
        vec.pop_back();
    }
    vector<vector<int> > subsets(vector<int> &s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        sort(s.begin(), s.end());
        vector<vector<int> > res;
        if(s.size() == 0) return res;
        vector<int> vec;
        subsets(s, 0, vec, res);
        return res;
    }
};
