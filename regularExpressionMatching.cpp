class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(p == 0)
        {
            if(s == 0) return true;
            else return false;
        }
        bool ret = isSectionMatch(s, p);
        return ret;
    }
    bool isSectionMatch(const char *s, const char *p) {
        const char *p1 = p;
        const char *p2 = s;
        while(*p1&&*p2)
        {
            if(*(p1 + 1) != '*')
            {
                if(*p1 == '.') { p1++; p2++;}
                else if(*p1++ != *p2++) {return false;}
            }
            else
            {
                if(*p1 != '.')
                {
                    char tmp = *p1;
                    if(isSectionMatch(p2, p1+2)) return true;
                    while(*p2++ == tmp)
                    {
                        if(isSectionMatch(p2, p1+2)) return true;
                    }
                    return false;
                }
                else
                {
                    if(isSectionMatch(p2, p1+2)) return true;
                    while(*p2++)
                    {
                        if(isSectionMatch(p2, p1+2)) return true;
                    }
                    return false;
                }
            }
        }
    	while(*p1)
    	{
    		if(*(p1+1)=='*')
    			p1+=2;
    		else
    		{
    			return false;
    		}
    	}
        if(!*p1 && !*p2)
        {
            return true;
        }
        return false;
    }
};
