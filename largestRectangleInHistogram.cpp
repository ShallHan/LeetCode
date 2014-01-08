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
};
