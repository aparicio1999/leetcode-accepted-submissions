int maxArea(int* height, int heightSize) {
    int i=0, j=heightSize-1, maxArea=height[i]>height[j]?(j-i)*height[j]:(j-i)*height[i];
    while (i!=j) {
        if (height[i]>height[j]) {
            maxArea = maxArea>(j-i)*height[j]?maxArea:(j-i)*height[j];
            j--;
        } else {
            maxArea = maxArea>(j-i)*height[i]?maxArea:(j-i)*height[i];
            i++;
        }
    }
    return maxArea;
}
