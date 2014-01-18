class Solution {
public:
    int maxArea(vector<int> &height) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int beg = 0;
        int end = height.size() - 1;
        int max = 0;
        while(beg < end)
        {
            int tmp = min(height[beg], height[end]) * (end - beg);
            if(tmp > max) max = tmp;
            if(height[beg] > height[end])
            {
                int k = end - 1;
                while(k > beg)
                {
                    if(height[k] > height[end])
                        break;
                    else --k;
                }
                end = k;
            }
            else
            {
                int k = beg + 1;
                while(k < end)
                {
                    if(height[k] > height[beg])
                        break;
                    else ++k;
                }
                beg = k;
            }
        }
        return max;
    }
};
