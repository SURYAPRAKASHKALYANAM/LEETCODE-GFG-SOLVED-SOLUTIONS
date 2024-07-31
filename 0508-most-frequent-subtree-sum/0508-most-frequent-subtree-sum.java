/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    HashMap<Integer,Integer> m=new HashMap<>();
    int maxf=0;
    public int help(TreeNode root)
    {
        if(root==null) return 0;
        int sum=help(root.left)+help(root.right)+root.val;
        m.put(sum,m.getOrDefault(sum,0)+1);
        maxf=Math.max(maxf,m.get(sum));
        return sum;
    }
    public int[] findFrequentTreeSum(TreeNode root) {
        int[] ans=new int[0];
        help(root);
        for(int i:m.keySet())
        {
            if(m.get(i)==maxf)
            {
                ans=Arrays.copyOf(ans,ans.length+1);
                ans[ans.length-1]=i;
            }
        }
        return ans;
    }
}