/**Problem:
Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.
If such an arrangement is not possible, it must rearrange to the lowest possible order (i.e. sorted in ascending order)
Link: https://www.codingninjas.com/studio/problems/893046?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
*/

//OPTIMAL APPROACH:
//Time: O(n)
/*
1. Find the first such element from the right side such that arr[i] < arr[i+1]. This is the breakpoint. 
   (It is just before the rightmost peak of the array(if array is represented in graph form))
2. Now from the elements on breakPoint's right, find the element which is just larger than breakpoint. Since all the elements on breakpoint's right
   are in descending order, you just have to find the first number from right which is larger than the breakpoint.
3. Now swap breakpoint with the just larger element.
4. Reverse the subarray to the right of the original breakpoint index. You have your answer.

INTUITION: The approach is that when an array is in its largest lexicograpic permutation, then the next permutation is the array sorted in ascending order.
So we just find the subarray from right side which is in desc order, i.e. it is its own largest permutation. Then to create next permutation, we replace the breakpoint 
with the next just larger number and arrange the subarray in ascending order, since for the given new breakpoint, this should now be the smallest permutation.
*/

vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int breakPoint = -1;
    int justLarger;

    for(int i = n-1; i > 0; i--){
        if(permutation[i] > permutation[i-1]){
            breakPoint = i-1;
            break;
        }
    }

    if(breakPoint == -1){
        reverse(permutation.begin(), permutation.end());
    }else {
        for(int i = n-1; i > breakPoint; i--){
            if(permutation[i] > permutation[breakPoint]){
                justLarger = i;
                break;
            }
        }

        int temp = permutation[breakPoint];
        permutation[breakPoint] = permutation[justLarger];
        permutation[justLarger] = temp;

        reverse(permutation.begin()+breakPoint+1, permutation.end());
    }

    return permutation;
}
