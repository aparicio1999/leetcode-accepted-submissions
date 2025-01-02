int max(int a, int b, int c) {
    int m = a;
    m = b>m?b:m;
    m = c>m?c:m;
    return m;
}

int maxProfit(int k, int* prices, int pricesSize) {
    if (pricesSize>1&&k>=1) {
        int memo[pricesSize][k];
        int min=prices[0];
        for (int i=0;i<pricesSize;i++) {
            for (int j=0;j<k;j++) {
                if (j>=i) {
                    memo[i][j] = 0;
                } else if (j==0){
                    memo[i][j] = memo[i-1][j]>prices[i]-min ? memo[i-1][j] : prices[i]-min;
                    if (prices[i]<min) {
                        min=prices[i];
                    }
                } else if (j==i-1) {
                    int m = memo[i][j-1];
                    int p = prices[i]-prices[0];
                    memo[i][j]= m>p?m:p;
                } else {
                    int opt=0;
                    for (int h=1;h<i;h++) {
                        int aux=prices[i]-prices[h]+memo[h-1][j-1];
                        opt = aux>opt?aux:opt;
                    }
                    memo[i][j] = max(memo[i][j-1],memo[i-1][j],opt);
                }
            }
        }
        return memo[pricesSize-1][k-1];
    }
    return 0;
}