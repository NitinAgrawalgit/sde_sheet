/*Problem:
Given an (m * n) matrix and an integer, find if the given integer exists in the matrix. Given matrix has the following properties:
1. Integers in each row are sorted from left to right.
2. The first integer of each row is greater than the last integer of the previous row
Link: https://www.codingninjas.com/studio/problems/search-in-a-2d-matrix_980531?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=1
*/

//APPROACH 1: (Pure 2D Binary Search)
//We can apply this since all the rows and cols are sorted in non decreasing order
bool searchMatrix(vector<vector<int>>& mat, int target) {
    int m = mat.size();
    int n = mat[0].size();

    /*This is 2D Binary Search */
    int si = 0, ei = (m * n)-1;
    while(si <= ei){
        int mid = (si + ei) / 2;

        int row = mid / n;
        int col = mid % n;

        if(mat[row][col] == target){
            return true;
        }else if(target > mat[row][col]){
            si = mid + 1;
        }else {
            ei = mid - 1;
        }
    }

    return false;
}

//APPROACH 2: (Using Linear Search)
//Using Linear Search to determine which row may contain the target. Then using binary Search to search in that row.
     bool binarySearch(vector<int> v, int target){ //This is a helper function module
        int si = 0, ei = v.size()-1;

        while(si <= ei){
            int mid = (si+ei)/2;

            if(v[mid] == target){
                return true;
            }else if(target > v[mid]){
                si = mid + 1;
            }else {
                ei = mid - 1;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target){ //This is the original function from question
        int m = matrix.size();
        int n = matrix[0].size()

        for(int i = 0; i < m; i++){
            if(matrix[i][0] <= target){
                if(matrix[i][n-1] >= target){
                    return binarySearch(matrix[i], target);
                }
            }
        }

        return false;
    }

//APPROACH 3: (Using Binary Search)
//This time we are using binary Search for searching the potential answer containing row as well. Then calling binary search on that row
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        int m = matrix.size();
        int n = matrix[0].size();

        int si = 0, ei = m-1;
        while(si <= ei){
            int mid = (si + ei) / 2;

            if(target >= matrix[mid][0]){
                if(target <= matrix[mid][n-1]){
                    return binarySearch(matrix[mid], target); //Binary Search fn is same as given in above approach
                }else {
                    si = mid + 1;
                }
            }else {
                ei = mid - 1;
            }
        }
      
        return false;
    }
