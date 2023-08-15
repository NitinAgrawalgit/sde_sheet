/*Problem Statement: 
Given an array consisting of only 0s, 1s, and 2s. Write a program to in-place sort the array without using inbuilt sort functions. 
Link: https://leetcode.com/problems/sort-colors/
*/

//OPTIMAL APPROACH:
//Time: O(n)
//Space: O(1) {inplace}
    void sortColors(vector<int>& nums) {
        int zi = 0, ti = nums.size()-1; //zi -> zeroIndex, ti -> twoIndex

        int i = 0;
        while(i <= ti){
            if(nums[i] == 0){
                swap(nums[zi], nums[i]);
                zi++;
            }else if(nums[i] == 2){
                swap(nums[ti], nums[i]);
                ti--;
                i--;
            }

            i++;
        }
    }

//OTHER APPROACHES:
/*
1. Simply sort it just like any other array
2. Use a frequency array to count occurence of each 0, 1 and 2. Then just fill the array with those many zeros, ones and twos.
*/
