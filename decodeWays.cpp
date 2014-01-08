class Solution {
public:
    int numDecodings(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(s.size() == 0) return 0;
        if(s[0] == '0') return 0;
        for(int i = 1; i < s.size(); ++i)
        {
            if(!(s[i] >= '0' && s[i] <= '9'))
                return 0;
            if(s[i] == '0' && s[i-1] != '1' && s[i-1] != '2')
                return 0;
        }
        if(s.size() == 1) return 1;
        vector<int> vec(s.size() + 1, 0);
        vec[s.size()] = 1;
        if(s[s.size() - 1] != '0') 
            vec[s.size() - 1] = 1;
        for(int i = s.size() - 2; i >= 0; --i)
        {
            if(s[i] != '0') 
                vec[i] = vec[i + 1];
            if(s[i] == '1'||(s[i] == '2' && s[i+1] <= '6'))
                vec[i] += vec[i + 2];
        }
        return vec[0];
    }
};
