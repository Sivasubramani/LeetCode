562. Longest Line of Consecutive One in Matrix
Medium

Given an m x n binary matrix mat, return the length of the longest line of consecutive one in the matrix.

The line could be horizontal, vertical, diagonal, or anti-diagonal.

 

Example 1:

Input: mat = [[0,1,1,0],[0,1,1,0],[0,0,0,1]]
Output: 3

Example 2:

Input: mat = [[1,1,1,1],[0,1,1,0],[0,0,0,1]]
Output: 4

 

Constraints:

    m == mat.length
    n == mat[i].length
    1 <= m, n <= 104
    1 <= m * n <= 104
    mat[i][j] is either 0 or 1.

class Solution {
public:
    int longestLine(vector<vector<int>>& A) {
        int m= A.size();
        int n= A[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(4,0)));
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(A[i][j]==1){
                    dp[i][j][0]= i ? (dp[i-1][j][0]+1):1;
                    res= max(dp[i][j][0],res);
                    
                    dp[i][j][1]= j ? (dp[i][j-1][1]+1):1;
                    res= max(dp[i][j][1],res);
                    
                    dp[i][j][2]= (i && j) ? (dp[i-1][j-1][2]+1):1;
                    res= max(dp[i][j][2],res);
                    
                    dp[i][j][3]= i && j<n-1 ? (dp[i-1][j+1][3]+1):1;
                    res= max(dp[i][j][3],res);
                    
                }
            }
        }
        return res;
    }
};
