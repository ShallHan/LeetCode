class Solution {
public:
    bool isMatch(const char *s, const char *p) 
    {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(*s == 0)
        {
            while(*p == '*')
                p++;
            return *p == 0;
        }
        const char *pres = s, *prep = p;
        bool star = false;
        while(*s)
        {
            if(*s == *p || *p == '?')
            {
                ++s;
                ++p;
            }
            else if(*p == '*')
            {
                star = true;
                while(*p == '*')
                    ++p;
                if(*p == 0) return true;
                pres = s;
                prep = p;
            }
            else if(star)
            {
                p = prep;
                s = ++pres;
            }
            else
                return false;
        }
        while(*p == '*')
            ++p;
        return *p == 0;
    }
};
