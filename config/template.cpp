#include <bits/stdc++.h>

#define FILL(X, V) memset((X), (V), sizeof(X))
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for(TI(a) i = (a).begin(); i != (a).end(); ++i)

#define pb push_back
#define mp make_pair
    
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

const double EPS = 1e-9;

int SGN(double a)
{
    return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0)));
}

int CMP(double a, double b)
{
    return SGN(a - b);
}

typedef long long int64;
typedef unsigned long long uint64;
typdef pair<int, int> ii;

struct node{
    int a, b;
    node (int a = 0, int b = 0) : a(a), b(b) {}
};

using namespace std;

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);

    return 0;
}
