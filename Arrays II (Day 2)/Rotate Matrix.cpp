/**Problem: 
Rotate 2D Matrix in clockWise Direction 
*/
//Link: https://leetcode.com/problems/rotate-image/description/

//APPROACH 1: Using Auxilliary space O(n^2):
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
    
        vector<vector<int>> newMat(n, vector<int>(n, 0));
    
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                newMat[j][n-i-1] = matrix[i][j];
            }
        }
    
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                matrix[i][j] = newMat[i][j];
            }
        }
    }

//APPROACH 2: Doing Inplace matrix transpose and then reversing each row:
//Slightly Slower than above approach, but doesn't need extra memory

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }

//APPROACH 2.1: Another Inplace approach, just using different transposing and swapping:

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n-i-1; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][n-i-1];
                matrix[n-j-1][n-i-1] = temp;
            }
        }

        for(int i = 0; i < n/2; i++){
            vector<int> temp = matrix[i];
            matrix[i] = matrix[n-i-1];
            matrix[n-i-1] = temp;
        }
    }
