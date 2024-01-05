//finished in 2024.1.5
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int have_stock = -prices[0];
        int no_stock = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int a = max(no_stock, have_stock + prices[i] - fee);
            int b = max(have_stock, no_stock - prices[i]);
            have_stock = b;
            no_stock = a;
        }
        return max(have_stock, no_stock);
    }
};