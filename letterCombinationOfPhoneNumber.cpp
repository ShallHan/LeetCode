class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res(1);
        if(digits.size() == 0)
            return res;
        for(int i = 0; i < digits.size(); ++i)
        {
            vector<string> vec = res;
            int index = digits[i] - '0';
            if(!(index >= 2 && index <= 9)) 
                continue;
            res.clear();
            for(vector<string>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
            {
                for(int j = 0; j < mapping[index].size(); ++j)
                {
                    string str = *iter;
                    str.push_back(mapping[index][j]);
                    res.push_back(str);
                }
            }
        }
        return res;
    }
};
