class Data
{
public:
	int left;
	int right;
	string str;
	Data():left(0), right(0){}
	Data(int l, int r, const string &s):left(l), right(r), str(s){}
};

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		if(n == 0) {vector<string> v; return v;}
		vector<Data> *pcur = new vector<Data>;
		vector<Data> *pold = new vector<Data>;
		pold->push_back(Data(1,0,"("));
		int len = 1;
		while(len < n*2)
		{
			for(size_t i = 0; i < pold->size(); ++i)
			{
				Data &d = (*pold)[i];
				if(d.left < n)
				{
					Data tmp(d.left+1, d.right, d.str+"(");
					pcur->push_back(tmp);
				}
				if(d.left > d.right)
				{
					Data tmp(d.left, d.right+1, d.str+")");
					pcur->push_back(tmp);
				}
			}
			++len;
			vector<Data> *tmp = pold;
			pold = pcur;
			pcur = tmp;
			pcur->clear();
		}
		vector<string> vec;
		for(size_t i = 0; i < pold->size(); ++i)
		{
			vec.push_back((*pold)[i].str);
		}
		delete pcur;
		delete pold;
		return vec;
	}
};
