int next_int(){
    int n = 0, neg = 1;
    char c = getchar_unlocked();
    if ( c == EOF ) exit(0);
    while (!('0' <= c && c <= '9')) {
        if ( c == '-' ) neg = -1;
        c = getchar_unlocked();
        if ( c == EOF ) exit(0);
    }
    while ('0' <= c && c <= '9') {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }
    return neg*n;
}