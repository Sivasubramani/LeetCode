// 253. Meeting Rooms II
// Medium

// Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

 

// Example 1:

// Input: intervals = [[0,30],[5,10],[15,20]]
// Output: 2

// Example 2:

// Input: intervals = [[7,10],[2,4]]
// Output: 1

 

// Constraints:

//     1 <= intervals.length <= 104
//     0 <= starti < endi <= 106

class Solution {
public:
    //Time Complexity 0(n)
    //Space Complexity 0(m+n)
    int minMeetingRooms(vector<vector<int>>& A) {
       map<int,int> m;
        for(auto a : A){
            m[a[0]]++;
            m[a[1]]--;
        }
        int res =INT_MIN;
        int sum=0;
        for(auto a:m){
            sum +=a.second;
            res =max(sum,res);
        }
        
        return res;
    }
};
