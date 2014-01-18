#include <algorithm>

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector< pair<int, size_t> > vec;
        for(size_t i = 0; i < numbers.size(); ++i)
        {
            vec.push_back(make_pair(numbers[i], i+1));
        }
        sort(vec.begin(), vec.end());
        size_t p1 = 0, p2 = vec.size() - 1;
        while(p1 < p2)
        {
            if(vec[p1].first + vec[p2].first == target)
            {
                vector<int> res;
                if(vec[p1].second < vec[p2].second)
                {
                    res.push_back(vec[p1].second);
                    res.push_back(vec[p2].second);
                }
                else
                {
                    res.push_back(vec[p2].second);
                    res.push_back(vec[p1].second);
                }
                return res;
            }
            else if(vec[p1].first + vec[p2].first < target)
                ++p1;
            else
                --p2;
        }
    }
};
