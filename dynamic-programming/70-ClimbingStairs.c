int climbStairs(int n) {
    if (n==1) {
        return 1;
    } else if (n==2) {
        return 2;
    }

    int memo[n];
    memo[0]=1;
    memo[1]=2;

    for (int i=2;i<n;i++) {
        memo[i] = memo[i-1] + memo[i-2];
    }

    return memo[n-1];
}