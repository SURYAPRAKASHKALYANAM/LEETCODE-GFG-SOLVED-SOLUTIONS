class Solution {

    public int[][] restoreMatrix(int[] rowSum, int[] colSum) {
        int[][] ans = new int[rowSum.length][colSum.length];
        //O(n*m)
        // for (int i = 0; i < rowSum.length; i++) {
        //     for (int j = 0; j < colSum.length; j++) {
        //         ans[i][j] = Math.min(rowSum[i], colSum[j]);
        //         rowSum[i] -= ans[i][j];
        //         colSum[j] -= ans[i][j];
        //     }
        // }
        // o(n+m)
        for (int i = 0, j = 0; i < rowSum.length && j < colSum.length;) {
            ans[i][j] = Math.min(rowSum[i], colSum[j]);
            rowSum[i] -= ans[i][j];
            colSum[j] -= ans[i][j];
            i += (rowSum[i] == 0)?1:0;
            j += (colSum[j] == 0)?1:0;
        }
        return ans;
    }
}
