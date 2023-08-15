/** Problem Statement:
You are given an array of prices where prices[i] is the price of a given stock on an ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

//OPTIMAL APPROACH (Using Kadane's Algorithm):
//Time: O(n)
    int maxProfit(vector<int>& prices) {
        int leastPrice = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < leastPrice){
                leastPrice = prices[i];
            }else {
                maxProfit = max(maxProfit, prices[i] - leastPrice);
            }
        }

        return maxProfit;
    }
