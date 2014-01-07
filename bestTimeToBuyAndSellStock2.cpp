class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(prices.size() == 0) return 0;
        int smallest = prices[0];
        int largest = prices[0];
        int profit = 0;
        for(int i =1; i < prices.size(); ++i)
        {
            if(prices[i] >= largest) 
                largest = prices[i];
            else
            {
                profit += largest - smallest;
                largest = prices[i];
                smallest = prices[i];
            }
        }
        profit += largest - smallest;
        return profit;
    }
};
