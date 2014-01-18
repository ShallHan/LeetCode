class Solution {
public:
    void combinationSum(vector<vector<int> > &res, vector<int> cur_res, vector<int> &candidates, int idx, int target)
    {
	if(target == 0)
	{
	    res.push_back(cur_res);
	    return;
	}
	if(target < 0)
	    return;
	if(idx >= candidates.size())
	    return;
	combinationSum(res, cur_res, candidates, idx + 1, target);
	int tmp_target = target;
	while(tmp_target > 0)
	{
	    cur_res.push_back(candidates[idx]);
	    tmp_target -= candidates[idx];
	    combinationSum(res, cur_res, candidates, idx + 1, tmp_target);
	}
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> >  res;
	if(candidates.size() == 0)
	    return res;
	sort(candidates.begin(), candidates.end());
	vector<int>::iterator it = unique(candidates.begin(), candidates.end());
	candidates.resize(it - candidates.begin());
	vector<int> cur_res;
	combinationSum(res, cur_res, candidates, 0, target);
	return res;
    }
};
