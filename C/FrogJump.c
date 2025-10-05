// Given an integer array height[] where height[i] represents the height of the i-th stair,
// a frog starts from the first stair and wants to reach the top. From any stair i, the frog has two options: 
// it can either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference in height between the two stairs. 
// Determine the minimum total cost required for the frog to reach the top.

// Example:

// Input: heights[] = [20, 30, 40, 20] 
// Output: 20
// Explanation:  Minimum cost is incurred when the frog jumps from stair 0 to 1 then 1 to 3:
// jump from stair 0 to 1: cost = |30 - 20| = 10
// jump from stair 1 to 3: cost = |20-30|  = 10
// Total Cost = 10 + 10 = 20
// Input: heights[] = [30, 20, 50, 10, 40]
// Output: 30
// Explanation: Minimum cost will be incurred when frog jumps from stair 0 to 2 then 2 to 4:
// jump from stair 0 to 2: cost = |50 - 30| = 20
// jump from stair 2 to 4: cost = |40-50|  = 10
// Total Cost = 20 + 10 = 30
// Constraints:

// 1 <= height.size() <= 105
// 0 <= height[i]<=104


#include<stdio.h>
#include<stdlib.h>
int min(int a, int b){
    return a>b? b:a;
}
//-------------------------------------------------------MEMORIZATION
//int findMinCost(int heights[],int idx,int dp[]){
//     if(idx == 0) return 0;
//     if(idx == 1) return abs(heights[1] - heights[0]);
//     if(dp[idx] != -1) return dp[idx];
//     dp[idx] = min(findMinCost(heights,idx-1,dp) + abs(heights[idx] - heights[idx-1]), 
//                     findMinCost(heights,idx-2,dp) + abs(heights[idx] - heights[idx-2]));
//     return dp[idx];
// }


// int minCost(int heights[],int size){
//     int *dp = (int*) malloc(size*sizeof(int));
//     for(int i=0; i<size;i++){
//         dp[i] = -1;
//     }
//    int ans = findMinCost(heights,size-1,dp);
//    free(dp);
//    return ans;
// }
//------------------------------------------------------------TABULATION
/*
int minCost(int heights[],int size){
    int *dp = (int*) malloc(size*sizeof(int));
    dp[0] = 0;
    if (size > 1)
    dp[1] = abs(heights[1] - heights[0]);

    for(int i = 2; i<size;i++){
        dp[i] = min(dp[i-1] + abs(heights[i]-heights[i-1]), dp[i-2] + abs(heights[i] - heights[i-2]));
    }
    return dp[size-1];
}*/
//------------------------------------------------------------------OPTIMIZED

int minCost(int heights[],int size){
    
    int prev2 = 0;
    int prev1 = 0;
    if (size > 1)
        prev1 = abs(heights[1] - heights[0]);
    
    // You need to implement the rest of the logic using prev1 and prev2, or remove this function if not needed.
    // The current code below references 'dp', which is not declared in this function.
    // For a space-optimized solution, you can use prev1 and prev2 as follows:

    for(int i = 2; i < size; i++){
        int curr = min(prev1 + abs(heights[i] - heights[i-1]), prev2 + abs(heights[i] - heights[i-2]));
        prev2 = prev1;
        prev1 = curr;
    }
    return (size == 1) ? 0 : prev1;
}

int main(){
    int heights[] = {20,30,40,20};
    printf("Min Cost is %d\n",minCost(heights,4));

}