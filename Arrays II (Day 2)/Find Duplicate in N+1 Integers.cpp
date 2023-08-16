/* Problem:
Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] 
inclusive. There is only one repeated number in nums, return this repeated number. You must solve 
the problem without modifying the array nums and uses only constant extra space.

Link: https://www.codingninjas.com/studio/problems/1112602?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
Link: https://leetcode.com/problems/find-the-duplicate-number/
*/

//OPTIMAL APPROACH(Cyclic Linked List method):
//Time O(n)
//Space O(1)

int findDuplicate(vector<int> &arr, int n){
	int slow = arr[0];
    int fast = arr[0];
    
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    }while(slow != fast);
    
    slow = arr[0];
    while(slow != fast){
        slow = arr[slow];
        fast = arr[fast];
    }
    
    return slow;
}

//ANOTHER OPTIMAL APPROACH(But it distorts the actual array):
//Time O(n)
//Space O(1)

//INTUITION: Start from index 0. The value stored at currentIndex is your nextIndex. Before going to nextIndex, change value at currentIndex to -1.
//Keep going to the nextIndex until you find an index where the value stored is already -1. It means that you've already visited this index, 
//and that index is the duplicate number.

int findDuplicate(vector<int>& nums) {
	int currentIndex = 0;

        while(1){ //Infinite Loop
            if(nums[currentIndex] == -1){
                return currentIndex;
            }

            int prevIndex = currentIndex;
            currentIndex = nums[currentIndex];
            nums[prevIndex] = -1;
        }

        return -1; 
        //return statement is to force compilation, bcz otherwise a non void function would not have a return value in all conditional execution paths
}

//Other Approaches:
//1. Sort the array and see if any two consecutive elements are equal
//2. Using a map or, a boolean array of size n+1 and initialized with false;
