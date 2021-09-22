// 200. Number of Islands
// Medium

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1

// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3

 

// Constraints:

//     m == grid.length
//     n == grid[i].length
//     1 <= m, n <= 300
//     grid[i][j] is '0' or '1'.


class Solution {
public:
    //DFS solution
   //Time Complexity O(4*m*n)
    //Space Complexity Space: O(m*n)
    bool check(vector<vector<char>>& A,int i,int j){
        if(i<A.size() && j<A[0].size() && i>=0 && j>=0 && A[i][j] =='1'){
            A[i][j]='0';
            check(A,i+1,j);
            check(A,i-1,j);
            check(A,i,j+1);
            check(A,i,j-1);
            return true;
        }
        
        return false;
    }
    int numIslands(vector<vector<char>>& A) {
        int m=A.size();
        if(m <1) return 0;
        int n= A[0].size();
        int sum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(A[i][j] == '1'){
                    if(check(A,i,j)){
                        sum++;
                    }
                }
            }
        }
        
        return sum;
    }

     //BFS solution
     //Time Complexity O(4*m*n)
    //Space Complexity Space: O(W) where W is max(M,N)
    bool check(vector<vector<char>>& A,int i,int j){
        queue<pair<int,int>> q;
        q.push({i,j});
        vector<int> dir{0,1,0,-1,0};
        bool ret=false;
        while(!q.empty()){
            pair<int,int> p= q.front();
            int x=p.first;
            int y= p.second;
            q.pop();
            ret =true;
            for(int i=0;i<4;i++){
                int dx = x+dir[i];
                int dy= y+dir[i+1];
                if(dx<A.size() && dy<A[0].size() && dx>=0 && dy>=0 && A[dx][dy]=='1'){
                    A[dx][dy]='0';
                    q.push({dx,dy});
                }
            }
            
        }
        return ret;
    }
    int numIslands(vector<vector<char>>& A) {
        int m=A.size();
        if(m <1) return 0;
        int n= A[0].size();
        int sum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(A[i][j] == '1'){
                    if(check(A,i,j)){
                        sum++;
                    }
                }
            }
        }
        
        return sum;
    }
    
};
