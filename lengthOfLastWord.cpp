class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = 0;
        const char *p = s;
        while(*p)
        {
            ++p;
            ++len;
        }
        int i = len - 1;
        for(; i >= 0; --i)
        {
            if(s[i] != ' ')
                break;
        }
        int end = i;
        for(; i >=0; --i)
        {
            if(s[i] == ' ')
                break;
        }
        int begin = i;
        return end - begin;
    }
};
