#include <stdbool.h>

struct TreeNode {
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
};

bool is_identical(struct TreeNode* root1, struct TreeNode* root2)
{
  // If both trees are NULL, they are identical, so return true
  if (!root1 && !root2)
  {
    return true;
  }

  // If one tree is NULL and the other is not, they are not identical, so return false
  if (!root1 || !root2)
  {
    return false;
  }

  // If the values at the root of the trees are not equal, the trees are not identical, so return false
  if (root1->val != root2->val)
  {
    return false;
  }

  // If the values at the root are equal, check the left and right subtrees
  // If both left subtrees are identical and both right subtrees are identical, return true
  // Otherwise, return false
  return is_identical(root1->left, root2->left) && is_identical(root1->right, root2->right);
}
