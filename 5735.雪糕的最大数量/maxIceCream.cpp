class Solution {
public:
    //贪心
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int res = 0;
        for (auto x : costs) {
            if (coins < x) {
                return res;
            }
            coins -= x;
            res++;
        }
        return res;
    }
};