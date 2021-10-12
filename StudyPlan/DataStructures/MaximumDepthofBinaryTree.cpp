// 104. Maximum Depth of Binary Tree
// Easy

// Given the root of a binary tree, return its maximum depth.

// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

// Example 1:

// Input: root = [3,9,20,null,null,15,7]
// Output: 3

// Example 2:

// Input: root = [1,null,2]
// Output: 2

// Example 3:

// Input: root = []
// Output: 0

// Example 4:

// Input: root = [0]
// Output: 1

 

// Constraints:

//     The number of nodes in the tree is in the range [0, 104].
//     -100 <= Node.val <= 100



// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
class Solution {
public:
    //DFS
//   [Time Complexity: O(n)] [Space Complexity: O(H)]
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
    
    //BFS
  //   [Time Complexity: O(n)] [Space Complexity: O(H)]
        int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> s;
        s.push(root);
        int k=0;
        while(!s.empty()){
            int size = s.size();
            for(int i=0;i<size;i++){
            TreeNode* x = s.front();
            s.pop();
            if(x->left) s.push(x->left);
            if(x->right) s.push(x->right);
            }
            k++;

        }    
        return k;
    }
};
