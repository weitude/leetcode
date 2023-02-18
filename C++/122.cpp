class Solution {
	public:
		int maxProfit(vector<int>& prices) {
			int profit = 0;
			for (int i = 1; i < prices.size(); i++)
			{
				int gap = prices[i] - prices[i - 1];
				if (gap > 0)
					profit += gap;
			}
			return profit;
		}
};

