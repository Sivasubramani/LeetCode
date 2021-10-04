// 1135. Connecting Cities With Minimum Cost
// Medium

// There are n cities labeled from 1 to n. You are given the integer n and an array connections where connections[i] = [xi, yi, costi] indicates that the cost of connecting city xi and city yi (bidirectional connection) is costi.

// Return the minimum cost to connect all the n cities such that there is at least one path between each pair of cities. If it is impossible to connect all the n cities, return -1,

// The cost is the sum of the connections' costs used.

 

// Example 1:

// Input: n = 3, connections = [[1,2,5],[1,3,6],[2,3,1]]
// Output: 6
// Explanation: Choosing any 2 edges will connect all cities so we choose the minimum 2.

// Example 2:

// Input: n = 4, connections = [[1,2,3],[3,4,4]]
// Output: -1
// Explanation: There is no way to connect all cities even if all edges are used.

 

// Constraints:

//     1 <= n <= 104
//     1 <= connections.length <= 104
//     connections[i].length == 3
//     1 <= xi, yi <= n
//     xi != yi
//     0 <= costi <= 105

class Solution {
public:
    bool static comp(vector<int> &a, vector<int>&b){
        return a[2] < b[2];
    }
    int find(int i,vector<int> &p){
        if(p[i] != i) p[i]= find(p[p[i]],p);
        return p[i];
    }
    int minimumCost(int n, vector<vector<int>>& A) {
        sort(A.begin(),A.end(),comp);
        vector<int> p(n+1);
        
        for(int i=1;i<=n;i++){
            p[i]=i;
        }
        int cnt =1;
        int res=0;
        for(auto a: A){
            int rx = find(a[0],p);
            int ry = find(a[1],p);
            if(rx != ry){
                res += a[2];
                p[rx] = p[ry];    
                cnt ++;
            }
            
            if(cnt == n) return res;
        }
        
        return -1;
    }
};

//Solutio 2
class Solution {
public:
    bool static comp(vector<int> &a, vector<int>&b){
        return a[2] < b[2];
    }
    int find(int i,vector<int> &p){
        if(p[i] != i) p[i]= find(p[p[i]],p);
        return p[i];
    }
        int minimumCost(int n, vector<vector<int>>& A) {
            vector<vector<pair<int,int>>> graph(n+1);
            vector<int> m(n+1,INT_MAX);
            vector<bool> v(n+1,false);
            
            for(auto a: A){
                graph[a[0]].push_back({a[2],a[1]});
                graph[a[1]].push_back({a[2],a[0]});
            }
            
            priority_queue <pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
            pq.push({0,1});
            int res =0;
            int N=0;
            while( !pq.empty() && N<n){
                pair<int,int> x = pq.top();
                int cost = x.first;
                int conn = x.second;
                pq.pop();
                if(v[conn]) continue;
                v[conn] = true;
                res += cost;
                N++;  
                cout<<n<<endl;
                for(auto a : graph[conn]){
                    if(!v[a.second]){
                        if(a.first < m[a.second]){
                            m[a.second] = a.first;
                            pq.push({a.first,a.second});
                        }
                            
                        
                    }
                }
            }
            cout<<""<<endl;
            return N==n ? res :-1;
            
}
};
