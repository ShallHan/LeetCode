class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        if(num.size() == 0)
        {
            vector<vector<int> > res;
            return res;
        }
        set<vector<int> > set_res;
        sort(num.begin(), num.end());
        for(int i = 0; i < num.size(); ++i)
        {
            int target = 0 - num[i];
            int beg = 0, end = num.size() - 1;
            while(beg < end)
            {
                if(beg == i)
                {
                    ++beg;
                    continue;
                }
                if(end == i)
                {
                    --end;
                    continue;
                }
                if(num[beg] + num[end] == target)
                {
                    vector<int> tmp;
                    tmp.push_back(num[i]);
                    tmp.push_back(num[beg]);
                    tmp.push_back(num[end]);
                    sort(tmp.begin(), tmp.end());
                    set_res.insert(tmp);
                    ++beg;
                    --end;
                    continue;
                }
                if(num[beg] + num[end] > target)
                    --end;
                else
                    ++beg;
            }
        }
        vector<vector<int> > res(set_res.begin(), set_res.end());
        return res;
    }
};
