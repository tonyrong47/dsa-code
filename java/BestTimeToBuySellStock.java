// Best Time to Buy and Sell Stocks (LeetCode Problem 121)

/* Problem Statement: Given an array where the i-th element is the price of a given stock on day i,
find the maximum profit you can achieve by choosing a single day to buy one stock and
a different day in the future to sell that stock.
 */

import java.util.Arrays;

public class BestTimeToBuySellStock {
    public static int maxProfit(int[] prices) {
        // Variable to track the minimum price seen so far (best day to buy)
        int buyPrice = Integer.MAX_VALUE;

        // Variable to track the maximum profit we can achieve
        int maxProfit = 0;

        // Loop through each day's stock price
        for (int i = 0; i < prices.length; i++) {

            // If today's price is greater than the buyPrice,
            // then selling today gives us a profit
            if (buyPrice < prices[i]) {
                // Calculate profit if we sell today
                int profit = prices[i] - buyPrice;

                // Update maxProfit if today's profit is higher
                maxProfit = Math.max(maxProfit, profit);
            } else {
                // If today's price is lower or equal, update buyPrice
                // because buying at a lower price may lead to better profit later
                buyPrice = prices[i];
            }
        }
        // Return the maximum profit possible
        return maxProfit;
    }

    // Example usage
    public static void main(String[] args) {

        int[] prices1 = { 7, 1, 5, 3, 6, 4 };
        int result1 = maxProfit(prices1);
        System.out.println("Prices: " + Arrays.toString(prices1));
        System.out.println("Maximum Profit: " + result1); // Output: Maximum Profit: 5

        int[] prices2 = { 7, 6, 4, 3, 1 };
        int result2 = maxProfit(prices2);
        System.out.println("\nPrices: " + Arrays.toString(prices2));
        System.out.println("Maximum Profit: " + result2); // Output: Maximum Profit: 0

    }
}
