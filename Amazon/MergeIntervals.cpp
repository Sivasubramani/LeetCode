class Solution {
public:
//Sorting solution
//Time Complexity -O(nlogn)
//Space Complexity -O(n)
  
vector<vector<int>> merge(vector<vector<int>>& A) {
    int n= A.size();
    if(n<=1) return A;
    vector<vector<int>> res;
    sort(A.begin(),A.end());
    res.push_back(A[0]);

    for(int i=1;i<n;i++){
        if(res.back()[1] >= A[i][0]){
            res.back()[1] = max(res.back()[1],A[i][1]); 
        }
        else{
           res.push_back(A[i]);
        }
    }

    return res;
}

    
//Map solution
//Time Complexity -O(n)
//Space Complexity -O(n)
   vector<vector<int>> merge(vector<vector<int>>& A) {
         int n= A.size();
        if(n<=1) return A;
       map<int,int> m;
       for(auto a:A){
           m[a[0]]++;
           m[a[1]]--;
       }
       int prevPos=0,prev=0,sum=0;
       vector<vector<int>> res;
       for(auto a:m){
           if(!prev){
               prevPos = a.first;
               prev=1;
           }
           sum += a.second;
           if(sum ==0){
               res.push_back({prevPos,a.first});
               prev=0;
           }
       }

       return res;
   }
};
