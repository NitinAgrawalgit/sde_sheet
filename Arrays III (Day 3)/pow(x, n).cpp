/* Problem: Given a double x and integer n, calculate x raised to power n. Basically Implement pow(x, n).
Link: https://leetcode.com/problems/powx-n/
*/

//OPTIMAL APPROACH: (Using Binary Exponentiation) RECURSIVE
//Time: O(log n)
    double myPow(double x, int n) {
        if(n == 0){ //Base Case
            return 1;
        }

        double ans;
        if(n % 2 == 0){
            ans = myPow(x*x, abs(n/2)); //Used abs(n/2), instead of abs(n)/2, to handle when n = INT_MIN, because in that case -> abs(INT_MIN) = INT_MIN, which gives wrong answer
        }else {
            ans = x*myPow(x*x, abs(n/2));
        }

        if(n < 0){ //If n is negative then answer is reciprocal of itself
            ans = 1.0 / ans;
        }

        return ans;
    }

//ABOVE APPROACH BUT (ITERATIVE)
//Time: O(log n)
double myPow(double x, int n) {
    long N = n;
    if(N < 0){
        N = -1 * N;
        x = 1.0 / x;
    }
    
    double ans = 1.0;
    
    while(N > 0){
        if(N % 2 == 0){
            x *= x;
            N /= 2;
        }else {
            ans *= x;
            N -= 1;
        }
    }

    return ans;
}

//BRUTE FORCE: (Gives TLE)
//Time: O(n)
    double myPow(double x, int n) {
        double ans = 1.0;
        
        if(n < 0){
            x = 1.0 / x;
        }
        
        for(long i = 0; i < abs(n); i++){ //Used long type for i, to handle for i = INT_MIN
            ans *= x;
        }

        return ans;
    }
