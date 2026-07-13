/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct NodeInfo {

    bool isBST;
    int mini;
    int maxi;
    int sum;

    NodeInfo(bool b,int mn,int mx,int s)
        :isBST(b),mini(mn),maxi(mx),sum(s){}
};

class Solution {

    int ans=0;

    NodeInfo solve(TreeNode* root){

        if(!root)
            return NodeInfo(true,INT_MAX,INT_MIN,0);

        auto left=solve(root->left);
        auto right=solve(root->right);

        if(left.isBST && right.isBST &&
           root->val>left.maxi &&
           root->val<right.mini){

            int currSum=
                left.sum+
                right.sum+
                root->val;

            ans=max(ans,currSum);

            return NodeInfo(
                true,
                min(root->val,left.mini),
                max(root->val,right.maxi),
                currSum
            );
        }

        return NodeInfo(false,INT_MIN,INT_MAX,0);
    }

public:

    int maxSumBST(TreeNode* root){

        solve(root);

        return ans;
    }
};