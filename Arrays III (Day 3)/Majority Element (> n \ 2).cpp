/* Problem: Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. 
You may consider that such an element always exists in the array.
Link: https://www.codingninjas.com/studio/problems/majority-element_6783241?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1
*/

//GOOD APPROACH: (Using Hashmap)
//Time: O(nlogn)
//Space: O(n)

    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            map[nums[i]]++;
        }

        for(auto i : map){
            if(i.second > n/2){
                return i.first;
            }
        }

        return -1; //Because there is no return on all control paths
    }

//OPTIMAL APPROACH: (Moore's Voting Algo)
//Time: O(n)
//Space: O(1)

int majorityElement(vector<int> v) {
	int size = v.size();

	int count = 0;
	int majElement;

	for(int i = 0; i < size; i++){
		if(count == 0){
			majElement = v[i];
		}else if(count > size/2){
			return majElement;
		}
		
		if(v[i] == majElement){
			count++;
		}else {
			count--;
		}
	}

	return majElement;
	//Directly returning majElement, instead of checking if majElement frequency > size/2,
	//bcz it is guaranteed in question that a majority element exists.
}
