// 792. Number of Matching Subsequences
// Medium

// Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

//     For example, "ace" is a subsequence of "abcde".

 

// Example 1:

// Input: s = "abcde", words = ["a","bb","acd","ace"]
// Output: 3
// Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".

// Example 2:

// Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
// Output: 2

 

// Constraints:

//     1 <= s.length <= 5 * 104
//     1 <= words.length <= 5000
//     1 <= words[i].length <= 50
//     s and words[i] consist of only lowercase English letters.

class Solution {
public:
    bool check(string s, string p){
        int i=0,j=0;
        while(i<s.size() && j<p.size()){
            if(s[i] == p[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        
        return j==p.size();
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int cnt=0;
        unordered_map<string,int> m;
        for(auto a:words) m[a]++;
        for(auto a:m){
            if(check(s,a.first)){
                cnt +=a.second;
            }
        }
        
        return cnt;
    }
};
