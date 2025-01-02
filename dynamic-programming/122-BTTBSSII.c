int maxProfit(int* prices, int pricesSize) {
    if (pricesSize>0) {
        int memo[pricesSize];
        memo[0] = 0;
        for (int i=1;i<pricesSize;i++) {
            int m = memo[i-1];
            int p = prices[i] - prices[0];
            int opt=m>p?m:p;
            for (int j=1;j<i;j++) {
                if (prices[i]-prices[j]+memo[j-1]>opt) {
                    opt = prices[i]-prices[j]+memo[j-1];
                }
            }
            memo[i] = opt;
        }
        return memo[pricesSize-1];
    }
    return 0;
}