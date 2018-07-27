/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
public TreeNode constructMaximumBinaryTree(int[] nums) {
    //边界处理，定义一个root节点
    TreeNode root = null;
    if(nums==null||nums.length==0){
        return root;
    }
    int maxnumber = Integer.MIN_VALUE;; // 当前数组最大值
    int index = 0; // 当前最大值下标
    int len = nums.length;

    for(int i=0;i<len;i++){
        if(nums[i]>=maxnumber){
            index = i;
            maxnumber = nums[i];
        }
    }
    root = new TreeNode(maxnumber);
    int[]left = new int[index];
    int[]right = new int[len-index-1];
    // 左侧数组初始化
    for(int i=0;i<index;i++){
        left[i] = nums[i];
    }
    // 右侧数组初始化
    for(int i=index+1;i<len;i++){
        right[i-index-1] = nums[i];
    }
    root.left = constructMaximumBinaryTree(left); // 递归左子树
    root.right = constructMaximumBinaryTree(right); // 递归右子树

    return root;
}
}