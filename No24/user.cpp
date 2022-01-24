int adj[100][5] ;
int cnt[100];
int king;
void dfs_init(int N, int path[100][2])
{
	for (int i = 0; i < 100; i++) {
		cnt[i] = 0;
		for (int j = 0; j < 5; j++)
			adj[i][j] = 0;
	}
	
	for (int i = 0; i < N-1; i++) {
		adj[path[i][0]][cnt[path[i][0]]++] = path[i][1];		
	}
}

int dfs2(int n) {
	int ret = -1;
	if (n > king) return n;
	if (cnt[n] == 0 ) return -1;
	
	for (int i = 0; i < cnt[n]; i++) {
		//cout << "HERE";
		ret = dfs2(adj[n][i]);
		if(ret != -1)
			return ret;
	}
	return ret;

}
int dfs(int n)
{
	int res;
	king = n;
	
	res = dfs2(n);
	//cout << "ANS : " << res << "\n";
	return res;
}
