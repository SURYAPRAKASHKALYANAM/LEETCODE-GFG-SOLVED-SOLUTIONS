class Solution {

    public int[][] buildMatrix(int k, int[][] rowConditions, int[][] colConditions) {
        int[] index = new int[k + 1];
        int[] col = new int[k + 1];
        List<List<Integer>> adjr = new ArrayList<>();
        List<List<Integer>> adjc = new ArrayList<>();
        for (int i = 0; i <= k; i++) {
            adjr.add(new ArrayList<>());
            adjc.add(new ArrayList<>());
        }
        for (int i = 0; i < rowConditions.length; i++) {
            adjr.get(rowConditions[i][0]).add(rowConditions[i][1]);
            index[rowConditions[i][1]]++;
        }
        for (int i = 0; i < colConditions.length; i++) {
            adjc.get(colConditions[i][0]).add(colConditions[i][1]);
            col[colConditions[i][1]]++;
        }
        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= k; i++) {
            if (index[i] == 0) q.add(i);
        }
        if (q.isEmpty()) return new int[0][0];
        int[][] ans = new int[k][k];
        int[] rowpos = new int[k + 1];
        int[] colpos = new int[k + 1];
        int r = 0;
        while (!q.isEmpty()) {
            int n = q.peek();
            q.remove();
            rowpos[n] = r++;
            index[n]--;
            for (int i = 0; i < adjr.get(n).size(); i++) {
                int ii = adjr.get(n).get(i);
                index[ii]--;
                if (index[ii] == 0) q.add(ii);
            }
        }
        r = 0;
        for (int i = 1; i <= k; i++) {
            if (col[i] == 0) q.add(i);
        }
        if (q.isEmpty() || q.size() == k) return new int[0][0];
        while (!q.isEmpty()) {
            int n = q.peek();
            q.remove();
            colpos[n] = r++;
            index[n]--;
            for (int i = 0; i < adjc.get(n).size(); i++) {
                int ii = adjc.get(n).get(i);
                col[ii]--;
                if (col[ii] == 0) q.add(ii);
            }
        }
        int[] countr = new int[k + 1], countc = new int[k + 1];
        for (int i = 1; i <= k; i++) {
            if (countr[rowpos[i]] > 0 || countc[colpos[i]] > 0) return new int[0][0];
            countr[rowpos[i]]++;
            countc[colpos[i]]++;
            ans[rowpos[i]][colpos[i]] = i;
        }
        return ans;
    }
}
