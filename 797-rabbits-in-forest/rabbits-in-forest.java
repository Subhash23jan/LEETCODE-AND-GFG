class Solution {

    public int numRabbits(int[] answers) {
        Map<Integer, Integer> map = new HashMap<>();
        int ans = 0;
        for (int num : answers) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        for (int key : map.keySet()) {
            int groupSize = key + 1;
            int count = map.get(key);
            ans += ((count + groupSize - 1) / groupSize) * groupSize;
        }
        return ans;
    }
}
