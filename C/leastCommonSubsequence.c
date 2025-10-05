#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int max(int a, int b){
    return a > b ? a : b ;
}
/*
int findLCS(char *s1, char *s2, int i, int j){
    if(i <0 || j <0) return 0;

    if(s1[i] == s2[j]){
        return 1 + findLCS(s1,s2,i-1,j-1);
    }
    return max(findLCS(s1,s2,i-1,j),findLCS(s1,s2,i,j-1));
}

int longestCommonSubsequence(char* text1, char* text2) {
    int i = strlen(text1);
    int j = strlen(text2);

    return findLCS(text1,text2,i-1,j-1);
}
*/


/*-------------MEMOIZATION----------------*/
/*
int findLCS(char*s1,char*s2,int i,int j,int**dp){
    if(i < 0 || j < 0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[i]){
        return dp[i][j] = 1 + findLCS(s1,s2,i-1,j-1,dp);
    }
    return dp[i][j] = max(findLCS(s1,s2,i-1,j,dp),findLCS(s1,s2,i,j-1,dp));
}

int longestCommonSubsequence(char* text1, char* text2){
    int m = strlen(text1);
    int n = strlen(text2);

    int **dp = (int**) malloc(m*sizeof(int*));

    for(int i = 0; i<m;i++){
        dp[i] = (int*) malloc(n*sizeof(int));

        for(int j = 0; j<n;j++){
            dp[i][j] = -1;
        }
    }
    return findLCS(text1,text2,m-1,n-1,dp);
}*/

/*----------Tabulation----------*/
// int longestCommonSubsequence(char* text1, char* text2){
//     int m = strlen(text1);
//     int n = strlen(text2);

//     int **dp = (int**) malloc((m+1)*sizeof(int*));

//     for(int i = 0; i<m+1;i++){
//         dp[i] = (int*) malloc((n+1)*sizeof(int));
//     }
//     for(int i = 0; i<m+1;i++) dp[i][0] = 0;
//     for(int j = 0; j<n+1;j++) dp[0][j] = 0;
    
//     for(int i = 1; i<m+1; i++){
//         for(int j = 1; j<n+1;j++){
//             if(text1[i] == text2[j]) dp[i][j] = 1 + dp[i-1][j-1];
//             else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
//         }
//     }
//     return dp[m][n];
// }



//optimized

int longestCommonSubsequence(char *s, char *t) {
    int n = strlen(s);
    int m = strlen(t);

    // allocate memory for two 1D arrays
    int *prev = (int*) calloc(m + 1, sizeof(int));
    int *cur  = (int*) calloc(m + 1, sizeof(int));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1])
                cur[j] = 1 + prev[j - 1];
            else
                cur[j] = max(prev[j], cur[j - 1]);
        }

        // copy cur into prev
        for (int j = 0; j <= m; j++) {
            prev[j] = cur[j];
        }
    }

    int result = prev[m];

    // free allocated memory
    free(prev);
    free(cur);

    return result;
}

int main(){
    char s1[] = "abcde";
    char s2[] = "ace";
    printf("%d",longestCommonSubsequence(s1,s2));

}