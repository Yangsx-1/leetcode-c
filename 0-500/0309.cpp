// finished in 2024.1.9
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;
        int no_stock = 0, cold = 0, have_stock = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            int no = max(no_stock, cold);
            int c = have_stock + prices[i];
            int have = max(no_stock - prices[i], have_stock);
            no_stock = no;
            cold = c;
            have_stock = have;
        }
        return max(no_stock, cold);
    }
};