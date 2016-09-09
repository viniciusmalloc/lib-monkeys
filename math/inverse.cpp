#define MOD 1000000007LL

/* This function calculates (a^b) % MOD */
int64 fastPow(int64 a, int64 b)
{
    int64 res = 1LL;
    while (b > 0LL)
    {
        if (b & 1LL)
        {
            res *= a; res %= MOD;
        }
        a *= a; a %= MOD;
        b >>= 1;
    }
    return res;
}

/*
    Modular Multiplicative Inverse
    Using Euler's Theorem
*/

long long InverseEuler(int64 n)
{
    return fastPow(n, MOD-2LL);
}