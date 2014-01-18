class Solution {
public:
    void combinationSum(set<vector<int> > &res, vector<int> &cur_res, vector<int> &candidates, int idx, int target)
    {
	if(target == 0)
	{
	    res.insert(cur_res);
	    return;
	}
	if(target < 0)
	    return;
	if(idx >= candidates.size())
	    return;
	combinationSum(res, cur_res, candidates, idx + 1, target);
	cur_res.push_back(candidates[idx]);
	combinationSum(res, cur_res, candidates, idx + 1, target - candidates[idx]);
	cur_res.erase(cur_res.end()-1);
    }
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
	if(candidates.size() == 0)
	{
        vector<vector<int> >  res;
	    return res;
	}
	sort(candidates.begin(), candidates.end());
	vector<int> cur_res;
	set<vector<int> > set_res;
	combinationSum(set_res, cur_res, candidates, 0, target);
	vector<vector<int> > res(set_res.begin(), set_res.end());
	return res;
    }
};
