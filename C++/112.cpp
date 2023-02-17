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
class Solution {
	public:
		bool ans = false;

		void DFS(TreeNode *root, int target, int sum)
		{
			if (!root->left && !root->right)
			{
				if (sum == target)
					ans = true;
				return;
			}
			if (root->left)
				DFS(root->left, target, sum + root->left->val);
			if (root->right)
				DFS(root->right, target, sum + root->right->val);
		}

		bool hasPathSum(TreeNode* root, int targetSum) {
			if (!root)
				return false;

			DFS(root, targetSum, root->val);
			return ans;
		}
};

