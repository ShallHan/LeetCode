class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > res;
        vector<vector<int> > vec(1);
        for(int i = 1; i <= n; ++i)
        {
            vector<vector<int> > tmp(vec);
            vec.clear();
            for(int j = 0; j < tmp.size(); ++j)
            {
                vec.push_back(tmp[j]);
                vector<int> v = tmp[j];
                v.push_back(i);
                if(v.size() == k)
                    res.push_back(v);
                else
                    vec.push_back(v);
            }
        }
        return res;
    }
};
