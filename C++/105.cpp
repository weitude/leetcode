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
		unordered_map<int, int> umap;
		int idx = 0;

		TreeNode *solve(vector<int> &pre, vector<int> &in, int left, int right)
		{
			if (left > right)
				return nullptr;

			int curr = pre[idx++];
			TreeNode *root = new TreeNode(curr);
			if (left == right)
				return root;

			int inIndex = umap[curr];
			root->left = solve(pre, in, left, inIndex - 1);
			root->right = solve(pre, in, inIndex + 1, right);

			return root;
		}

		TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
			int len = inorder.size();
			for (int i = 0; i < len; i++)
				umap[inorder[i]] = i;
			return solve(preorder, inorder, 0, len - 1);
		}
};

