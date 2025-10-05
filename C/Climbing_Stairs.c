#include<stdio.h>
#include<stdlib.h>


// -----------------------MEMORIZATION----------------------
// int countWays(int n, int dp[]){
//     if(n == 0) return 1;  // Fixed: == instead of =
//     if(n == 1) return 1;
//     if(dp[n] != -1) return dp[n];
//     return dp[n] = countWays(n-1, dp) + countWays(n-2, dp);
// }

// int climbStairs(int n) {
//     // Handle edge case
//     if(n < 0) return 0;
    
//     int* dp = (int*) malloc((n+1) * sizeof(int));
//     if(dp == NULL) {
//         printf("Memory allocation failed!\n");
//         return -1;
//     }
    
//     for(int i = 0; i <= n; i++){
//         dp[i] = -1;
//     }
    
//     int result = countWays(n, dp);
//     free(dp);  // Free allocated memory
//     return result;
// }

// -----------------------TABULATION----------------------

// int climbStairs(int n) {
//     // Handle edge case
//     if(n < 0) return 0;
    
//     int* dp = (int*) malloc((n+1) * sizeof(int));
    
//     dp[0] = 1;
//     dp[1] = 1;
//     for(int i = 2; i<n+1;i++){
//         dp[i] = dp[i-1] + dp[i - 2];
//     }
//     return dp[n];
// }

// -----------------------OPTIMIZING MEMORY----------------------

int climbStairs(int n) {
    // Handle edge case
    if(n < 0) return 0;
    
    int prev2= 1;
    int prev1 = 1;
    for(int i = 2; i<n+1;i++){
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int main(){
    printf("Enter the number of stairs: ");
    int n;
    scanf("%d", &n);
    
    int ways = climbStairs(n);
    if(ways >= 0) {
        printf("Number of ways to climb %d stairs: %d\n", n, ways);
    }
    
    return 0;
}