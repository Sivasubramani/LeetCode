// 323. Number of Connected Components in an Undirected Graph
// Medium

// You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.

// Return the number of connected components in the graph.

 

// Example 1:

// Input: n = 5, edges = [[0,1],[1,2],[3,4]]
// Output: 2

// Example 2:

// Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
// Output: 1

 

// Constraints:

//     1 <= n <= 2000
//     1 <= edges.length <= 5000
//     edges[i].length == 2
//     0 <= ai <= bi < n
//     ai != bi
//     There are no repeated edges.

class Solution {
public:
    //BFS
    //Time Complexity O(m+n)
    //Time Complexity O(n+m)
    int countComponents(int n, vector<vector<int>>& A) {
        if(n<=1) return n;
        vector<vector<int>> g(n);
        vector<bool> vis(n,false);
        for(auto a:A){
            g[a[0]].push_back(a[1]);
            g[a[1]].push_back(a[0]);
        }
        queue<int> q;
        int sum=0;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                q.push(i);
                sum++;
            }
            
            while(!q.empty()){
                int x= q.front();
                q.pop();
                vis[x]=true;
                for(auto a:g[x]){
                    if(!vis[a]) q.push(a);
                }
            }
            
        }
        
        return sum;
        
    }
    
    //DFS
    //Time Complexity O(m+n)
    //Time Complexity O(n+m) for recursive
    void dodfs(vector<vector<int>> &g,int i,vector<bool> &vis){
        vis[i]=true;
        for(auto a:g[i]){
            if(!vis[a])dodfs(g,a,vis);
        }
    }
    int countComponents(int n, vector<vector<int>>& A) {
        if(n<=1) return n;
        vector<vector<int>> g(n);
        vector<bool> vis(n,false);
        for(auto a: A){
            g[a[0]].push_back(a[1]);
            g[a[1]].push_back(a[0]);
        }
        int sum =0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                sum++;
                dodfs(g,i,vis);
            }
        }
        
        return sum;
    }
};
