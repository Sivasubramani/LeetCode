// 547. Number of Provinces
// Medium

// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

// A province is a group of directly or indirectly connected cities and no other cities outside of the group.

// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

// Return the total number of provinces.

 

// Example 1:

// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Output: 2

// Example 2:

// Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
// Output: 3

 

// Constraints:

//     1 <= n <= 200
//     n == isConnected.length
//     n == isConnected[i].length
//     isConnected[i][j] is 1 or 0.
//     isConnected[i][i] == 1
//     isConnected[i][j] == isConnected[j][i]

//Solution 1
//Time Complexity O(n^2)
//Space Complexity O(n)

class Solution {
public:
bool doDFS(vector<vector<int>>& A,int i,vector<int> &v){
	if(v[i]) return false;
	v[i] =1;
	for(int j=0;j<A.size();j++){
		if(A[i][j]== 1){
		doDFS(A,j,v);
		}
	}

	return true;
}

int findCircleNum(vector<vector<int>>& A) {
	if(A.size() ==0) return 0;
	int sum=0;
	vector<int> v(A.size(),0);
	for(int i=0;i<A.size();i++){
		sum += (!v[i]) && doDFS(A,i,v) ? 1 : 0; 
	}
		
	return sum;        
    }
};

//Solution 2
//Time Complexity O(n^2)
//Space Complexity O(1)
class Solution {
public:
void doDFS(vector<vector<int>>& A,int i){
	for(int j=0;j<A.size();j++){
		if(A[i][j] == 1){
		A[i][j] =0;
		A[j][i]=0;
		doDFS(A,j);
		}
	}
}
 
int findCircleNum(vector<vector<int>>& A) {
	if(A.size() ==0) return 0;
	int sum=0;
	for(int i=0;i<A.size();i++){
		for(int j=0;j<A.size();j++){
			if(A[i][j] == 1){
				doDFS(A,i);
				sum++;
			}
		}
	}
		
	return sum;        
    }
};



