class Solution {
    public int longestPalindrome(String[] words) {
        boolean flag1 = false;
        Map<String, Integer> map = new HashMap<>();

        for (String str : words) {
            map.put(str, map.getOrDefault(str, 0) + 1);
        }

        int ans = 0;
        Set<String> visited = new HashSet<>();

        for (Map.Entry<String, Integer> mp : map.entrySet()) {
            String str = mp.getKey();
            String reverse = new StringBuilder(str).reverse().toString();
            int freq = mp.getValue();

            if (!str.equals(reverse)) {
                if (map.containsKey(reverse) && !visited.contains(reverse)) {
                    int pairCount = Math.min(freq, map.get(reverse));
                    ans += pairCount * 4;
                    visited.add(str);
                }
            } else {
                ans += (freq / 2) * 4;
                if (freq % 2 == 1) flag1 = true;
            }
        }

        return ans + (flag1 ? 2 : 0);
    }
}
