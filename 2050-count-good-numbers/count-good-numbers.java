class Solution {
    final long mod = 1_000_000_007L;

    private long pow(long b, long p) {
        long res = 1;
        b %= mod;
        while (p > 0) {
            if ((p & 1) == 1) {
                res = (res * b) % mod;
            }
            b = (b * b) % mod;
            p >>= 1;
        }
        return res;
    }

    public int countGoodNumbers(long n) {
        long even = (n + 1) / 2;
        long odd = n / 2;
        return (int) ((pow(5, even) * pow(4, odd)) % mod);
    }
}
