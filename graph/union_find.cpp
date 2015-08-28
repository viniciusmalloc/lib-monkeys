struct no{
    int pai, rank;
};

typedef struct no UJoin;

UJoin pset[MAXV];

void initialize(){
    for ( int i = 0; i < V; ++i ){
        pset[i].pai = i;
        pset[i].rank = visited[i] = 0;
        dfs_parent[i] = dfs_low[i] = dfs_num[i] = 0;
        directed[i].clear(); undirected[i].clear();
    }
}

void link (int x, int y){
    if ( pset[x].rank > pset[y].rank ) pset[y].pai = x;
    else{
        pset[x].pai = y;
        if ( pset[x].rank == pset[y].rank )
            pset[y].rank = pset[y].rank + 1;
    }
}

int findSet ( int x ){
    while ( pset[x].pai != x )
        x = pset[x].pai;
    return x;   
}

void unionSet ( int x, int y ){
    link ( findSet(x), findSet(y) );
}

bool isSameSet ( int x, int y ){
    return findSet(x) == findSet(y);
}
