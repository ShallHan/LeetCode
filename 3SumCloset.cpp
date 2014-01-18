class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        sort(num.begin(), num.end());
        int ret = 0, dist = INT_MAX;
        for(int i = 0; i < num.size(); ++i)
        {
            int tmp_target = target - num[i];
            int l = i + 1, r = num.size() - 1;
            while(l < r)
            {
                if(num[l] + num[r] == tmp_target)
                {
                    ret = target;
                    dist = 0;
                    break;
                }
                if(num[l] + num[r] > tmp_target)
                {
                    if(num[l] + num[r] - tmp_target < dist)
                    {
                        ret = num[l] + num[r] + num[i];
                        dist = num[l] + num[r] - tmp_target;
                    }
                    --r;
                }
                else
                {
                    if(tmp_target - num[l] - num[r] < dist)
                    {
                        ret = num[l] + num[r] + num[i];
                        dist = tmp_target - num[l] - num[r];
                    }
                    ++l;
                }
            }
        }
        return ret;
    }
};
