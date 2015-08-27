template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

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

int nxt_cmd(){
	char c = getchar_unlocked();
	while ( c < 'A' || c > 'Z' ) c = getchar_unlocked();
	if ( c == 'K' ){
		getchar_unlocked(); getchar_unlocked();
		return 1;
	}
	c = getchar_unlocked();
	if ( c == 'O' ){
		getchar_unlocked(); getchar_unlocked();
		return -1;
	}
	getchar_unlocked(); getchar_unlocked();
	return 0;
}

struct edge_t{
	int v, c;
	edge_t( int vv = 0, int cc = 0 ) : v(vv), c(cc) {}
};

#define MAXN 10001
int N, parent[MAXN], L[MAXN], dis[MAXN];
int dp[15][MAXN];

vector< edge_t > gr[MAXN];

int lca( int u, int v ){
	if ( L[u] < L[v] ){
		u ^= v; v ^= u; u ^= v; 
	}
	int lg;
	for ( lg = 1; (1<<lg) <= L[u]; lg++ );
	lg--;
	
	for ( int i = lg; i >= 0; i-- )
		if ( L[u] - (1<<i) >= L[v] )
			u = dp[i][u];
	if ( u == v ) return u;
	for ( int i = lg; i >= 0; i-- )
		if ( dp[i][u] != -1 && dp[i][u] != dp[i][v] )
			u = dp[i][u], v = dp[i][v];
	return parent[u];
}

int kth( int k, int u ){
	while ( k > 0 ){
		int lg = 0;
		while ( (1<<lg) <= k ) lg++;
		lg--;
		u = dp[lg][u];
		k -= (1<<lg);
	}
	return u;
} 

int main( int argc, char* argv[] ){
	
	int t, u, v, c, k, wut;
	
	t = next_int();
	while ( t-- ){
		N = next_int();
		FOR( i, 1, N ){ parent[i] = -1; gr[i].clear(); }
		REP( i, N-1 ){
			u = next_int();
			v = next_int();
			c = next_int();
			gr[u].pb( edge_t(v, c) );
			gr[v].pb( edge_t(u, c) );
		}
		
		L[1] = 0; dis[1] = 0; parent[1] = 1;
		queue<int> q;
		q.push( 1 );
		while ( !q.empty() ){
			u = q.front(); q.pop();
			REP( i, SIZE(gr[u]) ){
				v = gr[u][i].v;
				c = gr[u][i].c;
				if ( parent[v] == -1 ){
					parent[v] = u;
					dis[v] = dis[u]+c;
					L[v] = L[u] + 1;
					q.push(v);
				}
			}
		}
		parent[1] = -1;
		
		for ( int lg = 0; (1<<lg) < N; lg++ )
			FOR( i, 1, N ) dp[lg][i] = -1;
			
		FOR( i, 1, N ) dp[0][i] = parent[i];
		
		for ( int lg = 1; (1<<lg) < N; lg++ )
			FOR( i, 1, N ) if( dp[lg-1][i] != -1 )
				dp[lg][i] = dp[lg-1][dp[lg-1][i]];
		
	qry:
	wut = nxt_cmd();
		if ( wut != -1 ){
			cin >> u >> v;
			int x = lca(u,v);
			if ( wut == 0 ) cout << dis[u]+dis[v]-2*dis[x] << "\n";
			else{
				k = next_int();
				k--;
				
				if ( L[u]-L[x] >= k ){
					printf("%d\n", kth( k, u ) );
				}
				else{
					k -= (L[u]-L[x]);
					k = L[v]-L[x]-k;
					printf("%d\n", kth( k, v ) );
				} 
			}

			goto qry;
		}
		puts("");
	}
	return 0;
}
