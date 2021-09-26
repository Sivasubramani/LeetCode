// 1041. Robot Bounded In Circle
// Medium

// 1793

// 452

// Add to List

// Share
// On an infinite plane, a robot initially stands at (0, 0) and faces north. The robot can receive one of three instructions:

// "G": go straight 1 unit;
// "L": turn 90 degrees to the left;
// "R": turn 90 degrees to the right.
// The robot performs the instructions given in order, and repeats them forever.

// Return true if and only if there exists a circle in the plane such that the robot never leaves the circle.

 

// Example 1:

// Input: instructions = "GGLLGG"
// Output: true
// Explanation: The robot moves from (0,0) to (0,2), turns 180 degrees, and then returns to (0,0).
// When repeating these instructions, the robot remains in the circle of radius 2 centered at the origin.
// Example 2:

// Input: instructions = "GG"
// Output: false
// Explanation: The robot moves north indefinitely.
// Example 3:

// Input: instructions = "GL"
// Output: true
// Explanation: The robot moves from (0, 0) -> (0, 1) -> (-1, 1) -> (-1, 0) -> (0, 0) -> ...
 

// Constraints:

// 1 <= instructions.length <= 100
// instructions[i] is 'G', 'L' or, 'R'.


//Time Complexity O(N)
//Space Complexity O(1)

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

bool findDirection(string s, char &curDirection){
    int vertical=0,horizontal=0;
 for(int i=0;i<s.size();i++){
     if(s[i] == 'G'){
         if(curDirection =='N') vertical++;
         else if(curDirection =='S') vertical--;
         else if(curDirection =='E') horizontal++;
         else if(curDirection =='W') horizontal--;
     }

     else{
         char c = s[i];
         if(curDirection =='N') curDirection = c == 'R' ? 'E':'W';
         else if(curDirection =='S') curDirection = c == 'R' ? 'W':'E';
         else if(curDirection =='E') curDirection = c == 'R' ? 'S':'N';
         else if(curDirection =='W') curDirection = c == 'R' ? 'N':'S';
     }
 }

// cout<<curDirection<<" "<<vertical<<" "<<horizontal<<endl;
     bool res = curDirection != 'N' || (vertical ==0 && horizontal ==0);
     return res;

}
int main() {
    string s="GG";
    char curDirection = 'N';
    bool res = findDirection(s,curDirection);
    if(res) cout<<"Yes";
    else cout<<"No";
    return 0;
}
