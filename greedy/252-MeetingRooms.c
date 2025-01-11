void sort(int** array, int size) {
    for (int i=0;i<size-1;i++) {
        for (int j=0;j<size-i-1;j++) {
            if (array[j][1]>array[j+1][1]) {
                int* temp = array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
}

bool canAttendMeetings(int** intervals, int intervalsSize, int* intervalsColSize) {
    sort(intervals, intervalsSize);
    for (int i=0;i<intervalsSize-1;i++) {
        if (intervals[i][1]>intervals[i+1][0]) {return false;}
    }
    return true;
}
