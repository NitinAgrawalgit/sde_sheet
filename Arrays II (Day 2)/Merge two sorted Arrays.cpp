/* Problem: You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, 
representing the number of elements in nums1 and nums2 respectively. Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, 
nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0, 
and should be ignored. nums2 has a length of n.
*/
//Link: https://leetcode.com/problems/merge-sorted-array/

//GOOD APPROACH:
//Time: O(m * n)
/*Steps:
1. Start loop of i on nums1. Compare nums1[i] with nums2[0]
2. If nums2[0] is smaller than nums1[i], swap them.
3. The element in nums1 is placed at its correct position. But the element at nums2[0] has to placed at its correct provisional position in nums2.
4. Iterate j over nums2, and place nums2[0] at its correct position, such that nums2 remains sorted.
5. When i ends, fill nums2 in the rest of nums1 as specified in question.
*/

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0){ //nums2 is empty, and nums1 is already sorted
            return ;
        }

        for(int i = 0; i < m; i++){
            if(nums1[i] > nums2[0]){
                swap(nums1[i], nums2[0]);

                int temp = nums2[0];
                int j;
                for(j = 0; j < n-1; j++){
                    if(nums2[j+1] < temp){
                        nums2[j] = nums2[j+1];
                    }else {
                        break;
                    }
                }
                nums2[j] = temp;
            }
        }

        for(int i = 0; i < n; i++){
            nums1[i+m] = nums2[i];
        }
    }

//OPTIMAL APPROACH: (Based on Shell Sort)
//Time: O(log m + log n)

