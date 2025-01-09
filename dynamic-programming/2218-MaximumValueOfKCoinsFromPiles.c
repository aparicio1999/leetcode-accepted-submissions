int maxValueOfCoins(int** piles, int pilesSize, int* pilesColSize, int k) {
    int memo[pilesSize+1][k+1];
    for (int i = 0; i <= pilesSize; i++) {
        for (int j = 0; j <= k; j++) {
            memo[i][j] = 0;
        }
    }

    
    for (int i=1;i<=pilesSize;i++) {
        for (int j=0;j<=k;j++) {
            
            int min = pilesColSize[i-1]>j?j:pilesColSize[i-1];
            int ithPileSum=0;
            memo[i][j] = memo[i - 1][j];
            
            for (int c=1;c<=min&&c<=pilesColSize[i-1];c++) {
                ithPileSum+=piles[i-1][c-1];
                memo[i][j] = ithPileSum+memo[i-1][j-c]>memo[i][j]?ithPileSum+memo[i-1][j-c]:memo[i][j];
            }
        }
    }

    return memo[pilesSize][k];
}
