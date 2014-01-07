class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(prices.size() == 0) return 0;
        int profit = 0;
        int lowest = prices[0];
        for(int i = 1; i < prices.size(); ++i)
        {
            if(prices[i] - lowest > profit)
                profit = prices[i] - lowest;
            if(prices[i] < lowest)
                lowest = prices[i];
        }
        return profit;
    }
};
