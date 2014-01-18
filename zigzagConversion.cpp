class Solution {
public:
    string convert(string s, int nRows) {
        // Note: The Solution object is instantiated only once and is reused by each test case.    
        string ret;
        if(s.size() ==0 || nRows == 1)
            return s;
        for(int i = 1; i <= nRows; ++i)
        {
            if(i == 1 || i == nRows)
            {
                int step = 2*nRows - 2;
                for(int j = i - 1; j < s.size(); j += step)
                    ret.push_back(s[j]);
            }
            else
            {
                int step1 = 2*nRows -2 - 2*(i - 1);
                int step2 = 2*i - 2;
                bool flag = true;
                int step = step1;
                for(int j = i - 1; j < s.size(); )
                {
                    if(flag == true )
                    {
                        flag = false;
                        ret.push_back(s[j]);
                        j += step;
                        step = step2;
                    }
                    else
                    {
                        flag = true;
                        ret.push_back(s[j]);
                        j += step;
                        step = step1;
                    }
                }
            }
        }
        return ret;
    }
};
