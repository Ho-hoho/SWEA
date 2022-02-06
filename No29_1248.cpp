#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 14
int V, E,S,D;
vector <int> adj[10001];
int parent[10001][MAX+1];
int depth[10001];
int lca_node,ans;
void make_depth() {
	queue <int> q;
	int prev = 1;
	for (int next : adj[1]) {
		q.push(next);
		depth[next] = 1;
		parent[next][0] = 1;
	}
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int next : adj[cur]) {
			q.push(next);
			parent[next][0] = cur;
			depth[next] = depth[cur] + 1;
		}
	}
}

void connect() {
	for (int k = 1; k <= MAX; k++) {
		for (int cur = 1; cur <= V; cur++) {
			parent[cur][k] = parent[parent[cur][k - 1]][k - 1];
		}
	}
}

int LCA(int u, int v) {
	if (depth[u] < depth[v]) {
		int temp = u;	u = v;	v = temp;
	}
	int diff = depth[u] - depth[v];
	for(int i = 0; diff != 0; i++) {
		if ((diff & 1))
			u = parent[u][i];
		diff = diff >> 1;
	}
	if (u != v) {
		for (int i = MAX; i >= 0; i--) {
			if (parent[u][i] != 0 && parent[u][i] != parent[v][i]) {
				u = parent[u][i];
				v = parent[v][i];
			}
		}
		u = parent[u][0];
	}
	return u;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(parent, 0, sizeof(parent));
		memset(depth, -1, sizeof(depth));
		cin >> V >> E >> S >> D;
		for (int i = 1; i <= V; i++)
			adj[i].clear();
		for (int i = 0; i < E; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
		}
		depth[1] = 0;
		make_depth();
		connect();
		lca_node = LCA(S, D);
		ans = 0;
		for (int i = 1; i <= V; i++) {
			if (LCA(lca_node, i) == lca_node)
				ans++;
		}
		cout << "#" << test_case << " "<< lca_node << " " << ans << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
