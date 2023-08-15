/** Problem Statement:
Program to generate Pascal’s Triangle
Link: https://leetcode.com/problems/set-matrix-zeroes/
*/

//OPTIMAL APPROACH:
vector<vector<int>> pascalTriangle(int N) {
    vector<vector<int>> ans;

    vector<int> temp(1, 1);
    ans.push_back(temp);

    for(int i = 1; i < N; i++){
        vector<int> temp;
        temp.push_back(1);
        
        for(int j = 1; j < i; j++){
            temp.push_back(ans[i-1][j-1] + ans[i-1][j]);
        }
        
        temp.push_back(1);
        ans.push_back(temp);
    }

    return ans;
}

//ANOTHER APPROACH (Uses Extra Space):
//Declaring a 2D vector of N*N, filling it with pascal's triangle, then extracting individual rows of increasing size for final answer,
//because the answer needs to be a jagged array.
vector<vector<int>> pascalTriangle(int N) {
    /**Not the best approach */
    
    vector<vector<int>> ans(N, vector<int>(N, 0));

    for(int i = 0; i < N; i++){
        ans[i][0] = 1;
        for(int j = 1; j <= i; j++){
            ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        }
    }

    vector<vector<int>> v;
    for(int i = 0; i < N; i++){
        vector<int> temp;
        for(int j = 0; j <= i; j++){
            temp.push_back(ans[i][j]);
        }
        v.push_back(temp);
    }

    return v;
}
