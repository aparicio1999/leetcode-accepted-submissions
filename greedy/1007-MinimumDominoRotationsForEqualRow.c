int minDominoRotations(int* tops, int topsSize, int* bottoms, int bottomsSize) {
    if (topsSize!=bottomsSize) {
        return -1;
    }
    int top[6], bottom[6], doubles[6];
    memset(top, 0, sizeof(top));
    memset(bottom, 0, sizeof(bottom));
    memset(doubles, 0, sizeof(doubles));
    for (int i=0;i<topsSize;i++) {
        if (tops[i]==bottoms[i]) {
            doubles[tops[i]-1]++;
        } else {
            top[tops[i]-1]++;
            bottom[bottoms[i]-1]++;
        }
    }
    int choose=topsSize;
    bool res=false;
    for (int i=0;i<6;i++) {
        if (bottom[i]+top[i]==topsSize-doubles[i]) {
            res=true;
            choose=bottom[i]<choose?bottom[i]:choose;
            choose=top[i]<choose?top[i]:choose;
        }
    }
    return res?choose:-1;
}
