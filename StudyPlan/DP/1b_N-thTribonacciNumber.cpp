
// 1137. N-th Tribonacci Number
// Easy

// The Tribonacci sequence Tn is defined as follows: 

// T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

// Given n, return the value of Tn.

 

// Example 1:

// Input: n = 4
// Output: 4
// Explanation:
// T_3 = 0 + 1 + 1 = 2
// T_4 = 1 + 1 + 2 = 4

// Example 2:

// Input: n = 25
// Output: 1389537

 

// Constraints:

//     0 <= n <= 37
//     The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.


// Runtime: 0 ms, faster than 100.00% of C++ online submissions for N-th Tribonacci Number.
// Memory Usage: 6.2 MB, less than 14.25% of C++ online submissions for N-th Tribonacci Number.

//Time and Space Complexity -> O(n)
class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n <=2) return 1;
        vector<int> tri(n+1,0);
        tri[0]=0;
        tri[1] =1;
        tri[2] =1;
        for(int i=3;i<=n;i++){
            tri[i] =tri[i-1]+tri[i-2]+tri[i-3];
        }
        return tri[n];
    }
};
