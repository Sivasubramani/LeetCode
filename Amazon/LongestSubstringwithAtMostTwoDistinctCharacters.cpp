// 159. Longest Substring with At Most Two Distinct Characters
// Medium

// Given a string s, return the length of the longest substring that contains at most two distinct characters.

 

// Example 1:

// Input: s = "eceba"
// Output: 3
// Explanation: The substring is "ece" which its length is 3.

// Example 2:

// Input: s = "ccaabbb"
// Output: 5
// Explanation: The substring is "aabbb" which its length is 5.

 

// Constraints:

//     1 <= s.length <= 105
//     s consists of English letters.



class Solution {
public:
int lengthOfLongestSubstringTwoDistinct(string s) {
int start =0,res =0,change =0;
for(int i=0;i<s.size();i++){

	if(s[i] != s[change]){
		if(change !=0 && s[i] != s[change-1] ){
				start = change;
		}	
		change =i;
	}
	res = max(res,i-start+1);

}
	return res;
      
    }
};

