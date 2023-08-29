/* Problem: Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. Where ⌊ n/3 ⌋ is floor(n/3).
Link: https://www.codingninjas.com/studio/problems/majority-element_6915220?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse&leftPanelTab=0
*/

//OPTIMAL APPROACH: (Boyer Moore's algo extended)
//Time: O(n)
//Space: O(1)

#include <climits>

vector<int> majorityElement(vector<int> v) {
	int size = v.size();

	int count1 = 0, element1 = INT_MIN;
	int count2 = 0, element2 = INT_MIN;

	for(int i : v){
		if(i == element1){
			count1++;
		}else if(i == element2){
			count2++;
		}else {
			if(count1 == 0){
				element1 = i;
				count1++;
			}else if(count2 == 0){
				element2 = i;
				count2++;
			}else {
				count1--;
				count2--;
			}
		}
	}

	int tempCount1 = 0, tempCount2 = 0;
	for(int i : v){
		if(i == element1){
			tempCount1++;
		}else if(i == element2){
			tempCount2++;
		}
	}

	vector<int> ans;
	if(tempCount1 > size/3){
		ans.push_back(element1);
	}
	if(tempCount2 > size/3){
		ans.push_back(element2);
	}

	return ans;
}

//GOOD APPROACH: (Using HashMap)
//Time: O(n)
//Space: O(n)

    vector<int> majorityElement(vector<int>& nums) {
        int majSize = nums.size()/3;

        unordered_map<int, int> map;
        for(int i : nums){
            map[i]++;
        }

        vector<int> ans;
        for(auto i : map){
            if(ans.size() == 2){
                break;
            }else if(i.second > majSize){
                ans.push_back(i.first);
            }
        }

        return ans;
    }
