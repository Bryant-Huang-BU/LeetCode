class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0 || prices.size() == 1) {
            return 0;
        }
        int high = prices[0], total = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > high) {
                total += (prices[i] - high);
                high = prices[i];
                //cout << "ADDED AT: " << i << " ";
                //cout << "total " << total << " high " << high << endl;
            }
            else if (prices[i] < high) {
                //cout << "CHANGED BUY SET FROM: " << high << " TO: " << prices[i] << endl;
                high = prices[i];
            }
        }
        return total;
    }
};
