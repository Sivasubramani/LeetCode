// 1481. Least Number of Unique Integers after K Removals
// Medium

// Given an array of integers arr and an integer k. Find the least number of unique integers after removing exactly k elements.

 

// Example 1:

// Input: arr = [5,5,4], k = 1
// Output: 1
// Explanation: Remove the single 4, only 5 is left.

// Example 2:

// Input: arr = [4,3,1,1,3,3,2], k = 3
// Output: 2
// Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.

 

// Constraints:

//     1 <= arr.length <= 10^5
//     1 <= arr[i] <= 10^9
//     0 <= k <= arr.length

//Time Complexity O(n+i+ilogn+ilogn) => O(ilogn) i>unique elements
//Space Complexity O(m)

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& A, int k) {
        unordered_map<int,int> m;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        
        for(auto a:A) m[a]++;
        for(auto p:m){
            pq.push({p.second,p.first});
        }
        while(!pq.empty() && k){
            k--;
            pair<int,int> x = pq.top();
            pq.pop();
            x.first--;
            if(x.first > 0)pq.push({x.first,x.second});
        }
        
        while(!pq.empty()){
            k++;
            pq.pop();
        }
        return k;
    }
};
