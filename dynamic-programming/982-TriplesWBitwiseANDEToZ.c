int countTriplets(int* nums, int numsSize) {
    int total=0;
    for (int i=0;i<numsSize;i++) {
        if (!nums[i]) {
            total++;
        }
        for (int j=i+1;j<numsSize;j++) {
            if (!(nums[j]&nums[i])) {
                total+=6;
            }
            for (int k=j+1;k<numsSize;k++) {
                if (!(nums[i]&nums[j]&nums[k])) {
                    total+=6;
                }
            }
        }
    }
    return total;
}
