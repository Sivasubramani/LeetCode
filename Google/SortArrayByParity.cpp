// 905. Sort Array By Parity
// Easy

// Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

// Return any array that satisfies this condition.

 

// Example 1:

// Input: nums = [3,1,2,4]
// Output: [2,4,3,1]
// Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

// Example 2:

// Input: nums = [0]
// Output: [0]

 

// Constraints:

//     1 <= nums.length <= 5000
//     0 <= nums[i] <= 5000

class Solution {
public:
    
    //Solution 1:
    //Time Complexity O(n+n)
    //Space Complexity O(n)
  
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2 ==0) result.push_back(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2 !=0) result.push_back(nums[i]);
        }      
        return result;
    }
    
    //Solution 2:
    //Time Complexity O(n)
    //Space Complexity O(1)
  
        vector<int> sortArrayByParity(vector<int>& nums) {
        for(int i=0,j=0;i<nums.size();i++){
            if(nums[i] %2==0){
                swap(nums[i],nums[j++]);
            }
        } 
  
        return nums;
    }
};
