class Solution
{
public:
    int findComplement(int num)
    {
        if (num == 0)
            return 1;
        int num_bit = log2(num) + 1;
        int mask = (unsigned)(1 << num_bit) - 1;
        return num ^ mask;
    }
};