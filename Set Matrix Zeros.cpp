/** Problem Statement: 
Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.
Link: https://leetcode.com/problems/set-matrix-zeroes/
*/

//Optimal Code: 
#include <bits/stdc++.h> 
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	bool firstRowZero = false;
	bool firstColZero = false;

	for(int i = 0; i < n; i++){ //Filling first row and col with zero
		for(int j = 0; j < m; j++){
			if(matrix[i][j] == 0){
				if(i == 0){
					firstRowZero = true;
				}
				if(j == 0){
					firstColZero = true;
				}
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
			
		}
	}

	for(int i = 1; i < n; i++){ //filling entire matrix based on first row and col
		for(int j = 1; j < m; j++){
			if(matrix[i][0] == 0 || matrix[0][j] == 0){
				matrix[i][j] = 0;
			}
		}
	}

	if(firstRowZero){ //filling first row
		for(int j = 0; j < m; j++){
			matrix[0][j] = 0;
		}
	}
	if(firstColZero){ //filling first col
		for(int i = 0; i < n; i++){
			matrix[i][0] = 0;
		}
	}

	return matrix;
}
