#include<string.h>

char* longestPalindrome(char* s) {
    char* aux = s;
    int length = 0;
    while (aux != NULL && *aux != '\0') {
        aux++;
        length++;
    }
    char memo[length][length];

    for (int i=0;i<length;i++) {
        for (int j=0;j<length;j++) {
            memo[i][j]=1;
        }
    }

    int left=0;int r=0;int maxLength=1;
    
    for (int i=0;i<length;i++) {
        memo[i][i]=1;
        if (i<length-1) {
            if (s[i]==s[i+1]) {
                    memo[i][i+1]=1;
                    if (memo[i][i+1]&&(2>maxLength)) {
                    maxLength=2;
                    left=i;
                }
            } else {
                memo[i][i+1]=0;
            }
        }
    }
    
    for (int l=3;l<=length;l++) {
        for (int i=0;i<=length-l;i++) {
            int j=i+l-1;
            if(i<j&&i!=j-1) {
                memo[i][j] = ((memo[i+1][j-1])&&(s[i]==s[j]));
                if (memo[i][j]&&(j-i+1>maxLength)) {
                    maxLength=j-i+1;
                    left=i;
                }
            }   
        }
    }
    
    char* result = (char*)malloc((maxLength + 1) * sizeof(char));
    strncpy(result, s + left, maxLength);
    result[maxLength] = '\0';
    return result;
}