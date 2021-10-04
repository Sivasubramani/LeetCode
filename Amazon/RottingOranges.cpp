// 994. Rotting Oranges

// You are given an m x n grid where each cell can have one of three values:

//     0 representing an empty cell,
//     1 representing a fresh orange, or
//     2 representing a rotten orange.

// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

// Example 1:

// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4

// Example 2:

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

// Example 3:

// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

 

// Constraints:

//     m == grid.length
//     n == grid[i].length
//     1 <= m, n <= 10
//     grid[i][j] is 0, 1, or 2.

//Time complexity is O(mn) where m,n are no. of rows and cols
//Space compelxity is O(mn) worst case if grid contains only rotten oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& A) {
        queue<pair<int,int>> q;
        int org=0;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A[0].size();j++){
                if(A[i][j] == 2){
                    q.push({i,j});
                }
                else if(A[i][j] == 1){
                    org++;
                }
            }
        }

        vector<int> dir{0,-1,0,1,0};
        int sum=-1;
        while(!q.empty()){
            int size = q.size();
            sum++;
            for(int i=0;i<size;i++){
                pair<int,int> p = q.front();
                q.pop();
                int dx = p.first;
                int dy = p.second;
                for(int j=0;j<4;j++){
                    int x = dx +dir[j];
                    int y= dy + dir[j+1];
                    
                    if(x >=0 && y>=0 && x<A.size() && y<A[0].size() && A[x][y] == 1){
                        A[x][y]=2;
                        q.push({x,y});
                        org--;
                    }
                }
                
            }
        }
        if(org >0) return -1;
        if(sum==-1) return 0;
        return sum;
        

    }
};
