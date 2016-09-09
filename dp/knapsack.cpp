int weight[MAX], value[MAX];

int fill_sack ( int items, int maxWeight ){
    int dp[items+1][maxWeight+1];
    for ( int i = 0; i <= maxWeight; i++ ) dp[0][i] = 0;
    for ( int i = 0; i <= items; i++ ) dp[i][0] = 0;
    for ( int i = 1; i <= items; i++ )
        for ( int j = 0; j <= maxWeight; j++ ){
            dp[i][j] = dp[i-1][j]; /* If I do not take this item */
            if ( j-weight[i] >= 0 ){
				/* suppose if I take this item */
				dp[i][j] = max( dp[i][j] , dp[i-1][j-weight[i]] + value[i] );
            }
        }
    return dp[items][maxWeight];
}