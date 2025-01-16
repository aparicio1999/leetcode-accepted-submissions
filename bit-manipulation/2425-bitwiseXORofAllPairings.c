int xorAllNums(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int res=0;
    if (nums1Size%2==0) {
        if (nums2Size%2==0) {
            return 0;
        } else {
            for (int j=0;j<nums1Size;j++) {
                res=res^nums1[j];
            }
        }
    } else {
        if (nums2Size%2==0) {
            for (int j=0;j<nums2Size;j++) {
                res=res^nums2[j];
            }
        } else {
            for (int j=0;j<nums2Size;j++) {
                res=res^nums2[j];
            }
            for (int j=0;j<nums1Size;j++) {
                res=res^nums1[j];
            }
        }
    }
    return res;
}
