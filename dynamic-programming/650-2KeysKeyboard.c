int minPrime(int n) {
    for (int i=2;i<n/2;i++) {
        if (n%i==0) {
            return i;
        }
    }
    return 1;
}

int minSteps(int n) {
    if (n==0||n==1) {
        return 0;
    }
    int memo[n+1];
    memo[0]=0;
    memo[1]=0;
    memo[2]=2;
    for (int i=3;i<=n;i++) {
        if (i&0x1==0) {
            memo[i]=memo[i/2]+2;
        } else {
            int p = minPrime(i);
            if (p!=1) {
                memo[i]=memo[i/p]+p;
            } else {
                memo[i]=i;
            }
        }
    }
    return memo[n];
}
