typedef pair<int, int> ii;

int dist[MAXV];
bool visited[MAXV];
vector<ii> grafo[MAXV];

/*	Verifiquem se o grafo esta indexado de 0 ou 1,
	para nao receberem resposta errada*/

int dijkstra(int s, int t){
	for (int i = 0; i < N; ++i){
        dist[i] = INF;
        visited[i] = false;
    }
    priority_queue<ii> pq;
    pq.push( make_pair(0, s) );
    dist[s] = 0;
    
    ii atual;
    //vector<ii>::iterator it;
    
    while (!pq.empty()){
		atual = pq.top(); pq.pop();
		int custo = -atual.first;
		int v = atual.second;
		if ( visited[v] ) continue; 
		visited[v] = true;
		for (int i = 0; i < grafo[v].size(); ++i){
			ii it = grafo[v][i];
			if (dist[it.first] > custo + it.second){
				dist[it.first] = custo + it.second;
				pq.push( make_pair( -dist[it.first], it.first ) );
			}
		}
    }
    return dist[t];
}