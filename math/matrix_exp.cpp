#define MAXN 111

int n;

void mult(double x[][MAXN], double y[][MAXN]) {
    double aux[n][n];
    REP(i, n) REP(j, n) aux[i][j] = 0.0;
    
    REP(i, n) REP(j, n) REP(k, n){
        aux[i][j] += (x[i][k] * y[k][j]);
    }
    
    REP(i, n) REP(j, n) x[i][j] = aux[i][j];
}

void powM(double mat[][MAXN], int ex) {
    //Inicializa com a identidade
    double res[MAXN][MAXN];
    REP(i, n) REP(j, n) res[i][j] = (i == j) ? 1.0 : 0.0;
    while(ex) {
        if(ex & 1) mult(res, mat);
        mult(mat, mat);
        ex >>= 1;
    }
    
    REP(i, n) REP(j, n) mat[i][j] = res[i][j];
}
