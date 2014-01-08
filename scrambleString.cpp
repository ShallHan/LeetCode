class Solution {
public:
	bool isScramble(string s1, string s2) {
		if(s1.size() != s2.size())
			return false;
		map<char, int> m;
		for(int i = 0; i < s1.size(); ++i)
			m[s1[i]]++;
		for(int i = 0; i < s2.size(); ++i)
			m[s2[i]]--;
		for(map<char, int>::const_iterator iter = m.begin(); iter != m.end(); ++iter)
		{
			if(iter->second != 0)
				return false;
		}
		if(s1.size() <= 1 && s2.size() <= 1)
			return true;
		bool ret = false;
		for(int i = 1; i < s1.size(); ++i)
		{
			ret = (isScramble(s1.substr(0, i), s2.substr(0,i)) && isScramble(s1.substr(i, s1.size() - i), s2.substr(i, s2.size() - i))) ||
				(isScramble(s1.substr(0, i), s2.substr(s2.size() - i, i)) && isScramble(s1.substr(i, s1.size() - i), s2.substr(0, s2.size() - i)));
			if(ret)
				break;
		}
		return ret;

	}
};
