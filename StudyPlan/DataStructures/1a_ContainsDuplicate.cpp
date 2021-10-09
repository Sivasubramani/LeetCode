// 217. Contains Duplicate
// Easy

// 2603

// 886

// Add to List

// Share
// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

// Example 1:

// Input: nums = [1,2,3,1]
// Output: true
// Example 2:

// Input: nums = [1,2,3,4]
// Output: false
// Example 3:

// Input: nums = [1,1,1,3,3,4,3,2,4,2]
// Output: true
 

// Constraints:

// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109

class Solution {
public:
    //Solution 1 
    //Time Complexity O(n)
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(auto a:nums){
            if(s.find(a) != s.end()){
                return true;
            }
            s.insert(a);
        }
        
        return false;
    }
    
    //Solution 2
    //Time Complexity O(n) for set insert
        bool containsDuplicate(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        
        return !(s.size() == nums.size());
    }
};
