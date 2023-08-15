#include <bits/stdc++.h> 

//This solution is the complete Kadane's algo
//It maintains si and ei so it can print the maximum sum subarray as well
//Time O(n)
//Space O(1)

long long maxSubarraySum(int arr[], int n)
{
    long long maxSum = INT_MIN, sum = 0;
    long s = 0, si = 0, ei = 0;
    
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum > maxSum){
            maxSum = sum;
            si = s;
            ei = i;
        }
        if(sum < 0){
            sum = 0;
            s = i+1;
        }
    }
    
    if(maxSum < 0){
        return 0;
    }
    return maxSum;
}

/**
--------------------------------------------------------
 * O(N) solution for LC QUESTION
 * Here the returned sum can also be negative and we don't need to return the subarray index
*/

int maxSubArray(vector<int>& nums) {
    long maxSum = INT_MIN, currentSum = 0;
    int si = 0;

    for(int i = 0; i < nums.size(); i++){
        currentSum += nums[i];
            
        maxSum = max(currentSum, maxSum);
        
        currentSum = max(currentSum, 0);
    }

    return maxSum;
}

/*
--------------------------------------------------------
O(n^2) APPROACH :-
*/

long long maxSubarraySum(int arr[], int n)
{
    long long maxSum = INT_MIN;
    for(long i = 0; i < n; i++){
        long long sum = 0;
        for(long j = i; j < n; j++){
            sum += arr[j];
            if(sum > maxSum){
                maxSum = sum;
            }
        }
    }
    if(maxSum < 0){
        return 0;
    }
    return maxSum;
}
