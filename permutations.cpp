class Solution {
public:
    void permute(vector<vector<int> > &res, vector<int> &cur_res, vector<int> &num, int idx)
    {
        if(idx == num.size())
        {
            res.push_back(cur_res);
            return;
        }
        for(int i = idx; i < num.size(); ++i)
        {
            int tmp = num[i];
            num[i] = num[idx];
            num[idx] = tmp;
            
            cur_res.push_back(num[idx]);
            
            permute(res, cur_res, num, idx + 1);
            
            cur_res.pop_back();
            
            tmp = num[i];
            num[i] = num[idx];
            num[idx] = tmp;
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        if(num.size() == 0)
            return res;
        vector<int> cur_res;
        permute(res, cur_res, num, 0);
        return res;
    }
};
