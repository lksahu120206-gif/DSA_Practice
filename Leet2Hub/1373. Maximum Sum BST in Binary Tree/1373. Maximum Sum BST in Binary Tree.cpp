1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12struct NodeInfo {
13
14    bool isBST;
15    int mini;
16    int maxi;
17    int sum;
18
19    NodeInfo(bool b,int mn,int mx,int s)
20        :isBST(b),mini(mn),maxi(mx),sum(s){}
21};
22
23class Solution {
24
25    int ans=0;
26
27    NodeInfo solve(TreeNode* root){
28
29        if(!root)
30            return NodeInfo(true,INT_MAX,INT_MIN,0);
31
32        auto left=solve(root->left);
33        auto right=solve(root->right);
34
35        if(left.isBST && right.isBST &&
36           root->val>left.maxi &&
37           root->val<right.mini){
38
39            int currSum=
40                left.sum+
41                right.sum+
42                root->val;
43
44            ans=max(ans,currSum);
45
46            return NodeInfo(
47                true,
48                min(root->val,left.mini),
49                max(root->val,right.maxi),
50                currSum
51            );
52        }
53
54        return NodeInfo(false,INT_MIN,INT_MAX,0);
55    }
56
57public:
58
59    int maxSumBST(TreeNode* root){
60
61        solve(root);
62
63        return ans;
64    }
65};