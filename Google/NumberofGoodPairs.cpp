// 1512. Number of Good Pairs
// Easy

// Given an array of integers nums, return the number of good pairs.

// A pair (i, j) is called good if nums[i] == nums[j] and i < j.

 

// Example 1:

// Input: nums = [1,2,3,1,1,3]
// Output: 4
// Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.

// Example 2:

// Input: nums = [1,1,1,1]
// Output: 6
// Explanation: Each pair in the array are good.

// Example 3:

// Input: nums = [1,2,3]
// Output: 0

 

// Constraints:

//     1 <= nums.length <= 100
//     1 <= nums[i] <= 100

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of Good Pairs.
// Memory Usage: 7.2 MB, less than 60.79% of C++ online submissions for Number of Good Pairs.


class ParkingSystem {
    vector<int> parkingType;
public:
    ParkingSystem(int big, int medium, int small) {
        parkingType= {big,  medium, small};

    }
    
    bool addCar(int carType) {
        if(parkingType[carType-1] > 0){
            parkingType[carType-1]--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
