#define MAX 10000 //bit size sample

int ft[MAX];

//range to count (must be valid)
int rsq(int a, int b){
    if ( a == 0 ){
        int sum = 0;
        for ( ; b >= 0; b = (b & (b + 1)) - 1 ){
            sum += ft[b];
        }
        return sum;
    }
    else return rsq(0, b) - rsq(0, a-1);
}

//add to the k-th element value
void adjust(int n, int k, int value){
    for ( ; k <= n; k |= k + 1 )
        ft[k] += value;
}