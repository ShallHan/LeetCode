class Solution {
public:

	bool isPalindrome(string s) {
		// IMPORTANT: Please reset any member data you declared, as
		// the same Solution instance will be reused for each test case.
		int beg = 0, end = s.size() - 1;
		while(beg < end)
		{
			if(!(s[beg] >= 'a' && s[beg] <= 'z' || s[beg] >= 'A' && s[beg] <= 'Z' || s[beg] >= '0' && s[beg] <= '9'))
			{
				++beg;
				continue;
			}
			if(!(s[end] >= 'a' && s[end] <= 'z' || s[end] >= 'A' && s[end] <= 'Z' || s[end] >= '0' && s[end] <= '9'))
			{
				--end;
				continue;
			}
			if(tolower(s[beg]) != tolower(s[end]))
				return false;
			++beg;
			--end;
		}
		return true;
	}
};
