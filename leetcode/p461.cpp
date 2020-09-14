class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        int ma = (x>y) ? x : y;
        ma = ceil(log2(ma));
        bitset<31> num(x);
        bitset<31> nu2(y);
        for (int i = 0; i<ma+1; i++) {
            if (num[i] != nu2[i]) count++;
        }
        return count;
    }
};