// 370. Range Addition

// You are given an integer length and an array updates where updates[i] = [startIdxi, endIdxi, inci].

// You have an array arr of length length with all zeros, and you have some operation to apply on arr. In the ith operation, you should increment all the elements arr[startIdxi], arr[startIdxi + 1], ..., arr[endIdxi] by inci.

// Return arr after applying all the updates.

 

// Example 1:

// Input: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
// Output: [-2,0,3,5,3]

// Example 2:

// Input: length = 10, updates = [[2,4,6],[5,6,8],[1,9,-4]]
// Output: [0,-4,2,2,2,4,4,-4,-4,-4]

 

// Constraints:

//     1 <= length <= 105
//     0 <= updates.length <= 104
//     0 <= startIdxi <= endIdxi < length
//     -1000 <= inci <= 1000

//Time Complexity O(n+l)
//Space Complexity O(n+l)
class Solution {
public:
vector<int> getModifiedArray(int l, vector<vector<int>>& u) {
  vector<int> v(l+1,0);
	int sum=0;
	vector<int> res;

	for(auto a : u){
		v[a[0]] += a[2];
		v[a[1]+1] -= a[2];
	}
	
	for(int i=0;i<l;i++){
		sum += v[i];
		res.push_back(sum);
	}

	return res;

    }
};
