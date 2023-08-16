/*Problem: Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals.
Link: https://leetcode.com/problems/merge-intervals/description/
*/

//Approach is to sort the intervals array based on the index 0 of each interval
//Then just merge intervals if 0th index of current interval is less than index 1 of previous interval

//BELOW CODE USES ERASE FUNCTION TO REMOVE AN INTERVAL THAT HAS BEEN MERGED INTO ANOTHER:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sortIntervals(intervals, 0, intervals.size()-1);

        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= intervals[i-1][1]){
                intervals[i-1][0] = min(intervals[i-1][0], intervals[i][0]);
                intervals[i-1][1] = max(intervals[i-1][1], intervals[i][1]);
                
                intervals.erase(intervals.begin() + i);
                i--;
            }
        }

        return intervals;
    }

//ABOVE METHOD DOESN'T REQUIRE EXTRA SPACE, BUT ERASING FUNCTIONALITY TAKES PROCESSING TIME
//WE CAN USE SECOND APPROACH WHERE WE NEED AN EXTRA AUXILLIARY ARRAY, BUT EXECUTION TIME IS REDUCED TO A FRACTION OF THE PREVIOUS APPROACH:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        for(int i = 0; i < intervals.size(); i++){
            if(ans.empty() || intervals[i][0] > ans.back()[1]){
                ans.push_back(intervals[i]);
            }else {
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            }
        }

        return ans;
    }
