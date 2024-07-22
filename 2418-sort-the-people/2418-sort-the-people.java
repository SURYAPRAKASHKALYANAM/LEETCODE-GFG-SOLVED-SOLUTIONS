class Solution {

    public static final <T> void swap(T[] a, int i, int j) {
        T t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    public static final void swap(int[] a, int i, int j) {
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }

    public String[] sortPeople(String[] names, int[] heights) {
        for (int j = 0; j < heights.length; j++) {
            for (int i = j + 1; i < heights.length; i++) {
                if (heights[j] < heights[i]) {
                    swap(heights, j, i);
                    swap(names, j, i);
                }
            }
        }
        return names;
    }
}
