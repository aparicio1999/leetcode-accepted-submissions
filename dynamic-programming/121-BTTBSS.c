int maxProfit(int* prices, int pricesSize) {
    if (pricesSize>0) {
        int memo[pricesSize];
        memo[0] = 0;
        int min = prices[0];
        for (int i=1;i<pricesSize;i++) {
            memo[i] = memo[i-1]>prices[i]-min ? memo[i-1] : prices[i]-min;
            if (prices[i]<min) {
                min=prices[i];
            }
        }
        return memo[pricesSize-1];
    }
    return 0;
}