void sort(int* min, int* mid, int* max,int a,int b,int c){
    if (*min > *mid) { *mid = a; *min = b; }
        if (*mid > *max)
        {
            *max = *mid;
            *mid = c;
            if (*min > *mid)
            {
                *mid = *min;
                *min = c;
            }
        }
}

int maximumScore(int a, int b, int c) {
        
    int min = a;
    int mid = b;
    int max = c;

    sort(&min,&mid,&max,a,b,c);
        
    if (max<=0) {
        return 0;
    }

    int points =0;
    while ((max>0&&min>0)||(max>0&&mid>0)||(min>0&&mid>0)) {
        mid--;
        max--;
        points++;
        sort(&min,&mid,&max,min,mid,max);
    }
    return points;
}
