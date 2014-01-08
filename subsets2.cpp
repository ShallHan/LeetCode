class Solution {
public:
    void subsetsWithDup(vector<int> &input, int index, vector<int> &vec, set<vector<int> > &res)
    {
        if(index == input.size()) 
        {
            res.insert(vec);
            return;
        }
        subsetsWithDup(input, index + 1, vec, res);
        vec.push_back(input[index]);
        subsetsWithDup(input, index + 1, vec, res);
        vec.erase(vec.end() - 1);
    }
    vector<vector<int> > subsetsWithDup(vector<int> &s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(s.size() == 0)
        {
            vector<vector<int> > vec;
            return vec;
        }
        sort(s.begin(), s.end());
        set<vector<int> > set_res;
        vector<int> vec;
        subsetsWithDup(s, 0, vec, set_res);
        vector<vector<int> > vec_res(set_res.begin(), set_res.end());
        return vec_res;
    }
};
