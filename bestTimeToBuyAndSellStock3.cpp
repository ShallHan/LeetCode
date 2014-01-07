class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(prices.size() == 0) return 0;
        vector<int> left, right;
        left.resize(prices.size() + 1);
        right.resize(prices.size() + 1);
        int smallest = prices[0];
        int profit = 0;
        for(int i = 1; i < prices.size(); ++i)
        {
            if(prices[i] - smallest > profit)
                profit = prices[i] - smallest;
            if(prices[i] < smallest)
                smallest = prices[i];
            left[i + 1] = profit;
        }
        int largest = prices[prices.size() - 1];
        profit = 0;
        for(int i = prices.size() - 2; i >= 0; --i)
        {
            if(largest - prices[i] > profit)
                profit = largest - prices[i];
            if(prices[i] > largest)
                largest = prices[i];
            right[i] = profit;
        }
        profit = 0;
        for(int i = 0; i <= prices.size(); ++i)
            if(left[i] + right[i] > profit)
                profit = left[i] + right[i];
        return profit;
    }
};
