class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > vec;
        if(num.size() < 4)
            return vec;
        sort(num.begin(), num.end());
        for(int i = 0; i < num.size(); ++i)
        {
            for(int j = i + 1; j < num.size(); ++j)
            {
                int tmp_target = target - num[i] - num[j];
                for(int a = j + 1, b = num.size() - 1; a < b; )
                {
                    if(num[a] + num[b] == tmp_target)
                    {
                        vec.push_back(vector<int>{num[i], num[j], num[a], num[b]});
                        while(a < num.size() - 1 && num[a + 1] == num[a])
                            ++a;
                        ++a;
                        while(b > j + 1 && num[b - 1] == num[b])
                            --b;
                        --b;
                    }
                    else if(num[a] + num[b] > tmp_target)
                        --b;
                    else
                        ++a;
                }
                while(j < num.size() - 1 && num[j + 1] == num[j])
                    ++j;
            }
            while(i < num.size() - 1 && num[i + 1] == num[i])
                ++i;
        }
        return vec;
    }
};
