/*Problem: Given an array of N integers, count the no. of Inversion Pairs. 
where Inversion Pair: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i]. */
//Link: https://www.codingninjas.com/studio/problems/count-inversions_615

//OPTIMAL APPROACH (using Merge Sort): 
//Time: O(nlogn)
/*Steps:
1. Create a recursive merge Sort Function, which returns the no. of inversion pairs.
2. Base case -> if size of input array <= 1, then return no. of pairs as 0 (zero);
3. find mid index, and call merge sort on both halves. Add the answer from both halves.
4. This gives the total no. of pairs that currently exist in each individual half. Now we have to count the 
   no. of pairs that will be generated when we merge these two halves. Merging Process:
5. Condition is that when i < j but arr[i] > arr[j]. So, when we insert an element in the merged array from right subarray, we won't be generating
   any new pairs. But when we insert an element from left subarray, (let's say it has index 3 in merged array), then this element has original index smaller
   than the already inserted elements, but it is itself larger than the already inserted elements. So it generates new pairs equal to:-
    
    New pairs generated = (index at which we are inserting) - (starting index of merged array) - [(index of the element in left subarray) - (starting index of left subarray)]

6. Add this answer to the existing sum of two merge sort halves. Repeat step until merged array is complete. return the answer from current step
   and let recursion handle the rest.
*/

long long mergeSort(long long *arr, int si, int ei){ //This is the helper function I created. Original fn from question is below
    if(si >= ei){
        return 0;
    }

    int mid = si + ((ei-si)/2);

    long long ans = 0;
    ans += mergeSort(arr, si, mid);
    ans += mergeSort(arr, mid+1, ei);

    int i = si, j = mid+1;
    long long temp[ei-si+1];
    for(int k = 0; k <= ei-si; k++){
        if(i > mid){
            temp[k] = arr[j];
            j++;
        }else if(j > ei){
            ans += (k - (i-si));
            
            temp[k] = arr[i];
            i++;
        }else {
            if(arr[i] <= arr[j]){
                ans += (k - (i-si));

                temp[k] = arr[i];
                i++;
            }else {
                temp[k] = arr[j];
                j++;
            }
        }
    }

    i = si;
    for(int k = 0; k <= ei-si; k++){
        arr[i] = temp[k];
        i++;
    }

    return ans;
}

long long getInversions(long long *arr, int n){ //This is the original function from question
    long long ans = mergeSort(arr, 0, n-1);  //Helper function that I created above
    return ans;
}

//BRUTE FORCE APPROACH:
//Time: O(n^2)
long long getInversions(long long *arr, int n){
    long long count = 0;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] > arr[j]){
                count++;
            }
        }
    }

    return count;
}
