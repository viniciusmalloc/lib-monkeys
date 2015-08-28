int prefList[430][430];
int status[830]; /* status[i] contains husband/wife of i, initially -1 */
map<int, string> rev_bib;

void stableMarriage(int n){
    FOR(i, 2*n) status[i] = -1; /* 0...n mens, n...2*n women */
    queue<int> singleM;
    FOR(i, n) singleM.push(i); /* Push all single men */
  
    /* While there is a single men */
    while (!singleM.empty()){   
        int i = singleM.front();
        singleM.pop();
        FOR(j, n){
            /* if girl is single marry her to this man */
            int singleW = prefList[i][j];
            if (status[singleW] == -1){
                status[i] = singleW; /* set this girl as wife of i */
                status[singleW] = i; /*make i as husband of this girl*/
                break;
            }
            else{
                int rank1, rank2; /* for holding priority of current */
                FOR(k, n){        /* husband and most preferable husband */
                    if (prefList[singleW][k] == status[singleW]) rank1 = k;
                    if (prefList[singleW][k] == i) rank2 = k;
                }
                /* if this girl j prefers current man i more than her present husband */
                if (rank2 < rank1){ 
                    status[i] = singleW; /* her wife of i */
                    int old = status[singleW];
                    status[old] = -1;    /* divorce current husband */
                    singleM.push(old);   /* add him to list of singles */
                    status[singleW] = i; /* set new husband for this girl */
                    break;
                }
            }
        }
    }
     
    FOR(i, n){
        /* print each matching */
        cout << rev_bib[i] << " " << rev_bib[status[i]] << endl;
    }
}
