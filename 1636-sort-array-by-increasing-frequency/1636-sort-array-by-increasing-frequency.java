class Solution {
    public int[] frequencySort(int[] nums) {
        HashMap<Integer, Integer> m = new HashMap<>();
        for (int i : nums) {
            m.put(i, m.getOrDefault(i, 0) + 1);
        }

        Integer[] numsInteger = Arrays.stream(nums).boxed().toArray(Integer[]::new);

        Arrays.sort(numsInteger, new Comparator<Integer>() {
            @Override
            public int compare(Integer n1, Integer n2) {
                int freqCompare = Integer.compare(m.get(n1), m.get(n2));
                return freqCompare == 0 ? Integer.compare(n2, n1) : freqCompare;
            }
        });

        return Arrays.stream(numsInteger).mapToInt(Integer::intValue).toArray();
    }
}