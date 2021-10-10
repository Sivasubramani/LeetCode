// 383. Ransom Note
// Easy

// Given two stings ransomNote and magazine, return true if ransomNote can be constructed from magazine and false otherwise.

// Each letter in magazine can only be used once in ransomNote.

 

// Example 1:

// Input: ransomNote = "a", magazine = "b"
// Output: false

// Example 2:

// Input: ransomNote = "aa", magazine = "ab"
// Output: false

// Example 3:

// Input: ransomNote = "aa", magazine = "aab"
// Output: true

 

// Constraints:

//     1 <= ransomNote.length, magazine.length <= 105
//     ransomNote and magazine consist of lowercase English letters.

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> m;
        for(auto a:magazine){
            m[a]++;
        }
        
        for(auto a:ransomNote){
            if(m.find(a) != m.end()){
                m[a]--;
                if(m[a] ==0) m.erase(a);
            }
            else return false;
        }
        
        return true;
    }
};
