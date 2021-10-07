// 340. Longest Substring with At Most K Distinct Characters
// Medium

// Given a string s and an integer k, return the length of the longest substring of s that contains at most k distinct characters.

 

// Example 1:

// Input: s = "eceba", k = 2
// Output: 3
// Explanation: The substring is "ece" with length 3.

// Example 2:

// Input: s = "aa", k = 1
// Output: 2
// Explanation: The substring is "aa" with length 2.

 

// Constraints:

//     1 <= s.length <= 5 * 104
//     0 <= k <= 50



class Solution {
public:
int lengthOfLongestSubstringKDistinct(string s, int k) {
    unordered_map<char,int> m;
    int i=0, r=0;
    int res =0;
    for(;i<s.size();i++){
       m[s[i]]++;
       if(m.size()>k){
           res = max(res,i-r);
           while(m.size() > k){
              --m[s[r]];
               if(m[s[r]]==0) m.erase(s[r]);
                r++;
           }
       }
    }
    
    res = max(res,i-r);
    return res;
    
    }
};
