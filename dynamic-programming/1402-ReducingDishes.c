void descendSort(int* array, int size) {
    for (int i=0;i<size-1;i++) {
        for (int j=0;j<size-i-1;j++) {
            if (array[j]<array[j+1]) {
                int temp = array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
}

int maxSatisfaction(int* satisfaction, int satisfactionSize) {
    if (satisfactionSize==0)
        return 0;
    int aux[satisfactionSize];
    for (int i=0;i<satisfactionSize;i++) {
        aux[i] = satisfaction[i];
    }
    descendSort(aux,satisfactionSize);
    if (aux[0]<=0)
        return 0;
    int LikeTime=aux[0];
    int prevLikeTime=aux[0];
    for (int i=2;i<=satisfactionSize&&LikeTime-prevLikeTime>=0;i++) {
        int auxSum = 0;
        int auxTimes = i;
        for (int j=0;j<i;j++) {
            auxSum+=aux[j]*auxTimes;
            auxTimes--;
        }
        prevLikeTime=LikeTime;
        LikeTime=auxSum;
    }
    return prevLikeTime>LikeTime?prevLikeTime:LikeTime;
}
