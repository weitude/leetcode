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
		int mn = INT_MAX;

		void traversal(TreeNode *root, int level)
		{
			if (!root->left && !root->right)
			{
				if (mn > level)
					mn = level;
				return;
			}
			if (root->left)
				traversal(root->left, level + 1);
			if (root->right)
				traversal(root->right, level + 1);
		}

		int minDepth(TreeNode* root) {
			if (!root)
				return 0;
			traversal(root, 1);
			return mn;
		}
};

