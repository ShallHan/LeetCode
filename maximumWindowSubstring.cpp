class Solution {
public:
	bool judge(map<char, int> &m, int &beg, int &end)
	{
		bool flag = true;
		for(map<char, int>::iterator iter = m.begin(); iter != m.end(); ++iter)
		{
			if(iter->second == -1)
				return false;
			if(iter->second > end)
				end = iter->second;
			if(iter->second < beg)
				beg = iter->second;
		}
		return true;
	}
	string minWindow(string s, string t) {
		if(t.size() == 0 || s.size() == 0)
			return "";
		int beg = -1, end = -1;
		int min = s.size() + 1;
		map<char, int> m;
		for(int i = 0; i < t.size(); ++i)
		{
			m[t[i]] = -1;
		}
		for(int i = 0; i < s.size(); ++i)
		{
			int tmp_beg = s.size(), tmp_end = 0;
			bool b = judge(m, tmp_beg, tmp_end);
			if(b && tmp_end - tmp_beg + 1 < min)
			{
				end = tmp_end;
				beg = tmp_beg;
				min = tmp_end - tmp_beg + 1;
			}
			if(m.count(s[i]))
			{
				int tmp = m[s[i]];
				m[s[i]] = i;
				for(map<char, int>::iterator iter = m.begin(); iter != m.end(); ++iter)
				{
					if(iter->second < tmp)
						iter->second = -1;
				}
			}
		}
		int tmp_beg = s.size(), tmp_end = 0;
		bool b = judge(m, tmp_beg, tmp_end);
		if(b && tmp_end - tmp_beg + 1 < min)
		{
			end = tmp_end;
			beg = tmp_beg;
			min = tmp_end - tmp_beg + 1;
		}
		if(beg == -1 && end == -1)
			return "";
		else
			return s.substr(beg, end - beg + 1);
	}
};
