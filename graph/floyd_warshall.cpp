for (int k = 0; k < N; k++){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (graph[i][j] > graph[i][k] + graph[k][j])
				graph[i][j] = graph[i][k] + graph[k][j];
		}
	}
}