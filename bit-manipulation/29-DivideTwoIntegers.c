int divide(int dividend, int divisor) {
    
    if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
    }
    if (dividend == INT_MIN && divisor == 1) {
        return INT_MIN;
    }
    if (divisor==2) {
        return dividend>>1;
    }
    if (divisor == 1) {
        return dividend;
    }

    long long n=dividend, div=divisor;
    n=n>0?n:-n;
    div=div>0?div:-div;

    if (n<div) {
        return 0;
    }

    int negative=(dividend^divisor)&0x80000000;

    long long q=0,r=n>>32;
    for (int i=1;i<=32;i++) {
        q=q<<1;
        if (div<=r) {
            r=((r-div)<<1)|((n>>(32-i))&1);
            q=q|1;
        } else {
            r=(r<<1)|((n>>(32-i))&1);
        }
    }
    q=(q<<1);
    if (div<=r) {
        q=q|1;
    }
    if (negative) {
        q=-q;
    }
    return q;
}
