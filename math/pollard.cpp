int64 pollard_r, pollard_n;

int64 f(int64 val){ return (val*val + pollard_r) % pollard_n; }
int64 myabs(int64 a){ return a >= 0 ? a : -a; }

int64 pollard(int64 n){
    srand(unsigned(time(0)));
    pollard_n = n;

    int64 d = 1;
    do{
        d = 1;
        pollard_r = rand() % n;

        int64 x = 2, y = 2;
        while (d == 1)
            x = f(x), y = f(f(y)), d = __gcd(myabs(x-y), n);
    } while (d == n);

    return d;
}
