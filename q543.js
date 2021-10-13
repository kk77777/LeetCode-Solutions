/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */
var diameterOfBinaryTree = function (root) {
  let dia = 0;
  const ht = (root) => {
    if (root === null) return 0;
    let lh = ht(root.left);
    let rh = ht(root.right);
    dia = Math.max(dia, lh + rh);
    return 1 + Math.max(lh, rh);
  };
  ht(root);
  return dia;
};
