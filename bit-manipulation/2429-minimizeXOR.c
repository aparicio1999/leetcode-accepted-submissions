int minimizeXor(int num1, int num2) {
    int a2=num2;
    int no1=0;
    while (a2!=0) {
        if (a2&1) {
            no1++;
        }
        a2=a2>>1;
    }
    printf("%d",no1);
    int a1=num1;
    int res=0;
    int m=0x40000000;
    while (m!=0&&no1>0) {
        if (a1 & m) {
            res=res|m;
            no1--;
        }
        m=m>>1;
    }
    m=1;
    while (no1>0&&m!=0) {
        if (!(res&m)) {
            res=res|m;
            no1--;
        }
        m=m<<1;
    }
    return res;
}
