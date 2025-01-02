int maxProfit(int* prices, int pricesSize) {
    if (pricesSize>1) {
        int memo[pricesSize];
        memo[0] = 0;
        int min = prices[0];
        memo[1] = prices[1]-prices[0]>0?prices[1]-prices[0]:0;
        for (int i=1;i<pricesSize;i++) {
            memo[i] = memo[i-1]>prices[i]-min ? memo[i-1] : prices[i]-min;
            if (prices[i]<min) {
                min=prices[i];
            }
        }
        int reverse[pricesSize];
        reverse[pricesSize-1] = 0;
        min = prices[pricesSize-1];
        int max = prices[pricesSize-1];
        for (int i=pricesSize-2;i>=0;i--) {
            if (prices[i]<max) {
                reverse[i] = max-prices[i]>reverse[i+1]?max-prices[i]:reverse[i+1];
            } else {
                max=prices[i];
                reverse[i]=reverse[i+1];
            }
        }
        int opt = memo[pricesSize-1];
        for (int i=1;i<pricesSize;i++) {
            opt = memo[i-1]+reverse[i]>opt ? memo[i-1]+reverse[i]:opt;
        }
        return opt;
    }
    return 0;
}