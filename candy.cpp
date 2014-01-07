class Solution {
public:
    int candy(vector<int> &ratings) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(ratings.size() == 0) return 0;
        if(ratings.size() == 1) return 1;
        vector<int> state(ratings.size(), 1);
        for(int i = 1; i < ratings.size(); ++i)
        {
            if(ratings[i] > ratings[i-1]) 
                state[i] = state[i - 1] + 1;
        }
        for(int i = ratings.size() -2; i >= 0; --i)
        {
            if(ratings[i] > ratings[i+1])
            {
                int tmp = state[i + 1] + 1;
                if(state[i] < tmp)
                    state[i] = tmp;
            }
        }
        int ret = 0;
        for(int i = 0; i < state.size(); ++i)
            ret += state[i];
        return ret;
    }
};
