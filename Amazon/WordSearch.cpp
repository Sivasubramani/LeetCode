// 79. Word Search
// Medium

// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

// Example 1:

// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true

// Example 2:

// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true

// Example 3:

// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false

 

// Constraints:

//     m == board.length
//     n = board[i].length
//     1 <= m, n <= 6
//     1 <= word.length <= 15
//     board and word consists of only lowercase and uppercase English letters.

 

// Follow up: Could you use search pruning to make your solution faster with a larger board?
  
// 1.Time comlexity
// I think is MN4^L
// For a given start point (i,j), it is impossible for you to search beyond the length of L and for each grid we have four directions in general. Thus time complexity is O(MN4^L)
// If we were lucky enough, it is possible that self.getWords(board, word, i, j + 1, visited, pos + 1) already return True. In such case, the best time complexity will be O(MNL)!
// (You can imagine the target string appear in the first row of our board.)
//https://leetcode.com/problems/word-search/discuss/228816/Time-complexity-clarification

// 2.space complexity
// The space complexity is O(MN+L)
// MN is to store the node we have visited. L is the depth of the recursion calls.
class Solution {
public:
    
    bool doDFS(int i,int j,string w,vector<vector<char>>& A,int k){
        if(k== w.size()) return true;
        bool res = false;
        if(i<A.size() && i>=0 && j>=0 && j<A[0].size() && A[i][j] == w[k]){
            char c= A[i][j];
            A[i][j]='*';
            res =doDFS(i+1,j,w,A,k+1) || doDFS(i-1,j,w,A,k+1)  || doDFS(i,j+1,w,A,k+1) || doDFS(i,j-1,w,A,k+1);
            A[i][j]=c;
        }
        return res;
    }
    bool exist(vector<vector<char>>& A, string w) {
        int m= A.size();
        if(m < 1) return true;
        int n= A[0].size();
        int k=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(doDFS(i,j,w,A,k)) return true;
            }
        }
        
        return false;
        
    }
};
