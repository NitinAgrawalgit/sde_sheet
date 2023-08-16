/*Problem: From an array of N integers, in the range of 1 to N, each integer appears exactly once, except for 'a' which appears 
twice and 'b' which is missing. Find a and b. */
//Link: https://www.codingninjas.com/studio/problems/missing-and-repeating-numbers_6828164?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse

/*OPTIMAL APPROACH: Using Bit manipulation. 
1. First XOR all elements of array and XOR all numbers from 1 to N. This gives us a^b
2. Now find that position of the first set bit from right side in (a ^ b)
3. Based on this bit, divide the numbers(elements in array, and no.s in range 1 to N) in two groups. Zero group has those numbers whose 'that' bit is zero, and One group has those numbers whose 'that' bit is one.
4. XOR all numbers in each group
5. the XOR answers in each group holds the two numbers -> a and b
6. Now we determine which is a and which is b, by looking in the array. a is the no. present in the array, while b is missing.
*/

//Time: O(n)
//Space: O(1)

vector<int> findMissingRepeatingNumbers(vector <int> a) {
    int n = a.size();
    
    int xr = 0;
    for(int i = 0; i < n; i++){
        xr = xr ^ a[i];
        xr = xr ^ (i+1);
    } //Now xor stores a^b

    int number = (xr & ~(xr - 1)); 
    //Binary representation of this number has only that bit set which is the rightmost set bit in xor number

    int zero = 0; //These represent the zero and one group
    int one = 0;
    for(int i = 0; i < n; i++){ //seperating and XORing array elements and first N integers, into zero and one group
        if((number & a[i]) != 0){
            one = one ^ a[i];
        }else {
            zero = zero ^ a[i];
        }

        if((number & (i+1)) != 0){
            one = one ^ (i+1);
        }else {
            zero = zero ^ (i+1);
        }
    }

    //After the above step zero and one hold a and b. We have to determine which is which
    //a is repeated number, b is missing number

    int count = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == zero){
            count++;
        }
    }

    if(count == 2){
        return {zero, one};
    }else {
        return {one, zero};
    }
}

//ANOTHER OPTIMAL APPROACH: (Use Maths)
/*
1. Calculate sum of all numbers (Sn). Now calculate the sum of squares of all numbers (Sn2).
2. We know ->    Sn - (Sum of first N Natural no.s) = a - b.
3. Similarily ->   Sn2 = (Sum of Squares of first N natural no.s) = a^2 - b^2 = (a+b)(a-b)
4. Using the above two equation, derive equations to calculate a and b directly.
5. This gives answer in O(n) time.
