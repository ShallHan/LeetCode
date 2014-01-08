class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(height.size() == 0) return 0;
        stack<int> stk;
        vector<int> h = height;
        h.push_back(0);
        int largest = 0;
        stk.push(0);
        for(int i = 1; i < h.size(); ++i)
        {
            int top = stk.top();
            while(h[i] < h[top])
            {
                stk.pop();
                int beg = 0;
                if(!stk.empty())
                    beg = stk.top() + 1;
                else
                    beg = 0;
                int tmp = h[top] * (i - beg);
                if(tmp > largest) largest = tmp;
                if(stk.empty())
                    break;
                top = stk.top();
            }
            if(stk.empty() || h[i] >= h[top])
                stk.push(i);
        }
        return largest;
    }
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int largest = 0;
        if(matrix.size() == 0) return 0;
        vector<int> vec(matrix[0].size());
        for(int i = 0; i < matrix.size(); ++i)
        {
            for(int j = 0; j < matrix[i].size(); ++j)
            {
                if(matrix[i][j] == '0')
                    vec[j] = 0;
                else
                    vec[j] += 1;
            }
            int tmp = largestRectangleArea(vec);
            if(tmp > largest) largest = tmp;
        }
        return largest;
    }
};
